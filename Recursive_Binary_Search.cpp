# include <iostream>
# include <vector>
# include <ctime>
using namespace std;


int recursiveBinarySearch (const vector <int> & array, int left, int right, int target, int & stepCount) 
{
    if (left > right) 
    {
        return -1;
    }
    int mid = (left + (right - left) / 2);
    stepCount++;
    if (array[mid] == target) 
    {
        return mid;
    }
    if (array[mid] > target) 
    {
        return recursiveBinarySearch (array, left, (mid - 1), target, stepCount);
    } else 
    {
        return recursiveBinarySearch (array, (mid + 1), right, target, stepCount);
    }
}

void measureSearchTime (const vector <int> & array, int target) 
{
    int stepCount = 0;
    clock_t start = clock();
    int length = (array.size() - 1);
    int result = recursiveBinarySearch (array, 0, length, target, stepCount);
    clock_t end = clock();
    double timeTaken = (double (end - start) / CLOCKS_PER_SEC);

    if (result != -1) 
    {
        cout << "Element found at Index :  " << result << endl;
    } 
    else 
    {
        cout << "Element not found !" << endl;
    }
    
    cout << "Time taken :  " << timeTaken << " seconds" << endl;
    cout << "Number of steps (comparisons) :  " << stepCount << endl;
}

vector <int> generateSortedArray (int size) 
{
    vector <int> array (size);
    for (int i = 0; i < size; i++) 
    {
        array[i] = (i * 10); 
    }
    return array;
}

int main() 
{
    vector <int> sizes = {10, 20, 30, 40};
    vector <int> stepCounts;
    vector <double> times;

    for (int size : sizes) 
    {
        vector <int> array = generateSortedArray (size);
        cout << "Best Case for size " << size << " (element at middle) :  " << endl;
        int target = array[size / 2];
        measureSearchTime(array, target);

        cout << "\nWorst Case for size " << size << " (element not found) :  " << endl;
        target = size * 5 + 1;
        measureSearchTime(array, target);

        cout << "\nAverage Case for size " << size << " (random element) :  " << endl;
        target = array[size / 3];
        measureSearchTime(array, target);

        cout << endl;
    }

    return 0;

}
