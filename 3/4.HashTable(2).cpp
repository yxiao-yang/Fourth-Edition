#include<vector>
template<typename T, typename V>
class LPhashST
{
private:
	int n;		//键值对总数
	int m = 16;		//线性探测表大小
	std::vector<T> keys;
	std::vector<V> values;
	int hash(T key)
	{
		std::hash<T> hash_t;
		return (hash_t(key) & 0x7fffffff) % m;
	}
	void resize(int cap)
	{
		keys.resize(cap);
		values.resize(cap);
	}
public:
	LPhashST()
	{
		keys.resize(m);
		values.resize(m);
	}
	void put(T key, V value)
	{
		if (n >= m / 2)
		{
			resize(2 * m);
		}
		int i;
		for (i = hash(key); keys[i] != NULL; i = (i + 1) % n)
		{
			if (keys[i] == key)
			{
				values[i] = value;
				return;
			}
		}
		keys[i] = key;
		values[i] = value;
	}
	V get(T key)
	{
		for (int i = hash(key); keys[i] != NULL; i = (i + 1) % n)
		{
			if (keys[i] == key)
			{
				return values[i];
			}
		}
		return NULL;
	}
	void deletenode(T key)
	{
		auto it = find(keys.begin(), keys.end(), key);
		if (it == keys.end())
			return;
		int i = hash(key);
		while (keys[i] != key)
		{
			i = (i + 1) % m;
		}
		keys[i] = NULL;
		values[i] = NULL;
		//如果仅仅是把该key的两个数组的值设为null是不行的，因为这将导致后续的值无法被读取
		int j = i;
		i = (i + 1) % m;
		while (keys[i] != NULL)	//所以我们需要遍历需要删除的键值后面的内存，如果不为空，则进行替换
		//直到为空，再停止，并将n-1，如果n远小于m，则将数组容量减半
		{
			keys[j] = keys[i];
			values[j] = values[i];
			keys[i] = NULL;
			values[i] == NULL;
			n--;
			j = i;
			i = (i - 1) % m;
		}
		n--;
		if (n > 0 && n <= m / 8)
		{
			resize(m / 2);
		}
	}
};
