#include "arithmetic.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


void readFile(string filePath, vector<string>& data)
{
    ifstream fileReader;
    fileReader.open(filePath, ios::in);
    while (!fileReader.eof())
    {
        string lineString;
        getline(fileReader, lineString);
        data.push_back(lineString);
    }
}

int main()
{
    string filePath = "data.txt";
    vector<string> data;
    readFile(filePath, data);
    for (int i = 0; i < data.size(); i++)
    {
        string postfix = InfixToPostfix(data[i]);
        cout << data[i] << endl;
        cout << postfix << endl;
        double result = caculate(postfix);
        cout << result << endl << endl;
    }
    return 0;
}