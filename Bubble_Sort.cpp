# include <iostream>
# include <vector>
using namespace std;

void bubbleSort (vector <int> & array, string order, int & stepCount) 
{
    int length = array.size();
    for (int i = 0; i < length; i++) 
    {
        for (int j = 0; j < (length - i - 1); j++) 
        {
            stepCount++;
            if ((order == "ascending" && array[j] > array[j + 1]) 
            || (order == "descending" && array[j] < array[j + 1])) 
            {
                swap(array[j], array[j + 1]);
                stepCount++;
            }
        }
    }
}

void selectionSort (vector <int> & array, string order, int & stepCount) 
{
    int length = array.size();
    for (int i = 0; i < (length - 1); i++) 
    {
        int minMaxIndex = i;
        for (int j = (i + 1); j < length; j++) 
        {
            stepCount++;
            if ((order == "ascending" && array[j] < array[minMaxIndex]) || 
            (order == "descending" && array[j] > array[minMaxIndex])) 
            {
                minMaxIndex = j;
            }
        }
        swap(array[i], array[minMaxIndex]);
        stepCount++;
    }
}

void insertionSort (vector <int> & array, string order, int & stepCount) 
{
    int length = array.size();
    for (int i = 1; i < length; i++) 
    {
        int key = array[i];
        int j = (i - 1);
        while (j >= 0 && ((order == "ascending" && array[j] > key) || 
        (order == "descending" && array[j] < key))) 
        {
            array[j + 1] = array[j];
            j--;
            stepCount += 2;
        }
        array[j + 1] = key;
        stepCount++;
    }
}

vector <int> generateInput (string caseType, int size) 
{
    vector <int> array(size);
    if (caseType == "Best") 
    {
        for (int i = 0; i < size; i++) 
        {
            array[i] =( i + 1);
        }
    } 
    else if (caseType == "Worst") 
    {
        for (int i = 0; i < size; i++) 
        {
            array[i] = (size - i);
        }
    } 
    else if (caseType == "Average") 
    {
        for (int i = 0; i < size; i++) 
        {
            array[i] = (rand() % 100 + 1);
        }
    }
    return array;
}

void displayArray (const vector <int> & array) 
{
    for (int num : array) 
    {
        cout << num << " ";
    }
    cout << endl;
}

int main() 
{

    vector <int> sizes = {10, 20, 30, 40};
    string orders [] = {"Ascending", "Descending"};
    string cases [] = {"Best", "Worst", "Average"};

    for (const string & caseType : cases) 
    {
        for (const string & order : orders) 
        {
            cout << "\n\nCase :  " << caseType << ", Order :  " << order << endl;
            for (int size : sizes) 
            {
                vector <int> array = generateInput (caseType, size);
                int stepCount = 0;
                cout << "Sorting Array of Size " << size << " : \n\n";
                vector <int> arrayCopy = array;

                bubbleSort(arrayCopy, order, stepCount);
                cout << "Sorted Array by Bubble Sort :  ";
                displayArray(arrayCopy);
                cout << "Step Count :  " << stepCount << endl;
                stepCount = 0;
                arrayCopy = array;

                selectionSort(arrayCopy, order, stepCount);
                cout << "Sorted Array by Selection Sort :  ";
                displayArray(arrayCopy);
                cout << "Step Count :  " << stepCount << endl;
                stepCount = 0;
                arrayCopy = array;

                insertionSort(arrayCopy, order, stepCount);
                cout << "Sorted Array by Insertion Sort :  ";
                displayArray(arrayCopy);
                cout << "Step Count :  " << stepCount << endl;
            }
        }
    }

    return 0;

}