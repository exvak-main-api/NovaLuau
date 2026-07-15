#include <iostream>
#include <string>

#include "core/VM.hpp"

using namespace NovaLuau;


int main()
{

    VM vm;


    vm.registerLibraries();


    std::cout
        << "NovaLuau Console\n";


    std::cout
        << "Type 'exit' to close\n\n";


    while(true)
    {

        std::string code;


        std::cout << "> ";

        std::getline(
            std::cin,
            code
        );


        if(code == "exit")
            break;


        vm.execute(
            code
        );

    }


    return 0;
}
