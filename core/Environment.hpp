#pragma once

#include <string>
#include <unordered_map>
#include <memory>
#include "Value.hpp"

namespace NovaLuau
{


class Environment : public std::enable_shared_from_this<Environment>
{

private:

    std::unordered_map<std::string, Value> variables;

    std::shared_ptr<Environment> parent;


public:

    Environment(
        std::shared_ptr<Environment> parent = nullptr
    );


    void define(
        const std::string& name,
        const Value& value
    );


    void set(
        const std::string& name,
        const Value& value
    );


    Value get(
        const std::string& name
    );


    bool exists(
        const std::string& name
    );


    std::shared_ptr<Environment> getParent();

};


}
