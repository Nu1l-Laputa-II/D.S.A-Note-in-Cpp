/**
 * @file currency.cpp
 * @brief 货币类的实现文件
 * @details 实现了一个表示美元货币的类，支持基本的货币操作
 * @author Nu1L
 * @date 2023
 */

#include <exception>
#include <iostream>
#include "./myExceptions.h"

/**
 * @brief 货币符号的枚举类型
 */
enum signType 
{
    plus,   ///< 正号
    minus   ///< 负号
};

/**
 * @brief 货币类
 * @details 用于表示和处理美元货币，支持美元和美分的存储与计算
 */
class currency
{
    public:
        /**
         * @brief 构造函数
         * @param theSign 货币符号，默认为正
         * @param theDollars 美元数，默认为0
         * @param theCents 美分数，默认为0
         */
        currency(signType theSign = plus, unsigned long theDollars = 0, unsigned int theCents = 0);
        
        /**
         * @brief 析构函数
         */
        ~currency() {}

        /**
         * @brief 设置货币值
         * @param theSign 货币符号
         * @param theDollars 美元数
         * @param theCents 美分数（必须小于100）
         * @throw illegalParameterValue 当美分数大于等于100时抛出异常
         */
        void setValue(signType, unsigned long, unsigned int);

        /**
         * @brief 通过浮点数设置货币值
         * @param theAmount 货币金额
         */
        void setValue(double);

        // getter 方法
        signType getSign() const { return sign; }      ///< 获取货币符号
        unsigned long getDollars() const { return dollars; }    ///< 获取美元数
        unsigned int getCents() const { return cents; }         ///< 获取美分数

        /**
         * @brief 货币加法运算
         * @param x 要相加的货币对象
         * @return 相加后的新货币对象
         */
        currency add(const currency& x) const;

        /**
         * @brief 货币减法运算
         * @param x 要相减的货币对象
         * @return 相减后的新货币对象
         * @details 从当前货币对象中减去参数货币对象
         */
        currency subtract(const currency& x) const;

        /**
         * @brief 货币增量运算
         * @param x 要增加的货币对象
         * @return 增加后的当前对象引用
         */
        currency& increment(const currency& x);

        /**
         * @brief 输出货币值
         * @details 按照标准格式输出，包括符号、美元符号、小数点和必要的前导零
         */
        void output() const;

        /**
         * @brief 从标准输入读取货币值
         * @details 接受格式为 "[$]d.cc" 或 "-[$]d.cc" 的输入，其中：
         *          - 可选的负号（-）表示负值
         *          - $ 是必需的美元符号
         *          - d 是美元数（整数部分）
         *          - cc 是美分数（小数部分）
         * @throw illegalParameterValue 当输入格式不正确时抛出异常
         */
        void input();
        
        private:
        signType sign;          ///< 货币符号
        unsigned long dollars;   ///< 美元数
        unsigned int cents;     ///< 美分数（0-99）
};

/**
 * @brief 构造函数的具体实现
 * @details 调用 setValue 函数设置初始值
 */
currency::currency(signType theSign, unsigned long theDollars, unsigned int theCents)
{
    setValue(theSign, theDollars, theCents);
}

/**
 * @brief 设置货币值的具体实现
 * @details 验证美分是否合法（小于100），并设置相应的属性值
 */
void currency::setValue(signType theSign, unsigned long theDollars, unsigned int theCents)
{
    if (theCents > 99)
    {
        throw illegalParameterValue("Cents should be < 100");
    }
    sign = theSign;
    dollars = theDollars;
    cents = theCents;
}

/**
 * @brief 通过浮点数设置货币值的具体实现
 * @details 处理正负号，并将浮点数转换为美元和美分
 */
void currency::setValue(double theAmount)
{
    if (theAmount < 0)
    {
        sign = minus;
        theAmount = - theAmount;
    }
    else
    {
        sign = plus;
    }

    dollars = (unsigned long) theAmount;
    cents = (unsigned int) ((theAmount + 0.001 - dollars) * 100);
}

/**
 * @brief 货币加法运算的具体实现
 * @details 将两个货币对象转换为以分为单位的整数进行计算，然后转回美元和美分
 */
currency currency::add(const currency& x) const
{
    long a1, a2, a3;
    currency result;

    a1 = dollars * 100 + cents;
    if (sign == minus) a1 = -a1;

    a2 = x.dollars * 100 + x.cents;
    if (x.sign == minus) a2 = -a2;

    a3 = a1 + a2;
    if (a3 < 0)
    {
        result.sign = minus;
        a3 = -a3;
    }
    else
    {
        result.sign = plus;
    }

    result.dollars = a3 / 100;
    result.cents = a3 - result.dollars * 100;

    return result;
}

/**
 * @brief 货币增量运算的具体实现
 * @details 调用 add 函数进行加法运算，并更新当前对象
 */
currency& currency::increment(const currency& x)
{
    *this = add(x);

    return *this;
}

/**
 * @brief 格式化输出货币值的具体实现
 * @details 按照标准格式输出：符号 + $ + 美元数 + . + 美分数（带前导零）
 */
void currency::output() const
{
    if (sign == minus)
    {
        std::cout << '-';
    }

    std::cout << '$' << dollars << '.';

    if (cents < 10)
    {
        std::cout << '0';
    }

    std::cout << cents;
}

/**
 * @brief 从标准输入读取货币值的具体实现
 * @details 按照指定格式读取输入并验证：
 *          1. 检查可能存在的负号
 *          2. 验证美元符号
 *          3. 读取并验证数值部分
 *          4. 设置最终的货币值
 */
void currency::input()
{
    char ch;
    double amount = 0.0;
    bool isNegative = false;
    
    // 检查是否有负号
    std::cin >> ch;
    if (ch == '-') 
    {
        isNegative = true;
        std::cin >> ch;
    }
    
    // 验证美元符号
    if (ch != '$')
        throw illegalParameterValue("No dollar sign");

    // 读取金额
    std::cin >> amount;
    if (amount < 0)
        throw illegalParameterValue("Invalid amount format");

    // 设置货币值，考虑符号
    setValue(isNegative ? -amount : amount);
}

/**
 * @brief 货币减法运算的具体实现
 * @details 将两个货币对象转换为以分为单位的整数进行计算：
 *          1. 转换两个操作数为以分为单位的整数
 *          2. 执行减法运算
 *          3. 处理结果的符号
 *          4. 转换回美元和美分格式
 */
currency currency::subtract(const currency& x) const
{
    long a1, a2, a3;
    currency result;

    a1 = dollars * 100 + cents;
    a2 = x.dollars * 100 + x.cents;

    if (a1 < 0) a1 = -a1;
    if (a2 < 0) a2 = -a2;

    a3 = a1 - a2;

    if (a3 < 0)
    {
        result.sign = minus;
        a3 = -a3;
    }
    else
    {
        result.sign = plus;
    }

    result.dollars = a3 / 100;
    result.cents = a3 - result.dollars * 100;

    return result;
}





