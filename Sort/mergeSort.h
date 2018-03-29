#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr, int left, int mid, int right, vector<int>& temp);
void MSort(vector<int>& arr, int left, int right, vector<int>& temp);
void mergeSort(vector<int>& arr);
void mergeSortIter(vector<int>& arr);