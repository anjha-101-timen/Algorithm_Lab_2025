
import random
import matplotlib.pyplot as plt

# Bubble Sort
def bubble_sort (array) :
    k = len (array)
    step_count = 0
    for i in range (k):
        swapped = False
        for j in range (0, (k - i - 1)) :
            step_count += 1  # Comparison
            if (array [j] > array [j + 1]) :
                array [j], array [j + 1] = array [j + 1], array [j]
                step_count += 1  # Swap
                swapped = True
        if not swapped :
            break
    return step_count

# Selection Sort
def selection_sort (array) :
    k = len (array)
    step_count = 0
    for i in range (k) :
        min_idx = i
        for j in range (i + 1, k) :
            step_count += 1  # Comparison
            if (array [j] < array [min_idx]) :
                min_idx = j
        if min_idx != i :
            array [i], array [min_idx] = array [min_idx], array [i]
            step_count += 1  # Swap
    return step_count

# Insertion Sort
def insertion_sort (array) :
    k = len (array)
    step_count = 0
    for i in range (1, k) :
        key = array[i]
        j = (i - 1)
        while (j >= 0) and (array [j] > key) :
            step_count += 1  # Comparison
            array [j + 1] = array [j]
            step_count += 1  # Assignment
            j -= 1
        array [j + 1] = key
        step_count += 1  # Assignment
    return step_count

# Function to measure step counts for different input sizes
def measure_step_counts () :
    input_sizes = [10, 20, 50]
    results = {"Bubble Sort": {"Best": [], "Worst": [], "Average": []},
               "Selection Sort": {"Best": [], "Worst": [], "Average": []},
               "Insertion Sort": {"Best": [], "Worst": [], "Average": []}}

    for size in input_sizes :
        # Generate test cases
        best_case = list (range (1, (size + 1)))  # Already sorted
        worst_case = list (range (size, 0, -1))  # Reverse sorted
        average_case = random.sample (range (1, 100), size)  # Randomized

        # Bubble Sort
        results ["Bubble Sort"] ["Best"].append (bubble_sort (best_case.copy ()))
        results ["Bubble Sort"] ["Worst"].append (bubble_sort (worst_case.copy ()))
        results ["Bubble Sort"] ["Average"].append (bubble_sort (average_case.copy ()))

        # Selection Sort
        results ["Selection Sort"] ["Best"].append (selection_sort (best_case.copy ()))
        results ["Selection Sort"] ["Worst"].append (selection_sort (worst_case.copy ()))
        results ["Selection Sort"] ["Average"].append (selection_sort (average_case.copy ()))

        # Insertion Sort
        results ["Insertion Sort"] ["Best"].append (insertion_sort (best_case.copy ()))
        results ["Insertion Sort"] ["Worst"].append (insertion_sort (worst_case.copy ()))
        results ["Insertion Sort"] ["Average"].append (insertion_sort (average_case.copy ()))

    return results, input_sizes

# Plot graphs
def plot_graphs (results, input_sizes):
    for algorithm in results :
        plt.figure (figsize = (10, 5))
        for case in results [algorithm] :
            plt.plot (input_sizes, results [algorithm][case], marker='o', label=f"{case} Case")
        plt.title (f"{algorithm}:  Step Count vs Input Size")
        plt.xlabel ("Input Size")
        plt.ylabel ("Step Count")
        plt.legend ()
        plt.grid (True)
        plt.show ()

# Main function
if __name__ == "__main__" :
    results, input_sizes = measure_step_counts ()
    plot_graphs (results, input_sizes)
