//ѡ������
#include<iostream>
using namespace std;

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
    for (int i = 0; i < n; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (_less(a[j], a[min]))
                min = j;
            _exch(a, i, min);
        }
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