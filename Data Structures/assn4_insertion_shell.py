#Assignment 4

n = int(input("Enter number of students: "))
per = [ ]
for i in range(n):
    p = float(input("Enter percentage of student: "))
    per.append(p)
    
#shell sort
def shell():
    gap = n//2
    while gap>0:
        for i in range(gap,n):
            temp = per[i]
            while(i >= gap) and (per[i-gap] > temp):
                per[i] = per[i-gap]
                per[i-gap] = temp
        gap = gap//2
    print(per)
    print("Top 5 percentages are: ",per[-5::1])

#insertion sort
def insertion():
    key = 0
    for i in range(0,n):
        key = per[i]
        #j = i - 1
        while((i-1) >= 0) and (per[i-1] > key):
            per[i] = per[i-1]
            #j = j -1
            per[i-1] = key
    print(per)
    print("Top 5 percentages are: ",per[-5::1])

#main part
print("1. Shell sort")
print("2. Insertion sort")
ch = int(input("Enter choice(1 or 2): "))
if ch == 1:
    shell()
elif ch == 2:
    insertion()
        
        
