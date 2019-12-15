#ifndef __R_COMMANDS_H__
#define __R_COMMANDS_H__
#include "base_commands.h"
#include "single_commands.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string>
#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
class R_command:public Base_Commands{
private:
	char type;
	std::string address;
public:
	R_command(){}
	void add(std::string,int&);
	bool do_commands();
	bool do_commands(int,int){};
	char* get_first_command(){}
};
void R_command::add(std::string st, int& i){
	//std::cout<<"\n";
	if (st[i]=='>'&&st[i+1]=='>') {
		type='a';
		i+=3;
	} else {
		type=st[i];
		i+=2;
	}
	std::string st2="";
	while (st[i]){
		if (st[i]==' ') break;
		//std::cout<<st[i];
		st2+=st[i];
		i++;
	}
	address=st2;
	//std::cout<<"\n"<<type<<" "<<address<<"\n";
}
bool R_command::do_commands(){
	char line[1024];
	int n;
	//std::cout<<"Doing "<<type<<" with "<<address<<"\n";
	if (type=='<') {
		int fd=open((char*)(new std::string(address))->c_str(),O_RDONLY);
		dup2(fd,0);
		//while (fgets(line, 1024, fd) != NULL)
		//	n = strlen(line);
		//	write(0, line, sizeof(line));
		//}
	}
	if (type=='>') {
		int fd=open((char*)(new std::string(address))->c_str(),O_WRONLY|O_CREAT, S_IRUSR|S_IWUSR);
		dup2(fd,1);
		//while (fgets(line, 1024, stdin) !=NULL) {
		//	n=strlen(line);
		//	write(1, line, sizeof(line));
		//}
	} 	
	if (type=='a') {
		int fd=open((char*)(new std::string(address))->c_str(),O_RDWR|O_CREAT, S_IRUSR|S_IWUSR);
		dup2(fd,1);
		//while (fgets(line,1024, stdin)!=NULL) {
		//	n=strlen(line);
		//	write(1, line, sizeof(line));
		//}
	}
}
#endif
