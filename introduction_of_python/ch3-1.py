# basic version
hrs = input("Enter hrs:")
rate = input("Enter rate:")
print("Pay:", float(hrs) * float(rate))

# advanced version
hrs = input("Enter Hours:")
rate = input("Enter Rate:")
try:
    h = float(hrs)
    r = float(rate)
except:
    print("Please enter the correct number")
    quit() # end the program

if h > 40:
    print(40 * r + (h - 40) * r * 1.5)
else :
    print(h * r)


def computepay(h,r):
    if h > 40:
        return 40 * r + (h - 40) * r * 1.5
    else:
        return 42.37

hrs = input("Enter Hours:")
rate = input("Enter Rate:")
try:
    h = float(hrs)
    r = float(rate)
except:
    print("Error")
    quit()

p = computepay(h, r)
print("Pay", p)