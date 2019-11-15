#ifndef __BASE_COMMANDS__
#define __BASE_COMMANDS__

#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
class Base_Commands{
public:
	void execute (char* arglist[]) {execvp(arglist[0],arglist);}
	virtual bool do_commands()=0;
	virtual char* get_first_command()=0;
};
#endif
