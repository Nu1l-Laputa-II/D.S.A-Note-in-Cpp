/*
描述: fill函数用于将数组中的元素赋值为指定的值
参数: a[]: 数组
      start: 起始位置
      end: 结束位置
      size: 数组大小
      value: 赋值的值
返回值: 无
*/
template<class T>
void fill(T a[], int start, int end, int size, T value)
{
    if (start < 0 || end > size || start > end) {
        throw std::out_of_range("Invalid array bounds");
    }
    for (int i = start; i < end; i++)
    {
        a[i] = value;
    }
}