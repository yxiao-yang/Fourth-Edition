//自顶向下的归并排序
#include<iostream>
using namespace std;

void _sort(int*, int, int);
void _merge(int*, int, int, int);
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
    _sort(a, 0, n-1);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << ' ';
    }
    cout << endl;
    system("pause");
    return 0;
}

void _sort(int* a, int left, int right)
{
    if (right <= left)
        return;
    int mid = (right + left) / 2;
    _sort(a, left, mid);
    _sort(a, mid+1, right);
    _merge(a, left, mid, right);
}

void _merge(int* a, int left, int mid, int right)
{
    int i = left;
    int j = mid + 1;
    int *aux = new int[right - left + 1];
    for (int k = left; k <= right; k++)
        aux[k] = a[k];
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