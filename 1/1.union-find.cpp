#include<iostream>
#include<cctype>
using namespace std;

void _UF(int*, int, int&);
void _union(int, int, int, int*, int&);
bool _connected(int, int, const int*);

int main()
{
    int id[10000];
    int n;
    int p, q;
    int count;
    cout << "请输入触点数量: ";
    cin >> n;
    _UF(id, n, count); //初始化触点
    cout << "请输入要联通的两个触点(输入-1结束):" << endl;
    while (1)
    {
        cin >> p >> q;
        if (p == -1 || q == -1)
            break;
        if (_connected(p, q, id))
            continue;
        _union(p, q, n, id, count);
        // cout << p << " " << q << endl;
    }
    cout << count << "components" << endl;
    system("pause");
    return 0;
}

void _UF(int* id, int n, int& count)
{
    count = n;
    for (int i = 0; i < n; i++)
    {
        id[i] = i;
    }
}

void _union(int p, int q, int n, int* id, int& count)
{
    int pID = id[p];
    int qID = id[q];
    if (pID == qID)
        return;
    for (int i = 0; i < n; i++)
    {
        if (id[i] == pID)
        {
            id[i] = qID;
        }
    }
    count--;
}

bool _connected(int p, int q, const int* id)
{
    return id[p] == id[q];
}
