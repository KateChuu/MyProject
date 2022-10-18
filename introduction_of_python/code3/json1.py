import json

# the value for "phone" is a dictionary too
data = '''
{
  "name" : "Chuck",
  "phone" : {
    "type" : "intl",
    "number" : "+1 734 303 4456"
  }, 
  "email" : {
    "hide" : "yes"
  }
}'''

info = json.loads(data) # info is a dictionary!
print('Name:', info["name"])
print('Hide:', info["email"]["hide"])
