# CS 100 Programming Project
2019 autumn.

Project designer:
1. Wendan Lou
2. Dehao Dai
## Introduction
Creating a program that develop a shell which called rshell and could runs these steps:
- Print a command prompt
- Read in a line of command(s) (and connector(s)) from standard input
- Execute the appropriate commands using fork, execvp, and waitpid
  - The example code: 
  `$ executable [argumentList] [connector] [executable]`
  
To develop this shell, It should be have a virtual class which name is `base_command`, and three classes inherit from the `base_command` and named `commands`, `single_commands`, `multiple_commands`. The commands class have a vector to hold single_commands and multiple_commands. 
## Diagram
![Image of class]
(Images/Class_Design.png)
![Image of OMT]
(Images/OMT.png)
## Classes
class `base_command`: a virtual class used for these class, `commands`, `single_commands` and `multiple_commands`.

class `commands`: a class which inherit from `base_command` and have a vector to reference to the `single_commands` and `multiple_commands`.

class `single_commands`: a class which inherit from `base_command` and save one single command.

class `multiple_commands`: a class which inherit from `base_command` and save one multiple commands order.
## Prototypes/Research

## Development and Testing Roadmap
Coding by **Dehao**:
-coding the class for `base_command`, `commands`, `single_commands`, `multiple_commands`.
Designing tests by **Wendan**:
1. single_command_tests.sh **tests primarily for command executions**
2. multiple_commands_tests.sh **tests primarily for command and connectors interaction**
3. commented_command_tests.sh **tests primarily for comments being respected**
4. exit_command_tests.sh **tests primarily for proper exit functionality**

Testing by **Wendan**.

Final checking by **Dehao** and **Wendan**.
