# Simple Shell

 a simple UNIX command interpreter

 ![My Image](/img/computer-nerd.gif)
## Learning Objectives

* Who designed and implemented the original Unix operating system

The original Unix operating system was designed and implemented by **Ken Thompson**, **Dennis Ritchie**, and others at *Bell Labs* in the early 1970s.

* Who wrote the first version of the UNIX shell

The first version of the UNIX shell was written by **Ken Thompson**.

* Who invented the B programming language (the direct predecessor to the C programming language)

The B programming language, the direct predecessor to the C programming language, was developed by **Ken Thompson** at *Bell Labs* in the early 1970s. 

* Who is Ken Thompson

 ![My Image](/img/download.jpeg)

**Ken Thompson** is a computer scientist and one of the pioneers in the field of computer science.[Ken Thompson](https://en.wikipedia.org/wiki/Ken_Thompson)

* How does a shell work

 ![My Image](/img/000.PNG)

A shell is a command-line interface that allows users to interact with an operating system. It interprets user commands and executes them, facilitating communication between the user and the operating system.

* What is a pid and a ppid

1. PID (Process ID): A number assigned to a running process, used to uniquely identify and manage processes.

2. PPID (Parent Process ID): The PID of the process that spawned the current process. It indicates the parent-child relationship between processes.

Learn about PIDs and PPIDs in this video: [Understanding PIDs and PPIDs](https://www.youtube.com/watch?v=PZrQ4eGm-hM)

* How to manipulate the environment of the current process

In a Unix-like operating system, the environment of a process includes a set of variables that define the environment in which the process runs. These variables can include information such as the user's home directory, the current working directory, and various configuration settings.

* What is the difference between a function and a system cal

1. Function:

 **Scope**: Functions are units of code within a program or a module. They are part of the application's source code and are designed to perform a specific task or set of tasks.

 **Purpose**: Functions are used for code organization, modularization, and reusability within a program. They help break down a program into smaller, manageable parts, improving maintainability and readability.

 **Invocation**: Functions are invoked by calling their name within the program. They typically run in user mode, and their execution is managed by the program itself.

2. System Call:

 **Scope**: System calls are interfaces provided by the operating system kernel to enable interaction between user-level processes and the operating system. They are part of the operating system's kernel code.

 **Purpose**: System calls provide a way for user-level programs to request services or resources from the operating system, such as file I/O, process creation, and network communication. They serve as a bridge between user space and kernel space.

 **Invocation**: System calls are invoked through a specific interface, often involving interruptmechanisms or special instructions that switch the CPU from user mode to kernel mode. They trigger privileged operations and are used to perform tasks that require kernel-level access.

* How to create processes

In Unix-like operating systems, processes are created using the fork() system call.

Learn about fork() in this video: [create processes](https://www.youtube.com/watch?v=94URLRsjqMQ)

* What are the three prototypes of main

In the C programming language, the main function serves as the entry point for the execution of a program. Here are the three common prototypes:

 1. No Command-Line Arguments:

 ```c
 int main(void);
 ```

 2. With Command-Line Arguments:
 
 ```c
 int main(int argc, char *argv[]);

 ```
 3. With Environment Variables:

 ```c
int main(int argc, char *argv[], char *envp[]);
 ```

* How does the shell use the PATH to find the programs

The PATH environment variable plays a crucial role in how the shell locates executable programs. When you enter a command in the shell, it searches through directories listed in the PATH variable to find the corresponding executable file. Here's how the process works:

[search_path.c](https://github.com/ANAS-OU/simple_shell/blob/master/get_path.c)

* How to execute another program with the execve system call

The execve system call in Unix-like operating systems is used to execute another program. It replaces the current process image with a new one, loading and executing a different program.

![execute](/img/44.PNG)

[execute_cmd.c](https://github.com/ANAS-OU/simple_shell/blob/master/execute_cmd.c)

* How to suspend the execution of a process until one of its children terminates

To suspend the execution of a process until one of its children terminates, you can use the waitpid system call in Unix-like operating systems. The waitpid system call allows a parent process to wait for a specific child process to exit or for any child process to exit. 

![wait](/img/00a0.PNG)

[execute_cmd.c](https://github.com/ANAS-OU/simple_shell/blob/master/execute_cmd.c)

* What is EOF / “end-of-file”?

EOF, or "end-of-file," is a concept used in file input/output operations to indicate the end of the data in a file. It is a special value that signifies that there are no more characters or data to be read from a file.

## Starting the shell

![start_coding](/img/giphy.gif)

### Clone the report

![git](/img/Capture1.PNG)

```git
git clone https://github.com/ANAS-OU/simple_shell.git
```
* execute this command in your terminal

![git](/img/jokes-how-to-speed-up-your-download.gif)

### Compile and test

* to execute using gcc

```gcc
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o shell
```
* run the code

1. ```sh
 ./shell 
 ```

2. ```sh
 valgrind --leak-check=full --show-leak-kinds=all -s ./shell
 ```

* testing time

![testing](/img/using-the-computer-debbie-harper.gif)

