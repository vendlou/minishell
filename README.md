# CS 100 Programming Project
2019 Fall.

Project designer:
1. Wendan Lou
2. Dehao Dai
## Introduction
Creating a program that develop a shell which called rshell and could run these steps:
- Print a command prompt
- Read in a line of command(s) (and connector(s)) from standard input
- Execute the appropriate commands using fork, execvp, and waitpid
  - The example code: 
  `$ executable [argumentList] [connector] [executable]`
  
To develop this shell, It should have a virtual class whose name is `base_command`, and three classes inherit from the `base_command` and named `commands`, `single_commands`, `multiple_commands`,. The commands class have a vector to hold single_commands and multiple_commands. 
## Diagram
![Image of class](https://github.com/cs100/assignment-goodluck/blob/master/Images/Class_Design.png)
![Image of OMT](https://github.com/cs100/assignment-goodluck/blob/master/Images/OMT.png)
## Classes
class `base_command`: a virtual class used for these class, `commands`, `single_commands` and `multiple_commands`.

class `commands`: a class which inherits from `base_command` and has a vector of reference to the `single_commands` and `multiple_commands`.

class `single_commands`: a class which inherits from `base_command` and saves one single command.

class `multiple_commands`: a class which inherits from `base_command` and saves one multiple commands order.
## Prototypes/Research
```
#inlcude <stdlib.h>
#include <unisted.h>
#include <sys/wait.h>
int main(int argc, char* argv[]){
	pid_t pid=fork();
	char* command[]={"echo", "hellow world", 0}
	if (pid>0) {
		printf("start fork()\n");
		waitpid(pid,NULL,0);
	} else if (pid==0) {
		printf("in the fork()\"n");
		execvp(command[0],command);
	}
	return 0;
}
```
This program tests the fork(), waitpid() and execvp() functions.

What this program do is, output a "start fork()" from the parent and output a "in the fork" from the child, which is created by the fork() function. And do a `echo` command to post a "hellow world" in the command from the child.
 
## Development and Testing Roadmap
Coding by **Dehao**([Link to Issue!](https://github.com/cs100/assignment-goodluck/issues/1) ):
-coding the class for `base_command`, `commands`, `single_commands`, `multiple_commands`.
Designing tests by **Wendan**([Link to Issue!](https://github.com/cs100/assignment-goodluck/issues/2)):
1. single_command_tests.sh **tests primarily for command executions**
2. multiple_commands_tests.sh **tests primarily for command and connectors interaction**
3. commented_command_tests.sh **tests primarily for comments being respected**
4. exit_command_tests.sh **tests primarily for proper exit functionality**

Testing by **Wendan**([Link to issue!](https://github.com/cs100/assignment-goodluck/issues/3)).

Final checking by **Dehao** and **Wendan**([Link to Issue!](https://github.com/cs100/assignment-goodluck/issues/4)).
