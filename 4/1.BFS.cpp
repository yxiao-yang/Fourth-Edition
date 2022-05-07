//���ҵ������ ���BFS��ʵ�Ͷ��������������һ��ԭ���
//��STL���������֮ǰѧϰC�Ļ���Ҫ��next pre�Ǻ�����ǵ�ʱ�� �ͷ���Ķ���
//����vector��������ʾ��һ��������Ҫ����
//visit bool�����ֹ�ظ�������ɲ���Ҫ�ļ��

vector<bool> visit(v1,false);//v1Ϊ�ڵ������ ��ʼ��Ϊȫû�з��ʹ�
vector<int> nowlevel,nextlevel;

bool BreadthFirstSearch(int v1,int v2)
{
	if(v1 == v2) return true;
	nowlevel.push_back(v1);
	visit[v1] = true;
	while(!nowlevel.empty())
	{
		for(const auto& num:nowlevel)
		{
			for(const auto& temp:G[num])
			{
				if(temp == v2) return true;
				if(visit[temp]) continue;
				nextlevel.push_back(temp);
				visit[temp] = true;	
			}
		}
		nowlevel = nextlevel;
		nextlevel.clear();
	}
	return false;
}
