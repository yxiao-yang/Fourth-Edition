//�ڽӾ��󷨹�������ͼ
//�����ձ���ڽӾ����е��������ڽӱ���������������
#include<vector>
#include<string>
#include <algorithm>

class graph
{
private:
	int v;	//������
	int e;	//����
	std::vector<std::vector<int>> adj; // �ڽӱ�
public:
	graph(int v) //�����ڽӾ���
	{
		this->v = v;
		this->e = 0;
		adj.resize(v);
	}
	int numv() //���ض�����
	{
		return this->v;
	}
	int nume() //���ر���
	{
		return e;
	}
	void add_edge(int v, int w)		//������뷽����������׳���������Ĳ�����vҪ������
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
		adj[v].push_back(w); //v����������w
		adj[w].push_back(v); //w����������v
        //ȥ�������ظ�Ԫ��
		std::unique(adj.begin(), adj.end());
		e++;
	}
	std::vector<int> *iterator(int v)	//����һ��ָ���Ӧ�ڵ�������ָ��
	{
		return &adj[v];
	}
	int degree(int v)	//���ض���
	{
		int degree = 0;
		for (auto w : adj[v])
		{
			degree++;
		}
		return degree;
	}
	int max_degree()	//��ȡ����
	{
		int max = 0;
		for (unsigned int i = 0; i < adj.size(); i++)
		{
			if (degree(i) > max)
				max = degree(i);
		}
		return max;
	}
	int selfloop_num()	//�����Է����������
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
	std::string tostring()	//��ȡ������Ϣ���ַ���
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
