def mergeSort(arr):
    if len(arr) > 1:
        mid = len(arr)//2
        L = arr[:mid]
        R = arr[mid:]

        mergeSort(L)
        mergeSort(R)

        i = j = k = 0

        while i < len(L) and j < len(R):
            if L[i][2] > R[j][2]:
                arr[k] = L[i]
                i += 1
            else:
                arr[k] = R[j]
                j += 1
            k += 1
        
        while i < len(L):
            arr[k] = L[i]
            i += 1
            k += 1
        
        while j < len(R):
            arr[k] = R[j]
            j += 1
            k += 1

def jobScheduler(arr,time):
    mergeSort(arr)
    result = [False] * time
    job = ['-1'] * time
    totalProfit = 0

    for i in range (len(arr)):
        for j in range(min(time-1,arr[i][1]-1),-1,-1):
            if result[j] is False:
                result[j] = True
                job[j] = arr[i][0]
                totalProfit += arr[i][2]
                break
    print("Job sequence: ",job)
    return totalProfit
    
if __name__ == "__main__":
    n = int(input("Enter number of jobs: "))
    arr = []
    for i in range(n):
        job_id = input("Enter job id: ")
        deadline = int(input("Enter job deadline: "))
        profit = int(input("Enter job profit: "))
        arr.append([job_id, deadline, profit])
    timeslots = int(input("Enter number of time slots: "))

    print("\nFollowing is maximum profit sequence of jobs: \n")
    max_profit = jobScheduler(arr,timeslots)
    print("\nMaximum profit is: ", max_profit)
