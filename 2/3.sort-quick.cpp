// 基于二分法的快速排序
#include<iostream>
using namespace std;

void _sort(int*, int, int);
int _partition(int*, int, int);
bool _less(int, int);
void _exch(int*, int, int);

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

void _sort(int* a, int lo, int hi)
{
    if (hi <= lo)
        return;
    int j = _partition(a, lo, hi); //切分
    _sort(a, lo, j-1); //将左半部分排序
    _sort(a, j+1, hi); //将右半部分排序
}

int _partition(int* a, int lo, int hi) //将数组切分为a[lo..i-1], a[i], a[i+1..hi]
{
    int i = lo, j = hi + 1; //左右扫描指针
    int v = a[lo]; //切分元素
    while (1)
    {
        // 检查扫描是否结束
        while (_less(a[++i], v))
        {
            if (i == hi)
                break;
        }
        while (_less(v, a[--j]))
        {
            if (j == lo)
                break;
        }
        if (i >= j)
            break;
        _exch(a, i, j);
    }
    // 将v=a[j]放入正确的位置
    _exch(a, lo, j);
    return j;
}

bool _less(int v, int w)
{
    return v < w;
}

void _exch(int* a, int i, int j)
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}