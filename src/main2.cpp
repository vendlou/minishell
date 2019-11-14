#include <iostream>
#include <fstream>
#include "../header/multiple_commands.hpp"

int main(){
	char* st="../integration_tests/commented_command_tests.sh";
	Multiple_Commands* mc=new Multiple_Commands(st);
	mc->do_commands();
}

