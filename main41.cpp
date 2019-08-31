map的元素是pair，所以其每个元素只能存放key-value两个值
set的元素只有一个
二者可以根据需要传入排序函数指针来组织元素顺序
tuple根据需要可以有若干个元素，但tuple不属于关联容器
map和set都只允许单一关键字，不允许重复关键字


C++11新添加了无序容器，基于哈希函数来维护。无序容器在存储上组织为一组桶，无序容器使用哈希函数将元素映射到桶。

https://blog.csdn.net/fengxinlinux/article/details/73718859
