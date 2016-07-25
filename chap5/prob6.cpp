
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Print
{
public:
    Print () : count (1) {}
    void operator() (int a)
    {
        cout << a << " ";
        if (count++ % 10 == 0) 
            cout << endl;
    }
private:
    int count;
};

struct Predicate
{
public:
    Predicate (int p) {
        prime = p;
    }

    bool operator () (int v)
    {
        return v != prime && v % prime == 0; 
    }
private:
    int prime;
};

int main()
{
    vector<int> numbers;
    numbers.reserve(999);
    for (int i = 2; i <= 1000; i++)
    {
        numbers.push_back(i);
    }
    int prime_counter = 0;
    int prime_number;
    do
    {
        prime_number = numbers[prime_counter++];

        auto last = remove_if (numbers.begin(), numbers.end(), Predicate (prime_number));
        numbers.erase(last, numbers.end());
    }
    while (prime_number != *numbers.rbegin());


    for_each (numbers.begin(), numbers.end(), Print());
    cout << endl;
    return 0;
}
