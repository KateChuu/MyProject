# Use the file name mbox-short.txt as the file name

# print the dates
print('The dates:')
fh = open('mbox-short.txt')
for line in fh:
    # line = line.rstrip() 這行好像可以不加?
    words = line.split()
    if len(words) < 3 or words[0] != 'From': continue
    print(words[2])

# print the email address (no duplicates)
fname = input("Enter file name: ")
if len(fname) < 1:
    fname = "mbox-short.txt"

fh = open(fname)
count = 0
lst = list()

for line in fh:
    if line.startswith('From'):
        words = line.split()

        if words[0] == 'From:': # skip the line starts with 'From:'
            continue

        if words[1] not in lst: # skip the same email address
            lst.append(words[1])
            print(words[1])
            count = count + 1

print("There were", count, "lines in the file with From as the first word")
