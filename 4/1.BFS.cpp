//在我的理解中 这个BFS其实和二叉树层序遍历是一个原理的
//有STL库相对于我之前学习C的还需要用next pre记号来标记的时候 就方便的多了
//利用vector数组来表示下一层我们需要检查的
//visit bool数组防止重复访问造成不必要的检查

vector<bool> visit(v1,false);//v1为节点最大数 初始化为全没有访问过
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
