import serial
import serial.tools.list_ports
import struct


#add default values for AA onwards
#this file is the one you spit data to send

def check_connect():

    pingval = 1
    ping = struct.pack("B",pingval) 
    frdm_port = "COM3"
    with serial.Serial(frdm_port, 115200) as pacemaker:
        pacemaker.write(ping)
        connection=0
        response = pacemaker.read(0)
        if response == 1:
            connection = 1 #on
        else:
            connection = 0 #off 
    return connection
        
def sendToSimulink(mode,ppm,url,AA,APW,AST,VA,VPW,VST,sVRP,sARP,sPVARP,sRS,sMSR,reactionTime,responseFactor,recoveryTime,activityThreshold,HRL):
    # Mac ports, for windows you have to find the ports yourself
    frdm_port = "COM3"
    #inputs that go into Serial Communication 
    #inputs will be just 'test' values for now
    #B is for uint 8
    #H is for uint16
    #f is for float
    Start = struct.pack("B",16)
    SYNC = struct.pack("B",69) #start of data packet
    #Fn_code = struct.pack("B",FnCode) #defines behavior, parameters, echo, egrams or estop
     #need to update com with actual testing
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
    data = pacemaker.read(88)

    mode_echo = struct.unpack('B',data[0:1])[0]
    lrl_echo = struct.unpack('B',data[1:2])[0]
    url_echo = struct.unpack('B',data[2:3])[0]
    PVARP_echo = struct.unpack("H", data[3:5])[0]
    RS_echo = struct.unpack("B", data[5:6])[0]
    reaction_time_echo = struct.unpack("H", data[6:8])[0]
    response_factor_echo = struct.unpack("B", data[8:9])[0]
    activity_threshold_echo = struct.unpack("d", data[9:17])[0]
    recovery_time_echo = struct.unpack("H", data[17:19])[0]
    MSR_echo = struct.unpack("B", data[19:20])[0]
    atr_amp_echo = struct.unpack("d", data[20:28])[0]
    atr_pulse_width_echo = struct.unpack("d", data[28:36])[0]
    ARP_echo = struct.unpack("H", data[36:38])[0]
    atr_threshold_echo = struct.unpack("d", data[38:46])[0]
    vent_amp_echo = struct.unpack("d", data[46:54])[0]
    vent_pulse_width_echo = struct.unpack("d", data[54:62])[0]
    VRP_echo = struct.unpack("H", data[62:64])[0]
    vent_threshold_echo = struct.unpack("d", data[64:72])[0]
    
    ATR_signal = struct.unpack("d", data[72:80])[0]
    VENT_signal = struct.unpack("d", data[80:88])[0]
    print(ATR_signal)
    print(VENT_signal)
    print("From the board:") #more values for testing later
    print("mode = ", mode)
    print("ppm = ", ppm)
    print("URL = ", Upper_rate_limit)
    print("Atrial Amp = ",  Atrial_Amplitude)
    print("Atrial Pulse Width = ", Atrial_Pulse_Width)
    #skip to end - if all this data has lined up correctly, activity threshold should be what is input.
    print("Activity Threshold = ", ActivityThreshold)
def read_ecg():
    frdm_port = "COM3"
    Start = b'\x16'
    SYNC = b'\x22'
    Fn_set = b'\x55'
    Signal_echo = Start + SYNC
    i=0
    while(i<72):
        Signal_echo = Signal_echo + struct.pack("B", 0)
        i = i+1
    with serial.Serial(frdm_port, 115200) as pacemaker:
        pacemaker.write(Signal_echo)
        data = pacemaker.read(88)
        ATR_signal = struct.unpack("d", data[72:80])[0]
        VENT_signal = struct.unpack("d", data[80:88])[0]
        return [ATR_signal,VENT_signal]