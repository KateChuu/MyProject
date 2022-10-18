# txt檔要跟程式碼放在同一個資料夾!!!
# 也要輸入副檔名, ex.words.txt
# Use the file name words.txt as the file name
fname = input("Enter file name: ")

# fh = file handle, a way to get data from second memory
fh = open(fname) 
for line in fh:
    line = line.rstrip()
    print(line.upper())
