class Item:
   def __init__(self, name, weight, profit):
       self.name = name
       self.weight = weight
       self.profit = profit

def fractional_knapsack(items, capacity):
   items.sort(key=lambda x: x.profit/x.weight, reverse=True)
   total_profit = 0
   selected_items = []
   print("Item\tWeight\tProfit\tProfit/Weight Ratio")
   for item in items:
       print(f"{item.name}\t{item.weight}\t{item.profit}\t{item.profit/item.weight:.2f}")
   for item in items:
       if capacity >= item.weight:
           capacity -= item.weight
           total_profit += item.profit
           selected_items.append((item.name, 1))
       else:
           fraction = capacity / item.weight
           total_profit += item.profit * fraction
           selected_items.append((item.name, fraction))
           break
   print(f"\nTotal Profit: {total_profit:.2f}\n")
   print("Selected Items:")
   for item in selected_items:
       print(f"  {item[0]}: {item[1]:.2f} ")

num_items = int(input("Enter the number of items: "))
items = []
for i in range(num_items):
   name = input(f"Enter the name of item {i+1}: ")
   weight = float(input(f"Enter the weight of item {i+1}: "))
   profit = float(input(f"Enter the profit of item {i+1}: "))
   items.append(Item(name, weight, profit))
capacity = float(input("Enter the capacity of the knapsack: "))
fractional_knapsack(items, capacity)