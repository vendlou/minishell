#include <iostream>
#include <fstream>
#include "../header/multiple_commands.h"

int main(){
	char* st="../integration_tests/precedence_tests.txt";
	Multiple_Commands* mc=new Multiple_Commands(st);
	std::cout<<mc->do_commands();
}

