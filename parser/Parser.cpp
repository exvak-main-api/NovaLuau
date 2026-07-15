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

        Token key = advance();


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


        if(!match(TokenType::Comma))
            break;

    }


    match(
        TokenType::RightBrace
    );


    return table;

}
