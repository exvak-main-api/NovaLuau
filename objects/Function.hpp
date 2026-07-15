#pragma once

#include <string>
#include <vector>
#include <memory>
#include <functional>

#include "../core/Value.hpp"
#include "../core/Environment.hpp"


namespace NovaLuau
{


class Function
{

public:

    using NativeFunction =
        std::function<Value(
            std::vector<Value>
        )>;


private:

    std::string name;

    NativeFunction nativeCallback;

    bool isNative;


public:

    Function(
        const std::string& name,
        NativeFunction callback
    );


    Function(
        const std::string& name
    );


    Value call(
        std::vector<Value> args
    );


    std::string getName();


    bool native();


};


}
