import random
def partition(arr,low,high):
   pivot_index = random.randint(low,high)
   arr[pivot_index],arr[high] = arr[high],arr[pivot_index]
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
quicksort(arr,0,n-1)
print("Sorted array is: ",arr)