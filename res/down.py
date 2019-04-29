import urllib.request
from progress.bar import Bar

filepath = '/tmp/ids.txt'

def file_lengthy(fname):
  with open(fname) as f:
    for i, l in enumerate(f):
      pass
  return i + 1

total = file_lengthy(filepath)

size =  0.000477 * total

print("Size Download: " + str(size) + "Mib")

bar = Bar('Processing', max=total)

  
with open(filepath) as fp:  
  line = fp.readline()
  while line:
    number = line.strip()
    urllib.request.urlretrieve("http://file5.ratemyserver.net/items/small/" + number + ".gif", number + ".gif")
    bar.next()
    line = fp.readline()
bar.finish()
