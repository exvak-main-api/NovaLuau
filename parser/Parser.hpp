#pragma once

#include <vector>
#include <memory>
#include "Lexer.hpp"

namespace NovaLuau
{


class ASTNode
{
public:

    virtual ~ASTNode() = default;

};



class Parser
{

private:

    std::vector<Token> tokens;

    size_t current;


    Token peek();


    Token advance();


    bool check(
        TokenType type
    );


    bool match(
        TokenType type
    );


    std::shared_ptr<ASTNode> parseStatement();


    std::shared_ptr<ASTNode> parseExpression();


public:

    Parser(
        const std::vector<Token>& tokens
    );


    std::vector<std::shared_ptr<ASTNode>> parse();


};


}
