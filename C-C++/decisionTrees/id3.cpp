#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

// A struct to represent a node in the decision tree
struct Node
{
    string label;
    Node *left;
    Node *right;
};

// A struct to represent a data point
struct DataPoint
{
    vector<string> features;
    string label;
};

// Calculates the entropy of a given data set
double entropy(vector<DataPoint> data)
{
    // YOUR CODE HERE
}

// Calculates the information gain of a given feature
double informationGain(vector<DataPoint> data, string feature)
{
    // YOUR CODE HERE
}

// Builds the ID3 decision tree
Node *buildTree(vector<DataPoint> data)
{
    // YOUR CODE HERE
}

// Prints the decision tree in a human-readable format
void printTree(Node *root, int depth)
{
    // YOUR CODE HERE
}

int main()
{
    // Read in the data
    int numFeatures;
    cin >> numFeatures;

    vector<string> featureNames;
    for (int i = 0; i < numFeatures; i++)
    {
        string featureName;
        cin >> featureName;
        featureNames.push_back(featureName);
    }

    int numDataPoints;
    cin >> numDataPoints;

    vector<DataPoint> data;
    for (int i = 0; i < numDataPoints; i++)
    {
        DataPoint datapoint;
        for (int j = 0; j < numFeatures; j++)
        {
            string feature;
            cin >> feature;
            datapoint.features.push_back(feature);
        }
        cin >> datapoint.label;
        data.push_back(datapoint);
    }

    // Build the tree
    Node *root = buildTree(data);

    // Print the tree
    printTree(root, 0);

    return 0;
}