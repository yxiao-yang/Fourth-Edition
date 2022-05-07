#include <iostream>
#define max 1000
using namespace std;

int _rank(int*, int, int, int);

int main()
{
    int a[max];
    int n;
    int x;
    int ans;

    cout << "请输入待查找的有序数组的长度：" << endl;
    cin >> n;
    cout << "请输入待查找的有序数组：" << endl;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << "请输入要查找的元素值：" << endl;
    cin >> x;
    ans = _rank(a, x, 0, n - 1) + 1;
    cout << "该元素排在第"
         << ans
         << "位" << endl;
    system("pause");
    return 0;
}

int _rank(int* a, int key, int lo, int hi)
{
    if (hi < lo)
        return lo;
    int mid = lo + (hi - lo) / 2;
    if (a[mid] < key)
        return _rank(a, key, a[mid], hi);
    else if (a[mid] > key)
        return _rank(a, key, lo, a[mid]);
    else
        return mid;
}