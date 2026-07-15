#include "Base.hpp"
#include "../objects/Function.hpp"
#include <iostream>

namespace NovaLuau
{


void BaseLibrary::registerFunctions(
    std::shared_ptr<Environment> environment
)
{

    auto printFunction =
        std::make_shared<Function>("print");


    auto typeFunction =
        std::make_shared<Function>("type");


    environment->define(
        "print",
        Value(printFunction)
    );


    environment->define(
        "type",
        Value(typeFunction)
    );

}


}
