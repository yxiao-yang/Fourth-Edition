template<typename key>
class maxPQ
{
private:
    key pq[];
    int n = 0;
    bool less(int i, int j)
    {
        return pq[i] < pq[j];
    }
    void swap(int i, int j)
    {
        key temp = pq[i];
        pq[i] = pq[j];
        pq[j] = temp;
    }
    void swim(int k)
    {
        while (k > 1 && less(k / 2, k))
        {
            swap(k / 2, k);
            k = k / 2;
        }
    }
    void sink(int k)
    {
        while (2 * k <= n)
        {
            
            int j = 2 * k;
            //std::cout << j << ' ';
            if (j < n && less(j, j + 1))
            {
                j++;
            }
            if (!less(k, j))
            {
                break;
            }
            swap(k, j);
            k = j;
        }
    }
public:
    maxPQ(int maxn)
    {
        pq = new int[maxn];
    }
    bool isempty()
    {
        return n == 0;
    }
    int sizs()
    {
        return n;
    }
    void insert(key v)
    {
        pq[++n] = v;
        swim(n);
    }
    key del_max()
    {
        key max = pq[1];
        pq[n + 1] = nullptr;
        sink(1);
        return max;
    }
    void show()
    {
        for (int i = 1; i < pq.size(); i++)
        {
            std::cout << pq[i];
        }
    }
};
