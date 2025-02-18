
#include <iostream>
#include <vector>
#include <climits>
#include <ctime>
using namespace std;

int matrixChainMultiplication(const vector <int> & array)
{
    int h = array.size();
    // Create a DP table to store results of subproblems
    vector <vector <int> > dp(h, vector <int> (h, 0));

    // Solve subproblems for chains of length (from 2 to n-1)
    for (int l = 2; (l < h); l++)
    { // l is the chain length
        for (int i = 1; i < (h - l + 1); i++)
        {
            int j = (i + l - 1);
            dp[i][j] = INT_MAX; // Initialize with infinity
            for (int k = i; k < j; k++)
            {
                // Calculate cost of splitting at k
                int cost = (dp[i][k] + dp[k + 1][j] + array[i - 1] * array[k] * array[j]);
                if (cost < dp[i][j])
                {
                    dp[i][j] = cost;
                }
            }
        }
    }
    return dp[1][h - 1]; // Result for the full chain
}

// Function to measure time taken for different input sizes
void measureTime ()
{
    vector <int> inputSizes = {3, 4, 5, 6, 7, 8, 9, 10};

    for (int size : inputSizes)
    {
        // Generate random matrix dimensions
        vector <int> array (size);
        srand (time(0)); // Seed for random numbers
        for (int i = 0; i < size; i++)
        {
            array [i] = rand () % 90 + 10; // Random values between 10 and 100
        }

        // Measure execution time
        clock_t start_time = clock ();
        int result = matrixChainMultiplication(array);
        clock_t end_time = clock();
        double elapsed_time = double (end_time - start_time) / CLOCKS_PER_SEC;

        cout << "Input Size :  " << size
             << ", Time Taken :  " << elapsed_time << " seconds"
             << ", Result :  " << result << endl;
    }
}

int main()
{
    measureTime();
    return 0;
}

