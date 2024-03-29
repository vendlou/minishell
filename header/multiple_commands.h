#ifndef __MULTIPLE_COMMANDS__
#define __MULTIPLE_COMMANDS__

#include "single_commands.h"
#include "commented_commands.h"
#include "test_commands.h"
#include "redirection.h"
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
	bool do_commands(int,int){}
	void cin_commands(char*);
	//void printc();
	void commented_commands(std::string,int&,commented_command*);
	void precedence_operators(std::string,int&,commented_command*);

	char* get_first_command(){return commands[0]->get_first_command();}
};
Multiple_Commands::Multiple_Commands(char* Filename){
	cin_commands(Filename);
}
void Multiple_Commands::add_command(Base_Commands* single){
	commands.push_back(single);
}
bool Multiple_Commands::do_commands(){
	bool k=true;
	for (int i=0;i<commands.size();i++){
		//std::cout<<"DOING COMMAND["<<i<<"]\n";
		//if ((std::string)commands[i]->get_first_command()=="exit") return true;
		k=k&&commands[i]->do_commands();
	}
	return k;
}
void Multiple_Commands::cin_commands(char* Filename){
	std::ifstream inFile;
	inFile.open(Filename);
	//std::cout<<"In!\N";
	char* command[20];
	std::string st2;
	int index=0;
	int num=0;
	char* st=new char[120];
	int i=0;
	bool k=true;
	bool tk=false;
	bool tr=false;
	Test_Command* tc;
	commented_command* cc;
	R_command* rc;
	while (!inFile.eof()){
		for (int i=0;i<20;i++) command[i]=NULL;
		inFile.getline(st,120);
		if (inFile.eof()) break;
		//std::cout<<"INPUT OK!\n";
		index=0;
		num=0;
		st2="";
		i=0;
		//for (int i=0;st[i];i++){
		k=true;
		//std::cout<<"st="<<st<<"\n";
		while (st[i]){
			//std::cout<<"st["<<i<<"]="<<st[i]<<"\n";
			if (st2=="test") {
				tc=new Test_Command();
				tc->t_add(st,i);
				st2="";
				tk=true;
			} else
			if (st[i]=='['){
				tc=new Test_Command();
				tc->s_add(st,i);
				st2="";
				tk=true;
			} else
			if (st[i]=='('){
				commented_command* cc=new commented_command();
				this->add_command(cc);
				i+=1;
				precedence_operators(st,i,cc);
				if (!st[i]) k=false;
			} else
			if (st[i]=='<'||st[i]=='>') {
				rc=new R_command();
				rc->add(st,i);
				this->add_command(rc);
			} else
//			if (st[i]=='>'){
//				rc=new R_command();
//				rc->add(st,i);
//				cc=new commented_command(rc,'r');
//				tr=true;
//				this->add_command(cc);
//				if (st[i+1]==' ') i+=2;
//				else i+=3;
//				commented_commands(st,i,cc);
//				if (!st[i]) k=false;
//				tk=false;
//			} else
			if (st[i]=='&'||st[i]=='|'){
				//std::cout<<"\nGOING TO COMMENTED\n";
				if (tk) {
					if (st[i+1]==' ') cc=new commented_command(tc,'p');
					else cc=new commented_command(tc,st[i]);
				}  else 
				if (tr){
					cc=new commented_command(rc,st[i]);
				}
				else {
					//std::cout<<"COMMAND:"<<command[0]<<command[1]<<"\n";
					Single_Commands* cm=new Single_Commands(command);
					//cm=new Single_Commands();
					//cm->do_commands();
					if (st[i+1]==' ') cc=new commented_command(cm,'p');
					else cc=new commented_command(cm,st[i]);
					//cc->do_commands();
				}
				this->add_command(cc);
				if (st[i+1]==' ') i+=2;
				else i+=3;
				//std::cout<<"st["<<i<<"]= "<<st[i]<<"\n";
				commented_commands(st,i,cc);
				if (!st[i]) k=false;
				tk=false;
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
		if (tk) {
			add_command(tc);
		} else 
		if (k){
			command[index]=(char*)(new std::string(st2))->c_str();
			Single_Commands* cm=new Single_Commands(command);
			add_command(cm);
		}
	}
}
void Multiple_Commands::precedence_operators(std::string st, int& i, commented_command* root){
	int index=0;
	std::string st2="";
	int num=0;
	char* command[20];
	for (int j=0;j<20;j++) command[j]=NULL;
	bool k=true;
	bool tk=false;
	Test_Command* tc;
	commented_command* cc;
	while (st[i]){
		if (st2=="test"){
			tc=new Test_Command();
			tc->t_add(st,i);
			tk=true;
			st2="";
		} else
		if (st[i]=='['){
			tc=new Test_Command();
			tc->s_add(st,i);
			tk=true;
			st2="";
		} else 
		if (st[i]==')') {
			i+=1;
			return;
		} else
		if (st[i]=='('){
			cc=new commented_command();
			root->add(cc);
			i+=1;
			precedence_operators(st,i,cc);
			if (!st[i]) k=false;
		} else
		if (st[i]=='&'||st[i]=='|'){
			//std::cout<<"GOING TO COMMENTED\n";
			if (tk) cc=new commented_command(tc,st[i]);
			else {
				Single_Commands* cm=new Single_Commands(command);
				cc=new commented_command(cm,st[i]);
			}
			root->add(cc);
			i+=3;
			commented_commands(st,i,cc);
			if (!st[i]) k=false;
			tk=false;
		} else
		if (st[i]=='#') return;
		else if (st[i]==';') {
			command[index]=(char*)(new std::string(st2))->c_str();
			root->add(new Single_Commands(command));
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
	if (tk){
		root->add(tc);
	} else 
	if (k){
		command[index]=(char*)(new std::string(st2))->c_str();
		Single_Commands* cm=new Single_Commands(command);
		root->add(cm);
	}
}
void Multiple_Commands::commented_commands(std::string st, int& i, commented_command* root){
	//std::cout<<"IN COMMENTED\n";
	int index=0;
	std::string st2="";
	Single_Commands* cm;
	int num=0;
	char* command[20];
	for (int j=0;j<20;j++) command[j]=NULL;
	bool tk=false;
	bool tr=false;
	Test_Command* tc;
	R_command* rc;
	//std::cout<<"HRER!\n";
	while(st[i]){
		//std::cout<<st[i];
		if (st2=="test") {
			tc=new Test_Command();
			tc->t_add(st,i);
			tk=true;
			st2="";
		} else
		if (st[i]=='<'||st[i]=='>'){
			cm=new Single_Commands(command);
			root->add(cm,'r');
			rc=new R_command();
			rc->add(st,i);
			root->add(rc);
		} if (st[i]=='[') {
			tc=new Test_Command();
			tc->s_add(st,i);
			tk=true;
			st2="";
		} else
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
			if (tk) root->add(tc,'&');
			else if(tr) root->add(rc,'&');
			else {
				cm=new Single_Commands(command);
				root->add(cm,'&');
			}
			index=0;
			i+=2;
			tk=false;
			tr=false;
		} else
		if (st[i]=='|' && st[i+1]==' '){
			//std::cout<<"\nGOING TO CREATED PIPE COMMAND\n";
			if (tk) root->add(tc,'p');
			else if (tr) root->add(rc,'p');
			else {
				//root->do_commands();
				cm=new Single_Commands(command);
				root->add(cm,'p');
			}
			index=0;
			i++;
			tk=false;
			tr=false;
		} else
		if (st[i]=='|' && st[i+1]=='|'){
			if (tk) root->add(tc,'|');
			else if (tr) root->add(rc,'|');
			else {
				cm=new Single_Commands(command);
				root->add(cm,'|');
			}
			index=0;
			i+=2;
			tk=false;
			tr=false;
		} else
		if (st[i]==')') {
			command[index]=(char*)(new std::string(st2))->c_str();
			cm=new Single_Commands(command);
			root->add(cm);
			return;
		} else
		if (st[i]=='#') return;
		else { 
			st2+=st[i];
		}
		i++;		
	}
	//std::cout<<"\n";
	if (tk) {
		root->add(tc);
		return;
	}
	if (tr) {
		root->add(rc);
		return;
	}
	if (st2!="") {
		//std::cout<<"index="<<index<<"\n";
		command[index]=(char*)(new std::string(st2))->c_str();
		//std::cout<<command[0]<<command[1]<<command[2];
		cm=new Single_Commands(command);
		//root->do_commands();
		root->add(cm);
		//root->do_commands();
	}
}
/*
void Multiple_Commands::printc(){
	for (int i=0;i<commands.size();i++) commands[i]->printc();
}
*/
#endif
