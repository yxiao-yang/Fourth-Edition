//邻接矩阵法构造无向图
//不是普遍的邻接矩阵，有点类似于邻接表，把链表换成数组了
#include<vector>
#include<string>
#include <algorithm>

class graph
{
private:
	int v;	//顶点数
	int e;	//边数
	std::vector<std::vector<int>> adj; // 邻接表
public:
	graph(int v) //创建邻接矩阵
	{
		this->v = v;
		this->e = 0;
		adj.resize(v);
	}
	int numv() //返回顶点数
	{
		return this->v;
	}
	int nume() //返回边数
	{
		return e;
	}
	void add_edge(int v, int w)		//这个插入方法还不够健壮，如果输入的参数比v要大会出错
	{
		/*
		if(v<0||v>this->v)
		{
			printf("%a");
			return;
		}
		if(w<0||w>this->v)
		{
			printf("%a");
			return;
		}
		*/
		adj[v].push_back(w); //v数组最后插入w
		adj[w].push_back(v); //w数组最后插入v
        //去除相邻重复元素
		std::unique(adj.begin(), adj.end());
		e++;
	}
	std::vector<int> *iterator(int v)	//返回一个指向对应节点的数组的指针
	{
		return &adj[v];
	}
	int degree(int v)	//返回度数
	{
		int degree = 0;
		for (auto w : adj[v])
		{
			degree++;
		}
		return degree;
	}
	int max_degree()	//获取最大度
	{
		int max = 0;
		for (unsigned int i = 0; i < adj.size(); i++)
		{
			if (degree(i) > max)
				max = degree(i);
		}
		return max;
	}
	int selfloop_num()	//返回自反顶点的数量
	{
		int count = 0;
		for (int i = 0; i < v; i++)
		{
			for (unsigned int j = 0; j < adj[i].size(); j++)
			{
				if (i == j)
				{
					count++;
					break;
				}
			}
		}
		return count;
	}
	std::string tostring()	//获取矩阵信息的字符串
	{
		std::string s;
		s = std::to_string(v) + " verticers" + std::to_string(e) + " edges\n";
		for (unsigned int i=0;i<adj.size();i++)
		{
			s += std::to_string(i) + ":";
			for (auto j:adj[i])
			{
				s += std::to_string(j) + " ";
			}
			s += "\n";
		}
		return s;
	}
};
