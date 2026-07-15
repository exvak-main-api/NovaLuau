#include "Function.hpp"

namespace NovaLuau
{


Function::Function(
    const std::string& name,
    const std::vector<std::string>& parameters,
    const std::vector<std::string>& body,
    const std::string& source,
    int lineDefined
)
{
    this->name = name;
    this->parameters = parameters;
    this->body = body;
    this->source = source;
    this->lineDefined = lineDefined;
    this->isNative = false;
}



Function::Function(
    const std::string& name
)
{
    this->name = name;
    this->source = "[C]";
    this->lineDefined = 0;
    this->isNative = true;
}



Value Function::call(
    std::vector<Value> args,
    std::shared_ptr<Environment> environment
)
{
    auto local = std::make_shared<Environment>(environment);


    for(size_t i = 0; i < parameters.size(); i++)
    {
        if(i < args.size())
            local->define(parameters[i], args[i]);
        else
            local->define(parameters[i], Value());
    }


    return Value();
}



std::string Function::getName()
{
    return name;
}



std::string Function::getSource()
{
    return source;
}



int Function::getLineDefined()
{
    return lineDefined;
}



bool Function::native()
{
    return isNative;
}



std::string Function::getInfo()
{
    std::string info;

    info += "source = " + source + "\n";
    info += "short_src = " + source.substr(0, 60) + "\n";
    info += "linedefined = " + std::to_string(lineDefined) + "\n";
    info += "what = ";

    if(isNative)
        info += "C\n";
    else
        info += "Lua\n";


    info += "name = " + name + "\n";
    info += "namewhat = global\n";
    info += "nups = 0";


    return info;
}


}
