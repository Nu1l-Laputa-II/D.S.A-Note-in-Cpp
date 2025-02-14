/*
描述: 创建一个二维数组, 该数组的行数为numberofRows, 每一行的列数为numberofColumns[i]
参数: 
    T ** &x: 二维数组的引用
    int numberofRows: 行数
    int numberofColumns[]: 每一行的列数
返回值: 无
*/
template<class T>
void make2dArray(T ** &x, int numberofRows, int numberofColumns[])
{
    // 创建行指针数组
    x = new T * [numberofColumns];

    // 为每一行分配空间
    for(int i = 0; i < numberofRows; i++)
    {
        x[i] = new T[numberofColumns[i]];
    }
}