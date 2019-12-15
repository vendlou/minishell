#include <iostream>
#include <fstream>
#include "../header/multiple_commands.h"

int main(){
	std::string st="";
	while (true) {
		//dup2(0,0);
		//dup2(0,0);
		//for (int i=3;i<10;i++) close(i);i
		int saved_stdin = dup(STDIN_FILENO);
		int saved_stdout = dup(STDOUT_FILENO);
		std::getline(std::cin,st);
		if (st=="exit") break;
		else {
			st+="\n";
		      	std::ofstream outfile("infile.txt");
			outfile<<st;	
			outfile.close();
			Multiple_Commands* mc=new Multiple_Commands("infile.txt");
		//std::cout<<"pass\n";
			mc->do_commands();
		//dup2(0,0);
		//dup2(1,1);
		}
		dup2(saved_stdin, STDIN_FILENO);
		close(saved_stdin);
		dup2(saved_stdout, STDOUT_FILENO);
		close(saved_stdout);
	}
}

