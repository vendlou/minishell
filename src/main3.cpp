#include <iostream>
#include <fstream>
#include "../header/multiple_commands.h"

int main(){
	char* st="../integration_tests/exit_command_tests.txt";
	Multiple_Commands* mc=new Multiple_Commands(st);
	mc->do_commands();
}

