// �������ַ��Ŀ�������
#include<iostream>
using namespace std;

void _sort(int*, int, int);
int _partition(int*, int, int);
bool _less(int, int);
void _exch(int*, int, int);

int main()
{
    int n;
    cout << "���������鳤�ȣ�";
    cin >> n;
    int a[n];
    cout << "�������������ݣ�" << endl;
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
    int lt = lo, i = lo + 1, gt = hi;
    int v = a[lo];
    while (i <= gt)
    {
        if (a[i] < v)
            _exch(a, lt++, i++);
        else if (a[i] > v)
            _exch(a, i, gt--);
        else
            i++;
    } //����a[lo..lt-1] < v = a[lt..gt] < a[gt+1..hi]����
    _sort(a, lo, lt - 1);
    _sort(a, gt + 1, hi);
}

int _partition(int* a, int lo, int hi) //�������з�Ϊa[lo..i-1], a[i], a[i+1..hi]
{
    int i = lo, j = hi + 1; //����ɨ��ָ��
    int v = a[lo]; //�з�Ԫ��
    while (1)
    {
        // ���ɨ���Ƿ����
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
    // ��v=a[j]������ȷ��λ��
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