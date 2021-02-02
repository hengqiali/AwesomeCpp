
std::tuple 类似于 std::pair的扩展，std::pair只能存放两个元素，而tuple可以存放任意个元素和类型，也可以将其当做结构体使用，不需要定义结构体，而又有结构体的特征

[更多具体使用](https://blog.csdn.net/sevenjoin/article/details/88420885)

#### 例子：

```c++
typedef std::tuple<std::vector<int>, float> part_tuple;
std::vector<part_tuple> part_idx = {
    part_tuple(std::vector<int>{1,2,3,4,5}, 0.25),                                                 
    part_tuple(std::vector<int>{6,7,8}, 0.25),                                                 
    part_tuple(std::vector<int>{9}, 0.25),                                
    part_tuple(std::vector<int>{10, 11, 12, 13, 14, 15}, 0.25)  
};
float result = 0.f;
for (auto &t : part_idx) {
    float score = 0;
    const auto &part = std::get<0>(t);
    for (auto i : part)
        score += i;
    result += std::get<1>(t) * score / part.size();
}
```
