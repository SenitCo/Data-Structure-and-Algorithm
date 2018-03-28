#include "shellSort.h"

void shellSort1(vector<int>& arr)
{
    int size = arr.size();
    int i, j, step;
    for (step = size / 2; step > 0; step /= 2)
    {
        for (i = 0; i < step; i++)
        {
            for (j = i + step; j < size; j += step)
            {
                if (arr[j] < arr[j - step])
                {
                    int temp = arr[j];
                    int k = j - step;
                    for (; k >= 0 && arr[k] > temp; k -= step)
                        arr[k + step] = arr[k];
                    arr[k + step] = temp;
                }
            }
        }
    }
}

void shellSort2(vector<int>& arr)
{
    int size = arr.size();
    int j, step;
    for (step = size / 2; step > 0; step /= 2)
    {
        for (j = step; j < size; j++)
        {
            if (arr[j] < arr[j - step])
            {
                int temp = arr[j];
                int k = j - step;
                for (; k >= 0 && arr[k] > temp; k -= step)
                    arr[k + step] = arr[k];
                arr[k + step] = temp;
            }
        }
    }
}

void shellSort3(vector<int>& arr)
{
    int size = arr.size();
    int j, step;
    for (step = size / 2; step > 0; step /= 2)
    {
        for (j = step; j < size; j++)
        {
            for (int k = j - step; k >= 0 && arr[k] > arr[k + step]; k -= step)
                swap(arr[k], arr[k + step]);
        }
    }
}