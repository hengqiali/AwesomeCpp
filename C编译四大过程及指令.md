
C编译过程主要包括预编译、编译、汇编、链接四大过程
1. 预编译就是将你写好的源文件进行预处理，主要是对以'#'开始（没有';'结束）的语句和注释进行处理,gcc -E hello.c -o a.i；
2. 编译就是对预处理之后的源文件处理成汇编语言， gcc -S hello.c -o a.s;
3. 汇编就是对编译之后生成的汇编语言文件处理成机器二进制，生成目标文件 gcc -c a.s -o a.o
4. 链接就是对汇编生成的各目标文件和需要的库链接在一起生成可执行文件

### 要想彻底理解和观看示例，可以参考下面的好文章
#### [C编译四大过程](https://zhuanlan.zhihu.com/p/90890103?utm_source=wechat_session&utm_medium=social&utm_oi=752170274572500992, https://www.cnblogs.com/CarpenterLee/p/5994681.html)
