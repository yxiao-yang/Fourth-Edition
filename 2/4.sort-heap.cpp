class sort
{
public:
    void heap_sort(std::vector<T> &a)   //nΪ���鳤��
        {
            int n = a.size();
            int i;
            /*��ʼ����*/
            for (i = n / 2; i >= 0; i--)  //������ѧ��2^n/2=2^(n-1),��������ײ��Ԫ�ص������ϲ�Ԫ�ص���+1 
                percdown(a, i, n);
            /*����*/
            for (i = n - 1; i >= 0; i--)
            {
                swap(a,0, i);          //���Ѷ�Ԫ�س���ѵף����ҽ��ѳ��ȼ�1
                percdown(a, 0, i);
            }
        }
private:
    void swap(std::vector<T> &a, int i, int j)
    {
        T temp;
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
    void percdown(std::vector<T> &a, int i, int n) //i�� �����һ��Ԫ�أ�n�Ǳ������һ��Ԫ�� 
    {
        int child;        //���ӽ��
        int temp;		  //��ʱ����
        /*�Զѽ�������*/
        for (temp = a[i]; i * 2 + 1 < n; i = child)
        {
            child = i * 2 + 1; 								//��ǰ�������ӽ��
            if (child != n - 1 && a[child] < a[child + 1])  //�Ƚ����Ӻ��Һ���˭��
                child++;
            if (temp < a[child])
                a[i] = a[child];//ʹa[i]����С�� 
            else
                break;
        }
        a[i] = temp;
    }
}