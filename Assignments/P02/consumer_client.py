#Gayal Hewakuruppu
#Michael Tull
#Program 2 - Consumer client file

import socket
import random
import time 
import json

cid = random.randint(1,100)
ClientSocket = socket.socket()
host = '167.99.224.154'
port = 33104

print('Waiting for connection')
try:
    ClientSocket.connect((host, port))
except socket.error as e:
    print(str(e))

Response = ClientSocket.recv(1024)
while True:
    consumer = {'type':"consumer",'id':cid ,'stock':" "}
    data = json.dumps(consumer)
    ClientSocket.send(str.encode(data))
    time.sleep(2)
    Response = ClientSocket.recv(1024)
    print(Response.decode('utf-8'))

ClientSocket.close()
