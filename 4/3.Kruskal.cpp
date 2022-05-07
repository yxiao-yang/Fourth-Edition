int dijkstra(EWdigraph g, int v, int to)
{
	int n = g.numv();
	bool *marked = new bool[n];		//��ӛ�Ƿ�����
	std::vector<diedge> path(n);	//·����������ȡ�Σ�������߷���vector�ĺ������}����to=e.to�����ĕr�����path��
	/*int **len = new int *[n];	//�����c�������c�ľ��x
	for (int i = 0; i < n; i++)
	{
		len[i] = new int[n];
	}*/
	int *dis = new int[n];	//�cv�������c�ľ��x
	std::fill(marked, marked + n, 0);
	//std::fill(len, len + n * n, inf);
	std::fill(dis, dis + n, inf);
	dis[v] = 0;
	while (n-- > 0)
	{
		std::vector<diedge> e = g.iterator(u);
		int min = inf;
		int u = inf;
		for(int i=0;i<n;i++)
		{
			if(dis[i]<min&&!marked[i]
			{
				min=dis[i];
				u=i;
			}
		}
		if (u == inf)
		{
			break;
		}
		marked[u] = true;
		for (auto i : e)
		{
			//assert(i.from()=u)
			if (dis[i.to()] > dis[u] + i.weight())
			{
				dis[i.to()] = dis[u] + i.weight();
			}
		}
	}
	return dis[to];
}
