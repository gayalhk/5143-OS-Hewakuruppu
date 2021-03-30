#Gayal Hewakuruppu
#Michael Tull
#Program 2 - Producer client file

import socket
import random 
import time 
import json

pid = random.randint(1,100)
stocks=["GOOG","MSFT","TSLA","AAPL","GM","BIO","WTM","HUN","VIRT",
"QRTEA"]
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
    price = random.uniform(5.00,1000.00)
    stock_num = random.randint(0,9)
    producer = {'type':"producer",'id':pid ,'stock':stocks[stock_num],
    'price':price}
    data = json.dumps(producer)
    ClientSocket.send(str.encode(data))
    time.sleep(1)
    Response = ClientSocket.recv(1024)
    print(Response.decode('utf-8'),flush=True)

ClientSocket.close()
