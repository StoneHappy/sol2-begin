#include <sol/state.hpp>
#include <sol/types.hpp>
#define SOL_ALL_SAFETIES_ON 1
#include <sol/sol.hpp>
#include <iostream>
#include <assert.h>
namespace a_hello_lua
{
    int main()
    {
        sol::state lua;
        lua.open_libraries(sol::lib::base);

        lua.script("print('bark bark bark')");

        return EXIT_SUCCESS;
    }
}
