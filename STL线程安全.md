首先，STL容器都是非线程安全的！

STL的线程安全问题，分为两种解决方法:

(1)第一点：自己实现相关的简单的数据结构，其中在所有的成员方法中，都获取锁、释放锁，在push和pop时还要配合使用信号量或者条件变量

(2)第二点：使用STL自带的容器，首先要避免会扩容的容器，如果要使用会扩容的容器，需提前固定好容器大小，然后不适用push或insert，用[]来代替，否则会出现其他线程迭代器失效的情况，例如vector，使用resize
提前固定大小(reserve只是预留空间可以push_back，但是不能[]访问大于end_的位置)。
对不会扩容或者固定大小的扩容容器，此时要对容器的每个操作都要封装出一个对应的函数，在每个函数内用锁搭配信号量或者条件变量实现

----------

顺带解释一下，vector的resize和reserve，更好的理解下文：：

reserve是预留空间大小，在vector初始化的时候，如果调用vector(){...}，则begin_=end_，也就是size() = end_-begin_ = 0, 但是cap_ = 16; 若调用vector(n){...}或者vector(n, v)，
此时end_ = begin_ + n, cap_ = begin_ + max(n, 16)， reserve预留的空间可以干嘛？？ 当你push_back的时候，其是判断 end_ != cap_则插入，否则构造新的空间再插入，所以reserve的空间可以用来插入
新的元素，但是！！，当你调用operator[]来访问元素时，其判断是 n < size(),而size返回end_ - begin_， 也就是访问的时候并不能访问超过end_的在reserve空间内的元素！！

resize是改变vector内实际元素的个数，毕竟size()函数也是返回vector中的实际元素的个数end_ - begin_，其改变的过程中有三点：（1）当resize的个数小于size()时，先remove和destroy多余的对象，cap_不变；
（2）当resize的个数大于等于size()并且小于cap_时，其会插入value对象，cap_不变；（3）当resize的个数大于cap_时，分配新的空间，然后复制Old元素插入新的元素，并拥有一个更大的cap_
