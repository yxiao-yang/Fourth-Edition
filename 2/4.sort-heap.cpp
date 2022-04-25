class sort
{
public:
    void heap_sort(std::vector<T> &a)   //n为数组长度
        {
            int n = a.size();
            int i;
            /*初始化堆*/
            for (i = n / 2; i >= 0; i--)  //根据数学，2^n/2=2^(n-1),二叉树最底层的元素的量是上层元素的量+1 
                percdown(a, i, n);
            /*排序*/
            for (i = n - 1; i >= 0; i--)
            {
                swap(a,0, i);          //将堆顶元素沉入堆底，并且将堆长度减1
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
    void percdown(std::vector<T> &a, int i, int n) //i是 本层第一个元素，n是本层最后一个元素 
    {
        int child;        //孩子结点
        int temp;		  //临时变量
        /*对堆进行整理*/
        for (temp = a[i]; i * 2 + 1 < n; i = child)
        {
            child = i * 2 + 1; 								//当前结点的左孩子结点
            if (child != n - 1 && a[child] < a[child + 1])  //比较左孩子和右孩子谁大
                child++;
            if (temp < a[child])
                a[i] = a[child];//使a[i]是最小的 
            else
                break;
        }
        a[i] = temp;
    }
}