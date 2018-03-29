#include "quickSort.h"
#include "mergeSort.h"
#include "bubbleSort.h"
#include "selectSort.h"
#include "insertSort.h"
#include "shellSort.h"
#include "heapSort.h"
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generateData()
{
    const int num = 20;
    vector<vector<int>> data(num);
    fstream file;
    string filePath = "data.txt";
    file.open(filePath);
    for (int i = 0; i < num; i++)
    {
        int size = 5 + rand() % 50;
        data[i].resize(size);
        for (int j = 0; j < size; j++)
        {
            data[i][j] = -100 + rand() % 200;
            file << data[i][j] << " ";
        }
        file << endl;
    }
    return data;
    file.close();
}

//算法测试
int main()
{
    vector<vector<int>> data = generateData();
    for (int i = 0; i < data.size(); i++)
    {
        heapSort(data[i]);
    }
    for (int i = 0; i < data.size(); i++)
    {
        for (int j = 0; j < data[i].size(); j++)
        {
            cout << data[i][j] << " ";
        }
        cout << endl << endl;
    }
    return 0;
}