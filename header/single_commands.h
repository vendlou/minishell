#ifndef __SINGLE_COMMANDS__
#define __SINGLE_COMMANDS__

#include "base_commands.h"
class Single_Commands:public Base_Commands{
private:
	char* command[21];
public:
	Single_Commands(){};
	Single_Commands(char*[]);
	bool do_commands();
	bool do_commands(int,int);
	char* get_first_command(){return command[0];};
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
		if (command[0]==(char*)"exit") return exit;
		if (execvp(command[0],command)==-1) {
			perror("execvp failed");
			return false;
		}
		
	}
	return true;
}
bool Single_Commands:: do_commands(int fd0, int fd1){
	//std::cout<<"IN PIPE\n";
	char buf[1024];
	int newfd;
	//std::cout<<"The command is ["<<command[0]<<" "<<command[1]<<"]\n";
	//dup2(fd0,0);
	pid_t pid=fork();
	//std::cout<<"FORK()\n";
	if (pid==-1) perror("fork error\n");
	if (pid>0) {
		//close(fd1);
		//read(fd0, buf, sizeof(buf));
		//write(0, buf, sizeof(buf));
		//std::cout<<"WAIT\n";
		waitpid(pid,NULL,0);
		//if (fd0==0) close(3);
		if (fd0!=0) close(fd0);
		close(fd1);
		//if (fd1==4) {
		//	read(3,buf,sizeof(buf));
		//	std::cout<<buf<<"\n";
		//}
	} else if (pid==0) {
		if (command[0]==(char*)"exit") exit;
		//std::cout<<"WILL START EXECVP\n";
		//close(fd0);
		//if (fd1==fileno(stdout)) std::cout<<"FD1=STDOUT\n";
		//std::cout<<"--fd0="<<fd0<<"\n--fd1="<<fd1<<"\n";
		//if (fd0==3) { close(5);std::cout<<"close(5)\n";}
		//else {close(3);std::cout<<"close(3)\n";}
		//std::cout<<"dup0="<<fd0<<"\n";
		dup2(fd0,0);
		//dup2(fd1,1);
		//std::cout<<"fd0="<<fd0<<" fd1="<<fd1<<"\n";
		//if (fd0==3) {
		//	read(0,buf,sizeof(buf));
		//	std::cout<<buf<<"\n";
		//}
		//std::cout<<"dup1="<<fd1<<"\n";
		dup2(fd1,1);
		//std::cout<<"string doing execvp\n";
		if (execvp(command[0],command)==-1){
			perror("execvp failed");
			return false;
		}
		//if (fd1==4) {
		//	read(fd0,buf,sizeof(buf));
		//	std::cout<<buf<<"\n";
		//}
		//close(fd0);
		//close(fd1);
		//std::cout<<"\nEXECVP OVER\n";
	}
	//close(fd0);
	//close(fd1);
	return true;
}
#endif
