#!/usr/bin/python3

from progress.bar import Bar
import pymysql

filepath = '/tmp/ids.txt'

def file_lengthy(fname):
  with open(fname) as f:
    for i, l in enumerate(f):
      pass
  return i + 1

total = file_lengthy(filepath)
bar = Bar('Processing', max=total)

# Open database connection
db = pymysql.connect(host="192.168.1.69", user="root",passwd="mirolhadb", db="rathena_rag")

# prepare a cursor object using cursor() method
cursor = db.cursor()

with open(filepath) as fp:  
  line = fp.readline()
  while line:
    number = line.strip()
    # Prepare SQL query to UPDATE required records
    sql = "update rathena_rag.item_db set item_image=load_file('/tmp/" + str(number) + ".gif') WHERE id=" + str(number)
    try:
      # Execute the SQL command
      cursor.execute(sql)
      # Commit your changes in the database
      db.commit()
      bar.next()
      line = fp.readline()
    except:
      # Rollback in case there is any error
      db.rollback()
      bar.next()
      line = fp.readline()

# disconnect from server
db.close()
bar.finish()
