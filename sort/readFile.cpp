

#include "readFile.h"

/*
*对字符串inputString按tag字符分割
*返回vector<string>格式的一维向量
*/
vector<string> split(string inputString, char tag)
{
    int length = inputString.length();
    int start = 0;//数值起始下标
    vector<string> line;
    for (int i = 0; i<length; i++)
    {
        if (inputString[i] == tag)
        {//遇到tag字符
            string sub = inputString.substr(start, i - start);    //取inputString[start]-inputString[i]子串
            line.push_back(sub);//压入向量中
            start = i + 1;
        }
        else if (i == length - 1)
        {
            string sub = inputString.substr(start, i - start + 1);//最后一个字符没有标点，需单独处理
            line.push_back(sub);//压入向量中
        }
    }
    return line;
}

/*
*读取绝对路径为filePath的文件，文件中每行中的数值以tag字符分开
*返回字节数
*/
int readFile(char tag, string filePath, vector<vector<int>>& data)
{
    ifstream fileReader;
    fileReader.open(filePath, ios::in);//以只读方式打开
    vector<vector<string>> vecData;//以2维向量的形势保持整个文件
    int i = 0, j = 0;
    while (!fileReader.eof())
    {//未到文件末尾    
        string linestring;
        getline(fileReader, linestring);//读取一行
        vector<string> line = split(linestring, tag);//分割每行,并放在line向量中    
        j = 0;
        vector<int> tmpData;
        for (vector<string>::iterator iter = line.begin(); iter != line.end(); iter++)
        {
            const char* tmpstr = iter->c_str();
            tmpData.push_back(atoi(tmpstr));
            //cout << atoi(tmpstr) << " ";
            j++;
        }
        //cout << endl;
        data.push_back(tmpData);
        //vecData.push_back(line);
        i++;
    }
    //return vecData;
    return i + 1;
}

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


