#include<vector>
template<typename T, typename V>
class LPhashST
{
private:
	int n;		//��ֵ������
	int m = 16;		//����̽����С
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
		//��������ǰѸ�key�����������ֵ��Ϊnull�ǲ��еģ���Ϊ�⽫���º�����ֵ�޷�����ȡ
		int j = i;
		i = (i + 1) % m;
		while (keys[i] != NULL)	//����������Ҫ������Ҫɾ���ļ�ֵ������ڴ棬�����Ϊ�գ�������滻
		//ֱ��Ϊ�գ���ֹͣ������n-1�����nԶС��m����������������
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
