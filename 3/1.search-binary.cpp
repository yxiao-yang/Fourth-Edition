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

    cout << "����������ҵ���������ĳ��ȣ�" << endl;
    cin >> n;
    cout << "����������ҵ��������飺" << endl;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << "������Ҫ���ҵ�Ԫ��ֵ��" << endl;
    cin >> x;
    ans = _rank(a, x, 0, n - 1) + 1;
    cout << "��Ԫ�����ڵ�"
         << ans
         << "λ" << endl;
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