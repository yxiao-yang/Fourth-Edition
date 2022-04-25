#include<iostream>
#include<cctype>
using namespace std;

void _UF(int*, int, int&, int*);
void _union(int, int, int, int*, int&, int*);
int _find(int, const int*);
bool _connected(int, int, const int*);

int main()
{
    int n;
    int p, q;
    int count;
    cout << "请输入触点数量: ";
    cin >> n;
    int id[n];
    int sz[n];
    _UF(id, n, count, sz); //初始化触点
    cout << "请输入要联通的两个触点(输入-1结束):" << endl;
    while (1)
    {
        cin >> p >> q;
        if (p == -1 || q == -1)
            break;
        if (_connected(p, q, id))
            continue;
        _union(p, q, n, id, count, sz);
        // cout << p << " " << q << endl;
    }
    cout << count << "components" << endl;
    system("pause");
    return 0;
}

void _UF(int* id, int n, int& count, int* sz)
{
    count = n;
    for (int i = 0; i < n; i++)
    {
        id[i] = i;
    }
    for (int i = 0; i < n; i++)
    {
        sz[i] = i;
    }
}

void _union(int p, int q, int n, int* id, int& count, int* sz)
{
    int pRoot = _find(p, id);
    int qRoot = _find(q, id);
    if (pRoot == qRoot)
        return;
    if (sz[pRoot] < sz[qRoot])
    {
        id[pRoot] = qRoot;
        sz[qRoot] += sz[pRoot];
    }
    else
    {
        id[qRoot] = pRoot;
        sz[pRoot] += sz[qRoot];
    }
    count--;
}

int _find(int p, const int* id)
{
    if (p != id[p])
        p = id[p];
    return p;
}

bool _connected(int p, int q, const int* id)
{
    return _find(p, id) == _find(q, id);
}
