# Smashing the Stack for Fun and Profit
## Software Systems Project 2 Report
### Zarin Bhuiyan and Ziyu (Selina) Wang
#### May 6th, 2018

## Project Goals

The goal of our project is explore the C stack vulnerabilities and smashing the C stack for fun (and maybe profit). The lower bound of our project is to complete all the exercises in this cyber security guide and gain a good understanding of the buffer overflow vulnerabilities. Our stretch goals include looking into some common cyber security tools that are listed on the guide, as well as looking at heap and socket vulnerabilities.

## Learning Goals

Our learning goals include exploring the weaknesses of C, as well as what makes software vulnerable and how a software engineer could prevent it. We also hope to tap into the wild world of cyber security and how attacks can be created and addressed.

## Resources

We plan to use an online guide linked (http://insecure.org/stf/smashstack.html) from the SoftSys project resources page. This guide also provides an extensive list of external resources that are related to the project. We found some additional resources including:

- https://exploit-exercises.com/protostar/
- http://www.win.tue.nl/~aeb/linux/hh/hh-10.html
- https://dhavalkapil.com/blogs/Buffer-Overflow-Exploit/


## What We Got Done

We finished exploring the different examples and exercises provided in the primary resource. 

Here's an example of a program that is vulnerable: 
~~~~
void function(char *str) {
   char buffer[16];

   strcpy(buffer,str);
}

void main() {
  char large_string[256];
  int i;

  for( i = 0; i < 255; i++)
    large_string[i] = 'A';

  function(large_string);
}
~~~~

Here, we are stuffing more data into `buffer` than it can handle. `buffer[]` is much smaller than `*str`, as it is 16 bytes long. However, we are trying to stuff it with 256 bytes. Running this program gives us a segmentation violation because strcpy() is copying the content of the larger `*str` into the smaller `buffer[]`. Looking at the diassembled program, it can be inferenced that the return address of the function has also changed due to the buffer overflow.


Here's the assembly output:
~~~~
(gdb) disassemble main
Dump of assembler code for function main:
0x8000490 <main>:       pushl  %ebp
0x8000491 <main+1>:     movl   %esp,%ebp
0x8000493 <main+3>:     subl   $0x4,%esp
0x8000496 <main+6>:     movl   $0x0,0xfffffffc(%ebp)
0x800049d <main+13>:    pushl  $0x3
0x800049f <main+15>:    pushl  $0x2
0x80004a1 <main+17>:    pushl  $0x1
0x80004a3 <main+19>:    call   0x8000470 <function>
0x80004a8 <main+24>:    addl   $0xc,%esp
0x80004ab <main+27>:    movl   $0x1,0xfffffffc(%ebp)
0x80004b2 <main+34>:    movl   0xfffffffc(%ebp),%eax
0x80004b5 <main+37>:    pushl  %eax
0x80004b6 <main+38>:    pushl  $0x80004f8
0x80004bb <main+43>:    call   0x8000378 <printf>
0x80004c0 <main+48>:    addl   $0x8,%esp
0x80004c3 <main+51>:    movl   %ebp,%esp
0x80004c5 <main+53>:    popl   %ebp
0x80004c6 <main+54>:    ret
0x80004c7 <main+55>:    nop
~~~~

We can see that when calling `function()`, the RET will be `0x8004a8`, and we want to jump past the assignment at `0x80004ab`. The next instruction we want is at `0x8004b2` which is 8 bytes away.



## Reflection

We learned about how programs can be vulnerable to attacks for root/admin privileges and all the ways a programmer can be hyper-aware and prevent any possible attacks. We feel as though we did achieve our learning goals and although we were unable to get to some of our stretch goals, we did reach just above the lower bound that we designated for ourselves.
