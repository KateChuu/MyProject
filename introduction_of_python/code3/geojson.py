# get the data from Google API in JSON structure 
# enter 'Ann Arbor, MI' for example
import urllib.request, urllib.parse, urllib.error
import json
import ssl

api_key = False
# If you have a Google Places API key, enter it here
# api_key = 'AIzaSy___IDByT70'
# https://developers.google.com/maps/documentation/geocoding/intro

if api_key is False:
    api_key = 42
    serviceurl = 'http://py4e-data.dr-chuck.net/json?'
else :
    serviceurl = 'https://maps.googleapis.com/maps/api/geocode/json?'

# Ignore SSL certificate errors
ctx = ssl.create_default_context()
ctx.check_hostname = False
ctx.verify_mode = ssl.CERT_NONE

while True:
    address = input('Enter location: ')
    if len(address) < 1: break

    # change the parameters into the address format
    # because we use the data which come from google map???
    parms = dict() # parem = parameters
    parms['address'] = address
    if api_key is not False: parms['key'] = api_key
    # change the address into the url format, so that we can use it
    url = serviceurl + urllib.parse.urlencode(parms)

    print('Retrieving', url)
    uh = urllib.request.urlopen(url, context=ctx) # uh = url handle
    data = uh.read().decode() # read the data, and change utf-8 to unicode
    print('Retrieved', len(data), 'characters')

    try:
        js = json.loads(data) # load data in json format 
    except:
        js = None

    # check that js != None, or the data in js are available
    if not js or 'status' not in js or js['status'] != 'OK':
        print('==== Failure To Retrieve ====')
        print(data)
        continue

    print(json.dumps(js, indent=4)) # 設定json縮排為四格

    # find the data along the tree
    
    # key 'result' -> [0] element in the list of values
    # -> geometry -> location -> lat
    lat = js['results'][0]['geometry']['location']['lat']
    lng = js['results'][0]['geometry']['location']['lng']
    print('lat', lat, 'lng', lng)

    location = js['results'][0]['formatted_address']
    print(location)
