#include <sol/overload.hpp>
#include <string>
#define SOL_ALL_SAFETIES_ON 1
#include <sol/sol.hpp>

std::string my_function(int a, const std::string& b)
{
    return (b + std::string("D", a));
}

struct my_class
{
    int a = 0;

    my_class(int x = 0) : a(x) {}

    int func() { return ++a; }
};


template <typename A, typename B>
auto my_add( A a, B b ) {
        return a + b;
}

namespace c_functions
{
    int main()
    {
        /**
         * @brief set function example
         * 
         */
        sol::state lua;
        lua["my_func"] = my_function;
        // lua.set("my_func", my_function);
        // lua.set_function("my_func", my_function);

        lua.script("som_str = my_func(1, 'Da')");
        std::string some_str = lua["som_str"];

        if (some_str != "DaD") {
            return EXIT_FAILURE;
        }

        // register class function with instance
        lua.set_function("my_class_func", &my_class::func, my_class());
        lua.script(R"(
            a1 = my_class_func()
            a2 = my_class_func()
        )");

        int a1 = lua["a1"];
        int a2 = lua["a2"];
        if (a1 != 1 || a2 != 2) {
            return EXIT_FAILURE;
        }

        // register class function without instance
        lua.set_function("my_class_func2", &my_class::func);
        lua.set("obj", my_class(24));
        lua.script(R"(
            a3 = my_class_func2(obj);
        )");
        int a3 = lua["a3"];
        if (a3 != 25) {
            return EXIT_FAILURE;
        }

        // register templated function
        lua.set_function("my_int_add", my_add<int, int>);
        lua.set_function("my_string_add", my_add<std::string, std::string>);
        lua["my_combine"] = sol::overload(my_add<int, int>, my_add<std::string, std::string>);

        lua.script(R"(
            m0 = my_int_add(1, 1)
            m1 = my_string_add('1', '1')
            m2 = my_combine(1, 1)
            m3 = my_combine('1', '1')
        )");

        int m0 = lua["m0"];
        std::string m1 = lua["m1"];
        int m2 = lua["m2"];
        std::string m3 = lua["m3"];
        if (m0 != m2 || m1 != m3) {
            return EXIT_FAILURE;
        }

        return EXIT_SUCCESS;
    }
}