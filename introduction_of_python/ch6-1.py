text = "X-DSPAM-Confidence:    0.8475"

# the first appearance of '0' in the string
index = text.find('0') 
number = text[index:]
print(float(number))
