//不妨可以在邻接表中增加一行 
//这个算法再补充一点是回溯法的核心思想
//可作为检测两个节点是否相连的算法访问

bool visit[v1] = false; //v1为节点最大数 初始化为全没有访问过

bool Backtracking(int v1,int v2)
{
    if(visit[v1])  return false;
    if(v1 == v2) return true;//找到后返回
    bool ret = false;
    visit[v1] = true;
    for(const auto& num:G[v1])
    {
    	if(!visit[num]) ret = Backtracking(num);
    	if(ret)	return true;
    }
    //当所有节点遍历完都没有返回时 我们即返回false 没有找到我们需要找到的点
    return false;
};
