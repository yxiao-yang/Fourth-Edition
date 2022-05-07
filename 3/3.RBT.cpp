template<typename T,typename V>

class RBT
{
public:
	void put(T key, V value)
	{
		root = put(root, key, value);
		root->color = black;
	}
private:
	const bool red = true;
	const bool black = false;
	struct node
	{
		T key;
		V value;
		node *left;
		node *right;
		int n;
		bool color;
	};
	node *root;
	node *create_node(T key, V value, int n, bool color) // �����ڵ�
	{
		node *newnode = new node;
		newnode->key = key;
		newnode->value = value;
		newnode->n = n;
		newnode->color = color;
		newnode->left = nullptr;
		newnode->right = nullptr;
		return newnode;
	}
	bool is_red(node *x) // �ж���ɫ
	{
		if (x == NULL)
			return false;
		return x->color;
	}
	int size(node *x) // ��xΪ�����ӽ������
	{
		if (x == NULL)
			return 0;
		else
			return x->n;
	}
	void rotate_left(node *h) // ����ת
	{
		node *x = h->right;
		h->right = x->left;
		x->left = h;
		x->color = h->color;
		h->color = red;
		x->n = h->n;
		h->n = 1 + size(h->left) + size(h->right);
	}
	void rotate_right(node *h) // ����ת
	{
		node *x = h->left;
		h->left = x->right;
		x->right = h;
		x->color = h->color;
		h->color = red;
		x->n = h->n;
		h->n = 1 + size(h->left) + size(h->right);
	}
	void flip_color(node *h) // ��ɫת�� 
	{
		h->color = red;
		h->left->color = black;
		h->right->color = black;
	}
	node *put(node *h, T key, V value) // ����
	{
		if (h == nullptr)
			return create_node(key, value, 1, red);
		if (key < h->key)
		{
			h->left = put(h->left, key, value);
		}
		else if (key > h->key)
		{
			h->right = put(h->right, key, value);
		}
		else
		{
			h->value = value;
		}
		if (is_red(h->right) && !is_red(h->left))
		{
			rotate_left(h);
		}
		if (is_red(h->left) && is_red(h->right))
		{
			rotate_right(h);
		}
		if (is_red(h->right) && is_red(h->left))
		{
			flip_color(h);
		}
		h->n = size(h->left) + size(h->right) + 1;
		return h;
	}
};
