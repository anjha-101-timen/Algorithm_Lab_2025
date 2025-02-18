
import time
import random
import matplotlib.pyplot as plt

# Recursive Binary Search Function
def recursive_binary_search (array, low, high, target) :
    if (low > high) :
        return -1  # Element not found
    
    mid = ((low + high) // 2)
    if (array [mid] == target) :
        return mid  # Element found at mid
    elif (array [mid] > target) :
        return recursive_binary_search (array, low, (mid - 1), target)  # Search left half
    else :
        return recursive_binary_search (array, (mid + 1), high, target)  # Search right half

# Measure time taken for different input sizes
def measure_time () :
    input_sizes = [100, 500, 1000, 5000, 10000, 50000, 100000]
    times = []
    
    for size in input_sizes :
        # Generate a sorted list of random numbers
        array = sorted ([random.randint (1, 100000) for _ in range (size)])
        
        # Choose a random target element
        target = random.choice (array)
        
        # Measure execution time
        start_time = time.time ()
        result = recursive_binary_search (array, 0, (len (array) - 1), target)
        end_time = time.time ()
        elapsed_time = (end_time - start_time)
        
        print (f"Input Size :  {size}, Target :  {target}, Index :  {result}, Time Taken :  {elapsed_time:.6f} seconds")
        times.append (elapsed_time)
    
    # Plot graph
    plt.plot (input_sizes, times, marker='o')
    plt.xlabel ("Input Size")
    plt.ylabel ("Time Taken (seconds)")
    plt.title ("Recursive Binary Search: Input Size vs Time Taken")
    plt.grid (True)
    plt.show ()

# Run the experiment
if __name__ == "__main__" :
    measure_time ()
