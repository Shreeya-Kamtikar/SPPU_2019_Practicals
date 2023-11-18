hashtable=[[],[],[],[],[],[],[],[],[],[]]
count=[-1,-1,-1,-1,-1,-1,-1,-1,-1,-1]

def insert_with_replace():
    n=int(input("Enter the number of elements :"))
    for i in range(n):
        val=int(input("Enter the element :"))
        key=val%10
        if hashtable[key]==[]:
            hashtable[key].append(val)
            hashtable[key].append(-1)
            if count[key]==-1:
                count[key]=key
        else:
            temp=key
            temp1=hashtable[key]
            ele=temp1[0]
            kn=ele%10
            if kn==key:
                a=temp1[1]
                if key<9:
                    key=key+1
                else:
                    key=0
                while key!=temp:
                    if key<=9:
                        if hashtable[key]==[]:
                            hashtable[key].append(val)
                            hashtable[key].append(-1)
                            if count[temp]==-1:
                                count[temp]=key
                            else:
                                a=count[temp]
                                l=hashtable[a]
                                l[1]=key
                                count[temp]=key
                            break
                        else:
                            key=key+1
                    else:
                        key=0
            else:                           
                hashtable[key]=[val,-1]
                if count[temp]==-1:
                    count[temp]=key
                if key<9:
                    key=key+1
                else:
                    key=0
                while key!=temp:
                    if key<=9:
                        if hashtable[key]==[]:
                            for i in range(0,10):
                                if hashtable[i]!=[]:
                                    b=hashtable[i]
                                    if b[1]==temp:
                                        b[1]=key
                                        hashtable[key]=temp1
                                        flag=1
                                        break
                            if flag==1:
                                break
                        else:
                            key=key+1
                    else:
                        key=0            
def insert_no_replace():
    n=int(input("Enter the number of elements :"))
    for i in range(n):
        val=int(input("Enter the element :"))
        key=val%10
        if hashtable[key]==[]:
            hashtable[key].append(val)
            hashtable[key].append(-1)
            if count[key]==-1:
                count[key]=key
        else:
            temp=key
            temp1=hashtable[temp]
            a=temp1[1]
            if key<9:
                key=key+1
            else:
                key=0
            while key!=temp:
                if key<=9:
                    if hashtable[key]==[]:
                        hashtable[key].append(val)
                        hashtable[key].append(-1)
                        if count[temp]==-1:
                            count[temp]=key
                        else:
                            a=count[temp]
                            l=hashtable[a]
                            l[1]=key
                            count[temp]=key
                        break
                    else:
                        key=key+1
                else:
                    key=0
                    
def display():
    print('index:\t\t\tdata\t\t\tchain')
    for i in range(0,10):
        if hashtable[i]!=[]:
            a=hashtable[i]
            if a[1]==-1:
                print(i,'\t\t\t',a[0],'\t\t\t',a[1])
            else:
                print(i,'\t\t\t',a[0],'\t\t\t',a[1])

def search():
    val=int(input('Enter the value to be searched : '))
    flag=0
    for i in range(0,10):
        if hashtable[i]!=[]:
            a=hashtable[i]
            if a[0]==val:
                print('Value',val,'found at index :',i)
                flag=1
                break    
    if flag==0:
        print('Value not found')

def delete():
    val=int(input('Enter the value in the table to deleted :'))
    for i in range(0,10):
        if hashtable[i]!=[]:
            a=hashtable[i]
            if a[0]==val:
                hashtable[i]=[]
                b=i
                break
    for i in range(0,10):
        if hashtable[i]!=[]:
            c=hashtable[i]
            if c[1]==b:
                c[1]=a[1]
                break

print('1) Chaining with Replacement')
print('2) Chaining without Replacement')
cho=int(input('Enter your choice :'))
if cho==1:
    insert_with_replace()
else:
    insert_no_replace()

display()
search()
delete()
display()
