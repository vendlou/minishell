# CS 100 Programming Project
2019 Fall.

Project designer:
1. Wendan Lou X677597
2. Dehao Dai  862152679
## Introduction
Develop a command shell called rshell which can perform the following steps:
- Print a command prompt
- Read in a line of command(s) (and connector(s)) from standard input
- Execute the appropriate commands using fork, execvp, and waitpid
  - The example code: 
  `$ executable [argumentList] [connector] [executable]`
  
To develop this shell, it should have a virtual class whose name is `base_command`, and three classes named `commands`, `single_commands` and `multiple_commands` inherit from the `base_command` . The `commands` class has a vector to hold `single_commands` and `multiple_commands`. 
## Diagram
![Image of class](https://github.com/cs100/assignment-goodluck/blob/master/Images/Class_Design.png)
![Image of OMT](https://github.com/cs100/assignment-goodluck/blob/master/Images/OMT.png)
## Classes
class `base_command`: a virtual class used for these class, `commands`, `single_commands` and `multiple_commands`.

class `commands`: a class which inherits from `base_command` and has a vector of reference to the `single_commands` and `multiple_commands`.

class `single_commands`: a class which inherits from `base_command` and saves one single command.

class `multiple_commands`: a class which inherits from `base_command` and saves multiple commands in order.
## Prototypes/Research
```
#inlcude <stdlib.h>
#include <unisted.h>
#include <sys/wait.h>
int main(int argc, char* argv[]){
	pid_t pid=fork();
	char* command[]={"echo", "hello world", 0}
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

What the program does is, outputting "start fork()" from the parent and "in the fork" from the child, which are created by the fork() function. And do a `echo` command to post a "hello world" in the command from the child.
 
## Development and Testing Roadmap
Coding by **Dehao**([Link to Issue!](https://github.com/cs100/assignment-goodluck/issues/1) ):
-coding the class for `base_command`, `commands`, `single_commands`, `multiple_commands`.
Designing tests by **Wendan**([Link to Issue!](https://github.com/cs100/assignment-goodluck/issues/2)):
1. single_command_tests.sh     **tests primarily for command executions**
2. multiple_commands_tests.sh  **tests primarily for command and connectors interaction**
3. commented_command_tests.sh  **tests primarily for comments being respected**
4. exit_command_tests.sh       **tests primarily for proper exit functionality**

Testing by **Wendan**([Link to issue!](https://github.com/cs100/assignment-goodluck/issues/3)).

Final checking by **Dehao** and **Wendan**([Link to Issue!](https://github.com/cs100/assignment-goodluck/issues/4)).
