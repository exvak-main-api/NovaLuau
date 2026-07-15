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



std::shared_ptr<ASTNode> Parser::parse()
{
    return nullptr;
}



std::shared_ptr<ASTNode> Parser::parsePrimary()
{

    Token token = advance();


    if(token.type == TokenType::Number)
    {
        return std::make_shared<ValueNode>(
            ASTType::Number,
            token.value
        );
    }


    if(token.type == TokenType::String)
    {
        return std::make_shared<ValueNode>(
            ASTType::String,
            token.value
        );
    }


    if(token.type == TokenType::True)
    {
        return std::make_shared<ValueNode>(
            ASTType::Boolean,
            "true"
        );
    }


    if(token.type == TokenType::False)
    {
        return std::make_shared<ValueNode>(
            ASTType::Boolean,
            "false"
        );
    }


    if(token.type == TokenType::Nil)
    {
        return std::make_shared<ValueNode>(
            ASTType::Nil,
            "nil"
        );
    }


    if(token.type == TokenType::Identifier)
    {
        return std::make_shared<VariableNode>(
            token.value
        );
    }


    throw std::runtime_error(
        "unexpected token: " + token.value
    );

}



std::shared_ptr<ASTNode> Parser::parseExpression()
{
    return parsePrimary();
}



std::shared_ptr<ASTNode> Parser::parseCall()
{
    Token name = advance();


    auto call =
        std::make_shared<CallNode>(
            name.value
        );


    match(
        TokenType::LeftParen
    );


    while(
        !check(TokenType::RightParen) &&
        !check(TokenType::EndOfFile)
    )
    {

        call->arguments.push_back(
            parseExpression()
        );


        if(!match(TokenType::Comma))
            break;

    }


    match(
        TokenType::RightParen
    );


    return call;
}



std::shared_ptr<ASTNode> Parser::parseStatement()
{

    if(match(TokenType::Local))
    {

        Token name = advance();


        match(
            TokenType::Equals
        );


        auto value =
            parseExpression();


        return std::make_shared<VariableDeclarationNode>(
            name.value,
            value
        );

    }



    if(check(TokenType::Identifier))
    {

        if(
            tokens[current + 1].type ==
            TokenType::LeftParen
        )
        {
            return parseCall();
        }

    }



    return parseExpression();

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
