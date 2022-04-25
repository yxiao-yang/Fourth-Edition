#include<iostream>
using namespace std;

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
    int h = 1;
    while (h < n/3)
        h = 3 * h + 1;
    while (h >= 1)
    {
        for (int i = h; i < n; i++)
        {
            for (int j = i; j >= h && _less(a[j], a[j-h]); j -= h)
                _exch(a, j, j-h);
        }
        h = h / 3;
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << ' ';
    }
    cout << endl;
    system("pause");
    return 0;
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