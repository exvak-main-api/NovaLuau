#pragma once

#include <vector>
#include <memory>

#include "Lexer.hpp"
#include "AST.hpp"


namespace NovaLuau
{


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


    std::shared_ptr<ASTNode> parsePrimary();


    std::shared_ptr<ASTNode> parseCall();


public:

    Parser(
        const std::vector<Token>& tokens
    );


    std::vector<std::shared_ptr<ASTNode>> parse();

};


}
