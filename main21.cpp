
/***////////////////////////////////////

            C++ 空指针
            
           NULL 和 nullptr
           
  1. 以往我们使用NULL表示空指针。它实际上是个为0的int值。下面的代码会产生岐义：
    void f(int i) {} // chose this one
    void f(const char* s) {}

    f(NULL);
  2. 为此C++ 11新增类型nullptr_t，它只有一个值nullptr。上面的调用代码可以写成: 
    void f(int i) {}
    void f(const char* s) {} // chose this one

    f(nullptr);
           
////////////////////////////////////***/
           
