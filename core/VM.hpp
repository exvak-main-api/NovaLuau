#pragma once

#include <string>
#include <memory>

#include "Environment.hpp"

namespace NovaLuau
{


class VM
{

private:

    std::shared_ptr<Environment> global;


public:

    VM();


    void registerLibraries();


    bool execute(
        const std::string& code
    );


    std::shared_ptr<Environment> getEnvironment();


};


}
