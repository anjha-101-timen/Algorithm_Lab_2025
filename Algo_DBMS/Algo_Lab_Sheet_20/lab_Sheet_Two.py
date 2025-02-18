
import time
import matplotlib.pyplot as plt
import random

def matrix_chain_multiplication (array) :
    h = len (array)
    # Create a DP table to store results of subproblems
    dp = [ [ 0 for _ in range (h) ] for _ in range (h) ]
    
    # Solve subproblems for chains of length (from 2 to h-1)
    for l in range(2, h):  # l is the chain length
        for i in range(1, (h - l + 1)):
            j = (i + l - 1)
            dp[i][j] = float ('inf')  # Initialize with infinity
            for k in range (i, j) :
                # Calculate cost of splitting at k
                cost = (dp[i][k] + dp[k+1][j] + array[i-1] * array[k] * array[j])
                if cost < dp[i][j] :
                    dp[i][j] = cost
    
    return (dp[1][h-1])

# Measure time taken for different input sizes
def measure_time():
    input_sizes = [3, 4, 5, 6, 7, 8, 9, 10]
    times = []
    
    for size in input_sizes :
        # Generate random but valid matrix dimensions
        array = [random.randint (10, 100) for _ in range (size)]
        
        # Ensure the array has at least two elements and forms valid matrix dimensions
        if len (array) < 2 :
            print("Error :  Array size must be at least 2.")
            continue
        
        # Measure execution time
        start_time = time.time ()
        result = matrix_chain_multiplication (array)
        end_time = time.time ()
        elapsed_time = (end_time - start_time)
        
        print(f"Input Size :  {size}, Time Taken :  {elapsed_time:.6f} seconds, Result :  {result}")
        times.append (elapsed_time)
    
    # Plot graph
    plt.plot (input_sizes, times, marker='o')
    plt.xlabel ("Input Size")
    plt.ylabel ("Time Taken (seconds)")
    plt.title ("Matrix Chain Multiplication: Input Size vs Time Taken")
    plt.grid (True)
    plt.show ()

# Run the experiment
if __name__ == "__main__":
    measure_time()
