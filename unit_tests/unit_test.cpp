#include "gtest/gtest.h"

#include "../unit_tests/single_command_tests.hpp"	
#include "../unit_tests/multiple_commands_tests.hpp" 
#include "../unit_tests/commented_command_tests.hpp" 
#include "../unit_tests/exit_command_tests.hpp"
#include "../unit_tests/test_literal_tests.hpp"
#include "../unit_tests/test_symbolic_tests.hpp"
#include "../unit_tests/precedence_tests.hpp"


int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
