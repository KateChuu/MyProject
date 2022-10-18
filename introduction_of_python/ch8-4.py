# Use the file name romeo.txt as the file name
fname = input("Enter file name: ")
fh = open(fname)
# creat a empty list
lst = list()

for line in fh:
    words = line.split() # split the line by space

    for word in words:
        if word not in lst: # if the word is not a duplicate
            lst.append(word) # append it to the list

lst.sort()  # sort the list in alphabetical order
print(lst)

# range() returns a list, ex. range(4) -> [0, 1, 2, 3]
# split() automatically splits string by space(s)
# split(';') splits string by ;

# string is immutable, python copys a string before using it
# list is mutable
