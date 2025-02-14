/*
描述: 确认数组a,b不匹配的最小索引
参数: a, b数组, size数组大小
返回: 不匹配的最小索引, 如果完全匹配返回size
*/
template <typename T>
int mismatch(T a[], T b[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (a[i] != b[i])
        {
            return i;
        }
    }

    return size;
}