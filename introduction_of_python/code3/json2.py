import json

# a list of dictionaries [{}, {}]
data = '''
[
  { "id" : "001",
    "x" : "2",
    "name" : "Chuck"
  } ,
  { "id" : "009",
    "x" : "7",
    "name" : "Brent"
  }
]'''

info = json.loads(data)
print('User count:', len(info)) # there are 2 dictionaries in the list

for item in info: # run 2 times
    print('Name', item['name'])
    print('Id', item['id'])
    print('Attribute', item['x'])
