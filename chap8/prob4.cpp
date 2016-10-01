

#include <cassert>
#include <iostream>
#include "set.h"
using namespace std;

int countSubsetSumWays(Set<int> set, int target);

int main()
{
    Set<int> sampleSet;
    sampleSet += 1, 3, 4, 5;
    assert(countSubsetSumWays(sampleSet, 11) == 0);
    assert(countSubsetSumWays(sampleSet, 5) == 2);
    return 0;
}

int countSubsetSumWays(Set<int> set, int target)
{
    if (set.isEmpty()) return 0;
    int result = 0;
    int num = set.first();
    if (num == target) ++result;
    set.remove(num);
    result += countSubsetSumWays(set, target - num);
    result += countSubsetSumWays(set, target);
    return result;
}
