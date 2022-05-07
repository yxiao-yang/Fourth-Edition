#include<vector>
class prim
{
private:
	bool *marked;	//标记是否访问
	double *dist_to;	//标记路径长短
	std::vector<edge> edge_to;
	std::vector<edge> temp;
	int min;
	std::vector<edge> mst;	//最终路径
	void visit(EWgraph g, int v)
	{
		marked[v] = true;
		edge tempe(0, v, inf);
		edge_to[v] = tempe;
		for (edge e : g.iterator(v))
		{
			int w = e.other(v);
			if (marked[w])
			{
				continue;
			}
			if (e.weight() < dist_to[w])
			{
				edge_to[w] = e;
				dist_to[w] = e.weight();
			}
		}
		temp = edge_to;
		std::sort(temp.begin(), temp.end(), ewcmp);
		mst.push_back(temp[0]);
		min = temp[0].either();
		if(marked[min])
			min = temp[0].other(temp[0].either());
		/*
		marked[v] = true;
		for (edge e : g.iterator(v))
		{
			if (!marked[e.other(v)])
			{
				pq.push_back(e);
			}
		}
		std::sort(pq.begin(), pq.end(),ewcmp);
		*/
	}
public:
	prim(EWgraph g)
	{
		marked = new bool[g.numv()];
		std::fill(marked, marked + g.numv(), 0);
		dist_to = new double[g.numv()];
		std::fill(dist_to, dist_to + g.numv(), inf);
		edge_to.resize(g.numv());
		edge e(0, 0, 0);
		edge_to[0] = e;
		min = 0;
		for(int i=0;i<g.numv()-1;i++)
		{
			visit(g,min);
		}
		/*
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
		*/
	}
	std::vector<edge> edges()
	{
		return mst;
	}
};
