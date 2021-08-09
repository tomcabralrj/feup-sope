# `#1` Ficha de Exercícios 

###### tema: `Basics of Operating Systems and Unix programming`

##### *Questões já resolvidas:*
- [X] `Q1`
- [x] `Q2`
- [x] `Q3`
- [ ] `Q4*`
- [x] `Q5`
- [ ] `Q6`
- [ ] `Q7`
- [x] `Q8`
- [ ] `Q9`
- [ ] `Q10`
- [ ] `Q11`
- [ ] `Q12`


***

### `Q1` «The make program is an interpreter of special programs (makefiles), that can only be used in Linux and just for compiling C source code.» 

#### `a` Is this true?
>**`Answer`** ***Não, o make, como um interpretador, pode ser usado para qualquer linguagem e em qualquer sistema operativo desde que haja uso de compilador apropriado para tal linguagem.***
#### `b` The compilation lines of the makefile used in the "Interesting examples of compilations" have the option -Wall. Write a simple program that shows the importance of using that compiler option.?
>**`Answer`** ***A importância da flag -Wall é demonstrar variáveis e funções criadas no programa que não foram utilizadas.***
>**arquivos:** ***[`1b.c`](https://github.com/tomcabralrj/feup-sope/blob/main/Praticas/FE1/1b.c)***
#### `c` Prepare a makefile for easing the compilation of the programs suggested in this Exercise Sheet.
>**`Answer`** 
>**arquivos:** ***[`Makefile`](https://github.com/tomcabralrj/feup-sope/blob/main/Praticas/FE1/Makefile)***

***

### `Q2` Present both an advantage and a disadvantage of dynamic linking programs over static linking.

>**`Answer`** 
* >***vantagem: uma vantagem seria o fato de que os programas de linkagem dinâmica conseguem partilhar o mesmo espaço de código, não havendo de alterar uma mesma função diversas vezes no código toda vez que necessitar de uma atualização.***
* >***desvantagem: por outro lado, a desvantagem seria a quantidade de vezes que esse programa deverá acessar esse espaço partilhado, o que pode afetar a performance.***

*** 

### `Q3` Study the man page of the service atexit.

#### `a` Could this service be useful when a running program is suddenly terminated (e.g. by CTRL-C)?
>**`Answer` Não, pois quando se usa o CTRL-C, isso gera um sinal de terminação que mata o processo imediatamente, o que acaba por não ser um normal exit, logo a função atexit não o detecta e o programa termina imediatamente.** 

#### `b` Try it with a slightly adapted code presented in the man's EXAMPLE section.
>**`Answer`** 
>**arquivos:** ***[`3.c`](https://github.com/tomcabralrj/feup-sope/blob/main/Praticas/FE1/3.c)***

***

### `Q4*` [Study the implementation of the read() system call, trying to see if if is compatible with the scheme presented in the classes' sheets. For that, write a mini-program with just that system call, compile it perhaps with static linking and inspect the disassembled code of the executable with objdump (man objdump!...).]

>**`Answer`** 

*** 

### `Q5` What are "command line arguments" and "environment variables"?
>**`Answer`**
* >***command line arguments: é um parâmetro que fornece ao programa na main function os argumentos que o utilizador deve passar para que o programa funcione adequadamente.***
* >***environment variables: são informaçãos partilhadas pelos vários programas da máquina e que são alteradas raramente.*** 

#### `a` Write a program that outputs to the screen its command line arguments and the name and value of all the shell's environment variables.
>**`Answer`** 
>**arquivos:** ***[`5a.c`](https://github.com/tomcabralrj/feup-sope/blob/main/Praticas/FE1/5a.c)***

#### `b` Change the program so that its output is just the value of the environment variables whose names are passed as arguments (e.g. prog PATH HOME would show the values of PATH and HOME). Confirm that the values output are correct using the shell commands echo and printenv.
>**`Answer`** 
>**arquivos:** ***[`5b.c`](https://github.com/tomcabralrj/feup-sope/blob/main/Praticas/FE1/5b.c)***

#### `c` From the command line create a new environment variable, DIR1, with value 123-testing and use the program you wrote in b. to confirm the existence and value of DIR1.
>**`Answer`** 

*** 

### `Q6` A system call may fail; by words, exemplify that with open. (If necessary: man 2 open !)

#### `a` Write a program that tries to open a file named in the command line argument and report the "open" failures without using perror. With the program prove the example of failure you gave above.
>**`Answer`** 

#### `b` Modify your program to ensure that failure messages are output to the standard error (stderr) and not to the standard output (stdout). Confirm your new program behavior with shell redirection. (Clue: prog > ofile 2> efile)
>**`Answer`** 

#### `c` Repeat a. using perror. Test stdout and stderr for the output of this program.
>**`Answer`** 

***

### `Q7` Explain the two main functions of an operating system.

>**`Answer`** 

***

### `Q8` Based on the output of the command ps aux say if Linux is

>**`Answer`** 
>- [x] **multi-programming**
>- [x] **multi-user**
>- [x] **time sharing**
>- [ ] **(cannot say just by the output)***

*** 

### `Q9` Some system operations can be performed while in user mode, others only in kernel mode.

#### `a` using the date command classify, in the above respect, the read and write operations on the internal clock. (Clue: date -s "20220913")
>**`Answer`** 

#### `b` name one (more) operation that can only be performed in kernel mode.
>**`Answer`** 

*** 

### `Q10` Write a program that outputs "Hello world!" 100 000 times and, before ending, presents the duration time of the running and of the processor usage (both in user and system modes). (Clue: "time ls -R /tmp".)

>**`Answer`** 

*** 

### `Q11` Think of a program that copies the content of a file to another file, both named as program arguments (e.g. prog fname1 fname2). Write such a program using:

#### `a` mainly (direct) system calls, such as open;
>**`Answer`** 
#### `b` mainly C library calls, such as fopen.
>**`Answer`** 
#### `c` Change one of those programs so that when the 2nd argument is missing (fname2, in the example above) the content of fname1 is shown on the screen (i.e. stdout).
>**`Answer`** 

*** 

### `Q12` Think of a program that writes to the standard output the name and size of all the regular files in a directory whose name is given as argument (e.g. prog dirname).

#### `a` Write such a program, also assuring one output line per file.
>**`Answer`** 

#### `b` From the output of the program and using wc show the number of regular files in the directory.
>**`Answer`** 

*** 