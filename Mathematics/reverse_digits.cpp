#include <iostream>
#include <concepts>

template <std::integral T>
T reverseDigits(T n)
{
    T reversedNumber(0);

    while (n)
    {
        T digit = n % 10;
        reversedNumber = reversedNumber * 10 + digit;
        n /= 10;
    }
    return reversedNumber;
}

void reverseDigitsRecursive(int n, int &revNum, int &basePos)
{
    if (n > 0)
    {
        reverseDigitsRecursive(n / 10, revNum, basePos);
        revNum += (n % 10) * basePos;
        basePos *= 10;
    }
}

int main()
{

    int num(0);
    std::cout << "Please enter a number: ";
    std::cin >> num;

    std::cout << "The number " << num << " reversed is equal to " << reverseDigits(num) << std::endl;

    return 0;
}