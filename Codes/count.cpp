/*
描述计算数组中某个值出现的次数
参数：a：数组，n：数组长度，value：要查找的值
返回值：value出现的次数
*/
template<class T>
int count(T a[], int n, T value)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == value)
        {
            count++;
        }
    }

    return count;
}