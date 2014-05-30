import urllib.parse
import urllib.request

url = 'http://59.145.203.105/'
values = {'txtRoll' : '1305024',
          'txtEnroll' : '13139428723',
          'txhSunmit'  : 'Submit'
           }

data = urllib.parse.urlencode(values)
binary_data=data.encode()
req = urllib.request.Request(url, binary_data)
response = urllib.request.urlopen(req)
the_page = response.read().decode()
html=open('Grade_Sheet.html','w+')
print(the_page,file=html)
html.close()
