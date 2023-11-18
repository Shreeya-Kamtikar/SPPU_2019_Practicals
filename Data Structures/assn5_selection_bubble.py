#Assignment 5

n = int(input("Enter number of students: "))
per = [ ]
for i in range(n):
    p = float(input("Enter percentage of student: "))
    per.append(p)

#selection sort
def selection():
    for i in range(n):
        for j in range(i+1, n):
            if(per[i]>per[j]):
                temp = per[i]
                per[i] = per[j]
                per[j] = temp 
    print(per)
    top = []
    for i in range(1,6):
        top.append(per[n-i])
    print("Top 5 percentages are: ",top)

#bubble sort
def bubble():
    for i in range(n):
        for j in range(n-i-1):
            if(per[j] < per[j+1]):
                temp = per[j]
                per[j] = per[j+1]
                per[j+1] = temp
    print(per)
    top = []
    for i in range(1,6):
        top.append(per[n-i])
    print("Top 5 percentages are: ",top)

#main program
print("1. Selection sort")
print("2.Bubble sort")
ch = int(input("Enter choice(1 or 2): "))
if ch == 1:
    selection()
elif ch == 2:
    bubble()

