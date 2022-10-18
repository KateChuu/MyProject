# Use the file name mbox-short.txt as the file name
fname = input("Enter file name: ")
fh = open(fname)
sum = 0
count = 0

for line in fh:
    if line.startswith("X-DSPAM-Confidence:"):
        index = line.find('0')
        number = float(line[index:])
        sum = sum + number
        count = count + 1

print('Average spam confidence:', sum / count)
