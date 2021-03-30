#Gayal Hewakuruppu
#Michael Tull
#Manager.py - Server side code

import socket
import os
from _thread import *
import queue
import json 
import time
from queue import Queue

stockName = Queue(maxsize = 15)
stockPrice = Queue(maxsize = 15)

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

            if stockName.full()==True:
                reply = "Production Unsuccessful"

            else:
                stockName.put(data['stock'])
                stockPrice.put(data['price'])
                print(data['type']+" "+str(data['id'])+" produced stock "+data['stock']+" for $ "
                +str(data['price']))
                reply = "Production Successful"
            
        
        elif data['type']=="consumer":

            if stockName.empty()==True:
                reply = "Consumption Unsuccessful"

            else:
                data['stock']=stockName.get()
                data['price']=stockPrice.get()
                print(data['type']+" "+str(data['id'])+" bought stock "+data['stock']+" at $"
                +str(data['price']))
                reply = "Consumption Successful"

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
    
  
