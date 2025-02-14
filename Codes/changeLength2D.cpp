#include <algorithm>  // 添加 min 函数头文件
/**
 * @brief 调整二维数组的大小
 * 
 * @tparam T 数组元素类型的模板参数
 * @param a 待调整大小的二维数组指针的引用
 * @param oldHeight 原数组的高度/行数
 * @param newHeight 新数组的高度/行数
 * @param oldLength 原数组的长度/列数
 * @param newLength 新数组的长度/列数
 * @throws const char* 如果newLength或newHeight为负数则抛出异常
 * 
 * @details 该函数的功能:
 * 1. 创建具有指定新维度的二维数组
 * 2. 将原数组中的元素复制到新数组
 * 3. 删除原数组
 * 4. 更新指针指向新数组
 * 
 * 只复制原数组和新数组重叠部分的元素。
 * 新数组中剩余的元素(如果有)将使用默认值初始化。
 */
template<class T>
void changeLength2D(T** &a, int oldHeight, int newHeight, int oldLength, int newLength)
{
    if (newHeight <= 0 || newLength <= 0) 
    {
        throw "new length and height must be greater than 0";
    }
    

    int numberofHeight = std::min(oldHeight, newHeight);
    int numberofLength = std::min(oldLength, newLength);

    T** temp = new T*[newHeight];
    for(int i = 0; i < newHeight; i++)
    {
        temp[i] = new T[newLength];
    }

    for(int i = 0; i < numberofHeight; i++)
    {
        for(int j = 0; j < numberofLength; j++)
        {
            temp[i][j] = a[i][j];
        }
    }

    for(int i = 0; i < oldHeight; i++)
    {
        delete[] a[i];
    }
    delete[] a;
    
    a = temp;
}