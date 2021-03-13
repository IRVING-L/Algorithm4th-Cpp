#pragma once
#include<iostream>
using namespace std;

/*
* ����������BST
* ����ε����ġ����ݽṹ���У��Զ����������������Լ���;������˵����֪���Զ�����������������������Եõ���������
* ����û��ѧϰ���롣ͨ������㷨4 ���Ķ��ô��룬�ŷ������BST��˸��ӣ�������floor��delete��������������Ƚ�����
*/
class BST
{
	typedef int KeyType;
	typedef int Value;
public:
	//���캯��
	BST():root(nullptr){}

	//��Ա����
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
	KeyType select(int k) {return select(root, k)->key;}//select�Ǵ�0��ʼ������
	int rank(KeyType k) { return rank(root, k); }
	void deleteMin() { root = deleteMin(root); }
	void _delete(KeyType k) { root = _delete(root, k); }
private:
	struct Node
	{
		KeyType key;//��
		Value val;//ֵ
		Node* left, * right;//���Ӻ��Һ���
		int N;//�ý��Ϊ���������еĽ������
		//�벻���ɣ�structҲ�й��캯��
		Node(KeyType k, Value v, int num)
			:key(k), val(v), left(nullptr), right(nullptr), N(num) {}
	};
	
	Node* root;//�����������ĸ��ڵ�

	int size(Node* x)
	{
		//��Ӧ�������ں������ذɡ����к���size���޲εģ�˽��size���вεģ����㺯�����ء�
		//�����ڹ���size�е���˽��size����Ʋŵ���ʵ��
		if (x == nullptr) return 0;
		else return x->N;
	}

	Value get(Node* x, KeyType k)
	{
		if (x == nullptr) return NULL;
		//�������
		//��������ҵ�k�ȵ�ǰ����keyС����ô�ݹ鵽������ȥ
		if (k < x->key) get(x->left, k);
		//��֮�ȵ�ǰ���󣬵ݹ鵽��������ȥ
		else if (k > x->key) get(x->right, k);
		//������õ��ڸý���key���Ǿ����ҵ���
		else return x->val;
		//����ķ��ؽ�������֣��������޵ݹ���ȥ��
		//��һ���ҵ��ˣ����ظ�key��Ӧ��value
		//�ڶ���δ�ҵ������Ƿ���NULL
	}

	Node* put(Node* x, KeyType k, Value v)
	{
		//�ÿ�ܵ�˼ά����������һ���������
		if (x == nullptr) return new Node(k, v, 1);
		if (k < x->key) x->left = put(x->left, k, v);
		else if (k > x->key) x->right = put(x->right, k, v);
		//����С�ڣ�Ҳ���Ǵ��ڣ��Ǿ��ǵ��ڡ�����һ��key��Ӧ��valueֵ����
		else x->val = v;
		//�������Ĵ����Ǹ���BST�еĽ�����
		//Ҫ����ȷͳ�����еĸ�������Ҫ��N������ȷ�ĳ�ʼ��
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
		//floor����С�ڵ��ڣ����ڵĲ����ǵڶ�����룬С�ڵĴ����ǵ�4-6�д���
		if (x == nullptr) return nullptr;
		if (k == x->key) return x;
		if (k < x->key) return floor(x->left, k);
		/*
		floor������ȡ���������ֵkey���ڵ�ǰ����key����ô��Ҫ����������ȥ�ң�
		�ؼ����ڣ���������������Ҳ�����������ֱ�ӷ��ؿգ����Ǵ���С�ڵ���key�����ֵ���ǵ�ǰ����keyֵ
		����Ҫ�������һ�ν�����������˫�׽�㣬Ҳ��Ҫ�������˫�׽�㣬Ҳ�������������Һ������������ǲ�һ����
		*/
		Node* t = floor(x->right, k);
		if (t != nullptr) return t;//���t�����ڿ�ָ�룬��ζ�����������ҵ���һ�����ڻ�������С��key�Ľ�㣬������󷵻ظý��
		else return x;//��֮�����Ϊ�գ�������������û���ҵ����ڻ�������С�ڵĽ��
	}

	Node* select(Node* x, int k)
	{
		if (x == nullptr) return nullptr;
		int t = size(x->left);//��ȡ��ǰ�������������ܸ���
		if (t > k) return select(x->left, k);
		else if (t < k) return select(x->right, k - t - 1);//�������Ľ�������t�����ϸ���㣬����t+1��
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
			//����ý��ֻ��������������������ɾ���ý�㣬�øý��ĺ�̽�㲹�ϼ��ɣ��������ɾ����������
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
			//����ý�����Һ��Ӷ����ڣ������ͻ�Ƚϸ���
			//��һ������Nodeָ�� t ����ý��x
			Node* t = x;
			//�ڶ�������xָ��x������������С��㡣����������С������x��������������н�㣬����С���������������㣬�����x��Ψһѡ��
			x = min(t->right);
			//����deleteMin������ɾ��tָ��Ľ�������������СԪ�أ������޳��ڶ���xָ���Ԫ�أ�
			x->right = deleteMin(t->right);
			//�ض���x����ָ��ָ��
			x->left = t->left;
			//�ͷ��ڴ棬�����ڴ�й©
			delete t;
		}
		x->N = size(x->left) + size(x->right) + 1;
		return x;
	}
};