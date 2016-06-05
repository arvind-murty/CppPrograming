

#include <iostream>
using namespace std;


int num_digits(int n)
{
    int digits = 1;
    while (n / 10 > 0)
    {
        ++digits;
        n /= 10;
    }
    return digits;
}


int power_of_ten(int n)
{
    int product = 1;
    while (n > 0)
    {
        product *= 10;
        --n;
    }
    return product;
}


int reverse(int n)
{
    int power = num_digits(n) - 1;
    int reversal = 0;
    while (power >= 0)
    {
        reversal += (n % 10) * power_of_ten(power);
        n /= 10;
        --power;
    }
    return reversal;
}


int main()
{
    int n;
    cout << "This program reverses the digits in an integer." << endl;
    cout << "Enter a positive integer: ";
    cin >> n;
    int reversal = reverse(n);
    cout << "The reversed integer is " << reversal << endl;
    return 0;
}
