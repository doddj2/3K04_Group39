#import modules

from math import ceil
from tkinter import *
import os
import time
import tkinter
import InputScreen
from combineFuncs import combine_funcs
from combineFuncs import roundToNearest
from serialCommunication import sendToSimulink
#global constants

#registration
 
def register():
    global register_screen
    register_screen = Toplevel(main_screen)
    register_screen.title("Register")
    register_screen.geometry("300x300")
 
    global username
    global password
    global confirm
    global username_entry
    global password_entry
    global confirm_entry
    
    username = tkinter.StringVar(register_screen)
    password = StringVar()
    confirm = StringVar()
 
    Label(register_screen, text="Please enter details below").pack()
    Label(register_screen, text="").pack()
    
    username_lable = Label(register_screen, text="Username * ")
    username_lable.pack()
    username_entry = Entry(register_screen, textvariable=username)
    username_entry.pack()
    
    password_lable = Label(register_screen, text="Password * ")
    password_lable.pack()
    password_entry = Entry(register_screen, textvariable=password, show= '*')
    password_entry.pack()
    
    confirm_lable = Label(register_screen, text="Verify Password * ")
    confirm_lable.pack()
    confirm_entry = Entry(register_screen, textvariable=confirm, show= '*')
    confirm_entry.pack()
    
    list_of_files = os.listdir()  
    Label(register_screen, text="").pack()
    Button(register_screen, text="Register", width=10, height=1, bg="light green", command = register_user).pack()
 

# login 
 
def login():
    global login_screen
    login_screen = Toplevel(main_screen)
    login_screen.title("Login")
    login_screen.geometry("300x250")
    Label(login_screen, text="Please enter details below to login").pack()
    Label(login_screen, text="").pack()
 
    global username_verify
    global password_verify
 
    username_verify = StringVar()
    password_verify = StringVar()
 
    global username_login_entry
    global password_login_entry
 
    Label(login_screen, text="Username * ").pack()
    username_login_entry = Entry(login_screen, textvariable=username_verify)
    username_login_entry.pack()
    Label(login_screen, text="").pack()
    Label(login_screen, text="Password * ").pack()
    password_login_entry = Entry(login_screen, textvariable=password_verify, show= '*')
    password_login_entry.pack()
    Label(login_screen, text="").pack()
    Button(login_screen, text="Login", width=10, height=1, command = login_verify).pack()
 
# click register
 
def register_user():
    global username_info
    username_info = StringVar()
    username_info = username.get()
    password_info = password.get()
    confirm_info = confirm.get()
    tally = 0
    error = 0
    files = os.listdir()
    
    invalid_list = ['CON', 'PRN', 'AUX', 'NUL', 'COM1', 'COM2', 'COM3', 'COM4', 'COM5', 'COM6', 'COM7', 'COM8', 'COM9', 'LPT1', 'LPT2', 'LPT3', 'LPT4', 'LPT5', 'LPT6', 'LPT7', 'LPT8', 'LPT9', ' ', '.','<','>',':','\"','/','\\', '|', '?','*', 'NULL', '', '!']
    for i in files:
        tally = tally + 1

    for i in invalid_list:
            if username_info == i:
                invalid_filename_error()
                error = 1

    for i in files:
            if username_info == i:
                overwrite_error()
                error = 1

    if tally <= 100: #this must be changed at very end of project to acommidate all files in folder
                
        if password_info != confirm_info:
            password_not_matched()

        if password_info == '' and username_info != '':
            password_not_present()


        else:
            if error == 0:
                global file
                file = open(username_info, "w")
                file.write(username_info + "\n")
                file.write(password_info + "\n")
                file.close()

 
                username_entry.delete(0, END)
                password_entry.delete(0, END)
                confirm_entry.delete(0, END)

                Label(register_screen, text="Success", fg="green", font=("calibri", 11)).pack()
                delete_register_screen()
                delete_main_screen()
                select_mode_register()
            
    else:
        max_users()
# allow new user to pick mode
def select_mode_register():
    global i
    i = 1
    global mode_screen
    mode_screen = Tk()
    mode_screen.geometry("600x600")
    mode_screen.title("Pacing Mode select")
    #embedded function to get selection
    def get_mode():
        selection = tkinter.StringVar(mode_screen)
        selection = mode_sel.get()
        label = Label(mode_screen, bg="green", text="Selection of " + selection + " is Successful", width = 25)
        label.place(x=250,y=150)
        button = Button(mode_screen, text = "Confirm", command = combine_funcs(delete_mode_screen,add2file)).place(x=250,y=170)
    #embedded function to add to file and move to parameter selection, still needs the actual file adding, currently only transports you to the next step
    def add2file():
        mode = tkinter.StringVar(mode_screen)
        mode = mode_sel.get()
        username_info = username.get()
        if mode == "AOO":
            #file = open(username_info, "w")
           # file.write(mode + "\n")
           # file.close()
            AOO_selections()
            delete_mode_screen()
        elif mode == "VOO":
            #file.write(mode + "\n")
            #file.close()
            VOO_selections()
            delete_mode_screen()
        elif mode == "AAI":
            #file.write(mode + "\n")
            #file.close()
            AAI_selections()
            delete_mode_screen()
        elif mode == "VVI":
            #file.write(mode + "\n")
            #file.close()
            VVI_selections()
            delete_mode_screen()
        elif mode == "AOOR":
            #file.write(mode + "\n")
            #file.close()
            AOOR_selections()
            delete_mode_screen()
        elif mode == "VOOR":
            #file.write(mode + "\n")
            #file.close()
            VOOR_selections()
            delete_mode_screen()
        elif mode == "AAIR":
            #file.write(mode + "\n")
            #file.close()
            AAIR_selections()
            delete_mode_screen()
        elif mode == "VVIR":
            #file.write(mode + "\n")
            #file.close()
            VVIR_selections()
            delete_mode_screen()
        
 
    Label(mode_screen, text="Before Starting, please select a pacing mode", bg="#C70039", width="300", height="2", font=("Calibri", 13)).pack()
    mode_sel= tkinter.StringVar(mode_screen)
    mode_sel.set("AOO")
    ModeOptions = ["AOO","VOO","AAI","VVI","AOOR","VOOR","AAIR","VVIR"]
    drop= tkinter.OptionMenu(mode_screen, mode_sel, *ModeOptions) #andrew this is the type of line youre gonna wanna edit,
    drop.pack()
    button = Button(mode_screen, text = "Select", command = get_mode).pack()
def select_mode_edit():
    global i
    i = 0
    global mode_screen
    mode_screen = Tk()
    mode_screen.geometry("600x600")
    mode_screen.title("Pacing Mode select")
    button = Button(mode_screen, text = "Back to Dashboard", command = combine_funcs(dashboard, delete_mode_screen)).pack()
    file = open(name, 'a')
    #embedded function to get selection
    def get_mode():
        selection = tkinter.StringVar(mode_screen)
        selection = mode_sel.get()
        label = Label(mode_screen, bg="green", text="Selection of " + selection + " is Successful", width = 25)
        label.place(x=250,y=150)
        button = Button(mode_screen, text = "Confirm", command = combine_funcs(delete_mode_screen,add2file)).place(x=250,y=170)
        
    #embedded function to add to file and move to parameter selection, still needs the actual file adding, currently only transports you to the next step
    def add2file():
        mode = tkinter.StringVar(mode_screen)
        mode = mode_sel.get()
        if mode == "AOO":
            #file.write(mode + "\n")
          #  file.close()
            AOO_selections()
            delete_mode_screen()
        elif mode == "VOO":
         #   file.write(mode + "\n")
        #file.close()
            VOO_selections()
            delete_mode_screen()
        elif mode == "AAI":
           # file.write(mode + "\n")
            #file.close()
            AAI_selections()
            delete_mode_screen()
        elif mode == "VVI":
            #file.write(mode + "\n")
            #file.close()
            VVI_selections()
            delete_mode_screen()
        elif mode == "AOOR":
            #file.write(mode + "\n")
            #file.close()
            AOOR_selections()
            delete_mode_screen()
        elif mode == "VOOR":
            #file.write(mode + "\n")
            #file.close()
            VOOR_selections()
            delete_mode_screen()
        elif mode == "AAIR":
            #file.write(mode + "\n")
            #file.close()
            AAIR_selections()
            delete_mode_screen()
        elif mode == "VVIR":
            #file.write(mode + "\n")
            #file.close()
            VVIR_selections()
            delete_mode_screen()

    Label(mode_screen, text="Before Starting, please select a pacing mode", bg="#C70039", width="300", height="2", font=("Calibri", 13)).pack()
    mode_sel= tkinter.StringVar(mode_screen)
    mode_sel.set("AOO")
    ModeOptions = ["AOO","VOO","AAI","VVI","AOOR","VOOR","AAIR","VVIR"]
    drop= tkinter.OptionMenu(mode_screen, mode_sel, *ModeOptions) #andrew this is the type of line youre gonna wanna edit,
    drop.pack()
    button = Button(mode_screen, text = "Select", command = get_mode).pack()
#when completed, these four functions will add the parameters to the txt file created upon register. I have not done that yet but probably will soon
def roundToNearest(input, toNearest=5):
    return toNearest * round(input/toNearest)

def success_param():
    global success_screen
    success_screen = Tk()
    success_screen.geometry("300x300")
    success_screen.title("parameter save success")
    def to_login():
        delete_success_screen()
        main_account_screen()
        
    Label(success_screen, text = 'Your parameters have been saved!', font=("Calibri", 13), bg = "#20E714", width="300", height="2").pack()
    Button(success_screen, text = "Back to main screen", command = to_login).pack()
    
def AOO_selections():
    #where I am saving 
    file = username_info
    #create class object 
    AOO_screen = InputScreen.InputScreenClass("AOO",file)
    #ranges for inputs, increments for those ranges, label, default value, whether or not "Off" is a valid input for 0 = FALSE
    AOO_screen.addInputBox([30,50,90,175],[5,1,5],"LRL (ppm) ",60) 
    AOO_screen.addInputBox([50,175],[5],"URL (ppm) ",120)
    AOO_screen.addInputBox([0.5,3.2,3.5,7],[0.1,0.5,0.5],"A Pulse Amplitude (V) ",3.5,TRUE)
    AOO_screen.addInputBox([0.05,0.1,1.9],[0.05,0.1],"A Pulse Width (ms) ",0.4)
    #AOO_screen.addInputBox([150,500],[10],"A Refractory Period (ms) ",320) #just for testing
    AOO_screen.open()
    main_account_screen()
    #file.close()
def VOO_selections(): ##literally the same as AOO except with some varible names swapped
    file = username_info
    VOO_screen = InputScreen.InputScreenClass("VOO",file)
    #ranges for inputs, increments for those ranges, label, default value, whether or not "Off" is a valid input for 0 = FALSE
    VOO_screen.addInputBox([30,50,90,175],[5,1,5],"LRL (ppm) ",60) 
    VOO_screen.addInputBox([50,175],[5],"URL (ppm) ",120)
    VOO_screen.addInputBox([0.5,3.2,3.5,7],[0.1,0.5,0.5],"V Pulse Amplitude (V) ",3.5,TRUE)
    VOO_screen.addInputBox([0.05,0.1,1.9],[0.05,0.1],"V Pulse Width (ms) ",0.4)
    VOO_screen.open()   
    main_account_screen()           
def AAI_selections():
    file = username_info
    AAI_screen = InputScreen.InputScreenClass("AAI",file)
    #ranges for inputs, increments for those ranges, label, default value, whether or not "Off" is a valid input for 0 = FALSE
    AAI_screen.addInputBox([30,50,90,175],[5,1,5],"LRL (ppm) ",60) 
    AAI_screen.addInputBox([50,175],[5],"URL (ppm) ",120)
    AAI_screen.addInputBox([0.5,3.2,3.5,7],[0.1,0.5,0.5],"A Pulse Amplitude (V) ",3.5,TRUE)
    AAI_screen.addInputBox([0.05,0.1,1.9],[0.05,0.1],"A Pulse Width (ms) ",0.4)
    AAI_screen.addInputBox([0.25,1,10],[0.25,0.5],"A Sensitivity (ms) ",0.75) #swap for VVI
    AAI_screen.addInputBox([150,500],[10],"A Refractory Period (ms) ",250) #swap for VVI
    AAI_screen.addInputBox([30,50,90,175],[5,1,5],"Hysteresis Rate Limit (ms) ","OFF",TRUE) #same as LRL
    AAI_screen.addInputBox([3,21,25],[3,5],"Rate Smoothing (%)","OFF",TRUE) #edgecase needs testing 
    AAI_screen.addInputBox([150,500],[10],"PVARP (ms)",250,TRUE) #edgecase needs testing 
    AAI_screen.open()
    main_account_screen()   
def VVI_selections():
    file = username_info
    AAI_screen = InputScreen.InputScreenClass("VVI",file)
    #ranges for inputs, increments for those ranges, label, default value, whether or not "Off" is a valid input for 0 = FALSE
    AAI_screen.addInputBox([30,50,90,175],[5,1,5],"LRL (ppm) ",60) 
    AAI_screen.addInputBox([50,175],[5],"URL (ppm) ",120)
    AAI_screen.addInputBox([0.5,3.2,3.5,7],[0.1,0.5,0.5],"V Pulse Amplitude (V) ",3.5,TRUE)
    AAI_screen.addInputBox([0.05,0.1,1.9],[0.05,0.1],"V Pulse Width (ms) ",0.4)
    AAI_screen.addInputBox([0.25,1,10],[0.25,0.5],"V Sensitivity (ms) ",2.5) #swap for VVI
    AAI_screen.addInputBox([150,500],[10],"V Refractory Period (ms) ",320) #swap for VVI
    AAI_screen.addInputBox([30,50,90,175],[5,1,5],"Hysteresis Rate Limit (ms) ","OFF",TRUE) #same as LRL
    AAI_screen.addInputBox([3,21,25],[3,5],"Rate Smoothing (%)","OFF",TRUE) #edgecase needs testing 
    AAI_screen.open()
    main_account_screen()   

def AOOR_selections():
    value_list = ["V-Low","Low","Med-Low","Med","Med-High","High","V-High"]
    #where I am saving 
    file = username_info
    #create class object 
    AOOR_screen = InputScreen.InputScreenClass("AOOR",file)
    #ranges for inputs, increments for those ranges, label, default value, whether or not "Off" is a valid input for 0 = FALSE
    AOOR_screen.addInputBox([30,50,90,175],[5,1,5],"LRL (ppm) ",60) 
    AOOR_screen.addInputBox([50,175],[5],"URL (ppm) ",120)
    AOOR_screen.addInputBox([50,175],[5],"Max Sensor Rate (ppm) ",120)
    AOOR_screen.addInputBox([0.1,5],[0.1],"A Pulse Amplitude (V) ",5,TRUE)
    AOOR_screen.addInputBox([1,30],[1],"A Pulse Width (ms) ",1)
    
    #DROPDOWN
    AOOR_screen.addDropBox('Activity Threshold','Med',value_list)
    
    AOOR_screen.addInputBox([10,50],[10],"Reaction Time (sec)",30)
    AOOR_screen.addInputBox([1,16],[1],"Response Factor ",8)
    AOOR_screen.addInputBox([2,16],[1],"Recovery Time (min)",5)
    

    #AOO_screen.addInputBox([150,500],[10],"A Refractory Period (ms) ",320) #just for testing
    AOOR_screen.open()
    #Label(AOOR_screen, text = 'working').pack()

    main_account_screen()
def VOOR_selections():
    value_list = ["V-Low","Low","Med-Low","Med","Med-High","High","V-High"]
    file = username_info
    VOOR_screen = InputScreen.InputScreenClass("VOOR",file)
    #ranges for inputs, increments for those ranges, label, default value, whether or not "Off" is a valid input for 0 = FALSE
    VOOR_screen.addInputBox([30,50,90,175],[5,1,5],"LRL (ppm) ",60) 
    VOOR_screen.addInputBox([50,175],[5],"URL (ppm) ",120)
    VOOR_screen.addInputBox([50,175],[5],"Max Sensor Rate (ppm) ",120)
    VOOR_screen.addInputBox([0.1,5],[0.1],"V Pulse Amplitude (V) ",5,TRUE)
    VOOR_screen.addInputBox([1,30],[1],"V Pulse Width (ms) ",1)
    VOOR_screen.addDropBox('Activity Threshold','Med',value_list)
    VOOR_screen.addInputBox([10,50],[10],"Reaction Time (sec)",30)
    VOOR_screen.addInputBox([1,16],[1],"Response Factor ",8)
    VOOR_screen.addInputBox([2,16],[1],"Recovery Time (min)",5)
    VOOR_screen.open()   
    main_account_screen()
def AAIR_selections():
    value_list = ["V-Low","Low","Med-Low","Med","Med-High","High","V-High"]
    file = username_info
    AAIR_screen = InputScreen.InputScreenClass("AAIR",file)
    #ranges for inputs, increments for those ranges, label, default value, whether or not "Off" is a valid input for 0 = FALSE
    AAIR_screen.addInputBox([30,50,90,175],[5,1,5],"LRL (ppm) ",60) 
    AAIR_screen.addInputBox([50,175],[5],"URL (ppm) ",120)
    AAIR_screen.addInputBox([50,175],[5],"Max Sensor Rate (ppm) ",120)
    AAIR_screen.addInputBox([0.1,5],[0.1],"A Pulse Amplitude (V) ",5,TRUE)
    AAIR_screen.addInputBox([1,30],[1],"A Pulse Width (ms) ",1)
    AAIR_screen.addInputBox([0,5],[0.1],"A Sensitivity (ms) ",0.75) #swap for VVI
    AAIR_screen.addInputBox([150,500],[10],"A Refractory Period (ms) ",250) #swap for VVI
    AAIR_screen.addInputBox([30,50,90,175],[5,1,5],"Hysteresis Rate Limit (ms) ","OFF",TRUE) #same as LRL
    AAIR_screen.addInputBox([3,21,25],[3,5],"Rate Smoothing (%)","OFF",TRUE) #edgecase needs testing 
    AAIR_screen.addInputBox([150,500],[10],"PVARP (ms)",250,TRUE) #edgecase needs testing
    AAIR_screen.addDropBox('Activity Threshold','Med',value_list)
    AAIR_screen.addInputBox([10,50],[10],"Reaction Time (sec)",30)
    AAIR_screen.addInputBox([1,16],[1],"Response Factor ",8)
    AAIR_screen.addInputBox([2,16],[1],"Recovery Time (min)",5)
    AAIR_screen.open()
    main_account_screen()
def VVIR_selections():
    value_list = ["V-Low","Low","Med-Low","Med","Med-High","High","V-High"]
    file = username_info
    VVIR_screen = InputScreen.InputScreenClass("VVIR",file)
    #ranges for inputs, increments for those ranges, label, default value, whether or not "Off" is a valid input for 0 = FALSE
    VVIR_screen.addInputBox([30,50,90,175],[5,1,5],"LRL (ppm) ",60) 
    VVIR_screen.addInputBox([50,175],[5],"URL (ppm) ",120)
    VVIR_screen.addInputBox([50,175],[5],"Max Sensor Rate (ppm) ",120)
    VVIR_screen.addInputBox([0.1,5],[0.1],"V Pulse Amplitude (V) ",5,TRUE)
    VVIR_screen.addInputBox([1,30],[1],"V Pulse Width (ms) ",1)
    VVIR_screen.addInputBox([0,5],[0.1],"V Sensitivity (ms) ",2.5) #swap for VVI
    VVIR_screen.addInputBox([150,500],[10],"V Refractory Period (ms) ",320) #swap for VVI
    VVIR_screen.addInputBox([30,50,90,175],[5,1,5],"Hysteresis Rate Limit (ms) ","OFF",TRUE) #same as LRL
    VVIR_screen.addInputBox([3,21,25],[3,5],"Rate Smoothing (%)","OFF",TRUE) #edgecase needs testing
    VVIR_screen.addDropBox('Activity Threshold','Med',value_list)
    VVIR_screen.addInputBox([10,50],[10],"Reaction Time (sec)",30)
    VVIR_screen.addInputBox([1,16],[1],"Response Factor ",8)
    VVIR_screen.addInputBox([2,16],[1],"Recovery Time (min)",5)
    VVIR_screen.open()
    main_account_screen()

def loadAndSend(mode, loadFrom):
    with open(loadFrom, 'r') as file:
            data = file.readlines()
            file.close()
    #FNCode? 
    if(mode == "AOO"):
        dataLocation = data.index(str((mode+"\n"))) 
        LRL = int(data[dataLocation+1]) #lrl in units of ppm
        URL = int(data[dataLocation+2])
        APA = float(data[dataLocation+3])
        APW = float(data[dataLocation+4])
        #for whatever reason DCM goes in the order 
    #AOO, VOO, AAI, VVI while simulink does VOO, AOO,VVI,AAI with modes 0,1,2,3 respectively
        sendToSimulink(1,LRL,URL,APA,APW,2.3,4,5,2.3,200,200,200,69,120,30,16,5,1,0)
                    #mode,ppm,url,AA,APW,AST,VA,VPW,VST,sVRP,sARP,sPVARP,sRS,sMSR,reactionTime,responseFactor,recoveryTime,activityThreshold
        return
    if(mode == "VOO"):
        dataLocation = data.index(str((mode+"\n"))) 
        LRL = int(data[dataLocation+1]) #lrl in units of ppm
        URL = int(data[dataLocation+2])
        VPA = float(data[dataLocation+3])
        VPW = float(data[dataLocation+4])
        #for whatever reason DCM goes in the order 
    #AOO, VOO, AAI, VVI while simulink does VOO, AOO,VVI,AAI with modes 0,1,2,3 respectively
        sendToSimulink(0,LRL,URL,4,5,2.3,VPA,VPW,2.3,200,200,200,69,120,30,16,5,1,0)  

    if(mode == "AAI"):
        dataLocation = data.index(str((mode+"\n"))) 
        LRL = int(data[dataLocation+1]) #lrl in units of ppm
        URL = int(data[dataLocation+2])
        APA = float(data[dataLocation+3])
        APW = float(data[dataLocation+4])
        ASense = float(data[dataLocation+5])
        ARP = float(data[dataLocation+6])
        HRL = float(data[dataLocation+7]) 
        RS =  float(data[dataLocation+8]) 
        PVARP =  float(data[dataLocation+9]) 
                      #mode,ppm,url,AA,APW,AST,VA,VPW,VST,sVRP,sARP,sPVARP,sRS,sMSR,reactionTime,responseFactor,recoveryTime,activityThreshold
        sendToSimulink(2,LRL,URL,APA,APW,ASense,4,5,2.3,200,200,ARP,PVARP,RS,30,16,5,1,HRL)  
    if(mode == "VVI"):
        dataLocation = data.index(str((mode+"\n"))) 
        LRL = int(data[dataLocation+1]) #translate to ppm? 
        URL = int(data[dataLocation+2])
        VPA = float(data[dataLocation+3])
        VPW = float(data[dataLocation+4])
        Vsense = float(data[dataLocation+5])
        VRP = float([dataLocations+6])
        HRL = float([dataLocations+7])
        RS = float(data[dataLocations + 8])
        sendToSimulink(3,LRL,URL,4,5,2.3,VPA,VPW,Vsense,VRP,200,200,RS,30,16,5,1,HRL)

    if(mode== "AOOR"):
        dataLocation = data.index(str((mode+"\n"))) 
        LRL = int(data[dataLocation+1]) #lrl in units of ppm
        URL = int(data[dataLocation+2])
        MSR = int(data[dataLocation+3])
        APA = float(data[dataLocation+4])
        APW = float(data[dataLocation+5])
        AT = data[dataLocation+6]

        if AT == "V-Low":
            AT = float(0.85)
        if AT == "Low":
            AT = float(1.71)
        if AT == "Med-Low":
            AT = float(2.55)
        if AT == "Med":
            AT = float(3.40)
        if AT == "Med-High":
            AT = float(4.26)
        if AT == "High":
            AT = float(5.1)
        if AT == "V-High":
            AT = float(5.96)
        RT = int(data[dataLocation+7])
        RF = int(data[dataLocation+8])
        Rect = int(data[dataLocation+9])
        
            
                      #mode,ppm,url,AA,APW,AST,VA,VPW,VST,sVRP,sARP,sPVARP,sRS,sMSR,reactionTime,responseFactor,recoveryTime,activityThreshold, HRL
        sendToSimulink(4,LRL,URL,APA,APW,2.3,4,5,2.3,200,200,200,69,MSR,RT,RF,Rect,AT,0)
    if(mode == "VOOR"):
        dataLocation = data.index(str((mode+"\n"))) 
        LRL = int(data[dataLocation+1]) #lrl in units of ppm
        URL = int(data[dataLocation+2])
        MSR = int(data[dataLocation+3])
        VPA = float(data[dataLocation+4])
        VPW = float(data[dataLocation+5])
        AT = data[dataLocation+6]

        if AT == "V-Low":
            AT = float(0.85)
        if AT == "Low":
            AT = float(1.71)
        if AT == "Med-Low":
            AT = float(2.55)
        if AT == "Med":
            AT = float(3.40)
        if AT == "Med-High":
            AT = float(4.26)
        if AT == "High":
            AT = float(5.1)
        if AT == "V-High":
            AT = float(5.96)

        RT = int(data[dataLocation+7])
        RF = int(data[dataLocation+8])
        Rect = int(data[dataLocation+9])
        
        #for whatever reason DCM goes in the order 
                    #mode,ppm,url,AA,APW,AST,VA,VPW,VST,sVRP,sARP,sPVARP,sRS,sMSR,reactionTime,responseFactor,recoveryTime,activityThreshold, HRL
        sendToSimulink(5,LRL,URL,4,5,2.3,VPA,VPW,2.3,200,200,200,69,MSR,RT,RF,Rect,AT,0)

    if(mode == "AAIR"):
        dataLocation = data.index(str((mode+"\n"))) 
        LRL = int(data[dataLocation+1]) #lrl in units of ppm
        URL = int(data[dataLocation+2])
        MSR = int(data[dataLocation+3])
        APA = float(data[dataLocation+4])
        APW = float(data[dataLocation+5])
        ASense = float(data[dataLocation+6])
        ARP = float(data[dataLocation+7])
        HRL = float(data[dataLocation+8]) 
        RS =  float(data[dataLocation+9]) 
        PVARP =  float(data[dataLocation+10])

        AT = data[dataLocation+11]

        if AT == "V-Low":
            AT = float(0.85)
        if AT == "Low":
            AT = float(1.71)
        if AT == "Med-Low":
            AT = float(2.55)
        if AT == "Med":
            AT = float(3.40)
        if AT == "Med-High":
            AT = float(4.26)
        if AT == "High":
            AT = float(5.1)
        if AT == "V-High":
            AT = float(5.96)

        RT = int(data[dataLocation+12])
        RF = int(data[dataLocation+13])
        Rect = int(data[dataLocation+14])
        
                      #mode,ppm,url,AA,APW,AST,VA,VPW,VST,sVRP,sARP,sPVARP,sRS,sMSR,reactionTime,responseFactor,recoveryTime,activityThreshold
        sendToSimulink(6,LRL,URL,APA,APW,ASense,4,5,2.3,200,200,ARP,PVARP,RS,MSR,RT,RF,Rect,AT,HRL)

    if(mode == "VVIR"):
        dataLocation = data.index(str((mode+"\n"))) 
        LRL = int(data[dataLocation+1]) #translate to ppm? 
        URL = int(data[dataLocation+2])
        MSR = int(data[dataLocation+3])
        VPA = float(data[dataLocation+4])
        VPW = float(data[dataLocation+5])
        Vsense = float(data[dataLocation+6])
        VRP = float([dataLocations+7])
        HRL = float([dataLocations+8])
        RS = float(data[dataLocations + 9])
        AT = data[dataLocation+10]

        if AT == "V-Low":
            AT = float(0.85)
        if AT == "Low":
            AT = float(1.71)
        if AT == "Med-Low":
            AT = float(2.55)
        if AT == "Med":
            AT = float(3.40)
        if AT == "Med-High":
            AT = float(4.26)
        if AT == "High":
            AT = float(5.1)
        if AT == "V-High":
            AT = float(5.96)

        RT = int(data[dataLocation+11])
        RF = int(data[dataLocation+12])
        Rect = int(data[dataLocation+13])
                   #mode,ppm,url,AA,APW,AST,VA,VPW,VST,sVRP,sARP,sPVARP,sRS,sMSR,reactionTime,responseFactor,recoveryTime,activityThreshold
        sendToSimulink(7,LRL,URL,4,5,2.3,VPA,VPW,Vsense,VRP,200,200,MSR,RT,RF,Rect,AT,HRL)

def login_verify():
    username1 = username_verify.get()
    global name
    name = StringVar()
    name = username1
    password1 = password_verify.get()
    username_login_entry.delete(0, END)
    password_login_entry.delete(0, END)
 
    list_of_files = os.listdir()
    if username1 in list_of_files:
        file1 = open(username1, "r")
        verify = file1.read().splitlines()
        if password1 in verify:
            global username_info 
            username_info= username1
            login_sucess()
 
        else:
            password_not_recognised()
 
    else:
        user_not_found()
 
# login sucess procedure
 
def login_sucess():
    global login_success_screen
    login_success_screen = Toplevel(login_screen)
    login_success_screen.title("Success")
    login_success_screen.geometry("150x100")
    Label(login_success_screen, text="Login Success").pack()
    Button(login_success_screen, text="OK", command=delete_login_success).pack()

    delete_login_screen()
    delete_main_screen()
    dashboard()
# Designing popup for too many users
 
def max_users():
    global max_users_screen
    max_users_screen = Toplevel(register_screen)
    max_users_screen.title("error")
    max_users_screen.geometry("150x100")
    Label(max_users_screen, text="max # of users reached").pack()
    Button(max_users_screen, text="OK", command=delete_max_users_screen).pack()

def invalid_filename_error():
    global invalid_fileame_error_screen
    invalid_fileame_error_screen = Toplevel(register_screen)
    invalid_fileame_error_screen.title("error")
    invalid_fileame_error_screen.geometry("150x100")
    Label(invalid_fileame_error_screen, text="Username is Invalid").pack()
    Button(invalid_fileame_error_screen, text="OK", command=delete_invalid_fileame_error).pack()

def overwrite_error():
    global overwrite_error_screen
    overwrite_error_screen = Toplevel(register_screen)
    overwrite_error_screen.title("error")
    overwrite_error_screen.geometry("150x100")
    Label(overwrite_error_screen, text="Username is already in use").pack()
    Button(overwrite_error_screen, text="OK", command=delete_overwrite_error).pack()
    
 
# Designing popup for login invalid password
 
def password_not_recognised():
    global password_not_recog_screen
    password_not_recog_screen = Toplevel(login_screen)
    password_not_recog_screen.title("Success")
    password_not_recog_screen.geometry("150x100")
    Label(password_not_recog_screen, text="Invalid Password ").pack()
    Button(password_not_recog_screen, text="OK", command=delete_password_not_recognised).pack()
    
# popup for unmatching passwords
def password_not_matched():
    global password_not_matched_screen
    password_not_matched_screen = Toplevel(register_screen)
    password_not_matched_screen.title("error")
    password_not_matched_screen.geometry("150x100")
    Label(password_not_matched_screen, text="Passwords do not match ").pack()
    Button(password_not_matched_screen, text="OK", command=delete_password_not_matched).pack()

def password_not_present():
    global password_not_present_screen
    password_not_present_screen = Toplevel(register_screen)
    password_not_present_screen.title("error")
    password_not_present_screen.geometry("150x100")
    Label(password_not_present_screen, text="A password is required").pack()
    Button(password_not_present_screen, text="OK", command=delete_password_not_present).pack()
 
# Designing popup for user not found
 
def user_not_found():
    global user_not_found_screen
    user_not_found_screen = Toplevel(login_screen)
    user_not_found_screen.title("Success")
    user_not_found_screen.geometry("150x100")
    Label(user_not_found_screen, text="User Not Found").pack()
    Button(user_not_found_screen, text="OK", command=delete_user_not_found_screen).pack()
# combining functions for buttons 
def combine_funcs(*funcs):
    def combined_func(*arg1, **arg2):
        for f in funcs:
            f(*arg1, **arg2)
    return combined_func

# Deleting stuff
 
def delete_login_success():
    login_success_screen.destroy()
    
def delete_password_not_matched():
    password_not_matched_screen.destroy()

def delete_password_not_present():
    password_not_present_screen.destroy()
 
 
def delete_password_not_recognised():
    password_not_recog_screen.destroy()
 
 
def delete_user_not_found_screen():
    user_not_found_screen.destroy()

def delete_overwrite_error():
    overwrite_error_screen.destroy()

def delete_invalid_fileame_error():
    invalid_fileame_error_screen.destroy()

def delete_max_users_screen():
    max_users_screen.destroy()

def delete_login_screen():
    login_screen.destroy()

def delete_register_screen():
    register_screen.destroy()

def delete_main_screen():
    main_screen.destroy()

def delete_mode_screen():
    mode_screen.destroy()

def delete_dashboard():
    dash_screen.destroy()
    
def delete_success_screen():
    success_screen.destroy()

def delete_egram_screen():
    egram_screen.destroy()

def delete_send_success_screen():
    send_success_screen.destroy()
 
# Designing login/register (first) window
 
def main_account_screen():
    global main_screen
    main_screen = Tk()
    main_screen.geometry("300x250")
    main_screen.title("Account Login")
    Label(text="Select Your Choice", bg="#C70039", width="300", height="2", font=("Calibri", 13)).pack()
    Label(text="").pack()
    Button(text="Login", height="2", width="30", command = login).pack()
    Label(text="").pack()
    Button(text="Register", height="2", width="30", command=register).pack()
 
    main_screen.mainloop()
#egram screen
def show_egram():
    delete_send_success_screen()
    global egram_screen
    egram_screen = Tk()   
    egram_screen.geometry("600x600")
    egram_screen.title("Egram Data")
    button = Button(egram_screen, text = "Back to Dashboard", command = combine_funcs(delete_egram_screen, dashboard)).pack()
    Label(text="Egram Data from past 30s", bg="#C70039", width="300", height="2", font=("Calibri", 15)).pack()
    #this will be the function where we pull the two pins for egram data

def send_success():
    
    global send_success_screen
    send_success_screen = Tk()   
    send_success_screen.geometry("300x300")
    send_success_screen.title("Send Success")
    delete_dashboard()

    def show_timebutton():
        timebutton = Button(send_success_screen, text = 'show egram data', command = show_egram)
        timebutton.pack()
        
    #Button(send_success_screen, text = "Back to Dashboard", command = combine_funcs(delete_send_success_screen, dashboard)).pack()
    Label(send_success_screen, text="Data has been sent!", bg="#94ed80", width="300", height="2", font=("Calibri", 15)).pack()
    if string_mode2send == 'AOO' or string_mode2send == 'VOO' or string_mode2send == 'AAI' or string_mode2send == 'VVI':
        Label(send_success_screen, text ="""
                    Your selected preset mode has been sent to the pacemaker. You may now look at heartview to see the reults
                    If you would like to see Egram data, Please wait until the "Show Egram Data" button appears.
                    
                                This will happen once the program has ran for at least 30s""").pack
        send_success_screen.after(5000, show_timebutton) #change to 30s after testing complete

    else:
        Label(send_success_screen, text ="""
                    Your selected preset mode has been sent to the pacemaker
                    Unfortunatley, the reactive modes have not been implemented
                    You are unable to view Egram data for this mode""").pack()
        
        

#creating dashboard after login (this is where all selections will go)
def dashboard():
    global dash_screen
    dash_screen = Tk()   
    dash_screen.geometry("600x600")
    dash_screen.title("Dashboard")
    Label(text="Welcome to the Dashboard", bg="#C70039", width="300", height="2", font=("Calibri", 15)).pack() #adding which user it is would be nice
    button = Button(dash_screen, text = "Back to Login", command = combine_funcs(delete_dashboard, main_account_screen)).place(x=0,y=2)
    Label(text="FOR TESTING PURPOSES ONLY",bg = "orange",font=("calibri", 14)).place(x=0, y=500)
    #need to find a way to port username to dashboard, likley need to redo the way things save in register
    #username_info = username.get()
    #Label(text="Welcome, signed in as" + username_info ,font=("calibri", 16)).pack()
    
    def change_status_c2d():
        status_label = Label(text="Status: connected", bg = 'green', width="30").place(x=60, y=600)
        Button(dash_screen, text = "change status", command = change_status_d2c).place(x=0, y=600)         

    def change_status_d2c():  
        status_label = Label(text="Status: disconnected", bg = 'red', width="30").place(x=60, y=600)
        Button(dash_screen, text = "change status", command = change_status_c2d).place(x=0, y=600)

    def change_pacemaker_1st():
            Label(dash_screen, text = ' ', width = 100, height = 2).place(x=0,y=550)
            status_label = Label(text="Pacemaker 1 Connected", bg = "cyan",width="30").place(x=80, y=550)
            Button(dash_screen, text = "change pacemaker", command = change_pacemaker_2nd).place(x=0, y=550)
            
            
    def change_pacemaker_2nd():
            status_label = Label(text="Pacemaker 2 Connected", bg = "cyan", width="30").place(x=80, y=550)
            Button(dash_screen, text = "change pacemaker", command = change_pacemaker_3rd).place(x=0, y=550)
            
    def change_pacemaker_3rd():
        status_label = Label(text="Pacemaker 3 Connected",bg = "cyan", width="30").place(x=80, y=550)
        Button(dash_screen, text = "change pacemaker", command = change_pacemaker_1st).place(x=0, y=550)
        
    Button(dash_screen, text="show status", command = change_status_c2d).place(x=0, y=600)
    Button(dash_screen, text="show connected pacemaker", command = change_pacemaker_1st).place(x=0, y=550)
    Label(dash_screen, text = "Hello " + name +"!", bg = "yellow", font=("Calibri", 13)).pack()
    userfile = open(name, 'r')
    filelines = userfile.readlines()
    user_name = filelines[0]
    user_pass = filelines[1]
    try:
       AOOLocation = filelines.index("AOO\n")
    except ValueError:
       AOOLocation = -1
    try:
        VOOLocation = filelines.index("VOO\n")
    except ValueError:
        VOOLocation = -1
    try: 
        AAILocation = filelines.index("AAI\n")
    except ValueError:
        AAILocation = -1
    try:
        VVILocation = filelines.index("VVI\n")
    except ValueError:
        VVILocation = -1
    try:
       AOORLocation = filelines.index("AOOR\n")
    except ValueError:
       AOORLocation = -1
    try:
       VOORLocation = filelines.index("VOOR\n")
    except ValueError:
       VOORLocation = -1
    try:
       AAIRLocation = filelines.index("AAIR\n")
    except ValueError:
       AAIRLocation = -1
    try:
       VVIRLocation = filelines.index("VVIR\n")
    except ValueError:
       VVIRLocation = -1
    Label(dash_screen, text = "Your Preset Modes", bg = "#C70039", font = ("Calibri", 12)).place(x=0,y=120)
    #Label(dash_screen, text = "mode = " + user_mode).place(x=0,y=150)
    def edit_selections():
        #file = open(name, 'w')
        #file.write(user_name)
        #file.write(user_pass)
        #file.close()
        select_mode_edit()
        delete_dashboard()
    
        
    xOffsetIncrement = 80
    xOffset = 0
    ybuffer = 20
    ybuffermode = 10
    preset_list = []
    mode_to_send= tkinter.StringVar(dash_screen)
    
    #dashboard locations for each mode
    if AOOLocation != -1:
        mode_to_send.set("AOO")
        preset_list.append('AOO')
        user_lrl = filelines[AOOLocation+1]
        user_url = filelines[AOOLocation+2]
        user_aa = filelines[AOOLocation+3]
        user_apw = filelines[AOOLocation+4]
        Label(dash_screen, text = " ", bg='#db4f66',width=11).place(x= 0 + xOffset*xOffsetIncrement,y=150+ybuffermode)
        Label(dash_screen, text = "AOO:", bg='#db4f66').place(x= 0 + xOffset*xOffsetIncrement,y=150+ybuffermode)
        Label(dash_screen, text = "LRL = " + user_lrl).place(x= 0 + xOffset*xOffsetIncrement,y=165+ybuffer)
        Label(dash_screen, text = "URL = " + user_url).place(x= 0 + xOffset*xOffsetIncrement,y=180+ybuffer)
        Label(dash_screen, text = "AA = " + user_aa).place(x= 0 + xOffset*xOffsetIncrement,y=195+ybuffer)
        Label(dash_screen, text = "APW = " + user_apw).place(x= 0 + xOffset*xOffsetIncrement,y=210+ybuffer)
        xOffset = xOffset+1
        
        
    if VOOLocation != -1:
        preset_list.append('VOO')
        mode_to_send.set("VOO")
        user_lrl = filelines[VOOLocation+1]
        user_url = filelines[VOOLocation+2]
        user_va = filelines[VOOLocation+3]
        user_vpw = filelines[VOOLocation+4]
        Label(dash_screen, text = " ", bg='#db4f66',width=11).place(x= 0 + xOffset*xOffsetIncrement,y=150+ybuffermode)
        Label(dash_screen, text = "VOO:", bg='#db4f66').place(x= 0 + xOffset*xOffsetIncrement,y=150+ybuffermode)
        Label(dash_screen, text = "LRL = " + user_lrl).place(x= 0 + xOffset*xOffsetIncrement,y=165+ybuffer)
        Label(dash_screen, text = "URL = " + user_url).place(x= 0 + xOffset*xOffsetIncrement,y=180+ybuffer)
        Label(dash_screen, text = "VA = " + user_va).place(x= 0 + xOffset*xOffsetIncrement,y=195+ybuffer)
        Label(dash_screen, text = "VPW = " + user_vpw).place(x= 0 + xOffset*xOffsetIncrement,y=210+ybuffer)
        xOffset = xOffset+1
        
    if AAILocation != -1:
        preset_list.append('AAI')
        mode_to_send.set('AAI')
        user_lrl = filelines[AAILocation+1]
        user_url = filelines[AAILocation+2]
        user_aa = filelines[AAILocation+3]
        user_apw = filelines[AAILocation+4]
        user_as = filelines[AAILocation+5]
        user_arp = filelines[AAILocation+6]
        user_pvarp = filelines[AAILocation+9]
        user_hyster = filelines[AAILocation+7]
        user_smooth = filelines[AAILocation+8]
        Label(dash_screen, text = " ", bg='#db4f66',width=11).place(x= 0 + xOffset*xOffsetIncrement,y=150+ybuffermode)
        Label(dash_screen, text = "AAI:", bg='#db4f66').place(x= 0 + xOffset*xOffsetIncrement,y=150+ybuffermode)
        Label(dash_screen, text = "LRL = " + user_lrl).place(x= 0 + xOffset*xOffsetIncrement,y=165+ybuffer)
        Label(dash_screen, text = "URL = " + user_url).place(x= 0 + xOffset*xOffsetIncrement,y=180+ybuffer)
        Label(dash_screen, text = "AA = " + user_aa).place(x= 0 + xOffset*xOffsetIncrement,y=195+ybuffer)
        Label(dash_screen, text = "APW = " + user_apw).place(x= 0 + xOffset*xOffsetIncrement,y=210+ybuffer)
        Label(dash_screen, text = "AS = " + user_as).place(x= 0 + xOffset*xOffsetIncrement,y=225+ybuffer)
        Label(dash_screen, text = "ARP = " + user_arp).place(x= 0 + xOffset*xOffsetIncrement,y=240+ybuffer)
        Label(dash_screen, text = "RSM = " + user_smooth).place(x= 0 + xOffset*xOffsetIncrement,y=255+ybuffer)
        Label(dash_screen, text = "HYSTER= " + user_hyster).place(x= 0 + xOffset*xOffsetIncrement,y=270+ybuffer)
        Label(dash_screen, text = "PVARP = " + user_pvarp).place(x= 0 + xOffset*xOffsetIncrement,y=285+ybuffer)
        xOffset = xOffset+1
        
    if VVILocation != -1:
        preset_list.append('VVI')
        mode_to_send.set('VVI')
        user_lrl = filelines[VVILocation+1]
        user_url = filelines[VVILocation+2]
        user_va = filelines[VVILocation+3]
        user_vpw = filelines[VVILocation+4]
        user_vs = filelines[VVILocation+5]
        user_vrp = filelines[VVILocation+6]
        user_hyster = filelines[VVILocation+7]
        user_smooth = filelines[VVILocation+8]
        Label(dash_screen, text = " ", bg='#db4f66',width=11).place(x= 0 + xOffset*xOffsetIncrement,y=150+ybuffermode)
        Label(dash_screen, text = "VVI:", bg='#db4f66').place(x= 0 + xOffset*xOffsetIncrement,y=150+ybuffermode)
        Label(dash_screen, text = "LRL = " + user_lrl).place(x= 0 + xOffset*xOffsetIncrement,y=165+ybuffer)
        Label(dash_screen, text = "URL = " + user_url).place(x= 0 + xOffset*xOffsetIncrement,y=180+ybuffer)
        Label(dash_screen, text = "VA = " + user_va).place(x= 0 + xOffset*xOffsetIncrement,y=195+ybuffer)
        Label(dash_screen, text = "VPW = " + user_vpw).place(x= 0 + xOffset*xOffsetIncrement,y=210+ybuffer)
        Label(dash_screen, text = "VS = " + user_vs).place(x= 0 + xOffset*xOffsetIncrement,y=225+ybuffer)
        Label(dash_screen, text = "VRP = " + user_vrp).place(x= 0 + xOffset*xOffsetIncrement,y=240+ybuffer)
        Label(dash_screen, text = "HYSTER= " + user_hyster).place(x= 0 + xOffset*xOffsetIncrement,y=255+ybuffer)
        Label(dash_screen, text = "RSM = " + user_smooth).place(x= 0 + xOffset*xOffsetIncrement,y=270+ybuffer)
        xOffset = xOffset+1

    if AOORLocation != -1:
        preset_list.append('AOOR')
        mode_to_send.set('AOOR')
        user_lrl = filelines[AOORLocation+1]
        user_url = filelines[AOORLocation+2]
        user_msr = filelines[AOORLocation+3]
        user_aa = filelines[AOORLocation+4]
        user_apw = filelines[AOORLocation+5]
        user_at = filelines[AOORLocation+6]
        user_rt = filelines[AOORLocation+7]
        user_rf = filelines[AOORLocation+8]
        user_rect = filelines[AOORLocation+9]
        Label(dash_screen, text = " ", bg='#db4f66',width=11).place(x= 0 + xOffset*xOffsetIncrement,y=150+ybuffermode)
        Label(dash_screen, text = "AOOR:", bg='#db4f66').place(x= 0 + xOffset*xOffsetIncrement,y=150+ybuffermode)
        Label(dash_screen, text = "LRL = " + user_lrl).place(x= 0 + xOffset*xOffsetIncrement,y=165+ybuffer)
        Label(dash_screen, text = "URL = " + user_url).place(x= 0 + xOffset*xOffsetIncrement,y=180+ybuffer)
        Label(dash_screen, text = "MSR = " + user_msr).place(x= 0 + xOffset*xOffsetIncrement,y=195+ybuffer)
        Label(dash_screen, text = "AA = " + user_aa).place(x= 0 + xOffset*xOffsetIncrement,y=210+ybuffer)
        Label(dash_screen, text = "APW = " + user_apw).place(x= 0 + xOffset*xOffsetIncrement,y=225+ybuffer)
        Label(dash_screen, text = "AT = " + user_at).place(x= 0 + xOffset*xOffsetIncrement,y=240+ybuffer)
        Label(dash_screen, text = "RT = " + user_rt).place(x= 0 + xOffset*xOffsetIncrement,y=255+ybuffer)
        Label(dash_screen, text = "RF= " + user_rf).place(x= 0 + xOffset*xOffsetIncrement,y=270+ybuffer)
        Label(dash_screen, text = "RecT = " + user_rect).place(x= 0 + xOffset*xOffsetIncrement,y=285+ybuffer)
        xOffset = xOffset+1

    if VOORLocation != -1:
        preset_list.append('VOOR')
        mode_to_send.set('VOOR')
        user_lrl = filelines[VOORLocation+1]
        user_url = filelines[VOORLocation+2]
        user_msr = filelines[VOORLocation+3]
        user_va = filelines[VOORLocation+4]
        user_vpw = filelines[VOORLocation+5]
        user_at = filelines[VOORLocation+6]
        user_rt = filelines[VOORLocation+7]
        user_rf = filelines[VOORLocation+8]
        user_rect = filelines[VOORLocation+9]
        Label(dash_screen, text = " ", bg='#db4f66',width=11).place(x= 0 + xOffset*xOffsetIncrement,y=150+ybuffermode)
        Label(dash_screen, text = "VOOR:", bg='#db4f66').place(x= 0 + xOffset*xOffsetIncrement,y=150+ybuffermode)
        Label(dash_screen, text = "LRL = " + user_lrl).place(x= 0 + xOffset*xOffsetIncrement,y=165+ybuffer)
        Label(dash_screen, text = "URL = " + user_url).place(x= 0 + xOffset*xOffsetIncrement,y=180+ybuffer)
        Label(dash_screen, text = "MSR = " + user_msr).place(x= 0 + xOffset*xOffsetIncrement,y=195+ybuffer)
        Label(dash_screen, text = "VA = " + user_va).place(x= 0 + xOffset*xOffsetIncrement,y=210+ybuffer)
        Label(dash_screen, text = "VPW = " + user_vpw).place(x= 0 + xOffset*xOffsetIncrement,y=225+ybuffer)
        Label(dash_screen, text = "AT = " + user_at).place(x= 0 + xOffset*xOffsetIncrement,y=240+ybuffer)
        Label(dash_screen, text = "RT = " + user_rt).place(x= 0 + xOffset*xOffsetIncrement,y=255+ybuffer)
        Label(dash_screen, text = "RF= " + user_rf).place(x= 0 + xOffset*xOffsetIncrement,y=270+ybuffer)
        Label(dash_screen, text = "RecT = " + user_rect).place(x= 0 + xOffset*xOffsetIncrement,y=285+ybuffer)
        xOffset = xOffset+1


    if AAIRLocation != -1:
        preset_list.append('AAIR')
        mode_to_send.set('AAIR')
        user_lrl = filelines[AAIRLocation+1]
        user_url = filelines[AAIRLocation+2]
        user_msr = filelines[AAIRLocation+3]
        user_aa = filelines[AAIRLocation+4]
        user_apw = filelines[AAIRLocation+5]
        user_as = filelines[AAIRLocation+6]
        user_arp = filelines[AAIRLocation+7]
        user_hyster = filelines[AAIRLocation+8]
        user_smooth = filelines[AAIRLocation+9]
        user_pvarp = filelines[AAIRLocation+10]
        user_at = filelines[AAIRLocation+11]
        user_rt = filelines[AAIRLocation+12]
        user_rf = filelines[AAIRLocation+13]
        user_rect = filelines[AAIRLocation+14]
        Label(dash_screen, text = " ", bg='#db4f66',width=11).place(x= 0 + xOffset*xOffsetIncrement,y=150+ybuffermode)
        Label(dash_screen, text = "AAIR:", bg='#db4f66').place(x= 0 + xOffset*xOffsetIncrement,y=150+ybuffermode)
        Label(dash_screen, text = "LRL = " + user_lrl).place(x= 0 + xOffset*xOffsetIncrement,y=165+ybuffer)
        Label(dash_screen, text = "URL = " + user_url).place(x= 0 + xOffset*xOffsetIncrement,y=180+ybuffer)
        Label(dash_screen, text = "MSR = " + user_msr).place(x= 0 + xOffset*xOffsetIncrement,y=195+ybuffer)
        Label(dash_screen, text = "AA = " + user_aa).place(x= 0 + xOffset*xOffsetIncrement,y=210+ybuffer)
        Label(dash_screen, text = "APW = " + user_apw).place(x= 0 + xOffset*xOffsetIncrement,y=225+ybuffer)
        Label(dash_screen, text = "AS = " + user_as).place(x= 0 + xOffset*xOffsetIncrement,y=225+ybuffer)
        Label(dash_screen, text = "ARP = " + user_arp).place(x= 0 + xOffset*xOffsetIncrement,y=240+ybuffer)
        Label(dash_screen, text = "HYSTER = " + user_hyster).place(x= 0 + xOffset*xOffsetIncrement,y=255+ybuffer)
        Label(dash_screen, text = "RSM = " + user_smooth).place(x= 0 + xOffset*xOffsetIncrement,y=270+ybuffer)
        Label(dash_screen, text = "PVARP = " + user_pvarp).place(x= 0 + xOffset*xOffsetIncrement,y=285+ybuffer)
        Label(dash_screen, text = "AT = " + user_at).place(x= 0 + xOffset*xOffsetIncrement,y=300+ybuffer)
        Label(dash_screen, text = "RT = " + user_rt).place(x= 0 + xOffset*xOffsetIncrement,y=315+ybuffer)
        Label(dash_screen, text = "RF= " + user_rf).place(x= 0 + xOffset*xOffsetIncrement,y=330+ybuffer)
        Label(dash_screen, text = "RecT = " + user_rect).place(x= 0 + xOffset*xOffsetIncrement,y=345+ybuffer)
        xOffset = xOffset+1

    if VVIRLocation != -1:
        preset_list.append('VVIR')
        mode_to_send.set('VVIR')
        user_lrl = filelines[VVIRLocation+1]
        user_url = filelines[VVIRLocation+2]
        user_msr = filelines[VVIRLocation+3]
        user_va = filelines[VVIRLocation+4]
        user_vpw = filelines[VVIRLocation+5]
        user_vs = filelines[VVIRLocation+6]
        user_vrp = filelines[VVIRLocation+7]
        user_hyster = filelines[VVIRLocation+8]
        user_smooth = filelines[VVIRLocation+9]
        user_at = filelines[VVIRLocation+10]
        user_rt = filelines[VVIRLocation+11]
        user_rf = filelines[VVIRLocation+12]
        user_rect = filelines[VVIRLocation+13]
        Label(dash_screen, text = " ", bg='#db4f66',width=11).place(x= 0 + xOffset*xOffsetIncrement,y=150+ybuffermode)
        Label(dash_screen, text = "VVIR:", bg='#db4f66').place(x= 0 + xOffset*xOffsetIncrement,y=150+ybuffermode)
        Label(dash_screen, text = "LRL = " + user_lrl).place(x= 0 + xOffset*xOffsetIncrement,y=165+ybuffer)
        Label(dash_screen, text = "URL = " + user_url).place(x= 0 + xOffset*xOffsetIncrement,y=180+ybuffer)
        Label(dash_screen, text = "MSR = " + user_msr).place(x= 0 + xOffset*xOffsetIncrement,y=195+ybuffer)
        Label(dash_screen, text = "VA = " + user_va).place(x= 0 + xOffset*xOffsetIncrement,y=210+ybuffer)
        Label(dash_screen, text = "VPW = " + user_vpw).place(x= 0 + xOffset*xOffsetIncrement,y=225+ybuffer)
        Label(dash_screen, text = "VS = " + user_vs).place(x= 0 + xOffset*xOffsetIncrement,y=225+ybuffer)
        Label(dash_screen, text = "VRP = " + user_vrp).place(x= 0 + xOffset*xOffsetIncrement,y=240+ybuffer)
        Label(dash_screen, text = "HYSTER = " + user_hyster).place(x= 0 + xOffset*xOffsetIncrement,y=255+ybuffer)
        Label(dash_screen, text = "RSM = " + user_smooth).place(x= 0 + xOffset*xOffsetIncrement,y=270+ybuffer)
        Label(dash_screen, text = "AT = " + user_at).place(x= 0 + xOffset*xOffsetIncrement,y=285+ybuffer)
        Label(dash_screen, text = "RT = " + user_rt).place(x= 0 + xOffset*xOffsetIncrement,y=300+ybuffer)
        Label(dash_screen, text = "RF= " + user_rf).place(x= 0 + xOffset*xOffsetIncrement,y=315+ybuffer)
        Label(dash_screen, text = "RecT = " + user_rect).place(x= 0 + xOffset*xOffsetIncrement,y=330+ybuffer)
        xOffset = xOffset+1



#sending to pacemaker dropdown

    def send_to_pace():
        global string_mode2send
        string_mode2send = mode_to_send.get()
        print(string_mode2send , name)

        #CURRENTLY TESTING, not going to uncomment line below until everything works
        #loadAndSend(string_mode2send , name)
        send_success()
        
        
    string_mode2send = mode_to_send.get()
    Button(dash_screen, text = 'edit selections', command = edit_selections, width = 11).place(x= 0,y=348)
    
    Label(dash_screen, text = 'Select preset to send to pacemaker', font=("Calibri", 12), bg = '#94ed80').place(x=0, y=375)
    #Label(dash_screen, text = 'due to changing requirements, Egram data not availavle for reactive modes',bg = 'orange').place(x=150,y=407)
    OptionMenu(dash_screen, mode_to_send, *preset_list).place(x=0, y=405)
    Button(dash_screen, text = "confirm", command = send_to_pace).place(x=80, y=405) #change to command = loadAndSend(mode_to_send,name) after serial
    
    
#run start
#loadAndSend("AOO","a")
main_account_screen()
