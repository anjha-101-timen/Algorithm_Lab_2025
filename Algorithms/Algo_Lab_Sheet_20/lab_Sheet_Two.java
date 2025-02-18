
import java.util.Random;

public class lab_Sheet_Two 
{
    // Function to calculate the minimum number of scalar multiplications
    public static int matrixChainMultiplication (int [] array) 
    {
        int h = array.length;
        // Create a DP table to store results of subproblems
        int [][] dp = new int [h][h];

        // Solve subproblems for chains of length (from 2 to h-1)
        for (int l = 2; l < h; l++) 
        {   // l is the chain length
            for (int i = 1; i < (h - l + 1); i++) 
            {
                int j = (i + l - 1);
                dp [i][j] = Integer.MAX_VALUE; // Initialize with infinity
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
        return (dp[1][h - 1]); // Result for the full chain
    }

    // Function to measure time taken for different input sizes
    public static void measureTime () 
    {
        int [] inputSizes = {3, 4, 5, 6, 7, 8, 9, 10};
        Random rand = new Random ();

        for (int size : inputSizes) 
        {
            // Generate random matrix dimensions
            int [] array = new int [size];
            for (int i = 0; i < size; i++) 
            {
                array[i] = rand.nextInt(90) + 10; // Random values between 10 and 100
            }

            // Measure execution time
            long startTime = System.nanoTime ();
            int result = matrixChainMultiplication (array);
            long endTime = System.nanoTime ();
            double elapsedTime = (endTime - startTime) / 1_000_000_000.0; // Convert to seconds

            System.out.printf("Input Size :  %d, Time Taken :  %.6f seconds, Result :  %d%n",
                              size, elapsedTime, result);
        }
    }

    // Main function
    public static void main(String[] args) 
    {
        measureTime();
    }
}
