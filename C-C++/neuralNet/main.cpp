#include <iostream>
#include <utility>
#include <string>
#include <cstring>
#include <vector>
#include"neuralnetwork.h"

using namespace std;
int main()
{
    // e.g., {3, 2, 1}
    vector<int> topology;
    topology.push_back(3);
    topology.push_back(2);
    topology.push_back(1);
    NeuralNetwork nn(topology);

    vector<double> inputVals;
    nn.feedForward(inputVals);

    vector<double> targetVals;
    nn.backProp(targetVals);

    vector<double> resultVals;
    nn.getResults(resultVals);
}