import time
def shell_sort(arr):
    n = len(arr)
    gap = n // 2 
    while gap > 0:
        for i in range(gap, n):
            temp = arr[i]
            j = i
            while j >= gap and arr[j - gap] > temp:
                arr[j] = arr[j - gap]
                j -= gap
            arr[j] = temp

        gap //= 2   

    return arr

def measure_time(sort_function, data):
    start_time = time.time()
    sort_function(data.copy())  # Sort a copy of the data to avoid modifying the original
    end_time = time.time()
    return end_time - start_time

sample_list = [1,2,3,4]
print("Original list:", sample_list)
sorted_list = shell_sort(sample_list)
print("Sorted list:", sorted_list)
shell_sort_time = measure_time(shell_sort, sample_list)
print(f"Time taken by Shell Sort: {shell_sort_time:.6f} seconds")

