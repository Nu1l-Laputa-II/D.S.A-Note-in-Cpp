/*
描述: 将数组a的前n个元素赋值为value, value, value+1, value+2, ...
参数: a: 数组, n: 数组长度, value: 赋值的起始值
返回值: 无
*/
template <typename T>
void iota(T a[], int n, T value)
{
    for (int i = 0; i < n; i++)
    {
        a[i] = value + i;
    }
}