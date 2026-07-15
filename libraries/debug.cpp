#include "Debug.hpp"
#include "../objects/Function.hpp"

namespace NovaLuau
{


void DebugLibrary::registerFunctions(
    std::shared_ptr<Environment> environment
)
{

    auto getInfo =
        std::make_shared<Function>(
            "getinfo"
        );


    auto debugTable =
        std::make_shared<Table>();


    debugTable->set(
        "getinfo",
        Value(getInfo)
    );


    environment->define(
        "debug",
        Value(debugTable)
    );

}


}
