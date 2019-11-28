#ifndef __COMMENTED_COMMANDS__
#define __COMMENTED_COMMANDS__

#include "base_commands.h"
#include<vector>
#include "string.h"
class commented_command:public Base_Commands{
private:
	std::vector<char> Op;
	std::vector<Base_Commands*> com_commands;
public:
	commented_command() {}
	commented_command(Base_Commands* c,char s) {add(c,s);}
	void add(Base_Commands* c,char s){
		com_commands.push_back(c);
		Op.push_back(s);
	}
	void add(Base_Commands* c){ com_commands.push_back(c);}
	bool do_commands();
	char* get_first_command(){return com_commands[0]->get_first_command();}
};
bool commented_command::do_commands(){
	bool k=com_commands[0]->do_commands();
	for (int i=0;i<Op.size();i++){
		if (Op.at(i)=='&'){
			if (k) k=com_commands[i+1]->do_commands();
		} else if (Op[i]=='|'){
			if (!k) k=com_commands[i+1]->do_commands();
			else k=true;
		}
	}
	return k;
}
#endif
