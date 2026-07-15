#include "Executor.hpp"
#include <iostream>

namespace NovaLuau
{


Executor::Executor(
    std::shared_ptr<Environment> environment
)
{
    this->environment = environment;
}



void Executor::execute(
    std::vector<std::shared_ptr<ASTNode>> nodes
)
{

    for(auto& node : nodes)
    {

        if(!node)
            continue;


        /*
            AST execution will be implemented here.

            This layer will handle:

            - variables
            - functions
            - tables
            - calls
            - returns
            - expressions
        */


    }

}


}
