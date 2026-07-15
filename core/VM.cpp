#include "Executor.hpp"

#include "VM.hpp"

#include "../libraries/Base.hpp"
#include "../libraries/Debug.hpp"

#include "../parser/Lexer.hpp"
#include "../parser/Parser.hpp"

#include <iostream>


namespace NovaLuau
{


VM::VM()
{
    global = std::make_shared<Environment>();
}



void VM::registerLibraries()
{

    BaseLibrary::registerFunctions(
        global
    );


    DebugLibrary::registerFunctions(
        global
    );

}



bool VM::execute(
    const std::string& code
)
{

    try
    {

        Lexer lexer(code);

        auto tokens =
            lexer.tokenize();


        Parser parser(tokens);

        auto tree =
            parser.parse();


        Executor executor(global);
        executor.execute(tree);
        return true;

    }

    catch(
        const std::exception& e
    )
    {

        std::cout
            << "NovaLuau Error: "
            << e.what()
            << std::endl;


        return false;

    }

}



std::shared_ptr<Environment> VM::getEnvironment()
{
    return global;
}


}
