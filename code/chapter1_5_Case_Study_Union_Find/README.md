# 1.5 案例研究：union-find 算法

## 动态连通性

动态连通性问题：设计一个数据结构来保存程序已知的所有整数对的足够多的信息，并用它们来判断一对新对象是否是相连的。

解决该问题的算法被称为 union-find。成本模型：在研究实现 union-find 的 API 的各种算法时，我们统计的是**数组的访问次数**（访问任意数组元素的次数，无论读写）。

路径压缩的加权 quick-union 算法是最优的算法，但并非所有操作*都能在常数时间内完成*。

## 展望

研究各种基础问题的基本步骤：

1. 完整而详细地定义问题，找出解决问题所必需的基本抽象操作并定义一份 API。
2. 简洁地实现一种初级算法，给出一个精心组织的开发用例并使用实际数据作为输入。
3. 当实现所能解决的问题的最大规模达不到期望时决定改进还是放弃。
4. 逐步改进实现，通过经验性分析或（和）数学分析验证改进后的效果。
5. 用更高层次的抽象表示数据结构或算法来设计更高级的改进版本。
6. 如果可能，尽量为最坏情况下的性能提供保证，但在处理普通数据时也要有良好的性能。
7. 在适当的时候将更细致的深入研究留给有经验的研究者并继续解决下一个问题。

## 看一下别人的总结

[算法(1)：Union-Find | Weber](http://binweber.top/2018/02/15/algs_1/)