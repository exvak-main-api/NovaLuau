#pragma once

#include <string>
#include <vector>
#include <memory>


namespace NovaLuau
{


enum class ASTType
{
    Number,
    String,
    Boolean,
    Nil,

    Variable,

    VariableDeclaration,

    Assignment,

    BinaryExpression,

    Call,

    Function,

    Return,

    Table
};



class ASTNode
{

public:

    ASTType type;


    virtual ~ASTNode() = default;


};



class ValueNode : public ASTNode
{

public:

    std::string value;


    ValueNode(
        ASTType type,
        const std::string& value
    )
    {
        this->type = type;
        this->value = value;
    }

};



class VariableNode : public ASTNode
{

public:

    std::string name;


    VariableNode(
        const std::string& name
    )
    {
        type = ASTType::Variable;
        this->name = name;
    }

};



class VariableDeclarationNode : public ASTNode
{

public:

    std::string name;

    std::shared_ptr<ASTNode> value;


    VariableDeclarationNode(
        const std::string& name,
        std::shared_ptr<ASTNode> value
    )
    {
        type = ASTType::VariableDeclaration;
        this->name = name;
        this->value = value;
    }

};



class CallNode : public ASTNode
{

public:

    std::string name;

    std::vector<std::shared_ptr<ASTNode>> arguments;


    CallNode(
        const std::string& name
    )
    {
        type = ASTType::Call;
        this->name = name;
    }

};



class ReturnNode : public ASTNode
{

public:

    std::shared_ptr<ASTNode> value;


    ReturnNode(
        std::shared_ptr<ASTNode> value
    )
    {
        type = ASTType::Return;
        this->value = value;
    }

};


}
