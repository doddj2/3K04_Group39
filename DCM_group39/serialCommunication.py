import serial
import serial.tools.list_ports
import struct
defVal = -1
#add default values for AA onwards
#this file is the one you spit data to send
frdm_port = "COM6"
Start = b'\x16'
SYNC = b'\x22'
Fn_set = b'\x55'

def check_connect():
    pingval = 1
    ping = struct.pack("B",pingval)

    with serial.Serial(frdm_port, 115200) as pacemaker:
        pacemaker.write(ping)

    response = pacemaker.read(0)
    if response == 1:
        connection = 1 #on
        return connection
    else:
        connection = 0 #off
        return connection
        
def sendToSimulink(mode,lrl,url,AA,APW,AST,VA,VPW,VST,sVRP,sARP,sPVARP,sRS,sMSR,reactionTime,responseFactor,recoveryTime,activityThreshold,HRL):
    
    ### PLEASE CHANGE THIS VALUE TO WHATEVER PORT IS ON YOUR COMPUTER ###

    ### thank you ###
    modei = struct.pack("B", mode) #0-VOO 1-AOO 2-VVI 3-AAI 4-VOOR 5-AOOR 6-VVIR 7-AAIR
    lrli = struct.pack("B", lrl)
    urli = struct.pack("B", url)
    PVARPi = struct.pack("H", sPVARP)
    RSi = struct.pack("B", sRS)
    reaction_timei = struct.pack("H", reactionTime)
    response_factori = struct.pack("B", responseFactor)
    activity_thresholdi = struct.pack("d", activityThreshold)
    #response factor, adctivity threshold
    recovery_timei = struct.pack("H", recoveryTime)
    MSRi = struct.pack("B", sMSR)
    atr_ampi = struct.pack("d", AA)
    atr_pulse_widthi = struct.pack("d", APW)
    ARPi = struct.pack("H", sARP)
    atr_thresholdi = struct.pack("d", AST)
    vent_ampi = struct.pack("d", VA)
    vent_pulse_widthi = struct.pack("d", VPW)
    VRPi = struct.pack("H", sVRP)
    vent_thresholdi = struct.pack("d", VST)
    """
    modei = struct.pack("B", 1)  # 0-VOO 1-AOO 2-VVI 3-AAI 4-VOOR 5-AOOR 6-VVIR 7 VVIR
    lrli = struct.pack("B", 60)
    urli = struct.pack("B", 120)
    PVARPi = struct.pack("H", 100)
    RSi = struct.pack("B", 149)
    reaction_timei = struct.pack("H", 2000)
    response_factori = struct.pack("B", 17)
    activity_thresholdi = struct.pack("d", 1.5)
    # response factori, adctivity threshold
    recovery_timei = struct.pack("H", 2000)
    MSRi = struct.pack("B", 160)
    atr_ampi = struct.pack("d", 3.6)
    atr_pulse_widthi = struct.pack("d", 5)
    ARPi = struct.pack("H", 150)
    atr_thresholdi = struct.pack("d", 3.0)
    vent_ampi = struct.pack("d", 4.1)
    vent_pulse_widthi = struct.pack("d", 5.3)
    VRPi = struct.pack("H", 150)
    vent_thresholdi = struct.pack("d", 2.3)
    """
    #broken up like this for the sake of readability and testing
    Signal_set = Start + Fn_set + modei + lrli + urli + atr_ampi + atr_pulse_widthi + atr_thresholdi + vent_ampi + \
                 vent_pulse_widthi + vent_thresholdi + VRPi + ARPi + PVARPi + RSi + MSRi + reaction_timei + \
                 response_factori + recovery_timei + activity_thresholdi

    Signal_set_order = Start + Fn_set + modei + lrli + urli + PVARPi + RSi + reaction_timei + response_factori + \
                       activity_thresholdi + recovery_timei + MSRi + atr_ampi + atr_pulse_widthi + ARPi + atr_thresholdi \
                       + vent_ampi + vent_pulse_widthi + VRPi + vent_thresholdi

    Signal_echo = Start + SYNC + modei + lrli + urli + atr_ampi + atr_pulse_widthi + atr_thresholdi + vent_ampi \
                  + vent_pulse_widthi + vent_thresholdi + VRPi + ARPi + PVARPi + RSi + MSRi+reaction_timei + \
                  response_factori + recovery_timei + activity_thresholdi

    Signal_echo_order = Start + SYNC + modei + lrli + urli + PVARPi + RSi + reaction_timei + response_factori + \
                       activity_thresholdi + recovery_timei + MSRi + atr_ampi + atr_pulse_widthi + ARPi + atr_thresholdi \
                       + vent_ampi + vent_pulse_widthi + VRPi + vent_thresholdi

    print("arrive here 2")
    with serial.Serial(frdm_port, 115200) as pacemaker:
        pacemaker.write(Signal_set_order)

    with serial.Serial(frdm_port, 115200) as pacemaker:
        pacemaker.write(Signal_echo_order)
        print(len(Signal_set))
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

    #EGRAM PINS



        #if mode_echo == mode and lrl_echo == lrl and url_echo == url and PVARP_echo == sPVARP and RS_echo == sRS and reaction_time_echo == reactionTime and response_factor_echo == responseFactor and activity_threshold_echo == activityThreshold and recovery_time_echo == recoveryTime and MSR_echo == sMSR and atr_amp_echo == AA and atr_pulse_width_echo == APW and ARP_echo == sARP and atr_threshold_echo == AST and vent_amp_echo == VA and vent_pulse_width_echo == VPW and VRP_echo == sVRP and vent_threshold_echo == VST:
            #return True
        #else:
            #return False
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
    """
    print("From the board:") #more values for testing later
    print("mode = ", mode)
    print("lrl = ", lrl)
    print("URL = ", Upper_rate_limit)
    print("Atrial Amp = ",  Atrial_Amplitude)
    print("Atrial Pulse Width = ", Atrial_Pulse_Width)
    #skip to end - if all this data has lined up correctly, activity threshold should be what is input.
    print("Activity Threshold = ", ActivityThreshold)
    """
