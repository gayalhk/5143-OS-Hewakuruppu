#Gayal Hewakuruppu
#Michael Tull
#Manager.py - Server side code

import socket
import os
from _thread import *
import queue
import json 
import time 

items = []
itemsP=[]

ServerSocket = socket.socket()
host = '167.99.224.154'
port = 33104
ThreadCount = 0
try:
    ServerSocket.bind((host, port))
except socket.error as e:
    print(str(e))

print('Waitiing for a Connection..')
ServerSocket.listen(5)


def threaded_client(connection):
    connection.send(str.encode('Welcome to the Servern'))
    while True:
        data = connection.recv(2048)
        data = data.decode('utf-8')
        data = json.loads(data)
        if data['type']=="producer":
            items.append(data['stock'])
            itemsP.append(data['price'])
            print(data['type']+" "+str(data['id'])+" produced stock "+data['stock']+" for $ "
            +str(data['price']))
        
        elif data['type']=="consumer":
            Stock = items[-1]
            Price = itemsP[-1]
            data['stock']=Stock
            data['price']=Price
            items.remove(Stock)
            itemsP.remove(Price)
            print(data['type']+" "+str(data['id'])+" bought stock "+data['stock']+" at $"
            +str(data['price']))

        #items.append(data)
        #print(len(items))
        reply = "Server Says: " #+ data['id']
        #reply = items[-1]
        if not data:
          break
        connection.sendall(str.encode(reply))
    
    connection.close()

while True:
    Client, address = ServerSocket.accept()
    print('Connected to: ' + address[0] + ':' +str(address[1]))
    start_new_thread(threaded_client, (Client, ))
    ThreadCount += 1
    print('Thread Number: ' + str(ThreadCount))
ServerSocket.close()
    
  
