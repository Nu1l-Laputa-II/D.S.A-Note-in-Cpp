/*
描述: 改变数组的长度
参数: a: 数组, oldLength: 旧长度, newLength: 新长度
返回值: 无
*/
template<class T>
void changeLength1D(T* &a, int oldLength, int newLength)
{
    if(newLength < 0)  // 新长度不能为负
    {
        throw "new length must be >= 0";
    }

    T* temp = new T[newLength];  // 创建新数组
    int number = min(oldLength, newLength);  // 计算复制元素的个数
    for(int i = 0; i < number; i++)  // 复制元素
    {
        temp[i] = a[i];
    }

    delete [] a;  // 删除旧数组

    a = temp;  // 使a指向新数组
}