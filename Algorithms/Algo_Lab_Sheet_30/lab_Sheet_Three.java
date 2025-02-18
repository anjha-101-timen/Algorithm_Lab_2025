
import java.util.Arrays;
import java.util.Random;

public class lab_Sheet_Three
{
    // Recursive Binary Search Function
    public static int recursiveBinarySearch (int [] array, int low, int high, int target)
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
    public static void measureTime ()
    {
        int [] inputSizes = {100, 500, 1000, 5000, 10000, 50000, 100000};
        Random rand = new Random();

        for (int size : inputSizes)
        {
            // Generate a sorted list of random numbers
            int [] array = new int[size];
            for (int i = 0; i < size; i++)
            {
                array [i] = rand.nextInt (100000) + 1; // Random values between 1 and 100000
            }
            Arrays.sort (array); // Sort the array

            // Choose a random target element
            int target = array [rand.nextInt(size)];

            // Measure execution time
            long startTime = System.nanoTime ();
            int result = recursiveBinarySearch (array, 0, (size - 1), target);
            long endTime = System.nanoTime ();
            double elapsedTime = (endTime - startTime) / 1_000_000_000.0; // Convert to seconds

            System.out.printf ("Input Size :  %d, Target :  %d, Index :  %d, Time Taken :  %.6f seconds%n",
                    size, target, result, elapsedTime);
        }
    }

    // Main function
    public static void main(String[] args)
    {
        measureTime();
    }
}
