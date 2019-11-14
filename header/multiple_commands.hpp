#ifndef __MULTIPLE_COMMANDS__
#define __MULTIPLE_COMMANDS__

#include "single_commands.hpp"
#include "commented_commands.hpp"
#include <vector>
#include <string>
#include "string.h"
#include <fstream>
class Multiple_Commands:public Base_Commands{
private:
	std::vector<Base_Commands*> commands;
public:
	Multiple_Commands(char*);
	void add_command(Base_Commands*);
	bool do_commands();
	void cin_commands(char*);
	//void printc();
	void commented_commands(std::string,int&,Base_Commands*);
};
Multiple_Commands::Multiple_Commands(char* Filename){
	cin_commands(Filename);
}
void Multiple_Commands::add_command(Base_Commands* single){
	commands.push_back(single);
}
bool Multiple_Commands::do_commands(){
	for (int i=0;i<commands.size();i++){
		commands[i]->do_commands();
	}
	return true;
}
void Multiple_Commands::cin_commands(char* Filename){
	std::ifstream inFile;
	inFile.open(Filename);
	char* command[20];
	std::string st2;
	int index=0;
	int num=0;
	char* st=new char[50];
	int i=0;
	bool k=true;
	while (!inFile.eof()){
		for (int i=0;i<20;i++) command[i]=NULL;
		inFile.getline(st,50);
		index=0;
		num=0;
		st2="";
		i=0;
		//for (int i=0;st[i];i++){
		k=true;
		while (st[i]){
			if (st[i]=='&'||st[i]=='|'){
				Single_Commands* cm=new Single_Commands(command);
				commented_commands(st,i,cm);
				if (!st[i]) k=false;
			} else
			if (st[i]=='#') return;
			else if (st[i]==';') {
				command[index]=(char*)(new std::string(st2))->c_str();
				add_command(new Single_Commands(command));
				st2="";
				num=0;
				index=0;
				for (int j=0;j<20;j++) command[j]=NULL;
				i+=2;
			} else
			if (st[i]==' ') {
				command[index]=(char*)(new std::string(st2))->c_str();
				st2="";
				index++;
				num=0;
			} else st2+=st[i];
			i++;
		}
		if (k){
			command[index]=(char*)(new std::string(st2))->c_str();
			Single_Commands* cm=new Single_Commands(command);
			add_command(cm);
		}
	}
}
void Multiple_Commands::commented_commands(std::string st, int& i, Base_Commands* left){
	commented_command* root=new commented_command(left,st[i]);
	this->add_command(root);
	i+=3;
	int index=0;
	std::string st2="";
	int num=0;
	char* command[20];
		for (int j=0;j<20;j++) command[j]=NULL;
		while(st[i]){
			if (st[i]==' ') {
				command[index]=(char*)(new std::string(st2))->c_str();
				st2="";
				index++;
				num=0;
			} else
			if (st[i]==';'){
				command[index]=(char*)(new std::string(st2))->c_str();
			return;
		} else
		if (st[i]=='&' && st[i+1]=='&'){
			Single_Commands* cm=new Single_Commands(command);
			root->add(cm,'&');
			i+=3;
		} else
		if (st[i]=='|' && st[i+1]=='|'){
			Single_Commands* cm=new Single_Commands(command);
			root->add(cm,'|');
			i+=3;
		} else
		if (st[i]=='#') return;
		else { 
			st2+=st[i];
		}
		i++;		
	}
	command[index]=(char*)(new std::string(st2))->c_str();
	Single_Commands* cm=new Single_Commands(command);
	root->add(cm);
}
/*
void Multiple_Commands::printc(){
	for (int i=0;i<commands.size();i++) commands[i]->printc();
}
*/
#endif
