

#include <cassert>
#include "vector.h"

bool isMeasurable(int target, Vector<int> weights);

int main()
{
    Vector<int> sampleWeights;
    sampleWeights += 1, 3;
    assert(isMeasurable(2, sampleWeights) == true);
    assert(isMeasurable(5, sampleWeights) == false);
    return 0;
}

bool isMeasurable(int target, Vector<int> weights)
{
    if (weights.size() == 0) return target == 0;
    int x = weights[0];
    weights.remove(0);
    return isMeasurable(target, weights) || isMeasurable(target - x, weights) || isMeasurable(target + x, weights);
}
