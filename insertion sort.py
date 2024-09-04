import time
def insertion_sort(arr):
   for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while j >= 0 and key < arr[j]:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key

def measure_time(sort_function, data):
    start_time = time.time()
    sort_function(data.copy())  # Sort a copy of the data to avoid modifying the original
    end_time = time.time()
    return end_time - start_time

if __name__ == "__main__":
    my_list = [2820,3452,4111,4251,3930,942,1328,1635,1705,2940,3499,3926,2069,1019,958,2242,883,1156,160,1581,3981,1272,4504,4516,3283,3247,4883,357,3900,4459,2172,3888,4678,153,4333,2822,3953,4819,2393,1115,843,3350,11,2220,4236,443,2623,4829,2099,720,4150,3292,4379,3672,2186,1437,3255,4619,3796,3837,1988,493,4908,2223,1116,1934,1094,4562,4892,2668,631,4626,2360,1531,1566,2244,2077,3510,3991,1211,3741,2437,4447,3681,700,1710,2971,2676,1806,1439,1691,3827,3989,318,3768,2578,4283,3133,3407,3576]
    insertion_sort(my_list)
    print("Sorted array is:", my_list)
    
    insertion_sort_time = measure_time(insertion_sort, my_list)
    print(f"Time taken by Insertion Sort: {insertion_sort_time:.6f} seconds")
    

