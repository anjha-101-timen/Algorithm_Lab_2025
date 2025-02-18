
import java.util.*;

public class lab_Sheet_One
{

    // Bubble Sort
    public static int bubbleSort (int [] array)
    {
        int k = array.length;
        int stepCount = 0;
        for (int i = 0; i < k; i++)
        {
            boolean swapped = false;
            for (int j = 0; j < (k - i - 1); j++)
            {
                stepCount++; // Comparison
                if (array [j] > array [j + 1])
                {
                    int temp = array [j];
                    array [j] = array [j + 1];
                    array [j + 1] = temp;
                    stepCount++; // Swap
                    swapped = true;
                }
            }
            if (!swapped) break;
        }
        return stepCount;
    }

    // Selection Sort
    public static int selectionSort (int [] array)
    {
        int k = array.length;
        int stepCount = 0;
        for (int i = 0; i < k; i++)
        {
            int minIdx = i;
            for (int j = (i + 1); j < k; j++)
            {
                stepCount++; // Comparison
                if (array [j] < array [minIdx])
                {
                    minIdx = j;
                }
            }
            if (minIdx != i)
            {
                int temp = array[i];
                array [i] = array [minIdx];
                array [minIdx] = temp;
                stepCount++; // Swap
            }
        }
        return stepCount;
    }

    // Insertion Sort
    public static int insertionSort (int [] array)
    {
        int k = array.length;
        int stepCount = 0;
        for (int i = 1; i < k; i++)
        {
            int key = array [i];
            int j = (i - 1);
            while ((j >= 0) && (array [j] > key))
            {
                stepCount++; // Comparison
                array [j + 1] = array [j];
                stepCount++; // Assignment
                j--;
            }
            array [j + 1] = key;
            stepCount++; // Assignment
        }
        return stepCount;
    }

    // Function to measure step counts for different input sizes
    public static void measureStepCounts ()
    {
        int [] inputSizes = {10, 20, 50};
        String [] algorithms = {"Bubble Sort", "Selection Sort", "Insertion Sort"};
        String [] cases = {"Best", "Worst", "Average"};

        // Results storage
        List <Integer> [] bubbleResults = new ArrayList [3];
        List <Integer> [] selectionResults = new ArrayList [3];
        List <Integer> [] insertionResults = new ArrayList [3];

        for (int i = 0; i < 3; i++)
        {
            bubbleResults [i] = new ArrayList <> ();
            selectionResults [i] = new ArrayList <> ();
            insertionResults [i] = new ArrayList <> ();
        }

        for (int size : inputSizes)
        {
            // Generate test cases
            int [] bestCase = new int [size];
            int [] worstCase = new int [size];
            int [] averageCase = new int [size];

            // Best case: Already sorted
            for (int i = 0; i < size; i++) bestCase [i] = (i + 1);

            // Worst case: Reverse sorted
            for (int i = 0; i < size; i++) worstCase [i] = (size - i);

            // Average case: Randomized
            Random random = new Random ();
            for (int i = 0; i < size; i++) averageCase [i] = random.nextInt(100) + 1;

            // Bubble Sort
            bubbleResults [0].add (bubbleSort (Arrays.copyOf (bestCase, bestCase.length)));
            bubbleResults [1].add (bubbleSort (Arrays.copyOf (worstCase, worstCase.length)));
            bubbleResults [2].add (bubbleSort (Arrays.copyOf (averageCase, averageCase.length)));

            // Selection Sort
            selectionResults [0].add (selectionSort (Arrays.copyOf (bestCase, bestCase.length)));
            selectionResults [1].add (selectionSort (Arrays.copyOf (worstCase, worstCase.length)));
            selectionResults [2].add (selectionSort (Arrays.copyOf (averageCase, averageCase.length)));

            // Insertion Sort
            insertionResults [0].add (insertionSort (Arrays.copyOf (bestCase, bestCase.length)));
            insertionResults [1].add (insertionSort (Arrays.copyOf (worstCase, worstCase.length)));
            insertionResults [2].add (insertionSort (Arrays.copyOf (averageCase, averageCase.length)));
        }

        // Print results
        System.out.println ("Bubble Sort : ");
        for (int i = 0; i < 3; i++)
        {
            System.out.print (cases [i] + " :  ");
            for (int count : bubbleResults [i]) System.out.print (count + " ");
            System.out.println ();
        }

        System.out.println ("\nSelection Sort : ");
        for (int i = 0; i < 3; i++)
        {
            System.out.print (cases [i] + " :  ");
            for (int count : selectionResults [i]) System.out.print (count + " ");
            System.out.println ();
        }

        System.out.println ("\nInsertion Sort : ");
        for (int i = 0; i < 3; i++)
        {
            System.out.print (cases [i] + " :  ");
            for (int count : insertionResults [i]) System.out.print (count + " ");
            System.out.println ();
        }
    }

    public static void main(String[] args)
    {
        measureStepCounts();
    }
}
