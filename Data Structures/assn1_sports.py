# Assignment 1- Set operations

#Universal set
total_no = int(input("Enter total number of students: "))
total_rno = []
for i in range(total_no):
        x = int(input("Enter roll number of student: "))
        if x not in total_rno:
                total_rno.append(x)
print("List of roll numbers of all students: ", total_rno)        

#Cricket
cric_no = int(input("Enter number of students who play cricket:  "))
list_cric = []
for i in range(cric_no):
        c = int(input("Enter roll number of students playing cricket:  "))
        list_cric.append(c)
print("List of roll numbers of students playing cricket: ", list_cric)

#Badminton
bd_no = int(input("Enter number of students who play badminton:  "))
list_bd = []
for i in range(bd_no):
        b = int(input("Enter roll number of students playing badminton:  "))
        list_bd.append(b)
print("List of roll numbers of students playing badminton: ", list_bd)

#Football
fb_no = int(input("Enter number of students who play football:  "))
list_fb = []
for i in range(fb_no):
        f= int(input("Enter roll number of students playing football:  "))
        list_fb.append(f)
print("List of roll numbers of students playing football: ", list_fb)

#Intersection -- cricket and badminton
int_cb = []
for i in list_cric:
    for j in list_bd:
        if i == j:
            int_cb.append(i)
print("List of students playing cricket and badminton both: ", int_cb)

#Union -- cricket and badminton
u_cb = []
u_cb = u_cb + list_cric
for i in list_bd:
    if i not in u_cb:
        u_cb.append(i)
print("List of students playing cricket and badminton: ", u_cb)

#Either cricket or badminton but not both
e_cb = []
for i in u_cb:
    if i not in int_cb:
        e_cb.append(i)
print("List of students playing either cricket or badminton but not both: ", e_cb)

#Neither cricket nor badminton
not_cb = []
for i in total_rno:
    if i not in u_cb:
        not_cb.append(i)
print("List of students playing neither cricket nor badminton: ",not_cb)

#Intersection -- cricket and football
int_cf = []
for i in  list_cric:
    for j in list_fb:
        if i == j:
            int_cf.append(i)
print("List of students playing cricket and football: ", int_cf)

#Cricket and football but not badminton
cf_n_bd = []
for i in int_cf:
    if i not in list_bd:
        cf_n_bd.append(i)
print("List of students playing cricket and football but not badminton is: ", cf_n_bd)
