[为什么MYSQL索引使用B+树，而Mongodb使用B树？（一）](https://zhuanlan.zhihu.com/p/81273236?utm_source=wechat_session&utm_medium=social&utm_oi=752170274572500992&utm_campaign=shareopn)

[为什么MYSQL索引使用B+树，而Mongodb使用B树？（二）](https://zhuanlan.zhihu.com/p/107228878?utm_source=wechat_session&utm_medium=social&utm_oi=752170274572500992&utm_campaign=shareopn)

总结来说就是：
  1. B树单一查询效率不稳定，B树每个节点都要存储索引和数据，所以每个节点页能存储的索引就会变少，导致树高度相比B+树变高，所以磁盘IO可能会比B+树多，但是B树每个节点存储数据，其单一查询可能最优是O(1)，。
  所以其适合非关系型数据库的单一查询，其叶子节点没有指向下一页子节点的指针，所以不适合关系型数据库的范围查询。
  
  2. B+树是非叶子节点只存储索引，所以树是最矮胖的，同时叶子节点间存在指向下一叶子节点的指针，所以适合范围查询！
  
  3. 红黑树虽然是平衡树，但是其是二叉树，相比于B/B+多叉树而言，树就高很多，从而从磁盘加载索引到内存时，会导致更多的磁盘IO
