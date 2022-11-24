#serial communications prototype
import time
import struct
import serial
import serial.tools.list_ports
ports = serial.tools.list_ports.comports()
serialInst = serial.Serial()

portList = []

for onePort in ports: 
    portList.append(str(onePort))
    print(str(onePort))

val = input("select Port: COM")
for x in range(0,len(portList)):
    if(portList[x].startswith("COM"+str(val))):
        portVar = "COM" + str(val)
        print(portList[x])

serialInst.baudrate = 9600
serialInst.port = portVar 
serialInst.open()

while True: 
    if serialInst.in_waiting: #iff waiting for data, read it in
        packet = serialInst.readline()
        print(packet.decode('utf'))


3