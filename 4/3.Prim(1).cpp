#include <vector>
class prim
{
private:
	std::vector<edge> pq;
	bool *marked;	//标记是否访问
	std::vector<edge> mst;	//最终路径
	void visit(EWgraph g, int v)
	{
		marked[v] = true;
		for (edge e : g.iterator(v))
		{
			if (!marked[e.other(v)])
			{
				pq.push_back(e);
			}
		}
		std::sort(pq.begin(), pq.end(),ewcmp);
	}
public:
	prim(EWgraph g)
	{
		marked = new bool[g.numv];
		std::fill(marked, marked + g.numv(), 0);
		visit(g, 0);
		while (!pq.empty())
		{
			edge e = *pq.end();
			pq.pop_back();
			int v = e.either();
			int w = e.other(v);
			if (marked[v] && marked[w])
			{
				continue;
			}
			mst.push_back(e);
			if (!marked[v])
				visit(g, v);
			if (!marked[w])
				visit(g, w);
		}
	}
	std::vector<edge> edges()
	{
		return mst;
	}
};
