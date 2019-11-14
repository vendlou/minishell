#ifndef __SINGLE_COMMANDS__
#define __SINGLE_COMMANDS__

#include "base_commands.hpp"
class Single_Commands:public Base_Commands{
private:
	char* command[21];
public:
	Single_Commands(){};
	Single_Commands(char*[]);
	bool do_commands();
	void printc();
};
Single_Commands::Single_Commands(char* command[]){
	for (int i=0;i<20;i++) this->command[i]=NULL;
	int p=20;
	int i=0;
	while (true){
		if (command[i]==NULL) {
			p=i;
			break;
		}
		this->command[i]=command[i];
		i++;	
	}
	this->command[p]=0;
}
bool Single_Commands:: do_commands(){
	pid_t pid=fork();
	if (pid==-1) perror("fork error");
	if (pid>0) {
		waitpid(pid,NULL,0);
	} else if (pid==0){
		execvp(command[0],command);
	}else {
		perror("execvp failed");
		return false;
	}
	return true;

}
void Single_Commands::printc(){
	for (int i=0;i<4;i++){
		if (command[i]==NULL) break;
	}
}
#endif
