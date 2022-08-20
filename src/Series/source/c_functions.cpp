#include <string>
#define SOL_ALL_SAFETIES_ON 1
#include <sol/sol.hpp>

std::string my_function(int a, const std::string& b)
{
    return (b + std::string("D", a));
}

namespace c_functions
{
    int main()
    {
        // read
        sol::state lua;
        lua["my_func"] = my_function;
        // lua.set("my_func", my_function);
        // lua.set_function("my_func", my_function);

        lua.script("som_str = my_func(1, 'Da')");
        std::string some_str = lua["som_str"];

        if (some_str != "DaD") {
            return EXIT_FAILURE;
        }

        return EXIT_SUCCESS;
    }
}