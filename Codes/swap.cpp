/*
描述: 交换a,b的数值
参数: a, b
返回值: 无
*/

// version 0
// bug: 不具备数据迁移,无法满足浮点数
/*
template<class T>
void swap(T& a, T& b)
{
    a ^= b;  // a = a xor b
    b ^= a;  // b = a xor b xor b = a
    a ^= b;  // a = a xor b xor a = b
}
*/

// version 1
template<class T>
void swap(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}


