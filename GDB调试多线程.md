GDB
=============

首先在编译程序时，记得加-g，让生成的链接文件具有调试信息

* 第一步：使用 **gcc/g++ -g test1.c test2.c -o test** 编译链接
* 第二步：使用 **gdb test** 启动gdb调试
* 第三步：使用 **break(简写b) testx.c:linenumber** 或者 **break(简写b) testx.c:functionname**来给特定文件的特定行或者特定函数处添加断点
* 第四步：使用 **run(简写r)** 来运行程序，程序会在断点处停住
* 第五步：此时若是多线程程序，则会有多个线程同时运行，每个线程都会有自己的运行堆栈，可以使用**info threads** 来查看所有的线程情况， 使用**thread ID**来切换线程，
  使用 **backtrace(bt)**来查看每个线程的调用堆栈可以来了解运行逻辑

**注意：** 在多线程程环境下，break设置断点默认是给所有线程设置，所以在调试多线程时，可能因为CPU时间片在不同线程之间的切换导致其他线程运行到更早的断点处，所以为了只让当前线程运行，可以设置 **set scheduler-locking on**来锁定当前线程，让其他线程不运行！ 

--------------------

更多常见的gdb调试命令

> * break(b) + [文件名]:[行号/函数名] thread [threadID/all] ， 加断点 
> * info break(b)，显示所有断点信息
> * disable/enable 断点号， 让特定断点失效或重启，若不加断点号，则针对所有断点
> * next(n)， 跳到下一行，若是函数也不进入
> * step(s)，跳进函数
> * until(u) + 行号， 跳到指定行
> * continue(c)，程序继续运行至下一个断点处停住
> * finish(fi)，结束当前调用函数，到上一层函数调用处
> * return，强制函数忽略还没有执行的语句并返回
> * print(p) + 变量/*array@len， 打印变量值或者len长度的array数组的值
> * display + 变量， 每次都自动显示变量的值
> * watch + 变量， 监视变量的值，只要改变，就会显示出来
> * layout + src, 一边gdb调试，一边看运行到哪块源代码，很方便

-------------------------------

关于多线程调试：

1. **set scheduler-locking on** 可以用来锁定当前线程，只观察这个线程的运行情况， 当锁定这个线程时， 其他线程就处于了暂停状态，
   也就是说你在当前线程执行 next、step、until、finish、return 命令时，其他线程是不会运行的。
2. **set scheduler-locking step** 也是用来锁定当前线程，当且仅当使用 next 或 step 命令做单步调试时会锁定当前线程，
   如果你使用 until、finish、return 等线程内调试命令，但是它们不是单步命令，所以其他线程还是有机会运行的。相比较 on 选项值，step 选项值给为单步调试提供了更加精细化的控制，因为通常我们只希望在单步调试时，不希望其他线程对当前调试的各个变量值造成影响。
3. **set scheduler-locking off** 用于关闭锁定当前线程

--------------------

 参考文章
 [文章一](https://www.linuxblogs.cn/articles/15041200.html)
 [文章二](https://my.oschina.net/alicoder/blog/4407941)
