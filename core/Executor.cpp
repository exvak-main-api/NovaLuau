#include "Executor.hpp"

#include "../parser/AST.hpp"
#include "../objects/Function.hpp"
#include "../objects/Table.hpp"

#include <iostream>


namespace NovaLuau
{


Executor::Executor(
    std::shared_ptr<Environment> environment
)
{
    this->environment = environment;
}



Value evaluate(
    std::shared_ptr<ASTNode> node,
    std::shared_ptr<Environment> environment
)
{

    if(node->type == ASTType::Number)
    {
        auto value =
            std::static_pointer_cast<ValueNode>(node);

        return Value(
            std::stod(value->value)
        );
    }



    if(node->type == ASTType::String)
    {
        auto value =
            std::static_pointer_cast<ValueNode>(node);

        return Value(
            value->value
        );
    }



    if(node->type == ASTType::Boolean)
    {
        auto value =
            std::static_pointer_cast<ValueNode>(node);

        return Value(
            value->value == "true"
        );
    }



    if(node->type == ASTType::Nil)
    {
        return Value();
    }



    if(node->type == ASTType::Variable)
    {
        auto variable =
            std::static_pointer_cast<VariableNode>(node);


        return environment->get(
            variable->name
        );
    }



    if(node->type == ASTType::Table)
    {

        auto tableNode =
            std::static_pointer_cast<TableNode>(node);



        auto table =
            std::make_shared<Table>();



        for(auto& field : tableNode->fields)
        {

            table->set(
                field.first,
                evaluate(
                    field.second,
                    environment
                )
            );

        }



        return Value(table);

    }



    return Value();

}



void Executor::execute(
    std::vector<std::shared_ptr<ASTNode>> nodes
)
{

    for(auto& node : nodes)
    {


        if(node->type == ASTType::VariableDeclaration)
        {

            auto declaration =
                std::static_pointer_cast<
                    VariableDeclarationNode
                >(node);



            Value value =
                evaluate(
                    declaration->value,
                    environment
                );



            environment->define(
                declaration->name,
                value
            );


            continue;

        }



        if(node->type == ASTType::Call)
        {

            auto call =
                std::static_pointer_cast<
                    CallNode
                >(node);



            Value functionValue =
                environment->get(
                    call->name
                );



            auto function =
                functionValue.asFunction();



            std::vector<Value> args;



            for(auto& argument : call->arguments)
            {

                args.push_back(
                    evaluate(
                        argument,
                        environment
                    )
                );

            }



            function->call(
                args
            );


        }


    }

}


}
