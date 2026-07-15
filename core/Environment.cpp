#include "Environment.hpp"
#include <stdexcept>

namespace NovaLuau
{


Environment::Environment(
    std::shared_ptr<Environment> parent
)
{
    this->parent = parent;
}



void Environment::define(
    const std::string& name,
    const Value& value
)
{
    variables[name] = value;
}



void Environment::set(
    const std::string& name,
    const Value& value
)
{

    if(variables.find(name) != variables.end())
    {
        variables[name] = value;
        return;
    }


    if(parent)
    {
        parent->set(name, value);
        return;
    }


    variables[name] = value;
}



Value Environment::get(
    const std::string& name
)
{

    if(variables.find(name) != variables.end())
    {
        return variables[name];
    }


    if(parent)
    {
        return parent->get(name);
    }


    throw std::runtime_error(
        "NovaLuau: unknown variable '" + name + "'"
    );
}



bool Environment::exists(
    const std::string& name
)
{

    if(variables.find(name) != variables.end())
        return true;


    if(parent)
        return parent->exists(name);


    return false;
}



std::shared_ptr<Environment> Environment::getParent()
{
    return parent;
}


}
