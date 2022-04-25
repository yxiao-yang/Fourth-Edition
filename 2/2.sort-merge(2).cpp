//自底向上的归并排序
#include<iostream>
#include<algorithm>
using namespace std;

void _sort(int*, int);
void _merge(int*, int, int, int, int*);
bool _less(int, int);

int main()
{
    int n;
    cout << "请输入数组长度：";
    cin >> n;
    int a[n];
    cout << "请输入数组内容：" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    _sort(a, n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << ' ';
    }
    cout << endl;
    system("pause");
    return 0;
}

void _sort(int* a, int n)
{
    int aux[n];
    for(int sz = 1; sz < n; sz = sz + 1)
    {
        for(int lo = 0; lo < n - sz; lo = lo + sz + sz)
        {
            _merge(a, lo, lo + sz - 1, min(lo+sz+sz-1, n-1), aux);
        }
    }
}

void _merge(int* a, int left, int mid, int right, int* aux)
{
    for (int k = 0; k <= right; k++)
        aux[k] = a[k];
    int i = left;
    int j = mid + 1;
    for (int k = left; k <= right; k++) 
    {
        if (i > mid)
            a[k] = aux[j++];
        else if (j > right)
            a[k] = aux[i++];
        else if (_less(aux[j], aux[i]))
            a[k] = aux[j++];
        else
            a[k] = aux[i++];
    }
}

bool _less(int v, int w)
{
    return v < w;
}