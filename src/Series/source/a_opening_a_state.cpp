#define SOL_ALL_SAFETIES_ON 1
#include <sol/sol.hpp>
#include <iostream>
#include <assert.h>
namespace a_opening_a_state
{
    int main()
    {
        std::cout << "=== opening a state ====" << std::endl;

        sol::state lua;
        // open some common libraries
        lua.open_libraries(sol::lib::base, sol::lib::package);
        lua.script("print('bark bark bark!')");

        std::cout << std::endl;

        return EXIT_SUCCESS;
    }
}
