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
        std::make_shared<Function>(
            "print",

            [](std::vector<Value> args)
            {

                for(auto& value : args)
                {

                    std::cout
                        << value.toString()
                        << " ";

                }


                std::cout
                    << std::endl;


                return Value();

            }
        );



    auto typeFunction =
        std::make_shared<Function>(
            "type",

            [](std::vector<Value> args)
            {

                if(args.empty())
                    return Value("nil");


                switch(
                    args[0].getType()
                )
                {

                    case ValueType::NIL:
                        return Value("nil");


                    case ValueType::BOOLEAN:
                        return Value("boolean");


                    case ValueType::NUMBER:
                        return Value("number");


                    case ValueType::STRING:
                        return Value("string");


                    case ValueType::TABLE:
                        return Value("table");


                    case ValueType::FUNCTION:
                        return Value("function");

                }


                return Value("unknown");

            }
        );



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
