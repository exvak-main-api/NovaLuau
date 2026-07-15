#pragma once

#include <memory>
#include <vector>

#include "../parser/Parser.hpp"
#include "Environment.hpp"

namespace NovaLuau
{


class Executor
{

private:

    std::shared_ptr<Environment> environment;


public:

    Executor(
        std::shared_ptr<Environment> environment
    );


    void execute(
        std::vector<std::shared_ptr<ASTNode>> nodes
    );


};


}
