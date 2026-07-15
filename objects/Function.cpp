#include "Function.hpp"


namespace NovaLuau
{


Function::Function(
    const std::string& name,
    NativeFunction callback
)
{

    this->name = name;

    this->nativeCallback = callback;

    this->isNative = true;

}



Function::Function(
    const std::string& name
)
{

    this->name = name;

    this->isNative = false;

}



Value Function::call(
    std::vector<Value> args
)
{

    if(
        isNative &&
        nativeCallback
    )
    {

        return nativeCallback(
            args
        );

    }


    return Value();

}



std::string Function::getName()
{
    return name;
}



bool Function::native()
{
    return isNative;
}


}
