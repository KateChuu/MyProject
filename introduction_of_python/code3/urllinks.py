# It very hard to use regular expression to extract html
# because the grammars of html are messy
# so we use 'beautiful soup' to solve the problem

# way1 to use beautiful soup:
# To run this, download the BeautifulSoup zip file
# http://www.py4e.com/code3/bs4.zip
# and unzip it in the same directory as this file

import urllib.request, urllib.parse, urllib.error
from bs4 import BeautifulSoup
import ssl
# 下載bs4.zip解壓縮，放在跟你要執行的程式碼同個資料夾，再貼上上面這三行程式碼

# way2 to use beautiful soup (i don't understand this way???)
# Ignore SSL certificate errors
ctx = ssl.create_default_context()
ctx.check_hostname = False
ctx.verify_mode = ssl.CERT_NONE

url = input('Enter - ')
html = urllib.request.urlopen(url, context=ctx).read()
soup = BeautifulSoup(html, 'html.parser') # html的代理??

# Retrieve all of the anchor tags
tags = soup('a') # a list of 超連結們
for tag in tags:
    print(tag.get('href', None))
