
C编译过程主要包括预编译、编译、汇编、链接四大过程
1. 预编译就是将你写好的源文件进行预处理，主要是对以'#'开始（没有';'结束）的语句和注释进行处理,gcc -E hello.c -o a.i；
2. 编译就是对预处理之后的源文件处理成汇编语言， gcc -S hello.c -o a.s;
3. 汇编就是对编译之后生成的汇编语言文件处理成机器二进制，生成目标文件 gcc -c a.s -o a.o
4. 链接就是对汇编生成的各目标文件和需要的库链接在一起生成可执行文件 gcc a.c -I $要链接的目录$ x1.o x2.0..
上述四个步骤可直接简化成 gcc hello.c -o a

### 要想彻底理解和观看示例，可以参考下面的好文章
#### [C编译四大过程文章一](https://www.cnblogs.com/ggjucheng/archive/2011/12/14/2287738.html)
#### [C编译四大过程文章二](https://www.cnblogs.com/CarpenterLee/p/5994681.html)


make和Makefile     
make其实是个命令，而gcc\g++是个编译器，make通过Makefile指定的一系列目标以及前置条件来执行对应的命令行
Makefile的语法采用Bash语法。Linux的shell第一行 **#!/bin/bash**是对该脚本文件指定解释器，然后使用此解释器来解释脚本中的Bash语法。**cat /etc/shells**可以查看系统支持的脚本解释器
### 参考下面两个文章 
#### [make和makefile一](https://www.ruanyifeng.com/blog/2015/02/make.html)
#### [make和makefile二](https://blog.csdn.net/lihao21/article/details/68137648)
