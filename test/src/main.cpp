#include "tests/basic.hpp"
#include "tests/move.hpp"
#include "tests/signal_destroyed_before_slot.hpp"
#include <iostream>

template<class TestFn>
bool run_test(TestFn f, const char* test_name)
{
    std::cout << "Running " << test_name << " test... " << std::flush;
    const auto success = f();
    if(success)
        std::cout << "OK\n";
    else
        std::cout << "FAILED\n";
    return success;
}

int main()
{
    auto test_count = 0;
    auto success_count = 0;

#define RUN_TEST(TEST_NAME) \
    { \
        const auto success = run_test(&tests::TEST_NAME::test, #TEST_NAME); \
        if(success) \
            ++success_count; \
        ++test_count; \
    }

    RUN_TEST(basic);
    RUN_TEST(move);
    RUN_TEST(signal_destroyed_before_slot);

    std::cout << "\n" << success_count << "/" << test_count << " tests succeeded.\n";
    if(success_count == test_count)
    {
        std::cout << "SUCCESS!\n";
        return 0;
    }
    else
    {
        std::cout << "FAILURE!\n";
        return 1;
    }
}
