#pragma once

#include <string>
#include <vector>

namespace NovaLuau
{


enum class TokenType
{
    Identifier,
    Number,
    String,

    LeftParen,
    RightParen,

    LeftBrace,
    RightBrace,

    LeftBracket,
    RightBracket,

    Comma,
    Dot,

    Equals,

    Local,
    Function,
    End,
    Return,

    True,
    False,
    Nil,

    Plus,
    Minus,
    Multiply,
    Divide,

    Comment,

    EndOfFile
};



struct Token
{

    TokenType type;

    std::string value;

    int line;

    int column;

};



class Lexer
{

private:

    std::string source;

    size_t position;

    int line;

    int column;


    char current();


    char advance();


    void skipWhitespace();


    Token makeToken(
        TokenType type,
        std::string value
    );


    Token readNumber();


    Token readString();


    Token readIdentifier();



public:

    Lexer(
        const std::string& source
    );


    std::vector<Token> tokenize();

};


}
