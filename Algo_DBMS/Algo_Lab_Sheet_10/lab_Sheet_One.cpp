
# include <iostream>
# include <vector>
# include <algorithm>
# include <cstdlib>
# include <ctime>
using namespace std;

// Bubble Sort
int bubble_sort (vector <int> & array)
{
    int k = array.size();
    int step_count = 0;
    for (int i = 0; i < k; ++i)
    {
        bool swapped = false;
        for (int j = 0; j < (k - i - 1); ++j)
        {
            step_count++; // Comparison
            if (array [j] > array [j + 1])
            {
                swap(array [j], array [j + 1]);
                step_count++; // Swap
                swapped = true;
            }
        }
        if (!swapped) break;
    }
    return step_count;
}

// Selection Sort
int selection_sort (vector <int> & array)
{
    int k = array.size();
    int step_count = 0;
    for (int i = 0; i < k; ++i)
    {
        int min_idx = i;
        for (int j = (i + 1); j < k; ++j)
        {
            step_count++; // Comparison
            if (array [j] < array [min_idx])
            {
                min_idx = j;
            }
        }
        if (min_idx != i)
        {
            swap(array [i], array [min_idx]);
            step_count++; // Swap
        }
    }
    return step_count;
}

// Insertion Sort
int insertion_sort (vector <int> & array)
{
    int k = array.size();
    int step_count = 0;
    for (int i = 1; i < k; ++i)
    {
        int key = array[i];
        int j = (i - 1);
        while ((j >= 0) && (array [j] > key))
        {
            step_count++; // Comparison
            array [j + 1] = array [j];
            step_count++; // Assignment
            --j;
        }
        array [j + 1] = key;
        step_count++; // Assignment
    }
    return step_count;
}

// Function to measure step counts for different input sizes
void measure_step_counts ()
{
    vector <int> input_sizes = {10, 20, 50};
    vector <string> algorithms = {"Bubble Sort", "Selection Sort", "Insertion Sort"};
    vector <string> cases = {"Best", "Worst", "Average"};

    // Results storage
    vector <vector <int> > bubble_results (3, vector <int> ());
    vector <vector <int> > selection_results (3, vector <int> ());
    vector <vector <int> > insertion_results (3, vector <int> ());

    for (int size : input_sizes)
    {
        // Generate test cases
        vector <int> best_case (size);
        vector <int> worst_case (size);
        vector <int> average_case (size);
        // Best case: Already sorted
        for (int i = 0; i < size; ++i) best_case [i] = (i + 1);
        // Worst case: Reverse sorted
        for (int i = 0; i < size; ++i) worst_case [i] = (size - i);
        // Average case: Randomized
        srand (time (0));
        for (int i = 0; i < size; ++i) average_case [i] = rand() % 100 + 1;

        // Bubble Sort
        bubble_results [0].push_back (bubble_sort (best_case));
        bubble_results [1].push_back (bubble_sort (worst_case));
        bubble_results [2].push_back (bubble_sort (average_case));

        // Selection Sort
        selection_results [0].push_back (selection_sort (best_case));
        selection_results [1].push_back (selection_sort (worst_case));
        selection_results [2].push_back (selection_sort (average_case));

        // Insertion Sort
        insertion_results [0].push_back (insertion_sort (best_case));
        insertion_results [1].push_back (insertion_sort (worst_case));
        insertion_results [2].push_back (insertion_sort (average_case));
    }

    // Print results
    cout << "Bubble Sort : \n";
    for (int i = 0; i < 3; ++i)
    {
        cout << cases [i] << " :  ";
        for (int count : bubble_results[i]) cout << count << " ";
        cout << endl;
    }

    cout << "\nSelection Sort : \n";
    for (int i = 0; i < 3; ++i)
    {
        cout << cases [i] << " :  ";
        for (int count : selection_results[i]) cout << count << " ";
        cout << endl;
    }

    cout << "\nInsertion Sort : \n";
    for (int i = 0; i < 3; ++i)
    {
        cout << cases [i] << " :  ";
        for (int count : insertion_results[i]) cout << count << " ";
        cout << endl;
    }
}

int main()
{
    measure_step_counts();
    return 0;
}
