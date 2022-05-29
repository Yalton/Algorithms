#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Struct to represent an arm in the bandit problem
struct Arm
{
    double value;
};

int main()
{
    // Set up the bandit problem
    vector<Arm> arms = {
        {0.2},
        {0.4},
        {0.6},
        {0.8}};

    // Parameters
    int T = 1000;         // number of timesteps
    double epsilon = 0.1; // amount to decrease/increase values

    // Run the hedge algorithm
    for (int t = 0; t < T; t++)
    {
        // Find the arm with the highest value
        int best_arm = 0;
        for (int i = 1; i < arms.size(); i++)
        {
            if (arms[i].value > arms[best_arm].value)
            {
                best_arm = i;
            }
        }

        // Choose the arm with the highest value
        cout << "t = " << t << "  arm = " << best_arm << endl;

        // Update the values of the arms
        for (int i = 0; i < arms.size(); i++)
        {
            if (i == best_arm)
            {
                // decrease the value of the chosen arm
                arms[i].value -= epsilon;
            }
            else
            {
                // increase the value of the other arms
                arms[i].value += epsilon;
            }
        }
    }

    return 0;
}