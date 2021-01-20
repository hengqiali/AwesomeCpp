### std::function

---

在 ``<functional>`` 头文件中， std::function 是个可调用Callable对象的容器，可以容纳 函数、函数指针、lambda表达式、成员函数等

```c++
#include <functional>
#include <iostream>

double sum(int a, float b, double c) {
  return a + b + c;
}

//有typedef的函数指针
typedef double(*sum_alias_td)(int, float, double);

int main() {

  std::function<double(int, float, double)> func_display = sum;
  std::cout << func_display(1, 1.5, 2.3);

  // 其和没有typedef的函数指针类似
  double(*sum_alias)(int, float, double) = sum;
  std::cout << sum_alias(1, 1.5, 2.3);

  sum_alias_td func = sum;
  std::cout << func(1, 1.5, 2.3); 

  return 0;
}
```



### std::bind

-----

在``<functional>``头文件中，std::bind 看作一个通用的函数适配器，它接受一个可调用对象，生成一个新的可调用对象来“适应”原对象的参数列表。std::bind将可调用对象与其参数一起进行绑定，绑定后的结果可以使用std::function保存，一般使用auto自动推导。

```c++
#include <functional>
#include <iostream>

double sum(int a, float b, double c) {
  return a + b + c;
}

int main() {

  auto simple_sum = std::bind(&sum, 1, std::placeholders::_1, 2.3);
  std::cout << simple_sum(1.5) << std::endl;

  return 0;
}
```

[关于``std::function``的更多的例子](https://www.sczyh30.com/posts/C-C/cpp-stl-functional/)

[关于``std::bind``的更多的例子](https://www.jianshu.com/p/f191e88dcc80)

