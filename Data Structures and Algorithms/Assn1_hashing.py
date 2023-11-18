hashtable=[[],[],[],[],[],[],[],[],[],[]]

def hashfunction(num):
    return num%10

def chaining(index,phoneno):
    hashtable[index].append(phoneno)

def linear(index,phoneno):
	i=index
	count=1
	flag=0
	while(count!=10):
		if(hashtable[i]==[]):
			hashtable[i].append(phoneno)
			flag=1
			break
		else:
			if (i<9):
				i+=1
				count+=1
			else:
				i=0
		if flag==0:
			print("Hashtable is full")

n=int(input("Enter the number of clients: "))
print("Enter 1 for Linear Probing")
print("Enter 2 for Chaining")
cho=int(input())

def insert():
	for i in range(0,n):
		phoneno=int(input("Enter the phone number:"))
		index=hashfunction(phoneno)
		if cho==1:
			if(hashtable[index]!=[]):
				linear(index,phoneno)
			else:
				hashtable[index].append(phoneno)
		elif cho==2:
			if(hashtable[index]!=[]):
				chaining(index,phoneno)
			else:
				hashtable[index].append(phoneno)

def display():
    print("Output is")
    for i in range(0,10):
   	 if(hashtable[i]!=[]):
   		 print("Index:",i,"-->",hashtable[i])

def search():
	no=int(input("Enter the Phone number to be searched: "))
	if(cho==1):
		linearsearch(no)
	else:
		chainsearch(no)

def chainsearch(no):
    counter=0
    index=hashfunction(no)
    if(hashtable[index]==[]):
	    print("Sorry the value not found")
	if(hashtable[index]!=[]):
	    for i in hashtable[index]:
		    if(i==no):
			    print("Success: ",no,"Found at index: ",index)
			else:
			    counter +=1
	else:
	    print("Sorry the number not found")

def linearsearch(no):
    flag=0
    for i in range(0,10):
   	 for j in hashtable[i]:
   		 if(j==no):
   			 print("Success: ",no,"Found at index: ",i)
   			 flag=1
   		 else:
   			 break
    if(flag==0):
   	 print("Sorry the number not found")

insert()
display()
search()
