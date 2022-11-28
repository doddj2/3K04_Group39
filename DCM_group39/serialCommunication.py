import serial
import serial.tools.list_ports
import struct
defVal = -1
#add default values for AA onwards
#this file is the one you spit data to send

def check_connect():
    pingval = 1
    ping = struct.pack("B",pingval) 
    
    with serial.Serial(frdm_port, 115200) as pacemaker:
        pacemaker.write(ping)

    response = pacemaker.read(0)
    if response == 1:
        conntection = 1 #on
    else:
        connection = 0 #off 
        
def sendToSimulink(mode,ppm,url,AA,APW,AST,VA,VPW,VST,sVRP,sARP,sPVARP,sRS,sMSR,reactionTime,responseFactor,recoveryTime,activityThreshold,HRL):
    # Mac ports, for windows you have to find the ports yourself
    
    #inputs that go into Serial Communication 
    #inputs will be just 'test' values for now
    #B is for uint 8
    #H is for uint16
    #f is for float
    #Start = struct.pack("B",16)
    #SYNC = struct.pack("B",69) #start of data packet
    #Fn_code = struct.pack("B",FnCode) #defines behavior, parameters, echo, egrams or estop
    frdm_port = "COM6" #need to update com with actual testing
    mode = struct.pack("B", mode)
    ppm = struct.pack("B", ppm) #LRL equivalent
    Upper_rate_limit = struct.pack("B", url)
    Atrial_Amplitude = struct.pack("f", AA)
    Atrial_Pulse_Width = struct.pack("B", APW) #change datatype?
    Atrial_Sense_Threshold = struct.pack("H", AST) #is this 'A sensitivity'? 
    Ventricular_Amplitude = struct.pack("f", VA)
    Ventricular_Pulse_Width = struct.pack("f", VPW) #change datatype?
    Ventricule_Sense_Threshold = struct.pack("f", VST) #is this 'V sensitivity'? 
    VRP = struct.pack("H", sVRP)
    ARP = struct.pack("H", sARP)
    PVARP = struct.pack("H", sPVARP) #explain what pvarp is 
    RS =  struct.pack("B", sRS) #what is this? 
    MSR =  struct.pack("B", sMSR) #what is this? 
    reaction_time = struct.pack("B", reactionTime) #and below? I don't 
    response_factor = struct.pack("B", responseFactor) #currently recognize it from anything 
    recovery_time = struct.pack("B", recoveryTime) #in the DCM. Is that something we need to implement?
    ActivityThreshold = struct.pack("B", activityThreshold)

    #broken up like this for the sake of readability and testing
    Signal_set = mode + ppm + Upper_rate_limit + Atrial_Amplitude + Atrial_Pulse_Width + Atrial_Sense_Threshold 
    Signal_set = Signal_set + Ventricular_Amplitude + Ventricular_Pulse_Width + Ventricule_Sense_Threshold 
    Signal_set = Signal_set + VRP + ARP + PVARP + RS + MSR
    Signal_set = Signal_set + reaction_time + response_factor + recovery_time + ActivityThreshold

    Signal_echo = mode + ppm + Upper_rate_limit + Atrial_Amplitude + Atrial_Pulse_Width + Atrial_Sense_Threshold 
    Signal_echo = Signal_echo + Ventricular_Amplitude + Ventricular_Pulse_Width + Ventricule_Sense_Threshold 
    Signal_echo = Signal_echo + VRP + ARP + PVARP + RS + MSR
    Signal_echo = Signal_echo + reaction_time + response_factor + recovery_time + ActivityThreshold

    with serial.Serial(frdm_port, 115200) as pacemaker:
        pacemaker.write(Signal_set)

    with serial.Serial(frdm_port, 115200) as pacemaker:
        pacemaker.write(Signal_echo)
    data = pacemaker.read(9)
    mode = data[0]
    ppm = data[1]
    Upper_rate_limit = data[2]
    Atrial_Amplitude = data[3]
    Atrial_Pulse_Width = data[4]#change datatype?
    Atrial_Sense_Threshold = data[5] #is this 'A sensitivity'? 
    Ventricular_Amplitude = data[6]
    Ventricular_Pulse_Width = data[7] #change datatype?
    Ventricule_Sense_Threshold = data[8] #is this 'V sensitivity'? 
    VRP = data[9]
    ARP = data[10]
    PVARP = data[11] #explain what pvarp is 
    MSR =  data[12] #what is this? 
    reaction_time = data[13] #and below? I don't 
    response_factor = data[14] #currently recognize it from anything 
    recovery_time = data[15] #in the DCM. Is that something we need to implement?
    ActivityThreshold = data[16]
    # off_rev =  struct.unpack("f", data[3:7])[0]
    # switch_rev =  struct.unpack("H", data[7:9])[0]
    print("From the board:") #more values for testing later
    print("mode = ", mode)
    print("ppm = ", ppm)
    print("URL = ", Upper_rate_limit)
    print("Atrial Amp = ",  Atrial_Amplitude)
    print("Atrial Pulse Width = ", Atrial_Pulse_Width)
    #skip to end - if all this data has lined up correctly, activity threshold should be what is input.
    print("Activity Threshold = ", ActivityThreshold)
