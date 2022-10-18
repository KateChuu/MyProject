# Use the file name mbox-short.txt as the file name

name = input("Enter file:")
if len(name) < 1:
    name = "mbox-short.txt"
handle = open(name)
emails = list() # store all the emails appeared
counts = dict() # the frequencies of emails

# get the emails
for line in handle:
    if line.startswith('From '):
        words = line.split()
        emails.append(words[1])

# count the frequencies
for email in emails:
    counts[email] = counts.get(email, 0) + 1

# find the most frequent one
max = 0
maxMail = None
# dict.items() gets both keys and values in the dictionary
for key, value in counts.items(): 
    if value > max:
        max = value
        maxMail = key

print(maxMail, max)

# dict.keys() returns a list of keys
# dict.values() returns a list of values
# list[] dict{} tuple()
