#include <iostream>
#define max 1000
using namespace std;

int _rank(int*, int, int);

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
    ans = _rank(a, x, n) + 1;
    cout << "该元素排在第"
         << ans
         << "位" << endl;
    system("pause");
    return 0;
}
// 查找到返回键，否则返回小于该值的元素数量
int _rank(int* a, int key, int N)
{
    int lo = 0;
    int hi = N-1;
    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        if (a[mid] < key)
            lo = mid + 1;
        else if (a[mid] > key)
            hi = mid - 1;
        else
            return mid;
    }
    return lo;
}