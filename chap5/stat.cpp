
#include <cmath>
#include "stat.h"

double stddev(Vector<double> & data)
{
    double avg = mean(data);
    double standev = 0;
    for (int i = 0; i < data.size(); i++)
    {
        standev += (avg - data[i]) * (avg - data[i]);
    }
    standev /= data.size();
    standev = sqrt(standev);
    return standev;
}

double mean(Vector<double> & data)
{
    double sum = 0;
    for (int i = 0; i < data.size(); i++)
    {
        sum += data[i];
    }
    sum /= data.size();
    return sum;
}
