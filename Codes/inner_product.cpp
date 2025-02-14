/*
描述: 两个数组的内积
参数: a, b: 数组
      size_a, size_b: 数组大小
返回值: 内积
*/
template<class T>
T inner_product(T a[], T b[], int size_a, int size_b)
{
    if (size_a != size_b) {
        throw std::invalid_argument("Arrays must have the same size");
    }

    T sum = 0;
    for (int i = 0; i < size_a; i++)
    {
        sum += a[i] * b[i];
    }

    return sum;
}