int dijkstra(EWdigraph g, int v, int to)
{
	int n = g.numv();
	bool *marked = new bool[n];		//標記是否搜索
	std::vector<diedge> path(n);	//路徑，可自行取捨（寫成類或者返回vector的函數，儅便利to=e.to（）的時候更新path）
	/*int **len = new int *[n];	//各個點到其他點的距離
	for (int i = 0; i < n; i++)
	{
		len[i] = new int[n];
	}*/
	int *dis = new int[n];	//點v到其他點的距離
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
