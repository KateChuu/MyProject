# http://py4e-data.dr-chuck.net/comments_1153804.json
import urllib.request
import urllib.parse
import urllib.error
import json
import ssl
# Ignore SSL certificate errors
ctx = ssl.create_default_context()
ctx.check_hostname = False
ctx.verify_mode = ssl.CERT_NONE

url = input('Enter - ')
html = urllib.request.urlopen(url).read().decode()

print('Retrieving', url)  # print時用原本的url就好
print('Retrieved', len(html), 'characters')  # len(html)是計算全部有幾個char

try: 
    js = json.loads(html)
except:
    js = None

count = 0
sum = 0
# key 'comments' 對應的value是一個有50個dictionaries的list
for item in js['comments']:  # run 50 times
    count = count + 1
    sum = sum + int(item['count'])

print("Count", count)
print("Sum", sum)
