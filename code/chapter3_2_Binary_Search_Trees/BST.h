#pragma once
#include<iostream>
using namespace std;

/*
* 二叉搜索树BST
* 在严蔚敏版的《数据结构》中，对二叉搜索树的性质以及用途进行了说明，知道对二叉搜索树进行中序遍历可以得到有序序列
* 但是没有学习代码。通过这次算法4 的阅读敲代码，才发现这个BST如此复杂，尤其是floor和delete函数，理解起来比较困难
*/
class BST
{
	typedef int KeyType;
	typedef int Value;
public:
	//构造函数
	BST():root(nullptr){}

	//成员函数
	int size() { return size(root); }
	Value get(KeyType k) { return get(root, k); }
	void put(KeyType k, Value v) { root = put(root, k, v); }
	KeyType min() { return min(root)->key; }
	KeyType max() { return max(root)->key; }
	KeyType floor(KeyType k)
	{
		Node* t = floor(root, k);
		if (t == nullptr) return NULL;
		else return t->key;
	}
	KeyType select(int k) {return select(root, k)->key;}//select是从0开始计数的
	int rank(KeyType k) { return rank(root, k); }
	void deleteMin() { root = deleteMin(root); }
	void _delete(KeyType k) { root = _delete(root, k); }
private:
	struct Node
	{
		KeyType key;//键
		Value val;//值
		Node* left, * right;//左孩子和右孩子
		int N;//该结点为根的子树中的结点总数
		//想不到吧，struct也有构造函数
		Node(KeyType k, Value v, int num)
			:key(k), val(v), left(nullptr), right(nullptr), N(num) {}
	};
	
	Node* root;//二叉搜索树的根节点

	int size(Node* x)
	{
		//这应该是属于函数重载吧。公有函数size是无参的，私有size是有参的，满足函数重载。
		//所以在公有size中调用私有size的设计才得以实现
		if (x == nullptr) return 0;
		else return x->N;
	}

	Value get(Node* x, KeyType k)
	{
		if (x == nullptr) return NULL;
		//后序遍历
		//如果待查找的k比当前结点的key小，那么递归到左子树去
		if (k < x->key) get(x->left, k);
		//反之比当前结点大，递归到右子树上去
		else if (k > x->key) get(x->right, k);
		//如果正好等于该结点的key，那就是找到了
		else return x->val;
		//程序的返回结果就两种（不会无限递归下去）
		//第一，找到了，返回该key对应的value
		//第二，未找到，就是返回NULL
	}

	Node* put(Node* x, KeyType k, Value v)
	{
		//用框架的思维来看，这是一个先序遍历
		if (x == nullptr) return new Node(k, v, 1);
		if (k < x->key) x->left = put(x->left, k, v);
		else if (k > x->key) x->right = put(x->right, k, v);
		//不是小于，也不是大于，那就是等于。更新一下key对应的value值即可
		else x->val = v;
		//接下来的代码是更新BST中的结点个数
		//要能正确统计树中的个数，需要对N进行正确的初始化
		x->N = size(x->left) + size(x->right) + 1;
		return x;
	}

	Node* min(Node* x)
	{
		if (x->left == nullptr) return x;
		return min(x->left);
	}

	Node* max(Node* x)
	{
		if (x->right == nullptr) return x;
		return max(x->right);
	}

	Node* floor(Node* x, KeyType k)
	{
		//floor是找小于等于，等于的查找是第二句代码，小于的代码是第4-6行代码
		if (x == nullptr) return nullptr;
		if (k == x->key) return x;
		if (k < x->key) return floor(x->left, k);
		/*
		floor是向下取整，如果该值key大于当前结点的key，那么就要在右子树中去找，
		关键在于，如果在右子树中找不到，并不是直接返回空，而是代表小于等于key的最大值就是当前结点的key值
		所以要返回最后一次进入右子树的双亲结点，也即要保存这个双亲结点，也即在左子树查找和右子树查找是不一样的
		*/
		Node* t = floor(x->right, k);
		if (t != nullptr) return t;//如果t不等于空指针，意味着在右子树找到了一个等于或者最大的小于key的结点，所以最后返回该结点
		else return x;//反之，如果为空，代表在右子树没有找到等于或者最大的小于的结点
	}

	Node* select(Node* x, int k)
	{
		if (x == nullptr) return nullptr;
		int t = size(x->left);//获取当前结点左子树结点总个数
		if (t > k) return select(x->left, k);
		else if (t < k) return select(x->right, k - t - 1);//左子树的结点个数是t，加上根结点，就是t+1。
		else return x;
	}

	int rank(Node* x, KeyType k)
	{
		if (x == nullptr) return 0;
		if (k < x->key) return rank(x->left, k);
		else if (k > x->key) return rank(x->right, k) + size(x->left) + 1;
		else return size(x->left);
	}

	Node* deleteMin(Node* x)
	{
		if (x->left == nullptr)
		{
			Node* temp = x->right;
			delete x;
			return temp;
		}
		x->left = deleteMin(x->left);
		x->N = size(x->left) + size(x->right) + 1;
		return x;
	}
	
	Node* _delete(Node* x, KeyType k)
	{
		if (x == nullptr) return nullptr;
		if (k < x->key) x->left = _delete(x->left, k);
		else if (k > x->key) x->right = _delete(x->right, k);
		else
		{
			//如果该结点只有左子树或者右子树，删除该结点，让该结点的后继结点补上即可，和链表的删除操作相似
			if (x->right == nullptr)
			{
				Node* temp = x->left;
				delete x;
				return temp;
			}
			if (x->left == nullptr)
			{
				Node* temp = x->right;
				delete x;
				return temp;
			}
			//如果该结点左右孩子都存在，操作就会比较复杂
			//第一步：用Node指针 t 保存该结点x
			Node* t = x;
			//第二步：让x指向x的右子树的最小结点。右子树的最小结点大于x结点左子树的所有结点，但是小于右子树的其余结点，是替代x的唯一选择
			x = min(t->right);
			//调用deleteMin函数，删除t指向的结点的右子树的最小元素（就是剔除第二步x指向的元素）
			x->right = deleteMin(t->right);
			//重定向x的左指针指向
			x->left = t->left;
			//释放内存，避免内存泄漏
			delete t;
		}
		x->N = size(x->left) + size(x->right) + 1;
		return x;
	}
};