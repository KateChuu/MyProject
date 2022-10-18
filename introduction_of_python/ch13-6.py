import urllib.request
import urllib.parse
import json

serviceurl = 'http://py4e-data.dr-chuck.net/json?key=42&'

address = input('Enter location: ')
parms = {"sensor": "false", "address": address}  # parem = parameters
url = serviceurl + urllib.parse.urlencode(parms)
print('Retrieving', url)

uh = urllib.request.urlopen(url)  # uh = url handle
data = uh.read().decode()  # read the data, and change utf-8 to unicode
print('Retrieved', len(data), 'characters')

try:
    js = json.loads(data)  # load data in json format
except:
    js = None

# check that js != None, or the data in js are available
if not js or 'status' not in js or js['status'] != 'OK':
    print('==== Failure To Retrieve ====')
    print(data)
    quit()

place_id = js["results"][0]["place_id"]
print(place_id)
