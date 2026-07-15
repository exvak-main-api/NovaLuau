#include "Lexer.hpp"
#include <cctype>

namespace NovaLuau
{


Lexer::Lexer(
    const std::string& source
)
{
    this->source = source;
    position = 0;
    line = 1;
    column = 1;
}



char Lexer::current()
{
    if(position >= source.size())
        return '\0';

    return source[position];
}



char Lexer::advance()
{
    char c = current();

    position++;

    if(c == '\n')
    {
        line++;
        column = 1;
    }
    else
    {
        column++;
    }

    return c;
}



void Lexer::skipWhitespace()
{
    while(
        current() == ' ' ||
        current() == '\t' ||
        current() == '\n' ||
        current() == '\r'
    )
    {
        advance();
    }
}



Token Lexer::makeToken(
    TokenType type,
    std::string value
)
{
    return {
        type,
        value,
        line,
        column
    };
}



Token Lexer::readNumber()
{
    std::string value;


    while(
        std::isdigit(current()) ||
        current() == '.'
    )
    {
        value += advance();
    }


    return makeToken(
        TokenType::Number,
        value
    );
}



Token Lexer::readString()
{
    std::string value;

    advance();


    while(
        current() != '"' &&
        current() != '\0'
    )
    {
        value += advance();
    }


    if(current() == '"')
        advance();


    return makeToken(
        TokenType::String,
        value
    );
}



Token Lexer::readIdentifier()
{
    std::string value;


    while(
        std::isalnum(current()) ||
        current() == '_'
    )
    {
        value += advance();
    }


    if(value == "local")
        return makeToken(TokenType::Local,value);

    if(value == "function")
        return makeToken(TokenType::Function,value);

    if(value == "end")
        return makeToken(TokenType::End,value);

    if(value == "return")
        return makeToken(TokenType::Return,value);

    if(value == "true")
        return makeToken(TokenType::True,value);

    if(value == "false")
        return makeToken(TokenType::False,value);

    if(value == "nil")
        return makeToken(TokenType::Nil,value);


    return makeToken(
        TokenType::Identifier,
        value
    );
}



std::vector<Token> Lexer::tokenize()
{
    std::vector<Token> tokens;


    while(current() != '\0')
    {

        skipWhitespace();


        char c = current();


        if(c == '\0')
            break;


        if(std::isdigit(c))
        {
            tokens.push_back(readNumber());
            continue;
        }



        if(c == '"')
        {
            tokens.push_back(readString());
            continue;
        }



        if(std::isalpha(c) || c == '_')
        {
            tokens.push_back(readIdentifier());
            continue;
        }



        advance();


        switch(c)
        {

            case '(':
                tokens.push_back(makeToken(TokenType::LeftParen,"("));
                break;

            case ')':
                tokens.push_back(makeToken(TokenType::RightParen,")"));
                break;

            case '{':
                tokens.push_back(makeToken(TokenType::LeftBrace,"{"));
                break;

            case '}':
                tokens.push_back(makeToken(TokenType::RightBrace,"}"));
                break;

            case '[':
                tokens.push_back(makeToken(TokenType::LeftBracket,"["));
                break;

            case ']':
                tokens.push_back(makeToken(TokenType::RightBracket,"]"));
                break;

            case ',':
                tokens.push_back(makeToken(TokenType::Comma,","));
                break;

            case '.':
                tokens.push_back(makeToken(TokenType::Dot,"."));
                break;

            case '=':
                tokens.push_back(makeToken(TokenType::Equals,"="));
                break;

            case '+':
                tokens.push_back(makeToken(TokenType::Plus,"+"));
                break;

            case '-':
                tokens.push_back(makeToken(TokenType::Minus,"-"));
                break;

            case '*':
                tokens.push_back(makeToken(TokenType::Multiply,"*"));
                break;

            case '/':
                tokens.push_back(makeToken(TokenType::Divide,"/"));
                break;
        }
    }


    tokens.push_back(
        makeToken(
            TokenType::EndOfFile,
            ""
        )
    );


    return tokens;
}


} 
