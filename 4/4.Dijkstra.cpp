#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

const int Ni = 10000;
const int INF = 1 << 27;
struct node
{
    int point, value;
    // 构造
    node(int a, int b)
    {
        point = a;
        value = b;
    }
    // 重载<操作符
    bool operator<(const node &a) const
    {
        // 对小于运算符进行重载，如果两个值相等，那么继续判断point，如果不等，则返回false
        if (value == a.value)
        {
            return point < a.point;
        }
        else
        {
            return value > a.value;
        }
    }
};
vector<node> e[Ni];
int dis[Ni], n;
priority_queue<node> q;
void dijkstra();

int main()
{
    int a, b, c, m;
    scanf("%d%d", &n, &m);
    while (m--)
    {
        scanf("%d%d%d", &a, &b, &c);
        e[a].push_back(node(b, c));
        e[b].push_back(node(a, c));
    }
    
    // for (int i = 0; i <= n; i++)
    // {
    //     dis[i] = INF;
    // }
    memset(dis, 0x3f, sizeof(dis));
    dis[1] = 0;
    // 优先队列，队头元素最大，但是如果类型为struct需要重载<运算符
    q.push(node(1, dis[1]));

    dijkstra();

    for (int i = 1; i <= n; i++)
    {
        printf("%d ", dis[i]);
    }
    system("pause");
    return 0;
}
void dijkstra()
{
    while (!q.empty())
    {
        node x = q.top();
        q.pop();
        for (int i = 0; i < e[x.point].size(); i++)
        {
            node y = e[x.point][i];
            if (dis[y.point] > dis[x.point] + y.value)
            {
                dis[y.point] = dis[x.point] + y.value;
                q.push(node(y.point, dis[y.point]));
            }
        }
    }
}
