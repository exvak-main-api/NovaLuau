#pragma once

#include "../core/Environment.hpp"

namespace NovaLuau
{


class DebugLibrary
{

public:

    static void registerFunctions(
        std::shared_ptr<Environment> environment
    );


};


}
