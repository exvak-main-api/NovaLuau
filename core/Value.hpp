#pragma once

#include <string>
#include <memory>
#include <variant>

namespace NovaLuau
{

class Table;
class Function;


enum class ValueType
{
    NIL,
    BOOLEAN,
    NUMBER,
    STRING,
    TABLE,
    FUNCTION
};


class Value
{
private:

    ValueType type;


    std::variant<
        std::monostate,
        bool,
        double,
        std::string,
        std::shared_ptr<Table>,
        std::shared_ptr<Function>
    > data;


public:

    Value();


    Value(bool value);

    Value(double value);

    Value(
        const std::string& value
    );


    Value(
        std::shared_ptr<Table> table
    );


    Value(
        std::shared_ptr<Function> function
    );


    ValueType getType() const;


    bool isNil() const;


    bool asBoolean() const;


    double asNumber() const;


    std::string asString() const;


    std::shared_ptr<Table> asTable() const;


    std::shared_ptr<Function> asFunction() const;


    std::string toString() const;

};


}
