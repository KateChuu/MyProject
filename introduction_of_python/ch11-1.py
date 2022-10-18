import re # import regular expression

name = input("Enter File:")
if len(name) < 1:
    name = "regexp.txt"
handle = open(name)

sum = 0
for line in handle:
    numbers = re.findall('([0-9]+)', line)
    # print(numbers)
    if numbers is not None:
        for n in numbers:
            sum = sum + float(n)
print(sum)

# re.search returns a True/False depending on whether the string matches the regular expression
# re.findall() returns the string we want to extract
# ([0-9]+): extract one or more digits
# ?: non-greedy, returns the string which is as short as possible
