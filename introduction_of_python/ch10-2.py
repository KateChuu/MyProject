name = input("Enter file:")
if len(name) < 1:
    name = "mbox-short.txt"
handle = open(name)

hours = list() # store all of the hours 
counts = dict()

# get the hours
for line in handle:
    if line.startswith('From '):
        tmp = line.split() # seperate the line word by word
        tmp = tmp[5].split(':') # ex. 09:44:12
        hours.append(tmp[0]) # append 09 in the list

# count the frequencies
for hour in hours:
    counts[hour] = counts.get(hour, 0) + 1

# chenge the dictionary(counts) to list of tuples(tmpList)
# ex. {'09': 1, '08': 2, '07': 3} 
# -> [('09', 1), ('08', 2), ('07', 3)]
tmpList = list()
for key, value in counts.items():
    tmpList.append((key, value))

# sort by the largest to the smallest
tmpList = sorted(tmpList, reverse=True)

for key, value in tmpList:
    print(key, value)
