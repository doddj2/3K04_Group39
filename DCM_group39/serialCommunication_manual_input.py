import serial
import serial.tools.list_ports
import struct

frdm_port = "COM5"

#B is for uint 8
#H is for uint16
#f is for float
Start = b'\x16'
SYNC = b'\x22'
Fn_set = b'\x55'

#manual input
mode = struct.pack("B", 2) #0-VOO 1-AOO 2-VVI 3-AAI 4-VOOR 5-AOOR 6-VVIR 7-AAIR
lrl = struct.pack("B", 60)
url = struct.pack("B", 120)
PVARP = struct.pack("H", 100)
av_delay = struct.pack("B", 149)
reaction_time = struct.pack("H", 22)
response_factor = struct.pack("B", 17)
activity_threshold = struct.pack("d", 1.5)
#response factor, adctivity threshold
recovery_time = struct.pack("H", 21)
MSR = struct.pack("B", 120)
atr_amp = struct.pack("d", 3.6)
atr_pulse_width = struct.pack("d", 5)
ARP = struct.pack("H", 400)
atr_threshold = struct.pack("d", 3.0)
vent_amp = struct.pack("d", 4.1)
vent_pulse_width = struct.pack("d", 5.3)
VRP = struct.pack("H", 400)
vent_threshold = struct.pack("d", 2.3)

#broken up like this for the sake of readability and testing
Signal_set = Start + Fn_set + mode + lrl + url + PVARP + av_delay + reaction_time + response_factor + activity_threshold \
             + recovery_time + MSR + atr_amp + atr_pulse_width + ARP + atr_threshold + vent_amp + vent_pulse_width + VRP \
             + vent_threshold
print(len(Signal_set))
Signal_echo = Start + SYNC + mode + lrl + url + PVARP + av_delay + reaction_time + response_factor+ activity_threshold \
              + recovery_time + MSR + atr_amp + atr_pulse_width + ARP + atr_threshold + vent_amp + vent_pulse_width + VRP \
              + vent_threshold
print(len(Signal_echo))

with serial.Serial(frdm_port, 115200) as pacemaker:
    pacemaker.write(Signal_set)

with serial.Serial(frdm_port, 115200) as pacemaker:
    pacemaker.write(Signal_echo)
    data = pacemaker.read(72)

    mode_echo = struct.unpack('B',data[0:1])[0]
    lrl_echo = struct.unpack('B',data[1:2])[0]
    url_echo = struct.unpack('B',data[2:3])[0]
    PVARP_echo = struct.unpack("H", data[3:5])[0]
    av_delay_echo = struct.unpack("B", data[5:6])[0]
    reaction_time_echo = struct.unpack("H", data[6:8])[0]
    response_factor_echo = struct.unpack("B", data[8:9])[0]
    activity_threshold_echo = struct.unpack("d", data[9:17])[0]
    recovery_time_echo = struct.unpack("H", data[17:19])[0]
    MSR_echo = struct.unpack("B", data[19:20])[0]
    atr_amp_echo = struct.unpack("d", data[20:28])[0]
    atr_pulse_width_echo = struct.unpack("d", data[28:36])[0]
    ARP_echo = struct.unpack("H", data[36:38])[0]
    atr_threshold = struct.unpack("d", data[38:46])[0]
    vent_amp_echo = struct.unpack("d", data[46:54])[0]
    vent_pulse_width_echo = struct.unpack("d", data[54:62])[0]
    VRP_echo = struct.unpack("H", data[62:64])[0]
    vent_threshold_echo = struct.unpack("d", data[64:72])[0]

print(len(data))
print("From the board:")
print("mode = ", mode_echo)
print("LRL = ", lrl_echo)
print("URL = ", url_echo)
print("PVARP = ", PVARP_echo)
print("av_delay = ", av_delay_echo)
print("reaction_time = ", reaction_time_echo)
print("response_factor = ", response_factor_echo)
print("activity_threshold = ", activity_threshold_echo)
print("recovery_time = ", recovery_time_echo)
print("MSR = ", MSR_echo)
print("atr_amp = ", atr_amp_echo)
print("atr_pulse_width = ", atr_pulse_width_echo)
print("ARP = ", ARP_echo)
print("atr_threshold = ", atr_threshold)
print("vent_amp = ", vent_amp_echo)
print("vent_pulse_width = ", vent_pulse_width_echo)
print("VRP = ", VRP_echo)
print("vent_threshold = ", vent_threshold_echo)

