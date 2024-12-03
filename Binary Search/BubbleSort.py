def bubble_sort(arr):
  """
  Sorts an array using the bubble sort algorithm.

  Args:
    arr: The array to be sorted.
  """
  n = len(arr)
  for i in range(n):
    # Flag to optimize, if no two elements were swapped in inner loop, array is sorted
    swapped = False
    # Last i elements are already in place
    for j in range(0, n - i - 1):
      # Traverse the array from 0 to n-i-1
      # Swap if the element found is greater than the next element
      if arr[j] > arr[j + 1]:
        arr[j], arr[j + 1] = arr[j + 1], arr[j]

        swapped = True
    if swapped == False:
      break


# Example usage:
arr = ["Tree", "Lucy", "Ben", "Her", "Derr", "Cel"]
bubble_sort(arr)
print("Sorted array:", arr)  # Output: Sorted array: [11, 12, 22, 25, 34, 64,   