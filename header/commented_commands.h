#ifndef __COMMENTED_COMMANDS__
#define __COMMENTED_COMMANDS__

#include "base_commands.h"
#include "single_commands.h"
#include<vector>
#include "string.h"
class commented_command:public Base_Commands{
private:
	int in=0;
	int out=1;
	std::vector<char> Op;
	std::vector<Base_Commands*> com_commands;
public:
	commented_command() {}
	commented_command(Base_Commands* c,char s) {add(c,s);}
	void add(Base_Commands* c,char s){
		com_commands.push_back(c);
		//std::cout<<"PUSH BACK\n";
		//c->do_commands();
		Op.push_back(s);
	}
	void add(Base_Commands* c){ com_commands.push_back(c);}
	bool do_commands();
	bool do_commands(int,int){}
	char* get_first_command(){return com_commands[0]->get_first_command();}
};
bool commented_command::do_commands(){
	bool k;
	int fd1[2];
	int fd2[2];
	//std::cout<<"Starting doing commands\n";
	pipe(fd1);
	pipe(fd2);
	//close(3);
	//close(4);
	//close(5);
	//close(6);
	int p1=fd1[0];
	int p2=fd2[1];
	//std::cout<<"||HERE||\n";
	//com_commands.at(0)->do_commands();
	//std::cout<<"--------\n";
	if (Op.at(0)=='p') k=com_commands[0]->do_commands(0,p2);
	//else if (Op.at(0)=='r') {
	//	k=com_commands[0]->do_commands(in,out);
	//}	
	else k=com_commands[0]->do_commands();
	int size=Op.size();
	//std::cout<<"Size="<<size<<"\n";
	//std::cout<<"||HERE||\n";
	for (int i=0;i<size;i++){
		//std::cout<<"doing commented_command["<<i+1<<"]\n";
		//std::cout<<"The OP["<<i<<"]="<<Op[i]<<"\n";
		if (i<(size-1)){
			if (Op.at(i+1)=='r') {
				com_commands[i+2]->do_commands();
				size--;
			}
		}
		if (Op.at(i)=='&'){
			if (k) k=com_commands[i+1]->do_commands();
		} else if (Op[i]=='|'){
			if (!k) k=com_commands[i+1]->do_commands();
			else k=true;
		//} else if ((Op[i]=='r')&&(i!=0)){
		//	k=com_commands[i+1]->do_commands();
		} else if (Op[i]=='p') {
			if (k) {
	//			std::cout<<"i="<<i<<"  size="<<size<<"\n";
				//close(p1);
				//close(p2);
				//std::cout<<"-close(p1)="<<p1<<"\n-close(p2)="<<p2<<"\n";
				if (p1==fd1[0]) p1=fd2[0];
				else p1=fd1[0];
				if (p2==fd1[1]) p2=fd2[1];
				else p2=fd1[1];
				if (i==(size-1)) {
					//std::cout<<"going END\n";
					k=(com_commands[i+1])->do_commands(p1,1);
					//std::cout<<"out END\n";
				} else k=((Single_Commands*)com_commands[i+1])->do_commands(p1,p2);
			}
		}
	}
	close(fd1[0]);
	close(fd1[1]);
	close(fd2[0]);
	close(fd2[1]);
	close(1);
	return k;
}
#endif
