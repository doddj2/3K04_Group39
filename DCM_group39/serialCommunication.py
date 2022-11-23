import serial
import serial.tools.list_ports
import struct

# Mac ports, for windows you have to find the ports yourself
frdm_port = "COM7" #need to update com with actual testing

Start = struct.pack("B",16)
SYNC = struct.pack("B",22)
Fn_set = struct.pack("B",55) #is this neccessary? It was on the example stuff 
#inputs that go into Serial Communication 
#inputs will be just 'test' values for now
#B is for uint 8
#H is for uint16
#f is for float
mode = struct.pack("B", 1)
ppm = struct.pack("B", 0) #LRL equivalent
Upper_rate_limit = struct.pack("B", 1)
Atrial_Amplitude = struct.pack("f", 3.1415926)
Atrial_Pulse_Width = struct.pack("f", 500)
Atrial_Sense_Threshold = struct.pack("H", 500) #is this 'A sensitivity'? 
Ventricular_Amplitude = struct.pack("f", 500)
Ventricular_Pulse_Width = struct.pack("f", 500)
Ventricule_Sense_Threshold = struct.pack("f", 500) #is this 'V sensitivity'? 
VRP = struct.pack("H", 500)
ARP = struct.pack("H", 500)
PVARP = struct.pack("H", 500)
MSR =  struct.pack("H", 500) #what is this? 
reaction_time = struct.pack("H", 500) #and below? I don't 
response_factor = struct.pack("H", 500) #currently recognize it from anything 
recovery_time = struct.pack("H", 500) #in the DCM. Is that something we need to implement?
ActivityThreshold = struct.pack("H", 500)


Signal_set = Start + Fn_set + red_en + green_en + blue_en + off_time + switch_time
Signal_echo = Start + SYNC + red_en + green_en + blue_en + off_time + switch_time

with serial.Serial(frdm_port, 115200) as pacemaker:
    pacemaker.write(Signal_set)

with serial.Serial(frdm_port, 115200) as pacemaker:
    pacemaker.write(Signal_echo)
    data = pacemaker.read(9)
    red_rev = data[0]
    green_rev = data[1]
    blue_rev = data[2]
    off_rev =  struct.unpack("f", data[3:7])[0]
    switch_rev =  struct.unpack("H", data[7:9])[0]

print("From the board:")
print("red_en = ", red_rev)
print("green_en = ", green_rev)
print("blue_en = ", blue_rev)
print("off_time = ",  off_rev)
print("switch_time = ", switch_rev)