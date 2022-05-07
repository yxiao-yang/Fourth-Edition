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
		int n; //以该结点为根的子树中的结点总数
	};
	node *root = nullptr;
	node* create_node(T key, V value, int n) //创建新结点并返回
	{
		node *newnode = new node;
		newnode->key = key;
		newnode->value = value;
		newnode->n = n;
		newnode->left = nullptr;
		newnode->right = nullptr;
		return newnode;
	}
	int size(node *x) // 返回结点的n
	{
		if (x == NULL)
			return 0;
		else
			return x->n;
	}
	V get(node *x, T key) //根据键查找值
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
	void put(node *x, T key, V value) //查找键，找到更新值，没找到新建结点
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
	T min(node *x) //返回最小结点
	{
		if (x->left == nullptr)
			return x;
		min(x->left);
	}
	T max(node *x) //返回最大结点
	{
		if (x->right == nullptr)
			return x;
		max(x->right);
	}
	node floor(node *x, T key) //小于等于key的最大键
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
	node ceiling(node *x, T key) //大于等于key的最小键
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
	node select(node *x, int k) //搜索排名为k的结点
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
	int rank(node *x, T key) //返回给定键的排名
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
	void keys(node x, std::queue<T> &q, T low, T high) //返回给定范围的键 中序遍历
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
	int size()	//树的大小
	{
		return size(root);
	}
	V get(T key)	//获取节点
	{
		return get(root, key);
	}
	void put(T key, V value)	//插入节点
	{
		put(root,key,value);

	}
	T min()		//最小值
	{
		min(root);
	}
	T max()		//最大值
	{
		max(root);
	}
	T floor(T key)	//下界，向下取整
	{
		node x = floor(root, key);
		if (x == NULL)
			return NULL;
		return x->key;
	}
	T ceiling(T key)	//上界，向上取整
	{
		node x = ceiling(root, key);
		if (x == NULL)
			return NULL;
		return x->key;
	}
	T select(int k)		//根据名次找出键
	{
		node x = select(root, k);
		return x->key;
	}
	int rank(T key)	//根据键找出排名
	{
		return rank(root, key);
	}
	std::queue<T> keys(T low,T high)	//范围查找
	{
		std::queue<T> q;
		keys(root, q, low, high);
		return q;
	}
};
