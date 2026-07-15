#pragma once

#include <string>
#include <unordered_map>
#include <vector>
#include "../core/Value.hpp"

namespace NovaLuau
{

class Table
{

private:

    std::unordered_map<std::string, Value> fields;

    std::unordered_map<int, Value> array;


public:

    void set(
        const std::string& key,
        const Value& value
    );


    void set(
        int index,
        const Value& value
    );


    Value get(
        const std::string& key
    );


    Value get(
        int index
    );


    bool has(
        const std::string& key
    );


    bool has(
        int index
    );


    size_t size();


    std::string toString();

};

}
