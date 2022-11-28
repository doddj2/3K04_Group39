import serial
import serial.tools.list_ports
import struct


#add default values for AA onwards
#this file is the one you spit data to send

def check_connect():

    pingval = 1
    ping = struct.pack("B",pingval) 
    frdm_port = "COM6"
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
    frdm_port = "COM6"
    #inputs that go into Serial Communication 
    #inputs will be just 'test' values for now
    #B is for uint 8
    #H is for uint16
    #f is for float
    #Start = struct.pack("B",16)
    #SYNC = struct.pack("B",69) #start of data packet
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
    RS =  struct.pack("B", sRS)  
    MSR =  struct.pack("B", sMSR)
    reaction_time = struct.pack("B", reactionTime) #and below? I don't 
    response_factor = struct.pack("B", responseFactor) #currently recognize it from anything 
    recovery_time = struct.pack("B", recoveryTime) #in the DCM. Is that something we need to implement?
    ActivityThreshold = struct.pack("B", activityThreshold)"""
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

    ### EGRAM PINS
    ATR_signal = struct.unpack("d", data[72:80])[0]
    VENT_signal = struct.unpack("d", data[80:88])[0]

    if mode_echo == mode and lrl_echo == lrl and url_echo == url and PVARP_echo == sPVARP and RS_echo == sRS and reaction_time_echo == reactionTime and response_factor_echo == responseFactor and activity_threshold_echo == activityThreshold and recovery_time_echo == recoveryTime and MSR_echo == sMSR and atr_amp_echo == AA and atr_pulse_width_echo == APW and ARP_echo == sARP and atr_threshold_echo == AST and vent_amp_echo == VA and vent_pulse_width_echo == VPW and VRP_echo == sVRP and vent_threshold_echo == VST:
        return True
    else:
        return False
    """
    data = pacemaker.read(9)
    modep = data[0]
    lrlp = data[1]
    urlp = data[2]
    aap = data[3]
    apwp = data[4]#change datatype?
    asensep = data[5] #is this 'A sensitivity'? 
    vap = data[6]
    vpwp = data[7] #change datatype?
    vsensep = data[8] #is this 'V sensitivity'? 
    VRPp = data[9]
    ARPp = data[10]
    PVARPp = data[11] #explain what pvarp is 
    MSRp =  data[12]  
    rrp = data[13] #and below? I don't 
    rfp = data[14] #currently recognize it from anything 
    rectp = data[15] #in the DCM. Is that something we need to implement?
    atp = data[16]
    """
    # off_rev =  struct.unpack("f", data[3:7])[0]
    # switch_rev =  struct.unpack("H", data[7:9])[0]
    print("From the board:") #more values for testing later
    print("mode = ", mode)
    print("lrl = ", lrl)
    print("URL = ", Upper_rate_limit)
    print("Atrial Amp = ",  Atrial_Amplitude)
    print("Atrial Pulse Width = ", Atrial_Pulse_Width)
    #skip to end - if all this data has lined up correctly, activity threshold should be what is input.
    print("Activity Threshold = ", ActivityThreshold)
