from cs50 import get_int

num = 0
while num < 1 or num > 8:
    num = get_int("Height: ")

for i in range(num):
    # spaces before
    for j in range(0, num - i - 1, 1):
        print(" ", end = "")
        
    #pyramid
    for k in range(0, i + 1, 1):
        print("#", end = "")
        
    print()