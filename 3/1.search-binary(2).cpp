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

    cout << "����������ҵ���������ĳ��ȣ�" << endl;
    cin >> n;
    cout << "����������ҵ��������飺" << endl;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << "������Ҫ���ҵ�Ԫ��ֵ��" << endl;
    cin >> x;
    ans = _rank(a, x, n) + 1;
    cout << "��Ԫ�����ڵ�"
         << ans
         << "λ" << endl;
    system("pause");
    return 0;
}
// ���ҵ����ؼ������򷵻�С�ڸ�ֵ��Ԫ������
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