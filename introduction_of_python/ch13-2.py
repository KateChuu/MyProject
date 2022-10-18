# http://py4e-data.dr-chuck.net/known_by_Sawdah.html

import urllib.request
import urllib.parse
import urllib.error
from bs4 import BeautifulSoup
import ssl
# 下載bs4.zip解壓縮，放在跟你要執行的程式碼同個資料夾，再貼上上面這三行程式碼

ctx = ssl.create_default_context()
ctx.check_hostname = False
ctx.verify_mode = ssl.CERT_NONE

url = input('Enter URL: ')
html = urllib.request.urlopen(url, context=ctx).read()
soup = BeautifulSoup(html, 'html.parser')  # html的代理??
count = int(input('Enter count: '))
pos = int(input('Enter position: '))
# Retrieve all of the anchor tags
tags = soup('a')  # a list of 超連結們

for i in range(0, count):
    line = 1
    for tag in tags:
        # 當程式進行到指定的行數，就跳出這個tags
        if line == pos:
            url = tag.get('href', None)
            print('Retrieving:', url)
            break
        line = line + 1

    # 連接到下一個超連結
    html = urllib.request.urlopen(url, context=ctx).read()
    soup = BeautifulSoup(html, 'html.parser')
    tags = soup('a')
