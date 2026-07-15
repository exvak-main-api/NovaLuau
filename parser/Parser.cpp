#include "Parser.hpp"
#include <stdexcept>

namespace NovaLuau
{


Parser::Parser(
    const std::vector<Token>& tokens
)
{
    this->tokens = tokens;
    current = 0;
}



Token Parser::peek()
{
    return tokens[current];
}



Token Parser::advance()
{
    if(current < tokens.size())
        current++;

    return tokens[current - 1];
}



bool Parser::check(
    TokenType type
)
{
    return peek().type == type;
}



bool Parser::match(
    TokenType type
)
{
    if(check(type))
    {
        advance();
        return true;
    }

    return false;
}



std::shared_ptr<ASTNode> Parser::parseStatement()
{
    Token token = peek();


    if(match(TokenType::Local))
    {
        return std::make_shared<ASTNode>();
    }


    if(match(TokenType::Function))
    {
        return std::make_shared<ASTNode>();
    }


    if(match(TokenType::Return))
    {
        return std::make_shared<ASTNode>();
    }


    return parseExpression();
}



std::shared_ptr<ASTNode> Parser::parseExpression()
{
    advance();

    return std::make_shared<ASTNode>();
}



std::vector<std::shared_ptr<ASTNode>> Parser::parse()
{
    std::vector<std::shared_ptr<ASTNode>> nodes;


    while(
        !check(TokenType::EndOfFile)
    )
    {
        nodes.push_back(
            parseStatement()
        );
    }


    return nodes;
}


}
