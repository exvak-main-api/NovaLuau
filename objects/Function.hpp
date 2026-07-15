#pragma once

#include <string>
#include <vector>
#include <memory>
#include "../core/Value.hpp"
#include "../core/Environment.hpp"

namespace NovaLuau
{

class Function
{

private:

    std::string name;

    std::vector<std::string> parameters;

    std::vector<std::string> body;

    std::string source;

    int lineDefined;

    bool isNative;


public:

    Function(
        const std::string& name,
        const std::vector<std::string>& parameters,
        const std::vector<std::string>& body,
        const std::string& source,
        int lineDefined
    );


    Function(
        const std::string& name
    );


    Value call(
        std::vector<Value> args,
        std::shared_ptr<Environment> environment
    );


    std::string getName();


    std::string getSource();


    int getLineDefined();


    bool native();


    std::string getInfo();


};

}
