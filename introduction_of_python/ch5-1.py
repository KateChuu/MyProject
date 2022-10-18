max = None
min = None
while True:
    num = input("Enter a number: ")
    if num == "done":
        break
    try:
        num = float(num)
    except:
        print("Invalid input")
        continue

    if max is None:
        max = num
    elif max < num:
        max = num

    if min is None:
        min = num
    elif min > num:
        min = num


print("Maximum is", int(max))
print("Minimum is", int(min))
