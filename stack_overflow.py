import urllib.parse
import urllib.request

url = 'http://59.145.203.105/'
values = {'txtRoll' : '1305024',
          'txtEnroll' : '13139428723',
          'btnSubmit' : 'formSubmit'
           }

data = urllib.parse.urlencode(values)
binary_data=data.encode('ascii')
req = urllib.request.Request(url, binary_data)
response = urllib.request.urlopen(req)
the_page = response.read()
print(the_page)
