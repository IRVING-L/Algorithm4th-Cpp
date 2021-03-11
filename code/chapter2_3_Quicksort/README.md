# 2.3 快速排序

**特点：**

* 原地排序（只需要一个很小的辅助栈）；
* 将长度为 N 的数组排序所需的时间和 NlgN 成正比。

## 基本算法

快速排序的**切分**方法：

一般策略是先随意地选取 a[lo] 作为**切分元素**，即那个会被排定的元素，然后我们从数组的左端开始向右扫描直到找到一个**大于等于**它的元素，再从数组的右端开始向左扫描直到找到一个小于等于它的元素。这两个元素显然是没有排定的，因此我们交换它们的位置。

如此继续，我们就可以保证左指针 i 的左侧元素都不大于切分元素，右指针 j 的右侧元素都不小于切分元素。当两个指针相遇时，我们只需要将切分元素 a[lo] 和左子数组最右侧的元素（a[j]）交换然后返回 j 即可。

## 性能特点

快速排序的两个速度优势：

1. 切分方法的内循环会用一个递增的索引将数组元素和一个定值比较，而归并排序、希尔排序等还在内循环中移动数据；
2. 比较次数少。

将长度为 N 的无重复数组排序，快速排序平均需要 ~2NlnN 次比较（以及 1/6 的交换）。

### 潜在缺点

快速排序的最好情况是每次都正好能将数组对半分。而**在切分不平衡**时，这个程序可能会最多需要约 **N^2/2** 次比较。例如，如果第一次从最小的元素切分，第二次从第二小的元素切分，如此这般，每次调用只会移除一个元素。

因此，我们在快速排序前将数组随机排序，以避免上述情况。

## 算法改进

### 切换到插入排序

和大多数递归排序算法一样，改进快速排序性能的一个简单办法基于以下两点：

* 对于小数组，快速排序比插入排序慢；
* 因为递归，快速排序的`sort()`方法在小数组中也会调用自己。

因此，在排序**小数组**时应该切换到插入排序。

### 三取样切分

使用子数组中的一小部分元素的中位数来切分数组。这样做得到的切分更好，但代价是需要计算中位数。

### 熵最优的排序

在**有大量重复元素**的情况下，快速排序的递归性会使元素全部重复的子数组经常出现，这就有很大的改进潜力，将当前实现的线性对数级的性能提高到**线性级别**。

一个简单的想法是将数组切分为**三部分**，分别对应小于、等于和大于切分元素的数组元素。这种做法被称为“三向切分”。

命题 1：不存在任何基于比较的排序算法能够保证在 NH-N 次比较之内将 N 个元素排序，其中 H 为由主键值出现频率定义的香农信息量。

命题 2：对于大小为 N 的数组，三向切分的快速排序需要 ~(2ln2)NH 次比较。其中 H 为由主键值出现频率定义的香农信息量。

**香农信息素**是对信息含量的一种标准的度量方法。给定包含 k 个不同值的 N 个主键，对于从 1 到 k 的每个 i，定义 fi 为第 i 个主键值出现的次数，pi 为 fi/N，即为随机抽取一个数组元素时第 i 个主键值出现的概率。那么所有主键的**香农信息素**可以定义为：

H = -(p1lgp1 + p2lgp2 + .. + pklgpk)