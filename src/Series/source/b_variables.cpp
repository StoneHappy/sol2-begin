#include <sol/forward.hpp>
#include <sol/state.hpp>
#define SOL_ALL_SAFETIES_ON 1
#include <sol/sol.hpp>
namespace b_variables
{
    int main()
    {
        // read
        sol::state lua;
        lua.script_file("lua/b_variables.lua");
        auto isfullscreen = lua["config"]["fullscreen"];
        sol::table config = lua["config"];


        // write
        if (isfullscreen.valid()) {
            isfullscreen = false;
        }


        return EXIT_SUCCESS;
    }
}