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



std::shared_ptr<ASTNode> Parser::parseTable()
{

    auto table =
        std::make_shared<TableNode>();


    match(
        TokenType::LeftBrace
    );


    while(
        !check(TokenType::RightBrace) &&
        !check(TokenType::EndOfFile)
    )
    {

        Token key =
            advance();


        if(
            key.type != TokenType::Identifier
        )
        {
            throw std::runtime_error(
                "expected table key"
            );
        }


        match(
            TokenType::Equals
        );


        auto value =
            parseExpression();



        table->fields.push_back(
        {
            key.value,
            value
        });



        if(
            !match(TokenType::Comma)
        )
            break;

    }



    match(
        TokenType::RightBrace
    );


    return table;

}



std::shared_ptr<ASTNode> Parser::parsePrimary()
{

    std::shared_ptr<ASTNode> node;



    if(
        check(TokenType::LeftBrace)
    )
    {

        node =
            parseTable();

    }

    else
    {

        Token token =
            advance();



        if(
            token.type == TokenType::Number
        )
        {
            node =
                std::make_shared<ValueNode>(
                    ASTType::Number,
                    token.value
                );
        }



        else if(
            token.type == TokenType::String
        )
        {
            node =
                std::make_shared<ValueNode>(
                    ASTType::String,
                    token.value
                );
        }



        else if(
            token.type == TokenType::True ||
            token.type == TokenType::False
        )
        {
            node =
                std::make_shared<ValueNode>(
                    ASTType::Boolean,
                    token.value
                );
        }



        else if(
            token.type == TokenType::Nil
        )
        {
            node =
                std::make_shared<ValueNode>(
                    ASTType::Nil,
                    "nil"
                );
        }



        else if(
            token.type == TokenType::Identifier
        )
        {

            node =
                std::make_shared<VariableNode>(
                    token.value
                );

        }



        else
        {
            throw std::runtime_error(
                "unexpected token: " + token.value
            );
        }

    }



    while(
        match(TokenType::Dot)
    )
    {

        Token key =
            advance();


        if(
            key.type != TokenType::Identifier
        )
        {
            throw std::runtime_error(
                "expected field name"
            );
        }


        node =
            std::make_shared<IndexNode>(
                node,
                key.value
            );

    }



    return node;

}



std::shared_ptr<ASTNode> Parser::parseExpression()
{
    return parsePrimary();
}



std::shared_ptr<ASTNode> Parser::parseCall()
{

    Token name =
        advance();


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


        if(
            !match(TokenType::Comma)
        )
            break;

    }



    match(
        TokenType::RightParen
    );


    return call;

}



std::shared_ptr<ASTNode> Parser::parseFunction()
{

    Token name =
        advance();



    auto function =
        std::make_shared<FunctionNode>(
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

        Token parameter =
            advance();


        if(
            parameter.type ==
            TokenType::Identifier
        )
        {

            function->parameters.push_back(
                parameter.value
            );

        }


        if(
            !match(TokenType::Comma)
        )
            break;

    }



    match(
        TokenType::RightParen
    );



    while(
        !check(TokenType::End) &&
        !check(TokenType::EndOfFile)
    )
    {

        function->body.push_back(
            parseStatement()
        );

    }



    match(
        TokenType::End
    );



    return function;

}



std::shared_ptr<ASTNode> Parser::parseStatement()
{

    if(
        match(TokenType::Function)
    )
    {

        return parseFunction();

    }



    if(
        match(TokenType::Local)
    )
    {

        Token name =
            advance();


        match(
            TokenType::Equals
        );


        return std::make_shared<
            VariableDeclarationNode
        >(
            name.value,
            parseExpression()
        );

    }



    if(
        check(TokenType::Identifier)
    )
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

    std::vector<
        std::shared_ptr<ASTNode>
    > nodes;



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
