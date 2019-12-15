#include <iostream>
#include <fstream>
#include "../header/multiple_commands.h"

int main(){
	char* st="../integration_tests/test_literal_tests.txt";
	Multiple_Commands* mc=new Multiple_Commands(st);
	mc->do_commands();
}

