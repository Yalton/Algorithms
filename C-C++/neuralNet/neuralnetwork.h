#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class NeuralNetwork
{
public:
    NeuralNetwork(vector<int> topology);
    void feedForward(vector<double> inputVals);
    void backProp(vector<double> targetVals);
    void getResults(vector<double> &resultVals) const;

private:
    vector<Layer> m_layers; // m_layers[layerNum][neuronNum]
    double m_error;
    double m_recentAverageError;
    double m_recentAverageSmoothingFactor;
};