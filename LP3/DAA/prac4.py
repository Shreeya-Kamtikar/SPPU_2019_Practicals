def knapSack(W, wt, prfit, n):
   K = [[0 for x in range(W + 1)] for x in range(n + 1)]
   # create the table by given criteria
   for i in range(n + 1):
       for j in range(W + 1):
           if i == 0 or j == 0:
               K[i][j] = 0
           elif j >= wt[i-1]:
               K[i][j] = max(K[i-1][j], prfit[i-1]+ K[i-1][j-wt[i-1]])
           else:
               K[i][j] = K[i-1][j]
   # print the table
   print("\nTable:")
   for row in K:
       print(row)
   # print the maximum profit
   max_profit = K[n][j]
   print("\nMaximum Profit: ", max_profit)
   # check for selected objects
   j = W
   objects = []
   for i in range(n,0,-1):
       if K[i][j] != K[i-1][j]:
           objects.append(i)
           j -= wt[i-1]
   print("\nSelected objects are: ", objects)

n = int(input("Enter the number of objects: "))
profit = []
weight = []
for i in range(n):
   pr = int(input(f"Enter profit for object{i+1}: "))
   wt = int(input(f"Enter weight for object{i+1}: "))
   profit.append(pr)
   weight.append(wt)
max_wt = int(input("Enter the maximum weight: "))
knapSack(max_wt,weight,profit,n)