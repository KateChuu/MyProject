import urllib.request
import urllib.parse
import urllib.error
import xml.etree.ElementTree as ET
import ssl

# Ignore SSL certificate errors
ctx = ssl.create_default_context()
ctx.check_hostname = False
ctx.verify_mode = ssl.CERT_NONE

url = input('Enter - ')
# 需要把url decode才能給xml使用????
html = urllib.request.urlopen(url).read().decode()
tree = ET.fromstring(html)

print('Retrieving', url) # print時用原本的url就好
print('Retrieved', len(html), 'characters') # len(html)是計算全部有幾個char
print('Count:', len(tree)) # len(tree)是計算tree的深度???

sum = 0
# 要找<comments>裡面的<comment></comment></comments>
lst = tree.findall('comments/comment')

for item in lst:
    # 再找<count>中間的東西</count>
    sum = sum + int(item.find('count').text)
print("Sum", sum)
