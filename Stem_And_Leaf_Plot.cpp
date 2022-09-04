#include <bits/stdc++.h>
using namespace std;

void printStemAndLeaf(vector<int> v, int splice)
{
    vector<int> onesVector;

    for (int i = 0; i < v.size(); i++)
    {
        onesVector.push_back(v[i] % 10);
    }

    int maximum = v[v.size() - 1];
    int maxOfRange = maximum - (maximum % splice) + (2 * splice) - 1;
    int minOfRange = maxOfRange - splice;

    int minimum = v[0];

    while (maxOfRange >= minimum)
    {
        if ((maxOfRange - maxOfRange % 10) / 10 >= 10)
        {
            cout << "\n"
                 << (maxOfRange - maxOfRange % 10) / 10 << " | ";
        }
        else
        {
            cout << "\n"
                 << (maxOfRange - maxOfRange % 10) / 10 << "  | ";
        }

        for (int i = 0; i < v.size(); i++)
        {
            if ((minOfRange < v[i]) && (v[i] <= maxOfRange))
            {
                cout << onesVector[i] << " ";
            }
        }
        maxOfRange -= splice;
        minOfRange -= splice;
    }

    cout << "\n\n";


    // calculating mean
    double mean = 0;
    for (int i = 0; i < v.size(); i++)
    {
        mean += v[i];
    }
    mean = mean / v.size();
    cout << "Mean: " << mean << "\n";


    //calculating median
    double median;
    if (v.size() % 2 == 0)
    {
        median = v[v.size() / 2 - 1] + v[v.size() / 2];
        median = median / 2;
    }
    else
    {
        median = v[v.size() / 2];
    }
    cout << "Median: " << median << "\n";
}

int main()
{

    int vecSize = 100;
    int maxRandomValue = 200;
    int splice = 5;

    cout << "Number of random values: " << vecSize << "\n";
    cout << "Maximum random value: " << maxRandomValue << "\n";
    cout << "Stem and Leaf Plot split every " << splice << " units"
         << "\n";

    srand(time(0));
    int randNumDivisor = RAND_MAX / maxRandomValue;

    vector<int> randomVec(vecSize);

    for (int i = 0; i < vecSize; i++)
    {
        randomVec[i] = (rand() / randNumDivisor);
    }

    sort(randomVec.begin(), randomVec.end());

    printStemAndLeaf(randomVec, splice);

    cout << "\n\n";
}