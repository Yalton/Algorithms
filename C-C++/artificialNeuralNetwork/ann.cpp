#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>

using namespace std;

class NeuralNetwork
{
public:
    NeuralNetwork(int nInputs, int nHidden, int nOutputs);
    void feedForward(vector<double> inputs);
    void backPropagate(vector<double> targets);
    void setLearningRate(double lr);
    void setActivationFunction(int af);
    vector<double> getOutputs();

private:
    int nInputs;
    int nHidden;
    int nOutputs;
    double learningRate;
    int activationFunction;
    vector<vector<double>> weightsInputHidden;
    vector<vector<double>> weightsHiddenOutput;
    vector<double> outputs;
    vector<double> inputs;
    vector<double> hidden;
    vector<double> errorsOutput;
    vector<double> errorsHidden;
};

NeuralNetwork::NeuralNetwork(int nInputs, int nHidden, int nOutputs)
{
    this->nInputs = nInputs;
    this->nHidden = nHidden;
    this->nOutputs = nOutputs;

    this->outputs.resize(nOutputs);
    this->inputs.resize(nInputs);
    this->hidden.resize(nHidden);
    this->errorsOutput.resize(nOutputs);
    this->errorsHidden.resize(nHidden);

    this->weightsInputHidden.resize(nInputs);
    for (int i = 0; i < this->weightsInputHidden.size(); i++)
    {
        this->weightsInputHidden[i].resize(nHidden);
    }

    this->weightsHiddenOutput.resize(nHidden);
    for (int i = 0; i < this->weightsHiddenOutput.size(); i++)
    {
        this->weightsHiddenOutput[i].resize(nOutputs);
    }

    for (int i = 0; i < this->nInputs; i++)
    {
        for (int j = 0; j < this->nHidden; j++)
        {
            this->weightsInputHidden[i][j] = rand() / double(RAND_MAX);
        }
    }

    for (int i = 0; i < this->nHidden; i++)
    {
        for (int j = 0; j < this->nOutputs; j++)
        {
            this->weightsHiddenOutput[i][j] = rand() / double(RAND_MAX);
        }
    }

    this->learningRate = 0.1;
    this->activationFunction = 1;
}

void NeuralNetwork::feedForward(vector<double> inputs)
{
    this->inputs = inputs;

    for (int i = 0; i < this->nHidden; i++)
    {
        this->hidden[i] = 0.0;
        for (int j = 0; j < this->nInputs; j++)
        {
            this->hidden[i] += this->inputs[j] * this->weightsInputHidden[j][i];
        }
        this->hidden[i] = this->activation(this->hidden[i]);
    }

    for (int i = 0; i < this->nOutputs; i++)
    {
        this->outputs[i] = 0.0;
        for (int j = 0; j < this->nHidden; j++)
        {
            this->outputs[i] += this->hidden[j] * this->weightsHiddenOutput[j][i];
        }
        this->outputs[i] = this->activation(this->outputs[i]);
    }
}

void NeuralNetwork::backPropagate(vector<double> targets)
{
    for (int i = 0; i < this->nOutputs; i++)
    {
        this->errorsOutput[i] = targets[i] - this->outputs[i];
        this->errorsOutput[i] *= this->activationDerivative(this->outputs[i]);
    }

    for (int i = 0; i < this->nHidden; i++)
    {
        this->errorsHidden[i] = 0.0;
        for (int j = 0; j < this->nOutputs; j++)
        {
            this->errorsHidden[i] += this->errorsOutput[j] * this->weightsHiddenOutput[i][j];
        }
        this->errorsHidden[i] *= this->activationDerivative(this->hidden[i]);
    }

    for (int i = 0; i < this->nHidden; i++)
    {
        for (int j = 0; j < this->nOutputs; j++)
        {
            this->weightsHiddenOutput[i][j] += this->learningRate * this->outputs[j] * this->errorsOutput[i];
        }
    }

    for (int i = 0; i < this->nInputs; i++)
    {
        for (int j = 0; j < this->nHidden; j++)
        {
            this->weightsInputHidden[i][j] += this->learningRate * this->inputs[i] * this->errorsHidden[j];
        }
    }
}

void NeuralNetwork::setLearningRate(double lr)
{
    this->learningRate = lr;
}

void NeuralNetwork::setActivationFunction(int af)
{
    this->activationFunction = af;
}

vector<double> NeuralNetwork::getOutputs()
{
    return this->outputs;
}

double NeuralNetwork::activation(double x)
{
    if (this->activationFunction == 1)
    { // Sigmoid
        return 1.0 / (1.0 + exp(-x));
    }
    else if (this->activationFunction == 2)
    { // Tanh
        return tanh(x);
    }
    else if (this->activationFunction == 3)
    { // ReLU
        if (x < 0)
        {
            return 0.0;
        }
        return x;
    }
}

double NeuralNetwork::activationDerivative(double x)
{
    if (this->activationFunction == 1)
    { // Sigmoid
        return x * (1.0 - x);
    }
    else if (this->activationFunction == 2)
    { // Tanh
        return 1 - x * x;
    }
    else if (this->activationFunction == 3)
    { // ReLU
        if (x < 0)
        {
            return 0.0;
        }
        return 1.0;
    }
}

int main()
{
    NeuralNetwork nn(2, 2, 1);

    vector<double> inputs{1.0, 2.0};
    vector<double> targets{3.0};

    nn.feedForward(inputs);
    nn.backPropagate(targets);
    vector<double> outputs = nn.getOutputs();

    for (int i = 0; i < outputs.size(); i++)
    {
        cout << outputs[i] << endl;
    }
}