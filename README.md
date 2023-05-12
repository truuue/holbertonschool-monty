![Holberton School logo](https://user-images.githubusercontent.com/120781178/229278297-98c6e4b7-f15f-4788-a893-15cb97f10351.png)

# :mortar_board: # C - Stacks, Queues - LIFO, FIFO

At the end of this project, we are expected to be able to  explain to explain to anyone  **without the help of Google**:
-   What do LIFO and FIFO mean
-   What is a stack, and when to use it
-   What is a queue, and when to use it
-   What are the common implementations of stacks and queues
-   What are the most common use cases of stacks and queues
-   What is the proper way to use global variables

# An interpreter for Monty ByteCodes files
Third group project at Holberton School : implementation of our own version of An interpreter for Monty ByteCodes files in C

## Description :scroll:
Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create from scratch a simple interpeter for Monty ByteCodes files. Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument. Monty byte code files can contain blank lines (empty or made of spaces only, and any additional text after the opcode or its required argument is not taken into account. Any output must be printed on `stdout`. Any error message must be printed on `stderr`.

## Exemples of Monty Byte files:
```
vlvalnoah@ubuntu:~/monty$ cat -e bytecodes/000.m
push 0$
push 1$
push 2$
  push 3$
                   pall    $
push 4$
    push 5    $
      push    6        $
pall$
vlvalnoah@ubuntu:~/monty$`
```
```
vlvalnoah@ubuntu:~/monty$ cat -e bytecodes/001.m
push 0 Push 0 onto the stack$
push 1 Push 1 onto the stack$
$
push 2$
  push 3$
                   pall    $
$
$
                           $
push 4$
$
    push 5    $
      push    6        $
$
pall This is the end of our program. Monty is awesome!$
vlvalnoah@ubuntu:~/monty$
```

## Technologies & Tools :computer:


![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white)
![Markdown](https://img.shields.io/badge/Markdown-%2300599C?style=for-the-badge&logo=markdown&logoColor=whithe)
![Visual Studio Code](https://img.shields.io/badge/Visual%20Studio%20Code-%230db7ed.svg?style=for-the-badge&logo=visual-studio-code&logoColor=white)
![Docker](https://img.shields.io/badge/docker-%230db7ed.svg?style=for-the-badge&logo=docker&logoColor=white)
![Trello](https://img.shields.io/badge/Trello-2300599C.svg?style=for-the-badge&logo=Trello&logoColor=white)
![GitHub](https://img.shields.io/badge/github-%23121011.svg?style=for-the-badge&logo=github&logoColor=white)
![Git](https://img.shields.io/badge/git-%23121011.svg?style=for-the-badge&logo=git&logoColor=white)

---

## Requirements :exclamation:
Installed gcc (GNU Compiler Collection) version 9.4.0 or newer.

### Clone repository using HTTPS
```
git clone https://github.com/v-dav/holbertonschool-monty
```


## Files :gear:
All of the following files contain functions written in C :
|**Filename**|**Description**|
|:-------|:---------:|
|`_isdigit.c`|File which content functions that check if there is an argument for the `push`opcode and that this argument is a digit|
|`close_free.c`|a function that frees line and stack and closes file|
|`copy_and_cut.c`|This function finds the command and its argument in the line|
|`functions.c, functions2.c, functions3.c`|Functions corresponding to opcodes|
|`get_ops.c`|Function that search a valid opcode|
|`main.c`|Main of the program that interpretes Monty ByteCodes files|
|`monty.h`|Header file which contains all functions prototypes and include librairies|

### Compilation
All files will be compiled on Ubuntu 20.04 LTS using :
```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o monty
```

### The monty program

- Usage: `monty file`, where file is the path to the file containing Monty byte code
- If the user does not give any file or more than one argument to program, prints the error message `USAGE: monty file`, followed by a new line, and exits with the status EXIT_FAILURE
- If, for any reason, it’s not possible to open the file, prints the error message `Error: Can't open file <file>`, followed by a new line, and exit with the status EXIT_FAILURE where <file> is the name of the file
- If the file contains an invalid instruction, prints the error message `L<line_number>: unknown instruction <opcode>`, followed by a new line, and exits with the status EXIT_FAILURE where is the line number where the instruction appears.
- Line numbers always start at 1
- The monty program runs the bytecodes line by line and stop if either: it executed properly every line of the file, it finds an error in the file, an error occured
- If malloc fails, prints the error message `Error: malloc failed`, followed by a new line, and exit with status EXIT_FAILURE.

## Supported opcodes
- `push` The opcode push pushes an element to the stack
- `pull` The opcode pall prints all the values on the stack, starting from the top of the stack
- `pint` The opcode pint prints the value at the top of the stack, followed by a new line
- `pop`  The opcode pop removes the top element of the stack
- `swap` The opcode swap swaps the top two elements of the stack
- `add` The opcode add adds the top two elements of the stack
- `nop` The opcode nop doesn’t do anything
- `sub` The opcode sub subtracts the top element of the stack from the second top element of the stack. The result is stored in the second top element of the stack, and the top element is removed, so that at the end: the top element of the stack contains the result and the stack is one element shorter
- `div` The opcode div divides the second top element of the stack by the top element of the stack. The result is stored in the second top element of the stack, and the top element is removed, so that at the end: the top element of the stack contains the result and the stack is one element shorter.
- `mul` The opcode mul multiplies the second top element of the stack with the top element of the stack. The result is stored in the second top element of the stack, and the top element is removed, so that at the end: the top element of the stack contains the result and the stack is one element shorter.

  
## Exemples of use
```
vlad@ubuntu:~/monty$ cat -e bytecodes/00.m
push 1$
push 2$
push 3$
pall$
vlad@ubuntu:~/monty$ ./monty bytecodes/00.m
3
2
1
vlad@ubuntu:~/monty$
```
```
vlad@ubuntu:~/monty$ cat bytecodes/06.m 
push 1
pint
push 2
pint
push 3
pint
vlad@ubuntu:~/monty$ ./monty bytecodes/06.m 
1
2
3
vlad@ubuntu:~/monty$ 
```
```
vlad@ubuntu:~/monty$ cat bytecodes/07.m 
push 1
push 2
push 3
pall
pop
pall
pop
pall
pop
pall
vlad@ubuntu:~/monty$ ./monty bytecodes/07.m 
3
2
1
2
1
1
vlad@ubuntu:~/monty$
```

## Valgrind
```
root@0bbfdb995af7:~/holbertonschool-monty# valgrind ./monty test.m
==64801== Memcheck, a memory error detector
==64801== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==64801== Using Valgrind-3.15.0 and LibVEX; rerun with -h for copyright info
==64801== Command: ./monty test.m
==64801== 
40
30
20
10
3
2
1
70
20
10
3
2
1
0
10
3
2
1
0
3
2
1
==64801== 
==64801== HEAP SUMMARY:
==64801==     in use at exit: 0 bytes in 0 blocks
==64801==   total heap usage: 39 allocs, 39 frees, 7,659 bytes allocated
==64801== 
==64801== All heap blocks were freed -- no leaks are possible
==64801== 
==64801== For lists of detected and suppressed errors, rerun with: -s
==64801== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
root@0bbfdb995af7:~/holbertonschool-monty# 
```

## Betty Style
```
V holbertonschool-monty %betty *.c *.h

========== _isdigit.c ==========
_isdigit
check_digit

========== close_free.c ==========
close_free

========== copy_and_cut.c ==========
copy_and_cut

========== functions.c ==========
push
pall
free_stack
pint
pop

========== functions2.c ==========
nop
swap
add
sub
_div

========== functions3.c ==========
mul

========== get_ops.c ==========
get_ops

========== main.c ==========
main

========== print_err.c ==========
print_err
print_err2

========== monty.h ==========
struct stack_s
struct instruction_s
V holbertonschool-monty %
```

## Authors :writing_hand:
Written by :
* **Vladimir Davidov**
* **Valentin Ralliard**
* **Noah Vernet**
