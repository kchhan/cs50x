from cs50 import get_float

change = 0
count = 0

# get change
while change <= 0:
    change = get_float("Change owed: ")
    
# make into cents
change = change * 100

# make into int
change = int(change)

# quarters
while change >= 25:
    change -= 25
    count += 1
    
# dimes
while change >= 10:
    change -= 10
    count += 1

# nickles    
while change >= 5:
    change -= 5
    count += 1
    
# pennies
while change > 0:
    change -= 1
    count += 1
 
# return number of coins  
print(count)