
三个函数的申明分别是: 
```c++
void* realloc(void* ptr, unsigned newsize); 
void* malloc(unsigned size); 
void* calloc(size_t numElements, size_t sizeOfElement); 
```
都在stdlib.h函数库内。它们的返回值都是请求系统分配的地址,如果请求失败就返回NULL。

malloc与calloc的区别为1块与n块的区别： 

malloc调用形式为(类型*)malloc(size)：在内存的动态存储区中分配一块长度为“size”字节的连续区域，返回该区域的首地址。 

calloc调用形式为(类型*)calloc(n，size)：在内存的动态存储区中分配n块长度为“size”字节的连续区域，返回首地址。 

realloc调用形式为(类型*)realloc(*ptr，size)：将ptr内存大小增大到size。(也可以缩小，缩小的内容消失)。

另外有一点不能直接看出的区别是，malloc 只管分配内存，并不能对所得的内存进行初始化，所以得到的一片新内存中，其值将是随机的。calloc在动态分配完内存后，自动初始化该内存空间为零。
