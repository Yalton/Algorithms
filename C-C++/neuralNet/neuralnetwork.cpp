#include <iostream>
#include <vector>
#include <cmath>
#include"neuralnetwork.h"

NeuralNetwork::NeuralNetwork(vector<int> topology)
{
    int numLayers = topology.size();
    for (int layerNum = 0; layerNum < numLayers; ++layerNum)
    {
        m_layers.push_back(Layer());
        int numOutputs = layerNum == topology.size() - 1 ? 0 : topology[layerNum + 1];

        // We have a new layer
        for (int neuronNum = 0; neuronNum <= topology[layerNum]; ++neuronNum)
        {
            m_layers.back().push_back(Neuron(numOutputs, neuronNum));
            cout << "Made a neuron!" << endl;
        }
    }

    // Force the bias node's output value to 1.0 (it was the last neuron pushed in this layer)
    m_layers.back().back().setOutputVal(1.0);

    m_error = 0.0;
    m_recentAverageError = 0.0;
    m_recentAverageSmoothingFactor = 100.0; // Number of training samples to average over
}

void NeuralNetwork::feedForward(vector<double> inputVals)
{
    // Check the num of inputVals euqal to neuronNum expect bias
    assert(inputVals.size() == m_layers[0].size() - 1);

    // Assign (latch) the input values into the input neurons
    for (int i = 0; i < inputVals.size(); ++i)
    {
        m_layers[0][i].setOutputVal(inputVals[i]);
    }

    // Forward propagation
    for (int layerNum = 1; layerNum < m_layers.size(); ++layerNum)
    {
        Layer &prevLayer = m_layers[layerNum - 1];
        for (int neuronNum = 0; neuronNum < m_layers[layerNum].size() - 1; ++neuronNum)
        {
            m_layers[layerNum][neuronNum].feedForward(prevLayer);
        }
    }
}

void NeuralNetwork::backProp(vector<double> targetVals)
{
    // Calculate overall net error (RMS of output neuron errors)

    Layer &outputLayer = m_layers.back();
    m_error = 0.0;

    for (int n = 0; n < outputLayer.size() - 1; ++n)
    {
        double delta = targetVals[n] - outputLayer[n].getOutputVal();
        m_error += delta * delta;
    }
    m_error /= outputLayer.size() - 1; // get average error squared
    m_error = sqrt(m_error);           // RMS

                                       // Implement a recent average measurement

    m_recentAverageError =
        (m_recentAverageError * m_recentAverageSmoothingFactor + m_error)
        / (m_recentAverageSmoothingFactor + 1.0);

    // Calculate output layer gradients

    for (int n = 0; n < outputLayer.size() - 1; ++n)
    {
        outputLayer[n].calcOutputGradients(targetVals[n]);
    }

    // Calculate hidden layer gradients

    for (int layerNum = m_layers.size() - 2; layerNum > 0; --layerNum)
    {
        Layer &hiddenLayer = m_layers[layerNum];
        Layer &nextLayer = m_layers[layerNum + 1];

        for (int n = 0; n < hiddenLayer.size(); ++n)
        {
            hiddenLayer[n].calcHiddenGradients(nextLayer);
        }
    }

    // For all layers from outputs to first hidden layer,
    // update connection weights

    for (int layerNum = m_layers.size() - 1; layerNum > 0; --layerNum)
    {
        Layer &layer = m_layers[layerNum];
        Layer &prevLayer = m_layers[layerNum - 1];

        for (int n = 0; n < layer.size() - 1; ++n)
        {
            layer[n].updateInputWeights(prevLayer);
        }
    }
}


void NeuralNetwork:: updateInputWeights(std::vector<double> &inputWeights, std::vector<double> &deltas, double learningRate) {
    for (int i = 0; i < inputWeights.size(); i++) {
        inputWeights[i] += learningRate * deltas[i];
    }
}

void NeuralNetwork::getResults(vector<double> &resultVals) const
{
    resultVals.clear();

    for (int n = 0; n < m_layers.back().size() - 1; ++n)
    {
        resultVals.push_back(m_layers.back()[n].getOutputVal());
    }
}