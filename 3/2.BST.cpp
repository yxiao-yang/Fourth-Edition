template<typename T,typename V>
class BST
{
private:
	struct node
	{
		T key;
		V value;
		node *left;
		node *right;
		int n; //�Ըý��Ϊ���������еĽ������
	};
	node *root = nullptr;
	node* create_node(T key, V value, int n) //�����½�㲢����
	{
		node *newnode = new node;
		newnode->key = key;
		newnode->value = value;
		newnode->n = n;
		newnode->left = nullptr;
		newnode->right = nullptr;
		return newnode;
	}
	int size(node *x) // ���ؽ���n
	{
		if (x == NULL)
			return 0;
		else
			return x->n;
	}
	V get(node *x, T key) //���ݼ�����ֵ
	{
		if (x == 0)
			return NULL;
		if (x->key < key)
		{
			get(x->right, key);
		}
		else if (x->key > key)
		{
			get(x->left, key);
		}
		else
			return x->value;
	}
	void put(node *x, T key, V value) //���Ҽ����ҵ�����ֵ��û�ҵ��½����
	{
		if (x == NULL)
		{
			x=create_node(key, value, 1);
			return;
		}
		if (x->key < key)
		{
			put(x->right, key, value);
		}
		else if (x->key > key)
		{
			put(x->left, key, value);
		}
		else
			x->value = value;
		x->n = size(x->left) + size(x->right)+1;
		return;
	}
	T min(node *x) //������С���
	{
		if (x->left == nullptr)
			return x;
		min(x->left);
	}
	T max(node *x) //���������
	{
		if (x->right == nullptr)
			return x;
		max(x->right);
	}
	node floor(node *x, T key) //С�ڵ���key������
	{
		if (x == NULL)
			return NULL;
		if (x->key == key)
			return x;
		if (x->key > key)
			return floor(x->left, key);
		node t = floor(x->right, key);
		if (t!=NULL)
			return t;
		else
			return x;
	}
	node ceiling(node *x, T key) //���ڵ���key����С��
	{
		if(x == NULL)
			return NULL;
		if (x->key == key)
			return x;
		if (x->key < key)
			return floor(x->right, key);
		node t = floor(x->left, key);
		if (t != NULL)
			return t;
		else
			return x;
	}
	node select(node *x, int k) //��������Ϊk�Ľ��
	{
		if (x == NULL)
			return NULL;
		int t = size(x->left);
		if (t > k)
			return select(x->left, k);
		else if (t < k)
			return select(x->right, k - t - 1);
		else 
			return x;
	}
	int rank(node *x, T key) //���ظ�����������
	{
		if (x == NULL)
			return 0;
		if (x->key > key)
		{
			return rank(x->left, key);
		}
		else if (x->key < key)
		{
			return 1 + size(x->left) + rank(x->right, key);
		}
		else
			return size(x->left);
	}
	void keys(node x, std::queue<T> &q, T low, T high) //���ظ�����Χ�ļ� �������
	{
		if (x == NULL)
			return;
		if (x->key > low)
		{
			keys(x->left, q, low, high);
		}
		if (x->key >= low && x->key <= high)
		{
			q->push(x->key);
		}
		if (x->key < high)
		{
			keys(x->right, q, low, high);
		}
	}
public:
	int size()	//���Ĵ�С
	{
		return size(root);
	}
	V get(T key)	//��ȡ�ڵ�
	{
		return get(root, key);
	}
	void put(T key, V value)	//����ڵ�
	{
		put(root,key,value);

	}
	T min()		//��Сֵ
	{
		min(root);
	}
	T max()		//���ֵ
	{
		max(root);
	}
	T floor(T key)	//�½磬����ȡ��
	{
		node x = floor(root, key);
		if (x == NULL)
			return NULL;
		return x->key;
	}
	T ceiling(T key)	//�Ͻ磬����ȡ��
	{
		node x = ceiling(root, key);
		if (x == NULL)
			return NULL;
		return x->key;
	}
	T select(int k)		//���������ҳ���
	{
		node x = select(root, k);
		return x->key;
	}
	int rank(T key)	//���ݼ��ҳ�����
	{
		return rank(root, key);
	}
	std::queue<T> keys(T low,T high)	//��Χ����
	{
		std::queue<T> q;
		keys(root, q, low, high);
		return q;
	}
};
