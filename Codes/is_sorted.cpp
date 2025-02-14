/*
描述：判断数组是否有序
参数：a：数组，n：数组长度
返回值：如果数组有序，返回true，否则返回false
*/
template<class T>
bool is_sorted(T a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] > a[i + 1])
        {
            return false;
        }
    }

    return true;
}