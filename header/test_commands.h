#ifndef __TEST_COMMANDS_H__
#define __TEST_COMMANDS_H__
#include "base_commands.h"
#include "single_commands.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string>

class Test_Command:public Base_Commands{
private:
	int type;
	char* command;
public:
	Test_Command(){type=0;}
	void t_add(std::string,int&);
	void s_add(std::string,int&);
	bool do_commands();
	char* get_first_command(){}
};
void Test_Command::t_add(std::string st, int& i){
	i++;
	int j=i;
	std::string st2="";
	while (st[i]){
		if (st[i]=='-') {
			st2=="";
			if (st[i+1]=='e') type=0;
			else if (st[i+1]=='f') type=1;
			else if (st[i+1]=='d') type=2;
			i+=2;
			j=i;
		}else
		if (st[i]==' ')	{
			command=(char*)(new std::string(st2))->c_str();
			return;
		} else st2+=st[i];
		i++;
	}
	command=(char*)(new std::string(st2))->c_str();
}
void Test_Command::s_add(std::string st, int& i){	
	i+=2;
	int j=i;
	std::string st2="";
	while (st[i]){
		if (st[i]=='-') {
			st2=="";
			if (st[i+1]=='e') type=0;
			else if (st[i+1]=='f') type=1;
			else if (st[i+1]=='d') type=2;
			i+=2;
			j=i;
		} else
		if (st[i+1]==']') {
			command=(char*)(new std::string(st2))->c_str();
			i+=2;
			return;
		} else st2+=st[i];
		i++;
	}	
}
bool Test_Command::do_commands(){
	struct stat buf;
	int result;
	result=stat(command,&buf);
	if (result!=0) {
		perror("Path Worrning!");
		return false;
	} else {
		if (type==0) {
			std::cout<<"(True)\n";
			return true;
		} else if (type==1 && S_ISREG(buf.st_mode)) {
			std::cout<<"(True)\n";
			return true;
		} else if (type==2 && S_ISDIR(buf.st_mode)) {
			std::cout<<"(True)\n";
			return true;
		} else {
			std::cout<<"(False)\n";
			return false;
		}
	}
}
#endif
