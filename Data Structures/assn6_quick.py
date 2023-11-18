#Quick Sort

n = int(input("Enter the number of students:- "))
per = []
for i in range(n):
        p = float(input("Enter percentages: "))
        per.append(p)

def partition(array,low,high):
            pivot = array[high]
            i = low - 1
            for j in range(low,high):
                    if array[j] <= pivot:
                            i = i +1
                            (array[i],array[j]) = (array[j],array[i])
            (array[i+1],array[high]) = (array[high],array[i+1])
            return i+1

def quicksort(array,low,high):
            if low < high:
                    pi = partition(array,low,high)
                    quicksort(array,low,pi-1)
                    quicksort(array,pi+1,high)
size = 0
for i in per:
        size += 1
quicksort(per,0,size-1)
print("Sorted array is: ",per)
top = []
for i in range(1,6):
        top.append(per[n-i])
print(top)
