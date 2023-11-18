# Problem Statement 3

no = int(input("Enter total number of students: "))
marklist = []
print("Enter -1 for absent students.")
for i in range (no):
        marks = int(input("Enter marks of student: "))
        marklist.append(marks)

def absent():
    ab_stu = 0;
    for marks in marklist:
        if marks == -1:
            ab_stu += 1
    print("Absent students: ", ab_stu)

def high():
    highest = 0
    for marks in marklist:
        if marks >= 0:
            if highest <= marks:
                highest = marks
    print("Highest marks: ",highest)

def low():
    lowest = 100
    for marks in marklist:
        if marks >= 0:
            if lowest >= marks:
                lowest = marks
    print("Lowest marks: ",lowest)

def avg():
    ab_stu = 0;
    for marks in marklist:
        if marks == -1:
            ab_stu += 1
    total = 0
    for marks in marklist:
        if marks >= 0:
            total += marks
    avg = total / (no - ab_stu)
    print("Average Marks: ",avg)

def frequency():
    freq_dict = {}
    for marks in marklist:
        if marks in freq_dict:
            freq_dict[marks] += 1
        else:
            freq_dict[marks] = 1
    print("Frequency of marks: ",freq_dict)
    h_f = 0
    for j in freq_dict:
        if h_f < freq_dict[j]:
            h_f = freq_dict[j]
    freq_list = []
    for k in freq_dict:
        if h_f == freq_dict[k]:
            freq_list.append(k)
    print("Marks with highest frequency: ",freq_list)

absent()
high()
low()
avg()
frequency()
