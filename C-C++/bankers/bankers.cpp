#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // # of processes
    int P = 5;

    // # of resources
    int R = 3;

    // Available instances of resources
    vector<int> Available = {3, 3, 2};

    // Maximum R that can be allocated
    // to processes
    vector<vector<int>> Maximum{{7, 5, 3},
                                {3, 2, 2},
                                {9, 0, 2},
                                {2, 2, 2},
                                {4, 3, 3}};

    // Resources currently allocated to processes
    vector<vector<int>> Allocation{{0, 1, 0},
                                   {2, 0, 0},
                                   {3, 0, 2},
                                   {2, 1, 1},
                                   {0, 0, 2}};

    // Required resources by each P
    vector<vector<int>> Need;

    // Fills Need array
    for (int i = 0; i < P; i++)
        for (int j = 0; j < R; j++)

            // Need of instance =
            // Max instance -
            // Allocated instance
            Need[i][j] = Maximum[i][j] -
                         Allocation[i][j];

    // Mark all processes as unfinished
    bool finish[P] = {0};

    // To store safe sequence
    vector<int> safeSequence;

    // Work
    vector<int> work;
    work = Available;

    // While all processes are not done
    // or system is not in safe state.
    while (1)
    {
        bool found = false;

        // Find a process which is not finish
        // and whose needs can be satisfied
        // with current work[] resources.
        for (int p = 0; p < P; p++)
        {
            // First check if a process is finished,
            // if no, go for next condition
            if (finish[p] == 0)
            {

                // Check if for all resources
                // of current P need is less
                // than work
                int j;
                for (j = 0; j < R; j++)
                    if (Need[p][j] > work[j])
                        break;

                // If all needs of p were satisfied.
                if (j == R)
                {
                    // Add the allocated resources of
                    // current P to the available/work
                    // resources i.e.free the resources
                    for (int k = 0; k < R; k++)
                        work[k] += Allocation[p][k];

                    // Add this process to safe sequence.
                    safeSequence.push_back(p);

                    // Mark this p as finished
                    finish[p] = 1;

                    found = true;
                }
            }
        }

        // If we could not find a next process
        // in safe sequence.
        if (found == false)
        {
            cout << "System is not in safe state";
            return false;
        }
    }

    // If system is in safe state then
    // safe sequence will be as below
    cout << "System is in safe state.\n"
         << "Safe sequence is: ";
    for (int i = 0; i < P; i++)
        cout << safeSequence[i] << " ";

    return 0;
}