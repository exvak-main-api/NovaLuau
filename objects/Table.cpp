#include "Table.hpp"
#include <sstream>

namespace NovaLuau
{


void Table::set(
    const std::string& key,
    const Value& value
)
{
    fields[key] = value;
}



void Table::set(
    int index,
    const Value& value
)
{
    array[index] = value;
}



Value Table::get(
    const std::string& key
)
{
    if(fields.find(key) != fields.end())
        return fields[key];

    return Value();
}



Value Table::get(
    int index
)
{
    if(array.find(index) != array.end())
        return array[index];

    return Value();
}



bool Table::has(
    const std::string& key
)
{
    return fields.find(key) != fields.end();
}



bool Table::has(
    int index
)
{
    return array.find(index) != array.end();
}



size_t Table::size()
{
    return fields.size() + array.size();
}



std::string Table::toString()
{
    std::stringstream out;

    out << "{";

    bool first = true;

    for(auto& item : fields)
    {
        if(!first)
            out << ", ";

        out << item.first;
        out << " = ";
        out << item.second.toString();

        first = false;
    }


    for(auto& item : array)
    {
        if(!first)
            out << ", ";

        out << "[" << item.first << "] = ";
        out << item.second.toString();

        first = false;
    }


    out << "}";

    return out.str();
}


}
