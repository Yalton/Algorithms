#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Struct to represent a data point
struct DataPoint
{
    double x, y;
    int label;
};

// Function to calculate the distance between two data points
double distance(DataPoint p1, DataPoint p2)
{
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return sqrt(dx * dx + dy * dy);
}

// Function to find the K nearest neighbors of a data point
vector<DataPoint> find_neighbors(vector<DataPoint> &points, DataPoint p, int K)
{
    // Sort the points by distance from p
    sort(points.begin(), points.end(), [&](DataPoint p1, DataPoint p2)
         { return distance(p1, p) < distance(p2, p); });

    // Return the K nearest neighbors
    vector<DataPoint> neighbors;
    for (int i = 0; i < K; i++)
    {
        neighbors.push_back(points[i]);
    }
    return neighbors;
}

// Function to find the most common label among a set of data points
int find_label(vector<DataPoint> &points)
{
    // Count the number of points with each label
    int counts[3] = {0, 0, 0};
    for (int i = 0; i < points.size(); i++)
    {
        counts[points[i].label]++;
    }

    // Return the label with the most points
    if (counts[0] > counts[1] && counts[0] > counts[2])
        return 0;
    if (counts[1] > counts[0] && counts[1] > counts[2])
        return 1;
    return 2;
}

int main()
{
    // Create some data points
    vector<DataPoint> points = {
        {1, 2, 0},
        {2, 1, 0},
        {2, 2, 0},
        {1, 1, 1},
        {2, 3, 1},
        {3, 2, 1},
        {3, 3, 1},
        {4, 4, 2},
        {5, 4, 2},
        {4, 5, 2}};

    // Choose a value for K
    int K = 5;

    // Find the K nearest neighbors of the point (4, 4)
    DataPoint p = {4, 4};
    vector<DataPoint> neighbors = find_neighbors(points, p, K);

    // Find the most common label among the neighbors
    int label = find_label(neighbors);

    // Print the label
    cout << "Label: " << label << endl;

    return 0;
}