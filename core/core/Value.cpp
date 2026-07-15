#include "Value.hpp"

namespace NovaLuau
{


Value::Value()
{
    type = ValueType::NIL;
    data = std::monostate{};
}


Value::Value(bool value)
{
    type = ValueType::BOOLEAN;
    data = value;
}


Value::Value(double value)
{
    type = ValueType::NUMBER;
    data = value;
}


Value::Value(const std::string& value)
{
    type = ValueType::STRING;
    data = value;
}


Value::Value(std::shared_ptr<Table> table)
{
    type = ValueType::TABLE;
    data = table;
}


Value::Value(std::shared_ptr<Function> function)
{
    type = ValueType::FUNCTION;
    data = function;
}


ValueType Value::getType() const
{
    return type;
}


bool Value::isNil() const
{
    return type == ValueType::NIL;
}


bool Value::asBoolean() const
{
    return std::get<bool>(data);
}


double Value::asNumber() const
{
    return std::get<double>(data);
}


std::string Value::asString() const
{
    return std::get<std::string>(data);
}


std::shared_ptr<Table> Value::asTable() const
{
    return std::get<std::shared_ptr<Table>>(data);
}


std::shared_ptr<Function> Value::asFunction() const
{
    return std::get<std::shared_ptr<Function>>(data);
}


std::string Value::toString() const
{

    switch(type)
    {

        case ValueType::NIL:
            return "nil";


        case ValueType::BOOLEAN:
            return asBoolean() ? "true" : "false";


        case ValueType::NUMBER:
            return std::to_string(asNumber());


        case ValueType::STRING:
            return asString();


        case ValueType::TABLE:
            return "table";


        case ValueType::FUNCTION:
            return "function";

    }


    return "nil";
}


}
