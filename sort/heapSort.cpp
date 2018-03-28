#include "heapSort.h"
#include <algorithm>
#include <functional>
using namespace std;

//使以start为根结点的子树成为一个大顶堆
void heapAdjust(vector<int>& arr, int start, int end)
{
    int temp = arr[start];
    for (int i = 2 * start; i <= end; i *= 2)   //沿取值较大的孩子结点向下筛选
    {
        if (i < end && arr[i] < arr[i + 1])
            ++i;                                //i为取值较大的元素对应的下标
        if (temp >= arr[i])                     //以start结点为根结点的子树已经是一个大顶堆
            break;
        arr[start] = arr[i];                    //将子结点中的较大值赋给根结点，然后沿该子结点继续调整（实际相当于交换这两个结点)
        start = i;
    }
    arr[start] = temp;
}

//对序列进行堆排序
void heapSort(vector<int>& arr)
{
    int size = arr.size();
    //构建大顶堆，从最后一个非叶子节点开始调整(i = size / 2 - 1，由完全二叉树的性质决定)
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        heapAdjust(arr, i, size - 1);
    }

    for (int i = size - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);   //交换堆顶元素（最大值）和最后一个元素
        heapAdjust(arr, 0, i - 1);  //将arr[0...i-1]重新调整为大顶堆
    }

}

//data的数据量为十亿级，需要从中选出最大的K(10000)个数，借助小顶堆实现
void getTopK(vector<float> data, vector<float>& topK, const int K)
{
    topK.resize(K);
    for (int i = 0; i < K; i++)
        topK[i] = rand() % K;
    make_heap(topK.begin(), topK.end(), greater<float>());  //构造小顶堆，所以要指定比较函数
    for (int i = 0; i < data.size(); i++)
    {
        if (data[i] > topK.front())
        {
            //将首部的最小元素和序列末尾元素交换（需手动删除），然后向下执行一次堆调整
            pop_heap(topK.begin(), topK.end(), greater<float>());
            topK.pop_back();                    //删除末尾最小元素
            topK.push_back(data[i]);            //在序列末尾增加元素
            push_heap(topK.begin(), topK.end(), greater<float>());      //向上执行一次堆调整
        }
    }
    sort_heap(topK.begin(), topK.end(), greater<float>());  //sort_heap()其实就是多次调用pop_heap()进行排序。
}