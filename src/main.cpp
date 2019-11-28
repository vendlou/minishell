#include <iostream>
#include <fstream>
#include "../header/multiple_commands.h"

int main(int argv,char** argc){
	Multiple_Commands* mc=new Multiple_Commands(argc[1]);
	mc->do_commands();
}

