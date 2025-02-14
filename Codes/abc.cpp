int abc(int a, int b, int c)
{
    if (a <0 && b < 0 && c < 0)
    {
        throw 1;
    }
    else if (a == 0 && b == 0 && c == 0)
    {
        throw 2;
    }
    else
    {
        return a + b * c;
    }
}

#include <iostream>

int main()
{
    using namespace std;

    int a, b, c;
    cin >> a >> b >> c;

    try
    {
        cout << abc(a, b, c) << endl;
    }
    catch (int e)
    {
        cout << "Error: ";
        if (e == 1)
        {
            cout << "All numbers are negative." << endl;
        }
        else if (e == 2)
        {
            cout << "All numbers are zero." << endl;
        }
    }

    return 0;
}