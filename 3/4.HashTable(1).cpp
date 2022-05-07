#include<vector>
template<typename T,typename V>
class hashST
{
private:
	int n;	//键对总数
	int m;	//线性表大小
	std::vector<std::vector<V>> st;
	int hash(T key)
	{
		std::hash<T> hash_t;
		return (hash_t(key) & 0x7fffffff) % m;
	}
public:
	hashST(int m)
	{
		this->m = m;
		st.resize(m);
	}
	V get(T key)
	{
		return st[hash(key)][0];
	}
	void put(T key, V value)
	{
		st[hash(key)].push_back(value);
	}
};
