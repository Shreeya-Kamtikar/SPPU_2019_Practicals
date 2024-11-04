import time
def partition(arr,low,high):
   pivot = arr[high]
   i = low - 1
   for j in range(low,high):
       if arr[j] <= pivot:
           i += 1
           arr[i],arr[j] = arr[j],arr[i]
   arr[i+1],arr[high] = arr[high], arr[i+1]
   return i+1

def quicksort(array,low,high):
   if low < high:
       pi = partition(array,low,high)
       quicksort(arr,low,pi-1)
       quicksort(arr,pi+1,high)

n = int(input("Enter the number of elements: "))
arr = []
for i in range(n):
   val = int(input(f"Enter the value{i+1}: "))
   arr.append(val)
print("Unsorted array is: ",arr)
start = time.perf_counter()
quicksort(arr,0,n-1)
end = time.perf_counter()
print("Sorted array is: ",arr)
exec = end - start
print("Execution Time: ",exec)