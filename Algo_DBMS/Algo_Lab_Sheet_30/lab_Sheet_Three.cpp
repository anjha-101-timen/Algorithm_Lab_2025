
# include <iostream>
# include <vector>
# include <algorithm>
# include <cstdlib>
# include <ctime>
using namespace std;

// Recursive Binary Search Function
int recursiveBinarySearch (const vector <int> & array, int low, int high, int target)
{
    if (low > high)
    {
        return -1; // Element not found
    }

    int mid = low + (high - low) / 2; // Avoids potential overflow
    if (array [mid] == target)
    {
        return mid; // Element found at mid
    }
    else if (array [mid] > target)
    {
        return recursiveBinarySearch (array, low, (mid - 1), target); // Search left half
    }
    else
    {
        return recursiveBinarySearch (array, (mid + 1), high, target); // Search right half
    }
}

// Measure time taken for different input sizes
void measureTime ()
{
    vector <int> inputSizes = {100, 500, 1000, 5000, 10000, 50000, 100000};

    for (int size : inputSizes)
    {
        // Generate a sorted list of random numbers
        vector <int> array (size);
        srand (time(0)); // Seed for random numbers
        for (int i = 0; i < size; i++)
        {
            array [i] = rand() % 100000 + 1; // Random values between 1 and 100000
        }
        sort (array.begin(), array.end()); // Sort the array

        // Choose a random target element
        int target = array [rand() % size];

        // Measure execution time
        clock_t start_time = clock ();
        int result = recursiveBinarySearch (array, 0, (size - 1), target);
        clock_t end_time = clock ();
        double elapsed_time = double (end_time - start_time) / CLOCKS_PER_SEC;

        cout << "Input Size :  " << size
             << ", Target :  " << target
             << ", Index :  " << result
             << ", Time Taken :  " << elapsed_time << " seconds" << endl;
    }
}

// Main function
int main()
{
    measureTime();
    return 0;
}
