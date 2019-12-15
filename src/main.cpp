#include <iostream>
#include <fstream>
#include "../header/multiple_commands.h"

int main(int argv,char** argc){
	Multiple_Commands* mc=new Multiple_Commands("integration_tests/test_symbolic_tests.txt");
	mc->do_commands();
}

