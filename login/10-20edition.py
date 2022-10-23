#import modules

from math import ceil
from tkinter import *
import os
import time
import tkinter

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
    
    username = StringVar()
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
 
    username_info = username.get()
    password_info = password.get()
    confirm_info = confirm.get()
    tally = 0
    files = os.listdir()
    
    for i in files:
        tally = tally + 1
    if tally <= 110: #REMEBER TO CHANGE BACK TO 11 when completed
 
        if password_info != confirm_info:
            password_not_matched()
        else:
            global file
            file = open(username_info, "w")
            file.write(username_info + "\n")
            file.write(password_info + "\n")
            #file.close()
 
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
    global mode_screen
    mode_screen = Tk()
    mode_screen.geometry("600x600")
    mode_screen.title("Pacing Mode select")
    button = Button(mode_screen, text = "Back to Dashboard", command = combine_funcs(dashboard, delete_mode_screen)).pack()
    
    #embedded function to get selection
    def get_mode():
        selection = StringVar()
        selection = mode_sel.get()
        label = Label(mode_screen, bg="green", text="Selection of " + selection + " is Successful")
        label.pack()
        button = Button(mode_screen, text = "Confirm", command = add2file).pack()
    #embedded function to add to file and move to parameter selection, still needs the actual file adding, currently only transports you to the next step
    def add2file():
        mode = StringVar()
        mode = mode_sel.get()
        username_info = username.get()
        if mode == "AOO":
            #file = open(username_info, "w")
            file.write(mode + "\n")
            #file.close()
            AOO_selections()
            delete_mode_screen()
        elif mode == "VOO":
            file.write(mode + "\n")
            file.close()
            VOO_selections()
            delete_mode_screen()
        elif mode == "AAI":
            file.write(mode + "\n")
            file.close()
            AAI_selections()
            delete_mode_screen()
        elif mode == "VVI":
            file.write(mode + "\n")
            file.close()
            VVI_selections()
            delete_mode_screen()
        
 
    Label(text="Before Starting, please select a pacing mode", bg="#C70039", width="300", height="2", font=("Calibri", 13)).pack()
    mode_sel= StringVar()
    mode_sel.set("AOO")
    ModeOptions = ["AOO","VOO","AAI","VVI"]
    drop= tkinter.OptionMenu(mode_screen, mode_sel, *ModeOptions) #andrew this is the type of line youre gonna wanna edit,
    drop.pack()
    button = Button(mode_screen, text = "Select", command = get_mode).pack()
#when completed, these four functions will add the parameters to the txt file created upon register. I have not done that yet but probably will soon
def roundToNearest(input, toNearest=5):
    return toNearest * round(input/toNearest)

def AOO_selections():
    default_LRL = 60
    LRL_ranges = [30,50,90,175] #range 1 low, range 1 high, range 2 low, range 2 high, etc
    LRL_increments = [5,1,5] #range 1 increment, range 2 increment, range 3 increment 
    
    AOO_screen = tkinter.Tk()
    AOO_screen.title("AOO Parameters")
    AOO_screen.geometry('600x600')
    Label(AOO_screen, text="AOO Parameter Selections", bg="#C70039", width="300", height="2", font=("Calibri", 13)).pack()
    def delete_AOO_screen():
        AOO_screen.destroy() #warning unsaved changes might be a good idea to implement here.  
    button = Button(AOO_screen, text = "Back", command = combine_funcs(select_mode_register, delete_AOO_screen)).pack()
    # add "unsaved changes warning" option on the back button
    ### FROM HERE TO NEXT COMMENT IS CRITICAL LRL ###
    label = Label(AOO_screen, text ="LRL selection (ppm):")
    CaptionLabelX = 70
    CaptionLabelY = 70
    CaptionLabelYIncrement = 47
    label.place(x=CaptionLabelX, y = CaptionLabelY)
    LRL_input = StringVar()
    LRL_menu = tkinter.Entry(AOO_screen, textvariable=LRL_input)
    LRL_menu.insert(0, str(default_LRL)) #once saving works, change this to "if a value is saved, insert that value here - if not, load the default."
    LRL_menu.pack()

    warningLabel = Label(AOO_screen, text="")
    warningLabel.pack(side=BOTTOM, padx=0, pady=0, anchor='n')
   # warningLabel.place(x=warningLabelX,y=warningLabelY)

    def get_LRL():
        LRL = tkinter.StringVar(AOO_screen)
        LRL = LRL_menu.get() #get the value from the insert
        warningLabel.config(text = "") #make existing error invisible
    #    warningLabel.place(x=warningLabelX,y=warningLabelY)
        def success():
            LRL = LRL_menu.get() 
            warningLabel.config(bg="green", text="Selection of " + str(LRL) + " is Successful.");
            file.write(str(LRL)+ '\n')
           # file.close() ASK
        try: #check if the input is translatable to float
            LRL=float(LRL)
        except ValueError:  
            print("Not a float") #if not, set to default value 
            LRL_menu.delete(0, END) #delete existing value
            LRL_menu.insert(0, default_LRL) #insert default value
            
            warningLabel.config(bg="red", text="Please insert a number. \n" + str(LRL) + " is not a number.")
     #       warningLabel.place(x=warningLabelX,y=warningLabelY)
        else:
            if(LRL<LRL_ranges[0]): #if below lowest increment, set to minimum
                LRL_menu.delete(0, END)
                LRL_menu.insert(0, str(LRL_ranges[0]))
                tempLRL = LRL_menu.get() 
                warningLabel.config(bg="yellow", text="Inserted value is below the minimum. \n Rounded to " + str(LRL_ranges[0]) + " for patient safety.")
      #          warningLabel.place(x=warningLabelX,y=warningLabelY)
            elif(LRL_ranges[0]<=LRL<LRL_ranges[1]): #if in the lowest range
                if(LRL%LRL_increments[0] != 0): #and not of a valid value
                    tempLRL = roundToNearest(LRL,LRL_increments[0]) #round to nearest valid value
                    LRL_menu.delete(0, END)
                    LRL_menu.insert(0, str(tempLRL)) #display that
                    warningLabel.config(bg="yellow", text="Inserted invalid value. \n Rounded to nearest valid increment, " + str(tempLRL) + ".")
                else:
                    success()
            elif(LRL_ranges[1]<=LRL<LRL_ranges[2]):
                if(LRL%LRL_increments[1] != 0): #and not of a valid value
                    tempLRL = roundToNearest(LRL,LRL_increments[1]) #round to nearest valid value
                    LRL_menu.delete(0, END)
                    LRL_menu.insert(0, str(tempLRL)) #display that
                    warningLabel.config(bg="yellow", text="Inserted invalid value. \n Rounded to nearest valid increment, " + str(tempLRL) + ".")
                else: #if valid, succeed
                    success()
            elif(LRL_ranges[2]<=LRL<=LRL_ranges[3]):
                if(LRL%LRL_increments[2] != 0): #and not of a valid value
                    tempLRL = roundToNearest(LRL,LRL_increments[2]) #round to nearest valid value
                    LRL_menu.delete(0, END)
                    LRL_menu.insert(0, str(tempLRL))
                    warningLabel.config(bg="yellow", text="Inserted invalid value. \n Rounded to nearest valid increment, " + str(tempLRL) + ".")      
                else:
                    success()
            elif(LRL>LRL_ranges[3]): #too big, round to highest valid 
                LRL_menu.delete(0, END)
                LRL_menu.insert(0, str(LRL_ranges[3]))
                warningLabel.config(bg="yellow", text="Inserted value is above the maximum. \n Rounded to " + str(LRL_ranges[3]) + " for patient safety.")
    button = Button(AOO_screen, text = "Select LRL", command = get_LRL).pack()
    
   ### FROM HERE TO NEXT COMMENT IS CRITICAL URL ###
    default_URL = 120
    URL_ranges = [50,175] #range 1 low, range 1 high
    URL_increments = [5,1,5] #range 1 increment, range 2 increment, range 3 increment 
    URLlabel = Label(AOO_screen, text ="URL selection (ppm):")
    URLlabel.place(x=CaptionLabelX, y = CaptionLabelY+CaptionLabelYIncrement)
    URL_input = StringVar()
    URL_menu = tkinter.Entry(AOO_screen, textvariable=URL_input)
    URL_menu.insert(0, str(default_URL)) #once saving works, change this to "if a value is saved, insert that value here - if not, load the default."
    URL_menu.pack()
    #no need to recreate the warning label, it exists up lop already
    def get_URL():
        URL = tkinter.StringVar(AOO_screen)
        URL = URL_menu.get() #get the value from the insert
        warningLabel.config(text = "") #make existing error invisible
    #    warningLabel.place(x=warningLabelX,y=warningLabelY)
        def success():
            URL = URL_menu.get() 
            warningLabel.config(bg="green", text="Selection of " + str(URL) + " is Successful.");
            file.write(str(URL)+ '\n')
            # file.close() ASK
        try: #check if the input is translatable to float
            URL=float(URL)
        except ValueError:  
            print("Not a float") #if not, set to default value 
            URL_menu.delete(0, END) #delete existing value
            URL_menu.insert(0, default_URL) #insert default value
            warningLabel.config(bg="red", text="Please insert a number. \n" + str(URL) + " is not a number.")
        else:    
            if(URL<URL_ranges[0]): #if below lowest increment, set to minimum
                URL_menu.delete(0, END)
                URL_menu.insert(0, str(URL_ranges[0]))
                tempURL = URL_menu.get() 
                warningLabel.config(bg="yellow", text="Inserted value is below the minimum. \n Rounded to " + str(URL_ranges[0]) + " for patient safety.")
            elif(URL_ranges[0]<=URL<=URL_ranges[1]): #if in the lowest range
                if(URL%URL_increments[0] != 0): #and not of a valid value
                    tempURL = roundToNearest(URL,URL_increments[0]) #round to nearest valid value
                    URL_menu.delete(0, END)
                    URL_menu.insert(0, str(tempURL)) #display that
                    warningLabel.config(bg="yellow", text="Inserted invalid value. \n Rounded to nearest valid increment, " + str(tempURL) + ".")
                else:
                    success()
            elif(URL>URL_ranges[1]): #if too high
                URL_menu.delete(0, END)
                URL_menu.insert(0, str(URL_ranges[1]))
                warningLabel.config(bg="yellow", text="Inserted value is above the maximum. \n Rounded to " + str(URL_ranges[1]) + " for patient safety.")
    button = Button(AOO_screen, text = "Select URL", command = get_URL).pack()
    
    ###Atrial Pulse Amplitude###
    default_APulseAmp = 3.5
    APulseAmp_ranges = [0.5,3.2] #range 1 low, range 1 high
    APulseAmp_increments = [0.1] #range 1 increment, range 2 increment, range 3 increment 
    APulseAmplabel = Label(AOO_screen, text ="APulseAmp selection (ppm):")
    APulseAmplabel.place(x=CaptionLabelX, y = CaptionLabelY+CaptionLabelYIncrement*2)
    APulseAmp_input = StringVar()
    APulseAmp_menu = tkinter.Entry(AOO_screen, textvariable=APulseAmp_input)
    APulseAmp_menu.insert(0, str(default_APulseAmp)) #once saving works, change this to "if a value is saved, insert that value here - if not, load the default."
    APulseAmp_menu.pack()
    #NEED TO ASK ABOUT THIS SECOND VALUE
    def get_APulseAmp():
        APulseAmp = tkinter.StringVar(AOO_screen)
        APulseAmp = APulseAmp_menu.get() #get the value from the insert
        warningLabel.config(text = "") #make existing error invisible
    #    warningLabel.place(x=warningLabelX,y=warningLabelY)
        def success():
            APulseAmp = APulseAmp_menu.get()
            if(str(APulseAmp) == "Off" or str(APulseAmp) == "off" or str(APulseAmp) == "OFF" or float(APulseAmp) == 0):
                warningLabel.config(bg="green", text="Selection of " + str(APulseAmp) + " is Successful. \n You have just turned off the AOO pace amplitude.")
            else:
                warningLabel.config(bg="green", text="Selection of " + str(APulseAmp) + " is Successful.")
            file.write(str(APulseAmp)+ '\n')
            # file.close() ASK
        if(str(APulseAmp) == "Off" or str(APulseAmp) == "off" or str(APulseAmp) == "OFF"): #if off
            APulseAmp_menu.delete(0, END) #delete existing value
            APulseAmp_menu.insert(0, 0) #0
            success()
            return
        try: #check if the input is translatable to float
            APulseAmp=float(APulseAmp)
        except ValueError:  
            print("Not a float") #if not, set to default value 
            APulseAmp_menu.delete(0, END) #delete existing value
            APulseAmp_menu.insert(0, default_APulseAmp) #insert default value
            warningLabel.config(bg="red", text="Please insert a number. \n" + str(APulseAmp) + " is not a number.")
        else:
            if(float(APulseAmp) == 0): #if off
                success()   
                return 
            if(APulseAmp<APulseAmp_ranges[0]): #if below lowest increment, set to minimum
                APulseAmp_menu.delete(0, END)
                APulseAmp_menu.insert(0, str(APulseAmp_ranges[0]))
                tempAPulseAmp = APulseAmp_menu.get() 
                warningLabel.config(bg="yellow", text="Inserted value is below the minimum. \n Rounded to " + str(APulseAmp_ranges[0]) + " for patient safety.")
            elif(APulseAmp_ranges[0]<=APulseAmp<=APulseAmp_ranges[1]): #if in the lowest range
                debugVar = float(APulseAmp*10)%float(APulseAmp_increments[0]*10)
                if(debugVar != 0): #and not of a valid value
                    tempAPulseAmp = float(int(roundToNearest(APulseAmp,APulseAmp_increments[0])*10)/10) #round to nearest valid value, in this scuffed way to account for floating point errors
                    APulseAmp_menu.delete(0, END)
                    APulseAmp_menu.insert(0, str(tempAPulseAmp)) #display that
                    warningLabel.config(bg="yellow", text="Inserted invalid value. \n Rounded to nearest valid increment, " + str(tempAPulseAmp) + ".")
                else:
                    success()
                    return
            elif(APulseAmp>APulseAmp_ranges[1]): #if too high
                APulseAmp_menu.delete(0, END)
                APulseAmp_menu.insert(0, str(APulseAmp_ranges[1]))
                warningLabel.config(bg="yellow", text="Inserted value is above the maximum. \n Rounded to " + str(APulseAmp_ranges[1]) + " for patient safety.")
    button = Button(AOO_screen, text = "Select APulse Amplitude (V)", command = get_APulseAmp).pack()

    ###Atrial Pulse Width###
    default_APulseWidth = 0.4
    APulseWidth_ranges = [0.1,1.9] #range 1 low, range 1 high
    APulseWidth_increments = [0.1] #range 1 increment, range 2 increment, range 3 increment 
    APulseWidthlabel = Label(AOO_screen, text ="APulseWidth selection (ms):")
    APulseWidthlabel.place(x=CaptionLabelX, y = CaptionLabelY+CaptionLabelYIncrement*3)
    APulseWidth_input = StringVar()
    APulseWidth_menu = tkinter.Entry(AOO_screen, textvariable=APulseWidth_input)
    APulseWidth_menu.insert(0, str(default_APulseWidth)) #once saving works, change this to "if a value is saved, insert that value here - if not, load the default."
    APulseWidth_menu.pack()
    #NEED TO ASK ABOUT THIS SECOND VALUE
    def get_APulseWidth():
        APulseWidth = tkinter.StringVar(AOO_screen)
        APulseWidth = APulseWidth_menu.get() #get the value from the insert
        warningLabel.config(text = "") #make existing error invisible
    #    warningLabel.place(x=warningLabelX,y=warningLabelY)
        def success():
            APulseWidth = APulseWidth_menu.get()
            warningLabel.config(bg="green", text="Selection of " + str(APulseWidth) + " is Successful.")
            file.write(str(APulseWidth)+ '\n')
            # file.close() ASK
        try: #check if the input is translatable to float
            APulseWidth=float(APulseWidth)
        except ValueError:  
            print("Not a float") #if not, set to default value 
            APulseWidth_menu.delete(0, END) #delete existing value
            APulseWidth_menu.insert(0, default_APulseWidth) #insert default value
            warningLabel.config(bg="red", text="Please insert a number. \n" + str(APulseWidth) + " is not a number.")
        else:
            if(float(APulseWidth) < 0.05): 
                warningLabel.config(bg="yellow", text="Inserted value is below the minimum. \n Rounded to " + "0.05 " + " for patient safety.")
                APulseWidth_menu.delete(0, END)
                APulseWidth_menu.insert(0, "0.05")
                return
            if(float(APulseWidth) == 0.05): #if that one specific value in the table 
                success()   
                return 
            if(APulseWidth<APulseWidth_ranges[0]): #if below lowest increment, set to minimum
                APulseWidth_menu.delete(0, END)
                APulseWidth_menu.insert(0, str(APulseWidth_ranges[0]))
                tempAPulseWidth = APulseWidth_menu.get() 
                warningLabel.config(bg="yellow", text="Inserted invalid value. \n Rounded to nearest valid increment " + str(APulseWidth_ranges[0]) + " for patient safety.")
            elif(APulseWidth_ranges[0]<=APulseWidth<=APulseWidth_ranges[1]): #if in the lowest range
                debugVar = float(APulseWidth*10)%float(APulseWidth_increments[0]*10)
                if(debugVar != 0): #and not of a valid value
                    tempAPulseWidth = float(int(roundToNearest(APulseWidth,APulseWidth_increments[0])*10)/10) #round to nearest valid value, in this scuffed way to account for floating point errors
                    APulseWidth_menu.delete(0, END)
                    APulseWidth_menu.insert(0, str(tempAPulseWidth)) #display that
                    warningLabel.config(bg="yellow", text="Inserted invalid value. \n Rounded to nearest valid increment, " + str(tempAPulseWidth) + ".")
                else:
                    success()
                    return
            elif(APulseWidth>APulseWidth_ranges[1]): #if too high
                APulseWidth_menu.delete(0, END)
                APulseWidth_menu.insert(0, str(APulseWidth_ranges[1]))
                warningLabel.config(bg="yellow", text="Inserted value is above the maximum. \n Rounded to " + str(APulseWidth_ranges[1]) + " for patient safety.")
    button = Button(AOO_screen, text = "Select APulse Width (ms)", command = get_APulseWidth).pack()
    
def VOO_selections(): ##literally the same as AOO except with some varible names swapped
    default_LRL = 60
    LRL_ranges = [30,50,90,175] #range 1 low, range 1 high, range 2 low, range 2 high, etc
    LRL_increments = [5,1,5] #range 1 increment, range 2 increment, range 3 increment 
    
    VOO_screen = tkinter.Tk()
    VOO_screen.title("VOO Parameters")
    VOO_screen.geometry('600x600')
    Label(VOO_screen, text="VOO Parameter Selections", bg="#C70039", width="300", height="2", font=("Calibri", 13)).pack()
    def delete_VOO_screen():
        VOO_screen.destroy() #warning unsaved changes might be a good idea to implement here.  
    button = Button(VOO_screen, text = "Back", command = combine_funcs(select_mode_register, delete_VOO_screen)).pack()
    # add "unsaved changes warning" option on the back button
    ### FROM HERE TO NEXT COMMENT IS CRITICAL LRL ###
    label = Label(VOO_screen, text ="LRL selection (ppm):")
    CaptionLabelX = 70
    CaptionLabelY = 70
    CaptionLabelYIncrement = 47
    label.place(x=CaptionLabelX, y = CaptionLabelY)
    LRL_input = StringVar()
    LRL_menu = tkinter.Entry(VOO_screen, textvariable=LRL_input)
    LRL_menu.insert(0, str(default_LRL)) #once saving works, change this to "if a value is saved, insert that value here - if not, load the default."
    LRL_menu.pack()

    warningLabel = Label(VOO_screen, text="")
    warningLabel.pack(side=BOTTOM, padx=0, pady=0, anchor='n')
   # warningLabel.place(x=warningLabelX,y=warningLabelY)

    def get_LRL():
        LRL = tkinter.StringVar(VOO_screen)
        LRL = LRL_menu.get() #get the value from the insert
        warningLabel.config(text = "") #make existing error invisible
    #    warningLabel.place(x=warningLabelX,y=warningLabelY)
        def success():
            LRL = LRL_menu.get() 
            warningLabel.config(bg="green", text="Selection of " + str(LRL) + " is Successful.");
            file.write(str(LRL)+ '\n')
           # file.close() ASK
        try: #check if the input is translatable to float
            LRL=float(LRL)
        except ValueError:  
            print("Not a float") #if not, set to default value 
            LRL_menu.delete(0, END) #delete existing value
            LRL_menu.insert(0, default_LRL) #insert default value
            
            warningLabel.config(bg="red", text="Please insert a number. \n" + str(LRL) + " is not a number.")
     #       warningLabel.place(x=warningLabelX,y=warningLabelY)
        else:
            if(LRL<LRL_ranges[0]): #if below lowest increment, set to minimum
                LRL_menu.delete(0, END)
                LRL_menu.insert(0, str(LRL_ranges[0]))
                tempLRL = LRL_menu.get() 
                warningLabel.config(bg="yellow", text="Inserted value is below the minimum. \n Rounded to " + str(LRL_ranges[0]) + " for patient safety.")
      #          warningLabel.place(x=warningLabelX,y=warningLabelY)
            elif(LRL_ranges[0]<=LRL<LRL_ranges[1]): #if in the lowest range
                if(LRL%LRL_increments[0] != 0): #and not of a valid value
                    tempLRL = roundToNearest(LRL,LRL_increments[0]) #round to nearest valid value
                    LRL_menu.delete(0, END)
                    LRL_menu.insert(0, str(tempLRL)) #display that
                    warningLabel.config(bg="yellow", text="Inserted invalid value. \n Rounded to nearest valid increment, " + str(tempLRL) + ".")
                else:
                    success()
            elif(LRL_ranges[1]<=LRL<LRL_ranges[2]):
                if(LRL%LRL_increments[1] != 0): #and not of a valid value
                    tempLRL = roundToNearest(LRL,LRL_increments[1]) #round to nearest valid value
                    LRL_menu.delete(0, END)
                    LRL_menu.insert(0, str(tempLRL)) #display that
                    warningLabel.config(bg="yellow", text="Inserted invalid value. \n Rounded to nearest valid increment, " + str(tempLRL) + ".")
                else: #if valid, succeed
                    success()
            elif(LRL_ranges[2]<=LRL<=LRL_ranges[3]):
                if(LRL%LRL_increments[2] != 0): #and not of a valid value
                    tempLRL = roundToNearest(LRL,LRL_increments[2]) #round to nearest valid value
                    LRL_menu.delete(0, END)
                    LRL_menu.insert(0, str(tempLRL))
                    warningLabel.config(bg="yellow", text="Inserted invalid value. \n Rounded to nearest valid increment, " + str(tempLRL) + ".")      
                else:
                    success()
            elif(LRL>LRL_ranges[3]): #too big, round to highest valid 
                LRL_menu.delete(0, END)
                LRL_menu.insert(0, str(LRL_ranges[3]))
                warningLabel.config(bg="yellow", text="Inserted value is above the maximum. \n Rounded to " + str(LRL_ranges[3]) + " for patient safety.")
    button = Button(VOO_screen, text = "Select LRL", command = get_LRL).pack()
    
   ### FROM HERE TO NEXT COMMENT IS CRITICAL URL ###
    default_URL = 120
    URL_ranges = [50,175] #range 1 low, range 1 high
    URL_increments = [5,1,5] #range 1 increment, range 2 increment, range 3 increment 
    URLlabel = Label(VOO_screen, text ="URL selection (ppm):")
    URLlabel.place(x=CaptionLabelX, y = CaptionLabelY+CaptionLabelYIncrement)
    URL_input = StringVar()
    URL_menu = tkinter.Entry(VOO_screen, textvariable=URL_input)
    URL_menu.insert(0, str(default_URL)) #once saving works, change this to "if a value is saved, insert that value here - if not, load the default."
    URL_menu.pack()
    #no need to recreate the warning label, it exists up lop already
    def get_URL():
        URL = tkinter.StringVar(VOO_screen)
        URL = URL_menu.get() #get the value from the insert
        warningLabel.config(text = "") #make existing error invisible
    #    warningLabel.place(x=warningLabelX,y=warningLabelY)
        def success():
            URL = URL_menu.get() 
            warningLabel.config(bg="green", text="Selection of " + str(URL) + " is Successful.");
            file.write(str(URL)+ '\n')
            # file.close() ASK
        try: #check if the input is translatable to float
            URL=float(URL)
        except ValueError:  
            print("Not a float") #if not, set to default value 
            URL_menu.delete(0, END) #delete existing value
            URL_menu.insert(0, default_URL) #insert default value
            warningLabel.config(bg="red", text="Please insert a number. \n" + str(URL) + " is not a number.")
        else:    
            if(URL<URL_ranges[0]): #if below lowest increment, set to minimum
                URL_menu.delete(0, END)
                URL_menu.insert(0, str(URL_ranges[0]))
                tempURL = URL_menu.get() 
                warningLabel.config(bg="yellow", text="Inserted value is below the minimum. \n Rounded to " + str(URL_ranges[0]) + " for patient safety.")
            elif(URL_ranges[0]<=URL<=URL_ranges[1]): #if in the lowest range
                if(URL%URL_increments[0] != 0): #and not of a valid value
                    tempURL = roundToNearest(URL,URL_increments[0]) #round to nearest valid value
                    URL_menu.delete(0, END)
                    URL_menu.insert(0, str(tempURL)) #display that
                    warningLabel.config(bg="yellow", text="Inserted invalid value. \n Rounded to nearest valid increment, " + str(tempURL) + ".")
                else:
                    success()
            elif(URL>URL_ranges[1]): #if too high
                URL_menu.delete(0, END)
                URL_menu.insert(0, str(URL_ranges[1]))
                warningLabel.config(bg="yellow", text="Inserted value is above the maximum. \n Rounded to " + str(URL_ranges[1]) + " for patient safety.")
    button = Button(VOO_screen, text = "Select URL", command = get_URL).pack()
    
    ###Ventricle Pulse Amplitude###
    default_VPulseAmp = 3.5
    VPulseAmp_ranges = [0.5,3.2] #range 1 low, range 1 high
    VPulseAmp_increments = [0.1] #range 1 increment, range 2 increment, range 3 increment 
    VPulseAmplabel = Label(VOO_screen, text ="VPulseAmp selection (ppm):")
    VPulseAmplabel.place(x=CaptionLabelX, y = CaptionLabelY+CaptionLabelYIncrement*2)
    VPulseAmp_input = StringVar()
    VPulseAmp_menu = tkinter.Entry(VOO_screen, textvariable=VPulseAmp_input)
    VPulseAmp_menu.insert(0, str(default_VPulseAmp)) #once saving works, change this to "if a value is saved, insert that value here - if not, load the default."
    VPulseAmp_menu.pack()
    #NEED TO ASK ABOUT THIS SECOND VALUE
    def get_VPulseAmp():
        VPulseAmp = tkinter.StringVar(VOO_screen)
        VPulseAmp = VPulseAmp_menu.get() #get the value from the insert
        warningLabel.config(text = "") #make existing error invisible
    #    warningLabel.place(x=warningLabelX,y=warningLabelY)
        def success():
            VPulseAmp = VPulseAmp_menu.get()
            if(str(VPulseAmp) == "Off" or str(VPulseAmp) == "off" or str(VPulseAmp) == "OFF" or float(VPulseAmp) == 0):
                warningLabel.config(bg="green", text="Selection of " + str(VPulseAmp) + " is Successful. \n You have just turned off the AOO pace amplitude.")
            else:
                warningLabel.config(bg="green", text="Selection of " + str(VPulseAmp) + " is Successful.")
            file.write(str(VPulseAmp)+ '\n')
            # file.close() ASK
        if(str(VPulseAmp) == "Off" or str(VPulseAmp) == "off" or str(VPulseAmp) == "OFF"): #if off
            VPulseAmp_menu.delete(0, END) #delete existing value
            VPulseAmp_menu.insert(0, 0) #0
            success()
            return
        try: #check if the input is translatable to float
            VPulseAmp=float(VPulseAmp)
        except ValueError:  
            print("Not a float") #if not, set to default value 
            VPulseAmp_menu.delete(0, END) #delete existing value
            VPulseAmp_menu.insert(0, default_VPulseAmp) #insert default value
            warningLabel.config(bg="red", text="Please insert a number. \n" + str(VPulseAmp) + " is not a number.")
        else:
            if(float(VPulseAmp) == 0): #if off
                success()   
                return 
            if(VPulseAmp<VPulseAmp_ranges[0]): #if below lowest increment, set to minimum
                VPulseAmp_menu.delete(0, END)
                VPulseAmp_menu.insert(0, str(VPulseAmp_ranges[0]))
                tempVPulseAmp = VPulseAmp_menu.get() 
                warningLabel.config(bg="yellow", text="Inserted value is below the minimum. \n Rounded to " + str(VPulseAmp_ranges[0]) + " for patient safety.")
            elif(VPulseAmp_ranges[0]<=VPulseAmp<=VPulseAmp_ranges[1]): #if in the lowest range
                debugVar = float(VPulseAmp*10)%float(VPulseAmp_increments[0]*10)
                if(debugVar != 0): #and not of a valid value
                    tempVPulseAmp = float(int(roundToNearest(VPulseAmp,VPulseAmp_increments[0])*10)/10) #round to nearest valid value, in this scuffed way to account for floating point errors
                    VPulseAmp_menu.delete(0, END)
                    VPulseAmp_menu.insert(0, str(tempVPulseAmp)) #display that
                    warningLabel.config(bg="yellow", text="Inserted invalid value. \n Rounded to nearest valid increment, " + str(tempVPulseAmp) + ".")
                else:
                    success()
                    return
            elif(VPulseAmp>VPulseAmp_ranges[1]): #if too high
                VPulseAmp_menu.delete(0, END)
                VPulseAmp_menu.insert(0, str(VPulseAmp_ranges[1]))
                warningLabel.config(bg="yellow", text="Inserted value is above the maximum. \n Rounded to " + str(VPulseAmp_ranges[1]) + " for patient safety.")
    button = Button(VOO_screen, text = "Select VPulse Amplitude (V)", command = get_VPulseAmp).pack()

    ###Ventrical Pulse Amplitude###
    default_VPulseWidth = 0.4
    VPulseWidth_ranges = [0.1,1.9] #range 1 low, range 1 high
    VPulseWidth_increments = [0.1] #range 1 increment, range 2 increment, range 3 increment 
    VPulseWidthlabel = Label(VOO_screen, text ="VPulseWidth selection (ms):")
    VPulseWidthlabel.place(x=CaptionLabelX, y = CaptionLabelY+CaptionLabelYIncrement*3)
    VPulseWidth_input = StringVar()
    VPulseWidth_menu = tkinter.Entry(VOO_screen, textvariable=VPulseWidth_input)
    VPulseWidth_menu.insert(0, str(default_VPulseWidth)) #once saving works, change this to "if a value is saved, insert that value here - if not, load the default."
    VPulseWidth_menu.pack()
    #NEED TO ASK ABOUT THIS SECOND VALUE
    def get_VPulseWidth():
        VPulseWidth = tkinter.StringVar(VOO_screen)
        VPulseWidth = VPulseWidth_menu.get() #get the value from the insert
        warningLabel.config(text = "") #make existing error invisible
    #    warningLabel.place(x=warningLabelX,y=warningLabelY)
        def success():
            VPulseWidth = VPulseWidth_menu.get()
            warningLabel.config(bg="green", text="Selection of " + str(VPulseWidth) + " is Successful.")
            file.write(str(VPulseWidth)+ '\n')
            # file.close() ASK
        try: #check if the input is translatable to float
            VPulseWidth=float(VPulseWidth)
        except ValueError:  
            print("Not a float") #if not, set to default value 
            VPulseWidth_menu.delete(0, END) #delete existing value
            VPulseWidth_menu.insert(0, default_VPulseWidth) #insert default value
            warningLabel.config(bg="red", text="Please insert a number. \n" + str(VPulseWidth) + " is not a number.")
        else:
            if(float(VPulseWidth) < 0.05): 
                warningLabel.config(bg="yellow", text="Inserted value is below the minimum. \n Rounded to " + "0.05 " + " for patient safety.")
                VPulseWidth_menu.delete(0, END)
                VPulseWidth_menu.insert(0, "0.05")
                return
            if(float(VPulseWidth) == 0.05): #if that one specific value in the table 
                success()   
                return 
            if(VPulseWidth<VPulseWidth_ranges[0]): #if below lowest increment, set to minimum
                VPulseWidth_menu.delete(0, END)
                VPulseWidth_menu.insert(0, str(VPulseWidth_ranges[0]))
                tempVPulseWidth = VPulseWidth_menu.get() 
                warningLabel.config(bg="yellow", text="Inserted invalid value. \n Rounded to nearest valid increment " + str(VPulseWidth_ranges[0]) + " for patient safety.")
            elif(VPulseWidth_ranges[0]<=VPulseWidth<=VPulseWidth_ranges[1]): #if in the lowest range
                debugVar = float(VPulseWidth*10)%float(VPulseWidth_increments[0]*10)
                if(debugVar != 0): #and not of a valid value
                    tempVPulseWidth = float(int(roundToNearest(VPulseWidth,VPulseWidth_increments[0])*10)/10) #round to nearest valid value, in this scuffed way to account for floating point errors
                    VPulseWidth_menu.delete(0, END)
                    VPulseWidth_menu.insert(0, str(tempVPulseWidth)) #display that
                    warningLabel.config(bg="yellow", text="Inserted invalid value. \n Rounded to nearest valid increment, " + str(tempVPulseWidth) + ".")
                else:
                    success()
                    return
            elif(VPulseWidth>VPulseWidth_ranges[1]): #if too high
                VPulseWidth_menu.delete(0, END)
                VPulseWidth_menu.insert(0, str(VPulseWidth_ranges[1]))
                warningLabel.config(bg="yellow", text="Inserted value is above the maximum. \n Rounded to " + str(VPulseWidth_ranges[1]) + " for patient safety.")
    button = Button(VOO_screen, text = "Select VPulse Width (ms)", command = get_VPulseWidth).pack()
                     
def AAI_selections():
    default_LRL = 60
    LRL_ranges = [30,50,90,175] #range 1 low, range 1 high, range 2 low, range 2 high, etc
    LRL_increments = [5,1,5] #range 1 increment, range 2 increment, range 3 increment 
    
    AAI_screen = tkinter.Tk()
    AAI_screen.title("AAI Parameters")
    AAI_screen.geometry('600x600')
    Label(AAI_screen, text="AAI Parameter Selections", bg="#C70039", width="300", height="2", font=("Calibri", 13)).pack()
    def delete_AAI_screen():
        AAI_screen.destroy() #warning unsaved changes might be a good idea to implement here.  
    button = Button(AAI_screen, text = "Back", command = combine_funcs(select_mode_register, delete_AAI_screen)).pack()
    # add "unsaved changes warning" option on the back button
    ### FROM HERE TO NEXT COMMENT IS CRITICAL LRL ###
    label = Label(AAI_screen, text ="LRL selection (ppm):")
    CaptionLabelX = 70
    CaptionLabelY = 70
    CaptionLabelYIncrement = 47
    label.place(x=CaptionLabelX, y = CaptionLabelY)
    LRL_input = StringVar()
    LRL_menu = tkinter.Entry(AAI_screen, textvariable=LRL_input)
    LRL_menu.insert(0, str(default_LRL)) #once saving works, change this to "if a value is saved, insert that value here - if not, load the default."
    LRL_menu.pack()
    warningLabel = Label(AAI_screen, text="")
    warningLabel.pack(side=BOTTOM, padx=0, pady=0, anchor='n')
   # warningLabel.place(x=warningLabelX,y=warningLabelY)

    def get_LRL():
        LRL = tkinter.StringVar(AAI_screen)
        LRL = LRL_menu.get() #get the value from the insert
        warningLabel.config(text = "") #make existing error invisible
    #    warningLabel.place(x=warningLabelX,y=warningLabelY)
        def success():
            LRL = LRL_menu.get() 
            warningLabel.config(bg="green", text="Selection of " + str(LRL) + " is Successful.");
            file.write(str(LRL)+ '\n')
           # file.close() ASK
        try: #check if the input is translatable to float
            LRL=float(LRL)
        except ValueError:  
            print("Not a float") #if not, set to default value 
            LRL_menu.delete(0, END) #delete existing value
            LRL_menu.insert(0, default_LRL) #insert default value
            
            warningLabel.config(bg="red", text="Please insert a number. \n" + str(LRL) + " is not a number.")
     #       warningLabel.place(x=warningLabelX,y=warningLabelY)
        else:
            if(LRL<LRL_ranges[0]): #if below lowest increment, set to minimum
                LRL_menu.delete(0, END)
                LRL_menu.insert(0, str(LRL_ranges[0]))
                tempLRL = LRL_menu.get() 
                warningLabel.config(bg="yellow", text="Inserted value is below the minimum. \n Rounded to " + str(LRL_ranges[0]) + " for patient safety.")
      #          warningLabel.place(x=warningLabelX,y=warningLabelY)
            elif(LRL_ranges[0]<=LRL<LRL_ranges[1]): #if in the lowest range
                if(LRL%LRL_increments[0] != 0): #and not of a valid value
                    tempLRL = roundToNearest(LRL,LRL_increments[0]) #round to nearest valid value
                    LRL_menu.delete(0, END)
                    LRL_menu.insert(0, str(tempLRL)) #display that
                    warningLabel.config(bg="yellow", text="Inserted invalid value. \n Rounded to nearest valid increment, " + str(tempLRL) + ".")
                else:
                    success()
            elif(LRL_ranges[1]<=LRL<LRL_ranges[2]):
                if(LRL%LRL_increments[1] != 0): #and not of a valid value
                    tempLRL = roundToNearest(LRL,LRL_increments[1]) #round to nearest valid value
                    LRL_menu.delete(0, END)
                    LRL_menu.insert(0, str(tempLRL)) #display that
                    warningLabel.config(bg="yellow", text="Inserted invalid value. \n Rounded to nearest valid increment, " + str(tempLRL) + ".")
                else: #if valid, succeed
                    success()
            elif(LRL_ranges[2]<=LRL<=LRL_ranges[3]):
                if(LRL%LRL_increments[2] != 0): #and not of a valid value
                    tempLRL = roundToNearest(LRL,LRL_increments[2]) #round to nearest valid value
                    LRL_menu.delete(0, END)
                    LRL_menu.insert(0, str(tempLRL))
                    warningLabel.config(bg="yellow", text="Inserted invalid value. \n Rounded to nearest valid increment, " + str(tempLRL) + ".")      
                else:
                    success()
            elif(LRL>LRL_ranges[3]): #too big, round to highest valid 
                LRL_menu.delete(0, END)
                LRL_menu.insert(0, str(LRL_ranges[3]))
                warningLabel.config(bg="yellow", text="Inserted value is above the maximum. \n Rounded to " + str(LRL_ranges[3]) + " for patient safety.")
    button = Button(AAI_screen, text = "Select LRL", command = get_LRL).pack()
    
   ### FROM HERE TO NEXT COMMENT IS CRITICAL URL ###
    default_URL = 120
    URL_ranges = [50,175] #range 1 low, range 1 high
    URL_increments = [5,1,5] #range 1 increment, range 2 increment, range 3 increment 
    URLlabel = Label(AAI_screen, text ="URL selection (ppm):")
    URLlabel.place(x=CaptionLabelX, y = CaptionLabelY+CaptionLabelYIncrement)
    URL_input = StringVar()
    URL_menu = tkinter.Entry(AAI_screen, textvariable=URL_input)
    URL_menu.insert(0, str(default_URL)) #once saving works, change this to "if a value is saved, insert that value here - if not, load the default."
    URL_menu.pack()
    #no need to recreate the warning label, it exists up lop already
    def get_URL():
        URL = tkinter.StringVar(AAI_screen)
        URL = URL_menu.get() #get the value from the insert
        warningLabel.config(text = "") #make existing error invisible
    #    warningLabel.place(x=warningLabelX,y=warningLabelY)
        def success():
            URL = URL_menu.get() 
            warningLabel.config(bg="green", text="Selection of " + str(URL) + " is Successful.");
            file.write(str(URL)+ '\n')
            # file.close() ASK
        try: #check if the input is translatable to float
            URL=float(URL)
        except ValueError:  
            print("Not a float") #if not, set to default value 
            URL_menu.delete(0, END) #delete existing value
            URL_menu.insert(0, default_URL) #insert default value
            warningLabel.config(bg="red", text="Please insert a number. \n" + str(URL) + " is not a number.")
        else:    
            if(URL<URL_ranges[0]): #if below lowest increment, set to minimum
                URL_menu.delete(0, END)
                URL_menu.insert(0, str(URL_ranges[0]))
                tempURL = URL_menu.get() 
                warningLabel.config(bg="yellow", text="Inserted value is below the minimum. \n Rounded to " + str(URL_ranges[0]) + " for patient safety.")
            elif(URL_ranges[0]<=URL<=URL_ranges[1]): #if in the lowest range
                if(URL%URL_increments[0] != 0): #and not of a valid value
                    tempURL = roundToNearest(URL,URL_increments[0]) #round to nearest valid value
                    URL_menu.delete(0, END)
                    URL_menu.insert(0, str(tempURL)) #display that
                    warningLabel.config(bg="yellow", text="Inserted invalid value. \n Rounded to nearest valid increment, " + str(tempURL) + ".")
                else:
                    success()
            elif(URL>URL_ranges[1]): #if too high
                URL_menu.delete(0, END)
                URL_menu.insert(0, str(URL_ranges[1]))
                warningLabel.config(bg="yellow", text="Inserted value is above the maximum. \n Rounded to " + str(URL_ranges[1]) + " for patient safety.")
    button = Button(AAI_screen, text = "Select URL", command = get_URL).pack()
    ###Ventricle Pulse Amplitude###
    default_APulseAmp = 3.5
    APulseAmp_ranges = [0.5,3.2] #range 1 low, range 1 high
    APulseAmp_increments = [0.1] #range 1 increment, range 2 increment, range 3 increment 
    APulseAmplabel = Label(AAI_screen, text ="APulseAmp selection (ppm):")
    APulseAmplabel.place(x=CaptionLabelX, y = CaptionLabelY+CaptionLabelYIncrement*2)
    APulseAmp_input = StringVar()
    APulseAmp_menu = tkinter.Entry(AAI_screen, textvariable=APulseAmp_input)
    APulseAmp_menu.insert(0, str(default_APulseAmp)) #once saving works, change this to "if a value is saved, insert that value here - if not, load the default."
    APulseAmp_menu.pack()
    #NEED TO ASK ABOUT THIS SECOND VALUE
    def get_APulseAmp():
        APulseAmp = tkinter.StringVar(AAI_screen)
        APulseAmp = APulseAmp_menu.get() #get the value from the insert
        warningLabel.config(text = "") #make existing error invisible
    #    warningLabel.place(x=warningLabelX,y=warningLabelY)
        def success():
            APulseAmp = APulseAmp_menu.get()
            if(str(APulseAmp) == "Off" or str(APulseAmp) == "off" or str(APulseAmp) == "OFF" or float(APulseAmp) == 0):
                warningLabel.config(bg="green", text="Selection of " + str(APulseAmp) + " is Successful. \n You have just turned off the AAI pace amplitude.")
            else:
                warningLabel.config(bg="green", text="Selection of " + str(APulseAmp) + " is Successful.")
            file.write(str(APulseAmp)+ '\n')
            # file.close() ASK
        if(str(APulseAmp) == "Off" or str(APulseAmp) == "off" or str(APulseAmp) == "OFF"): #if off
            APulseAmp_menu.delete(0, END) #delete existing value
            APulseAmp_menu.insert(0, 0) #0
            success()
            return
        try: #check if the input is translatable to float
            APulseAmp=float(APulseAmp)
        except ValueError:  
            print("Not a float") #if not, set to default value 
            APulseAmp_menu.delete(0, END) #delete existing value
            APulseAmp_menu.insert(0, default_APulseAmp) #insert default value
            warningLabel.config(bg="red", text="Please insert a number. \n" + str(APulseAmp) + " is not a number.")
        else:
            if(float(APulseAmp) == 0): #if off
                success()   
                return 
            if(APulseAmp<APulseAmp_ranges[0]): #if below lowest increment, set to minimum
                APulseAmp_menu.delete(0, END)
                APulseAmp_menu.insert(0, str(APulseAmp_ranges[0]))
                tempAPulseAmp = APulseAmp_menu.get() 
                warningLabel.config(bg="yellow", text="Inserted value is below the minimum. \n Rounded to " + str(APulseAmp_ranges[0]) + " for patient safety.")
            elif(APulseAmp_ranges[0]<=APulseAmp<=APulseAmp_ranges[1]): #if in the lowest range
                debugVar = float(APulseAmp*10)%float(APulseAmp_increments[0]*10)
                if(debugVar != 0): #and not of a valid value
                    tempAPulseAmp = float(int(roundToNearest(APulseAmp,APulseAmp_increments[0])*10)/10) #round to nearest valid value, in this scuffed way to account for floating point errors
                    APulseAmp_menu.delete(0, END)
                    APulseAmp_menu.insert(0, str(tempAPulseAmp)) #display that
                    warningLabel.config(bg="yellow", text="Inserted invalid value. \n Rounded to nearest valid increment, " + str(tempAPulseAmp) + ".")
                else:
                    success()
                    return
            elif(APulseAmp>APulseAmp_ranges[1]): #if too high
                APulseAmp_menu.delete(0, END)
                APulseAmp_menu.insert(0, str(APulseAmp_ranges[1]))
                warningLabel.config(bg="yellow", text="Inserted value is above the maximum. \n Rounded to " + str(APulseAmp_ranges[1]) + " for patient safety.")
    button = Button(AAI_screen, text = "Select APulse Amplitude (V)", command = get_APulseAmp).pack()
    ###Atrial Pulse Amplitude###
    default_APulseWidth = 0.4
    APulseWidth_ranges = [0.1,1.9] #range 1 low, range 1 high
    APulseWidth_increments = [0.1] #range 1 increment, range 2 increment, range 3 increment 
    APulseWidthlabel = Label(AAI_screen, text ="APulseWidth selection (ms):")
    APulseWidthlabel.place(x=CaptionLabelX, y = CaptionLabelY+CaptionLabelYIncrement*3)
    APulseWidth_input = StringVar()
    APulseWidth_menu = tkinter.Entry(AAI_screen, textvariable=APulseWidth_input)
    APulseWidth_menu.insert(0, str(default_APulseWidth)) #once saving works, change this to "if a value is saved, insert that value here - if not, load the default."
    APulseWidth_menu.pack()
    #NEED TO ASK ABOUT THIS SECOND VALUE
    def get_APulseWidth():
        APulseWidth = tkinter.StringVar(AAI_screen)
        APulseWidth = APulseWidth_menu.get() #get the value from the insert
        warningLabel.config(text = "") #make existing error invisible
    #    warningLabel.place(x=warningLabelX,y=warningLabelY)
        def success():
            APulseWidth = APulseWidth_menu.get()
            warningLabel.config(bg="green", text="Selection of " + str(APulseWidth) + " is Successful.")
            file.write(str(APulseWidth)+ '\n')
            # file.close() ASK
        try: #check if the input is translatable to float
            APulseWidth=float(APulseWidth)
        except ValueError:  
            print("Not a float") #if not, set to default value 
            APulseWidth_menu.delete(0, END) #delete existing value
            APulseWidth_menu.insert(0, default_APulseWidth) #insert default value
            warningLabel.config(bg="red", text="Please insert a number. \n" + str(APulseWidth) + " is not a number.")
        else:
            if(float(APulseWidth) < 0.05): 
                warningLabel.config(bg="yellow", text="Inserted value is below the minimum. \n Rounded to " + "0.05 " + " for patient safety.")
                APulseWidth_menu.delete(0, END)
                APulseWidth_menu.insert(0, "0.05")
                return
            if(float(APulseWidth) == 0.05): #if that one specific value in the table 
                success()   
                return 
            if(APulseWidth<APulseWidth_ranges[0]): #if below lowest increment, set to minimum
                APulseWidth_menu.delete(0, END)
                APulseWidth_menu.insert(0, str(APulseWidth_ranges[0]))
                tempAPulseWidth = APulseWidth_menu.get() 
                warningLabel.config(bg="yellow", text="Inserted invalid value. \n Rounded to nearest valid increment " + str(APulseWidth_ranges[0]) + " for patient safety.")
            elif(APulseWidth_ranges[0]<=APulseWidth<=APulseWidth_ranges[1]): #if in the lowest range
                debugVar = float(APulseWidth*10)%float(APulseWidth_increments[0]*10)
                if(debugVar != 0): #and not of a valid value
                    tempAPulseWidth = float(int(roundToNearest(APulseWidth,APulseWidth_increments[0])*10)/10) #round to nearest valid value, in this scuffed way to account for floating point errors
                    APulseWidth_menu.delete(0, END)
                    APulseWidth_menu.insert(0, str(tempAPulseWidth)) #display that
                    warningLabel.config(bg="yellow", text="Inserted invalid value. \n Rounded to nearest valid increment, " + str(tempAPulseWidth) + ".")
                else:
                    success()
                    return
            elif(APulseWidth>APulseWidth_ranges[1]): #if too high
                APulseWidth_menu.delete(0, END)
                APulseWidth_menu.insert(0, str(APulseWidth_ranges[1]))
                warningLabel.config(bg="yellow", text="Inserted value is above the maximum. \n Rounded to " + str(APulseWidth_ranges[1]) + " for patient safety.")
    button = Button(AAI_screen, text = "Select APulse Width (ms)", command = get_APulseWidth).pack()

    default_ASensitivity = 0.75
    ASensitivity_ranges = [0.25,1,10] #range 1 low, range 1 high
    ASensitivity_increments = [0.25,0.5] #range 1 increment, range 2 increment, range 3 increment 
    ASensitivitylabel = Label(AAI_screen, text ="ASensitivity selection (mV):")
    ASensitivitylabel.place(x=CaptionLabelX, y = CaptionLabelY+CaptionLabelYIncrement*4)
    ASensitivity_input = StringVar()
    ASensitivity_menu = tkinter.Entry(AAI_screen, textvariable=ASensitivity_input)
    ASensitivity_menu.insert(0, str(default_ASensitivity)) #once saving works, change this to "if a value is saved, insert that value here - if not, load the default."
    ASensitivity_menu.pack()

    def get_ASensitivity():
        ASensitivity = tkinter.StringVar(AAI_screen)
        ASensitivity = ASensitivity_menu.get() #get the value from the insert
        warningLabel.config(text = "") #make existing error invisible
        def success():
            ASensitivity = ASensitivity_menu.get()
            warningLabel.config(bg="green", text="Selection of " + str(ASensitivity) + " is Successful.")
            file.write(str(ASensitivity)+ '\n')
            # file.close() ASK
        try: #check if the input is translatable to float
            ASensitivity=float(ASensitivity)
        except ValueError:  
            print("Not a float") #if not, set to default value 
            ASensitivity_menu.delete(0, END) #delete existing value
            ASensitivity_menu.insert(0, default_ASensitivity) #insert default value
            warningLabel.config(bg="red", text="Please insert a number. \n" + str(ASensitivity) + " is not a number.")
        else: 
            if(ASensitivity<ASensitivity_ranges[0]): #if below lowest increment, set to minimum
                ASensitivity_menu.delete(0, END)
                ASensitivity_menu.insert(0, str(ASensitivity_ranges[0]))
                tempASensitivity = ASensitivity_menu.get() 
                warningLabel.config(bg="yellow", text="Inserted invalid value. \n Rounded to nearest valid increment " + str(ASensitivity_ranges[0]) + " for patient safety.")
            elif(ASensitivity_ranges[0]<=ASensitivity<ASensitivity_ranges[1]): #if in the lowest range
                debugVar = float(ASensitivity*100)%float(ASensitivity_increments[0]*100)
                if(debugVar != 0): #and not of a valid value
                    tempASensitivity = float(int(roundToNearest(ASensitivity,ASensitivity_increments[0])*100)/100) #round to nearest valid value, in this scuffed way to account for floating point errors
                    ASensitivity_menu.delete(0, END)
                    ASensitivity_menu.insert(0, str(tempASensitivity)) #display that
                    warningLabel.config(bg="yellow", text="Inserted invalid value. \n Rounded to nearest valid increment, " + str(tempASensitivity) + ".")
                else:
                    success()
                    return
            elif(ASensitivity_ranges[1]<=ASensitivity<=ASensitivity_ranges[2]): #if in the lowest range
                debugVar = float(ASensitivity*100)%float(ASensitivity_increments[1]*100)
                if(debugVar != 0): #and not of a valid value
                    tempASensitivity = float(int(roundToNearest(ASensitivity,ASensitivity_increments[1])*100)/100) #round to nearest valid value, in this scuffed way to account for floating point errors
                    ASensitivity_menu.delete(0, END)
                    ASensitivity_menu.insert(0, str(tempASensitivity)) #display that
                    warningLabel.config(bg="yellow", text="Inserted invalid value. \n Rounded to nearest valid increment, " + str(tempASensitivity) + ".")
                else:
                    success()
                    return
            elif(ASensitivity>ASensitivity_ranges[2]): #if too high
                ASensitivity_menu.delete(0, END)
                ASensitivity_menu.insert(0, str(ASensitivity_ranges[2]))
                warningLabel.config(bg="yellow", text="Inserted value is above the maximum. \n Rounded to " + str(ASensitivity_ranges[2]) + " for patient safety.")
    button = Button(AAI_screen, text = "Select ASensitivity (mv)", command = get_ASensitivity).pack()

    ###Atrial Refractory Period###
    default_ARP = 250
    ARP_ranges = [150,500] #range 1 low, range 1 high
    ARP_increments = [10] #range 1 increment, range 2 increment, range 3 increment 
    ARPlabel = Label(AAI_screen, text ="ARP selection (ms):")
    ARPlabel.place(x=CaptionLabelX, y = CaptionLabelY+CaptionLabelYIncrement*5)
    ARP_input = StringVar()
    ARP_menu = tkinter.Entry(AAI_screen, textvariable=ARP_input)
    ARP_menu.insert(0, str(default_ARP)) #once saving works, change this to "if a value is saved, insert that value here - if not, load the default."
    ARP_menu.pack()

    def get_ARP():
        ARP = tkinter.StringVar(AAI_screen)
        ARP = ARP_menu.get() #get the value from the insert
        warningLabel.config(text = "") #make existing error invisible
        def success():
            ARP = ARP_menu.get()
            warningLabel.config(bg="green", text="Selection of " + str(ARP) + " is Successful.")
            file.write(str(ARP)+ '\n')
            # file.close() ASK
        try: #check if the input is translatable to float
            ARP=float(ARP)
        except ValueError:  
            print("Not a float") #if not, set to default value 
            ARP_menu.delete(0, END) #delete existing value
            ARP_menu.insert(0, default_ARP) #insert default value
            warningLabel.config(bg="red", text="Please insert a number. \n" + str(ARP) + " is not a number.")
        else: 
            if(ARP<ARP_ranges[0]): #if below lowest increment, set to minimum
                ARP_menu.delete(0, END)
                ARP_menu.insert(0, str(ARP_ranges[0]))
                tempARP = ARP_menu.get() 
                warningLabel.config(bg="yellow", text="Inserted invalid value. \n Rounded to nearest valid increment " + str(ARP_ranges[0]) + " for patient safety.")
            elif(ARP_ranges[0]<=ARP<=ARP_ranges[1]): #if in the lowest range
                debugVar = float(ARP*100)%float(ARP_increments[0]*100)
                if(debugVar != 0): #and not of a valid value
                    tempARP = float(int(roundToNearest(ARP,ARP_increments[0])*100)/100) #round to nearest valid value, in this scuffed way to account for floating point errors
                    ARP_menu.delete(0, END)
                    ARP_menu.insert(0, str(tempARP)) #display that
                    warningLabel.config(bg="yellow", text="Inserted invalid value. \n Rounded to nearest valid increment, " + str(tempARP) + ".")
                else:
                    success()
                    return
            elif(ARP>ARP_ranges[1]): #if too high
                ARP_menu.delete(0, END)
                ARP_menu.insert(0, str(ARP_ranges[1]))
                warningLabel.config(bg="yellow", text="Inserted value is above the maximum. \n Rounded to " + str(ARP_ranges[1]) + " for patient safety.")
    button = Button(AAI_screen, text = "Select ARP (ms)", command = get_ARP).pack()

    
    default_HRL = 60
    HRL_ranges = [30,50,90,175] #range 1 low, range 1 high
    HRL_increments = [5,1,5] #range 1 increment, range 2 increment, range 3 increment 
    HRLlabel = Label(AAI_screen, text ="HRL selection (ppm):")
    HRLlabel.place(x=CaptionLabelX, y = CaptionLabelY+CaptionLabelYIncrement*6-3)
    HRL_input = StringVar()
    HRL_menu = tkinter.Entry(AAI_screen, textvariable=HRL_input)
    HRL_menu.insert(0, str(default_HRL)) #once saving works, change this to "if a value is saved, insert that value here - if not, load the default."
    HRL_menu.pack()

    warningLabel = Label(AAI_screen, text="")
    warningLabel.pack(side=BOTTOM, padx=0, pady=0, anchor='n')
   # warningLabel.place(x=warningLabelX,y=warningLabelY)

    def get_HRL():
        HRL = tkinter.StringVar(AAI_screen)
        HRL = HRL_menu.get() #get the value from the insert
        warningLabel.config(text = "") #make existing error invisible
        def success():
            HRL = HRL_menu.get() 
            if(str(HRL) == "Off" or str(HRL) == "off" or str(HRL) == "OFF" or float(HRL) == 0):
                warningLabel.config(bg="green", text="Selection of " + str(HRL) + " is Successful. \n You have just turned off Hysterisis pacing.")
            else:
                warningLabel.config(bg="green", text="Selection of " + str(HRL) + " is Successful.")
            file.write(str(HRL)+ '\n')
            # file.close() ASK
        if(str(HRL) == "Off" or str(HRL) == "off" or str(HRL) == "OFF"): #if off
            HRL_menu.delete(0, END) #delete existing value
            HRL_menu.insert(0, 0) #0
            success()
            return
        try: #check if the input is translatable to float
            HRL=float(HRL)
        except ValueError:  
            print("Not a float") #if not, set to default value 
            HRL_menu.delete(0, END) #delete existing value
            HRL_menu.insert(0, default_HRL) #insert default value
            
            warningLabel.config(bg="red", text="Please insert a number. \n" + str(HRL) + " is not a number.")
     #       warningLabel.place(x=warningLabelX,y=warningLabelY)
        else:
            if(float(HRL)==0):
                HRL_menu.delete(0, END) #delete existing value
                HRL_menu.insert(0, 0) #0
                success()
                return 
            if(HRL<HRL_ranges[0]): #if below lowest increment, set to minimum
                HRL_menu.delete(0, END)
                HRL_menu.insert(0, str(HRL_ranges[0]))
                tempHRL = HRL_menu.get() 
                warningLabel.config(bg="yellow", text="Inserted value is below the minimum. \n Rounded to " + str(HRL_ranges[0]) + " for patient safety.")
      #          warningLabel.place(x=warningLabelX,y=warningLabelY)
            elif(HRL_ranges[0]<=HRL<HRL_ranges[1]): #if in the lowest range
                if(HRL%HRL_increments[0] != 0): #and not of a valid value
                    tempHRL = roundToNearest(HRL,HRL_increments[0]) #round to nearest valid value
                    HRL_menu.delete(0, END)
                    HRL_menu.insert(0, str(tempHRL)) #display that
                    warningLabel.config(bg="yellow", text="Inserted invalid value. \n Rounded to nearest valid increment, " + str(tempHRL) + ".")
                else:
                    success()
            elif(HRL_ranges[1]<=HRL<HRL_ranges[2]):
                if(HRL%HRL_increments[1] != 0): #and not of a valid value
                    tempHRL = roundToNearest(HRL,HRL_increments[1]) #round to nearest valid value
                    HRL_menu.delete(0, END)
                    HRL_menu.insert(0, str(tempHRL)) #display that
                    warningLabel.config(bg="yellow", text="Inserted invalid value. \n Rounded to nearest valid increment, " + str(tempHRL) + ".")
                else: #if valid, succeed
                    success()
            elif(HRL_ranges[2]<=HRL<=HRL_ranges[3]):
                if(HRL%HRL_increments[2] != 0): #and not of a valid value
                    tempHRL = roundToNearest(HRL,HRL_increments[2]) #round to nearest valid value
                    HRL_menu.delete(0, END)
                    HRL_menu.insert(0, str(tempHRL))
                    warningLabel.config(bg="yellow", text="Inserted invalid value. \n Rounded to nearest valid increment, " + str(tempHRL) + ".")      
                else:
                    success()
            elif(HRL>HRL_ranges[3]): #too big, round to highest valid 
                HRL_menu.delete(0, END)
                HRL_menu.insert(0, str(HRL_ranges[3]))
                warningLabel.config(bg="yellow", text="Inserted value is above the maximum. \n Rounded to " + str(HRL_ranges[3]) + " for patient safety.")
    button = Button(AAI_screen, text = "Select HRL", command = get_HRL).pack()

    default_RS = 0
    RS_ranges = [0,21,25] #range 1 low, range 1 high
    RS_increments = [3,5] #range 1 increment, range 2 increment, range 3 increment 
    RSlabel = Label(AAI_screen, text ="Rate Smoothing Factor (%):")
    RSlabel.place(x=CaptionLabelX, y = CaptionLabelY+CaptionLabelYIncrement*7-10)
    RS_input = StringVar()
    RS_menu = tkinter.Entry(AAI_screen, textvariable=RS_input)
    RS_menu.insert(0, str(default_RS)) #once saving works, change this to "if a value is saved, insert that value here - if not, load the default."
    RS_menu.pack()

    warningLabel = Label(AAI_screen, text="")
    warningLabel.pack(side=BOTTOM, padx=0, pady=0, anchor='n')
   # warningLabel.place(x=warningLabelX,y=warningLabelY)

    def get_RS():
        RS = tkinter.StringVar(AAI_screen)
        RS = RS_menu.get() #get the value from the insert
        warningLabel.config(text = "") #make existing error invisible
        def success():
            RS = RS_menu.get() 
            if(str(RS) == "Off" or str(RS) == "off" or str(RS) == "OFF" or float(RS) == 0):
                warningLabel.config(bg="green", text="Selection of " + str(RS) + " is Successful. \n You have just turned off Hysterisis pacing.")
            else:
                warningLabel.config(bg="green", text="Selection of " + str(RS) + " is Successful.")
            file.write(str(RS)+ '\n')
            # file.close() ASK
        if(str(RS) == "Off" or str(RS) == "off" or str(RS) == "OFF"): #if off
            RS_menu.delete(0, END) #delete existing value
            RS_menu.insert(0, 0) #0
            success()
            return
        try: #check if the input is translatable to float
            RS=float(RS)
        except ValueError:  
            print("Not a float") #if not, set to default value 
            RS_menu.delete(0, END) #delete existing value
            RS_menu.insert(0, default_RS) #insert default value
            
            warningLabel.config(bg="red", text="Please insert a number. \n" + str(RS) + " is not a number.")
     #       warningLabel.place(x=warningLabelX,y=warningLabelY)
        else:
            if(float(RS)==0):
                RS_menu.delete(0, END) #delete existing value
                RS_menu.insert(0, 0) #0
                success()
                return 
            if(RS<RS_ranges[0]): #if below lowest increment, set to minimum
                RS_menu.delete(0, END)
                RS_menu.insert(0, str(RS_ranges[0]))
                tempRS = RS_menu.get() 
                warningLabel.config(bg="yellow", text="Inserted value is below the minimum. \n Rounded to " + str(RS_ranges[0]) + " for patient safety.")
      #          warningLabel.place(x=warningLabelX,y=warningLabelY)
            elif(RS_ranges[0]<=RS<=RS_ranges[1]): #if in the lowest range
                if(RS%RS_increments[0] != 0): #and not of a valid value
                    tempRS = roundToNearest(RS,RS_increments[0]) #round to nearest valid value
                    RS_menu.delete(0, END)
                    RS_menu.insert(0, str(tempRS)) #display that
                    warningLabel.config(bg="yellow", text="Inserted invalid value. \n Rounded to nearest valid increment, " + str(tempRS) + ".")
                else:
                    success()
            elif(RS_ranges[1]<RS<=RS_ranges[2]):
                if(RS%RS_increments[1] != 0): #and not of a valid value
                    tempRS = roundToNearest(RS,RS_increments[1]) #round to nearest valid value
                    RS_menu.delete(0, END)
                    RS_menu.insert(0, str(tempRS)) #display that
                    warningLabel.config(bg="yellow", text="Inserted invalid value. \n Rounded to nearest valid increment, " + str(tempRS) + ".")
                else: #if valid, succeed
                    success()
                    return
            elif(RS>RS_ranges[2]): #too big, round to highest valid 
                RS_menu.delete(0, END)
                RS_menu.insert(0, str(RS_ranges[2]))
                warningLabel.config(bg="yellow", text="Inserted value is above the maximum. \n Rounded to " + str(RS_ranges[2]) + " for patient safety.")
    button = Button(AAI_screen, text = "Select Rate Smoothing (%):", command = get_RS).pack()

def VVI_selections():
    default_LRL = 60
    LRL_ranges = [30,50,90,175] #range 1 low, range 1 high, range 2 low, range 2 high, etc
    LRL_increments = [5,1,5] #range 1 increment, range 2 increment, range 3 increment 
    
    VVI_screen = tkinter.Tk()
    VVI_screen.title("VVI Parameters")
    VVI_screen.geometry('600x600')
    Label(VVI_screen, text="VVI Parameter Selections", bg="#C70039", width="300", height="2", font=("Calibri", 13)).pack()
    def delete_VVI_screen():
        VVI_screen.destroy() #warning unsaved changes might be a good idea to implement here.  
    button = Button(VVI_screen, text = "Back", command = combine_funcs(select_mode_register, delete_VVI_screen)).pack()
    # add "unsaved changes warning" option on the back button
    ### FROM HERE TO NEXT COMMENT IS CRITICVL LRL ###
    label = Label(VVI_screen, text ="LRL selection (ppm):")
    CaptionLabelX = 70
    CaptionLabelY = 70
    CaptionLabelYIncrement = 47
    label.place(x=CaptionLabelX, y = CaptionLabelY)
    LRL_input = StringVar()
    LRL_menu = tkinter.Entry(VVI_screen, textvariable=LRL_input)
    LRL_menu.insert(0, str(default_LRL)) #once saving works, change this to "if a value is saved, insert that value here - if not, load the default."
    LRL_menu.pack()
    warningLabel = Label(VVI_screen, text="")
    warningLabel.pack(side=BOTTOM, padx=0, pady=0, anchor='n')
   # warningLabel.place(x=warningLabelX,y=warningLabelY)

    def get_LRL():
        LRL = tkinter.StringVar(VVI_screen)
        LRL = LRL_menu.get() #get the value from the insert
        warningLabel.config(text = "") #make existing error invisible
    #    warningLabel.place(x=warningLabelX,y=warningLabelY)
        def success():
            LRL = LRL_menu.get() 
            warningLabel.config(bg="green", text="Selection of " + str(LRL) + " is Successful.");
            file.write(str(LRL)+ '\n')
           # file.close() VSK
        try: #check if the input is translatable to float
            LRL=float(LRL)
        except ValueError:  
            print("Not a float") #if not, set to default value 
            LRL_menu.delete(0, END) #delete existing value
            LRL_menu.insert(0, default_LRL) #insert default value
            
            warningLabel.config(bg="red", text="Please insert a number. \n" + str(LRL) + " is not a number.")
     #       warningLabel.place(x=warningLabelX,y=warningLabelY)
        else:
            if(LRL<LRL_ranges[0]): #if below lowest increment, set to minimum
                LRL_menu.delete(0, END)
                LRL_menu.insert(0, str(LRL_ranges[0]))
                tempLRL = LRL_menu.get() 
                warningLabel.config(bg="yellow", text="Inserted value is below the minimum. \n Rounded to " + str(LRL_ranges[0]) + " for patient safety.")
      #          warningLabel.place(x=warningLabelX,y=warningLabelY)
            elif(LRL_ranges[0]<=LRL<LRL_ranges[1]): #if in the lowest range
                if(LRL%LRL_increments[0] != 0): #and not of a valid value
                    tempLRL = roundToNearest(LRL,LRL_increments[0]) #round to nearest valid value
                    LRL_menu.delete(0, END)
                    LRL_menu.insert(0, str(tempLRL)) #display that
                    warningLabel.config(bg="yellow", text="Inserted invalid value. \n Rounded to nearest valid increment, " + str(tempLRL) + ".")
                else:
                    success()
            elif(LRL_ranges[1]<=LRL<LRL_ranges[2]):
                if(LRL%LRL_increments[1] != 0): #and not of a valid value
                    tempLRL = roundToNearest(LRL,LRL_increments[1]) #round to nearest valid value
                    LRL_menu.delete(0, END)
                    LRL_menu.insert(0, str(tempLRL)) #display that
                    warningLabel.config(bg="yellow", text="Inserted invalid value. \n Rounded to nearest valid increment, " + str(tempLRL) + ".")
                else: #if valid, succeed
                    success()
            elif(LRL_ranges[2]<=LRL<=LRL_ranges[3]):
                if(LRL%LRL_increments[2] != 0): #and not of a valid value
                    tempLRL = roundToNearest(LRL,LRL_increments[2]) #round to nearest valid value
                    LRL_menu.delete(0, END)
                    LRL_menu.insert(0, str(tempLRL))
                    warningLabel.config(bg="yellow", text="Inserted invalid value. \n Rounded to nearest valid increment, " + str(tempLRL) + ".")      
                else:
                    success()
            elif(LRL>LRL_ranges[3]): #too big, round to highest valid 
                LRL_menu.delete(0, END)
                LRL_menu.insert(0, str(LRL_ranges[3]))
                warningLabel.config(bg="yellow", text="Inserted value is above the maximum. \n Rounded to " + str(LRL_ranges[3]) + " for patient safety.")
    button = Button(VVI_screen, text = "Select LRL", command = get_LRL).pack()
    
   ### FROM HERE TO NEXT COMMENT IS CRITICVL URL ###
    default_URL = 120
    URL_ranges = [50,175] #range 1 low, range 1 high
    URL_increments = [5,1,5] #range 1 increment, range 2 increment, range 3 increment 
    URLlabel = Label(VVI_screen, text ="URL selection (ppm):")
    URLlabel.place(x=CaptionLabelX, y = CaptionLabelY+CaptionLabelYIncrement)
    URL_input = StringVar()
    URL_menu = tkinter.Entry(VVI_screen, textvariable=URL_input)
    URL_menu.insert(0, str(default_URL)) #once saving works, change this to "if a value is saved, insert that value here - if not, load the default."
    URL_menu.pack()
    #no need to recreate the warning label, it exists up lop already
    def get_URL():
        URL = tkinter.StringVar(VVI_screen)
        URL = URL_menu.get() #get the value from the insert
        warningLabel.config(text = "") #make existing error invisible
    #    warningLabel.place(x=warningLabelX,y=warningLabelY)
        def success():
            URL = URL_menu.get() 
            warningLabel.config(bg="green", text="Selection of " + str(URL) + " is Successful.");
            file.write(str(URL)+ '\n')
            # file.close() VSK
        try: #check if the input is translatable to float
            URL=float(URL)
        except ValueError:  
            print("Not a float") #if not, set to default value 
            URL_menu.delete(0, END) #delete existing value
            URL_menu.insert(0, default_URL) #insert default value
            warningLabel.config(bg="red", text="Please insert a number. \n" + str(URL) + " is not a number.")
        else:    
            if(URL<URL_ranges[0]): #if below lowest increment, set to minimum
                URL_menu.delete(0, END)
                URL_menu.insert(0, str(URL_ranges[0]))
                tempURL = URL_menu.get() 
                warningLabel.config(bg="yellow", text="Inserted value is below the minimum. \n Rounded to " + str(URL_ranges[0]) + " for patient safety.")
            elif(URL_ranges[0]<=URL<=URL_ranges[1]): #if in the lowest range
                if(URL%URL_increments[0] != 0): #and not of a valid value
                    tempURL = roundToNearest(URL,URL_increments[0]) #round to nearest valid value
                    URL_menu.delete(0, END)
                    URL_menu.insert(0, str(tempURL)) #display that
                    warningLabel.config(bg="yellow", text="Inserted invalid value. \n Rounded to nearest valid increment, " + str(tempURL) + ".")
                else:
                    success()
            elif(URL>URL_ranges[1]): #if too high
                URL_menu.delete(0, END)
                URL_menu.insert(0, str(URL_ranges[1]))
                warningLabel.config(bg="yellow", text="Inserted value is above the maximum. \n Rounded to " + str(URL_ranges[1]) + " for patient safety.")
    button = Button(VVI_screen, text = "Select URL", command = get_URL).pack()
    ###Ventricle Pulse Amplitude###
    default_VPulseAmp = 3.5
    VPulseAmp_ranges = [0.5,3.2] #range 1 low, range 1 high
    VPulseAmp_increments = [0.1] #range 1 increment, range 2 increment, range 3 increment 
    VPulseAmplabel = Label(VVI_screen, text ="VPulseAmp selection (ppm):")
    VPulseAmplabel.place(x=CaptionLabelX, y = CaptionLabelY+CaptionLabelYIncrement*2)
    VPulseAmp_input = StringVar()
    VPulseAmp_menu = tkinter.Entry(VVI_screen, textvariable=VPulseAmp_input)
    VPulseAmp_menu.insert(0, str(default_VPulseAmp)) #once saving works, change this to "if a value is saved, insert that value here - if not, load the default."
    VPulseAmp_menu.pack()
    #NEED TO VSK VBOUT THIS SECOND VVLUE
    def get_VPulseAmp():
        VPulseAmp = tkinter.StringVar(VVI_screen)
        VPulseAmp = VPulseAmp_menu.get() #get the value from the insert
        warningLabel.config(text = "") #make existing error invisible
    #    warningLabel.place(x=warningLabelX,y=warningLabelY)
        def success():
            VPulseAmp = VPulseAmp_menu.get()
            if(str(VPulseAmp) == "Off" or str(VPulseAmp) == "off" or str(VPulseAmp) == "OFF" or float(VPulseAmp) == 0):
                warningLabel.config(bg="green", text="Selection of " + str(VPulseAmp) + " is Successful. \n You have just turned off the VVI pace amplitude.")
            else:
                warningLabel.config(bg="green", text="Selection of " + str(VPulseAmp) + " is Successful.")
            file.write(str(VPulseAmp)+ '\n')
            # file.close() VSK
        if(str(VPulseAmp) == "Off" or str(VPulseAmp) == "off" or str(VPulseAmp) == "OFF"): #if off
            VPulseAmp_menu.delete(0, END) #delete existing value
            VPulseAmp_menu.insert(0, 0) #0
            success()
            return
        try: #check if the input is translatable to float
            VPulseAmp=float(VPulseAmp)
        except ValueError:  
            print("Not a float") #if not, set to default value 
            VPulseAmp_menu.delete(0, END) #delete existing value
            VPulseAmp_menu.insert(0, default_VPulseAmp) #insert default value
            warningLabel.config(bg="red", text="Please insert a number. \n" + str(VPulseAmp) + " is not a number.")
        else:
            if(float(VPulseAmp) == 0): #if off
                success()   
                return 
            if(VPulseAmp<VPulseAmp_ranges[0]): #if below lowest increment, set to minimum
                VPulseAmp_menu.delete(0, END)
                VPulseAmp_menu.insert(0, str(VPulseAmp_ranges[0]))
                tempVPulseAmp = VPulseAmp_menu.get() 
                warningLabel.config(bg="yellow", text="Inserted value is below the minimum. \n Rounded to " + str(VPulseAmp_ranges[0]) + " for patient safety.")
            elif(VPulseAmp_ranges[0]<=VPulseAmp<=VPulseAmp_ranges[1]): #if in the lowest range
                debugVar = float(VPulseAmp*10)%float(VPulseAmp_increments[0]*10)
                if(debugVar != 0): #and not of a valid value
                    tempVPulseAmp = float(int(roundToNearest(VPulseAmp,VPulseAmp_increments[0])*10)/10) #round to nearest valid value, in this scuffed way to account for floating point errors
                    VPulseAmp_menu.delete(0, END)
                    VPulseAmp_menu.insert(0, str(tempVPulseAmp)) #display that
                    warningLabel.config(bg="yellow", text="Inserted invalid value. \n Rounded to nearest valid increment, " + str(tempVPulseAmp) + ".")
                else:
                    success()
                    return
            elif(VPulseAmp>VPulseAmp_ranges[1]): #if too high
                VPulseAmp_menu.delete(0, END)
                VPulseAmp_menu.insert(0, str(VPulseAmp_ranges[1]))
                warningLabel.config(bg="yellow", text="Inserted value is above the maximum. \n Rounded to " + str(VPulseAmp_ranges[1]) + " for patient safety.")
    button = Button(VVI_screen, text = "Select VPulse Amplitude (V)", command = get_VPulseAmp).pack()
    ###Vtrial Pulse Amplitude###
    default_VPulseWidth = 0.4
    VPulseWidth_ranges = [0.1,1.9] #range 1 low, range 1 high
    VPulseWidth_increments = [0.1] #range 1 increment, range 2 increment, range 3 increment 
    VPulseWidthlabel = Label(VVI_screen, text ="VPulseWidth selection (ms):")
    VPulseWidthlabel.place(x=CaptionLabelX, y = CaptionLabelY+CaptionLabelYIncrement*3)
    VPulseWidth_input = StringVar()
    VPulseWidth_menu = tkinter.Entry(VVI_screen, textvariable=VPulseWidth_input)
    VPulseWidth_menu.insert(0, str(default_VPulseWidth)) #once saving works, change this to "if a value is saved, insert that value here - if not, load the default."
    VPulseWidth_menu.pack()
    #NEED TO VSK VBOUT THIS SECOND VVLUE
    def get_VPulseWidth():
        VPulseWidth = tkinter.StringVar(VVI_screen)
        VPulseWidth = VPulseWidth_menu.get() #get the value from the insert
        warningLabel.config(text = "") #make existing error invisible
    #    warningLabel.place(x=warningLabelX,y=warningLabelY)
        def success():
            VPulseWidth = VPulseWidth_menu.get()
            warningLabel.config(bg="green", text="Selection of " + str(VPulseWidth) + " is Successful.")
            file.write(str(VPulseWidth)+ '\n')
            # file.close() VSK
        try: #check if the input is translatable to float
            VPulseWidth=float(VPulseWidth)
        except ValueError:  
            print("Not a float") #if not, set to default value 
            VPulseWidth_menu.delete(0, END) #delete existing value
            VPulseWidth_menu.insert(0, default_VPulseWidth) #insert default value
            warningLabel.config(bg="red", text="Please insert a number. \n" + str(VPulseWidth) + " is not a number.")
        else:
            if(float(VPulseWidth) < 0.05): 
                warningLabel.config(bg="yellow", text="Inserted value is below the minimum. \n Rounded to " + "0.05 " + " for patient safety.")
                VPulseWidth_menu.delete(0, END)
                VPulseWidth_menu.insert(0, "0.05")
                return
            if(float(VPulseWidth) == 0.05): #if that one specific value in the table 
                success()   
                return 
            if(VPulseWidth<VPulseWidth_ranges[0]): #if below lowest increment, set to minimum
                VPulseWidth_menu.delete(0, END)
                VPulseWidth_menu.insert(0, str(VPulseWidth_ranges[0]))
                tempVPulseWidth = VPulseWidth_menu.get() 
                warningLabel.config(bg="yellow", text="Inserted invalid value. \n Rounded to nearest valid increment " + str(VPulseWidth_ranges[0]) + " for patient safety.")
            elif(VPulseWidth_ranges[0]<=VPulseWidth<=VPulseWidth_ranges[1]): #if in the lowest range
                debugVar = float(VPulseWidth*10)%float(VPulseWidth_increments[0]*10)
                if(debugVar != 0): #and not of a valid value
                    tempVPulseWidth = float(int(roundToNearest(VPulseWidth,VPulseWidth_increments[0])*10)/10) #round to nearest valid value, in this scuffed way to account for floating point errors
                    VPulseWidth_menu.delete(0, END)
                    VPulseWidth_menu.insert(0, str(tempVPulseWidth)) #display that
                    warningLabel.config(bg="yellow", text="Inserted invalid value. \n Rounded to nearest valid increment, " + str(tempVPulseWidth) + ".")
                else:
                    success()
                    return
            elif(VPulseWidth>VPulseWidth_ranges[1]): #if too high
                VPulseWidth_menu.delete(0, END)
                VPulseWidth_menu.insert(0, str(VPulseWidth_ranges[1]))
                warningLabel.config(bg="yellow", text="Inserted value is above the maximum. \n Rounded to " + str(VPulseWidth_ranges[1]) + " for patient safety.")
    button = Button(VVI_screen, text = "Select VPulse Width (ms)", command = get_VPulseWidth).pack()

    default_VSensitivity = 0.25
    VSensitivity_ranges = [0.25,1,10] #range 1 low, range 1 high
    VSensitivity_increments = [0.25,0.5] #range 1 increment, range 2 increment, range 3 increment 
    VSensitivitylabel = Label(VVI_screen, text ="VSensitivity selection (mV):")
    VSensitivitylabel.place(x=CaptionLabelX, y = CaptionLabelY+CaptionLabelYIncrement*4)
    VSensitivity_input = StringVar()
    VSensitivity_menu = tkinter.Entry(VVI_screen, textvariable=VSensitivity_input)
    VSensitivity_menu.insert(0, str(default_VSensitivity)) #once saving works, change this to "if a value is saved, insert that value here - if not, load the default."
    VSensitivity_menu.pack()

    def get_VSensitivity():
        VSensitivity = tkinter.StringVar(VVI_screen)
        VSensitivity = VSensitivity_menu.get() #get the value from the insert
        warningLabel.config(text = "") #make existing error invisible
        def success():
            VSensitivity = VSensitivity_menu.get()
            warningLabel.config(bg="green", text="Selection of " + str(VSensitivity) + " is Successful.")
            file.write(str(VSensitivity)+ '\n')
            # file.close() VSK
        try: #check if the input is translatable to float
            VSensitivity=float(VSensitivity)
        except ValueError:  
            print("Not a float") #if not, set to default value 
            VSensitivity_menu.delete(0, END) #delete existing value
            VSensitivity_menu.insert(0, default_VSensitivity) #insert default value
            warningLabel.config(bg="red", text="Please insert a number. \n" + str(VSensitivity) + " is not a number.")
        else: 
            if(VSensitivity<VSensitivity_ranges[0]): #if below lowest increment, set to minimum
                VSensitivity_menu.delete(0, END)
                VSensitivity_menu.insert(0, str(VSensitivity_ranges[0]))
                tempVSensitivity = VSensitivity_menu.get() 
                warningLabel.config(bg="yellow", text="Inserted invalid value. \n Rounded to nearest valid increment " + str(VSensitivity_ranges[0]) + " for patient safety.")
            elif(VSensitivity_ranges[0]<=VSensitivity<VSensitivity_ranges[1]): #if in the lowest range
                debugVar = float(VSensitivity*100)%float(VSensitivity_increments[0]*100)
                if(debugVar != 0): #and not of a valid value
                    tempVSensitivity = float(int(roundToNearest(VSensitivity,VSensitivity_increments[0])*100)/100) #round to nearest valid value, in this scuffed way to account for floating point errors
                    VSensitivity_menu.delete(0, END)
                    VSensitivity_menu.insert(0, str(tempVSensitivity)) #display that
                    warningLabel.config(bg="yellow", text="Inserted invalid value. \n Rounded to nearest valid increment, " + str(tempVSensitivity) + ".")
                else:
                    success()
                    return
            elif(VSensitivity_ranges[1]<=VSensitivity<=VSensitivity_ranges[2]): #if in the lowest range
                debugVar = float(VSensitivity*100)%float(VSensitivity_increments[1]*100)
                if(debugVar != 0): #and not of a valid value
                    tempVSensitivity = float(int(roundToNearest(VSensitivity,VSensitivity_increments[1])*100)/100) #round to nearest valid value, in this scuffed way to account for floating point errors
                    VSensitivity_menu.delete(0, END)
                    VSensitivity_menu.insert(0, str(tempVSensitivity)) #display that
                    warningLabel.config(bg="yellow", text="Inserted invalid value. \n Rounded to nearest valid increment, " + str(tempVSensitivity) + ".")
                else:
                    success()
                    return
            elif(VSensitivity>VSensitivity_ranges[2]): #if too high
                VSensitivity_menu.delete(0, END)
                VSensitivity_menu.insert(0, str(VSensitivity_ranges[2]))
                warningLabel.config(bg="yellow", text="Inserted value is above the maximum. \n Rounded to " + str(VSensitivity_ranges[2]) + " for patient safety.")
    button = Button(VVI_screen, text = "Select VSensitivity (mv)", command = get_VSensitivity).pack()

    ###Vtrial Refractory Period###
    default_VRP = 320
    VRP_ranges = [150,500] #range 1 low, range 1 high
    VRP_increments = [10] #range 1 increment, range 2 increment, range 3 increment 
    VRPlabel = Label(VVI_screen, text ="VRP selection (ms):")
    VRPlabel.place(x=CaptionLabelX, y = CaptionLabelY+CaptionLabelYIncrement*5)
    VRP_input = StringVar()
    VRP_menu = tkinter.Entry(VVI_screen, textvariable=VRP_input)
    VRP_menu.insert(0, str(default_VRP)) #once saving works, change this to "if a value is saved, insert that value here - if not, load the default."
    VRP_menu.pack()

    def get_VRP():
        VRP = tkinter.StringVar(VVI_screen)
        VRP = VRP_menu.get() #get the value from the insert
        warningLabel.config(text = "") #make existing error invisible
        def success():
            VRP = VRP_menu.get()
            warningLabel.config(bg="green", text="Selection of " + str(VRP) + " is Successful.")
            file.write(str(VRP)+ '\n')
            # file.close() VSK
        try: #check if the input is translatable to float
            VRP=float(VRP)
        except ValueError:  
            print("Not a float") #if not, set to default value 
            VRP_menu.delete(0, END) #delete existing value
            VRP_menu.insert(0, default_VRP) #insert default value
            warningLabel.config(bg="red", text="Please insert a number. \n" + str(VRP) + " is not a number.")
        else: 
            if(VRP<VRP_ranges[0]): #if below lowest increment, set to minimum
                VRP_menu.delete(0, END)
                VRP_menu.insert(0, str(VRP_ranges[0]))
                tempVRP = VRP_menu.get() 
                warningLabel.config(bg="yellow", text="Inserted invalid value. \n Rounded to nearest valid increment " + str(VRP_ranges[0]) + " for patient safety.")
            elif(VRP_ranges[0]<=VRP<=VRP_ranges[1]): #if in the lowest range
                debugVar = float(VRP*100)%float(VRP_increments[0]*100)
                if(debugVar != 0): #and not of a valid value
                    tempVRP = float(int(roundToNearest(VRP,VRP_increments[0])*100)/100) #round to nearest valid value, in this scuffed way to account for floating point errors
                    VRP_menu.delete(0, END)
                    VRP_menu.insert(0, str(tempVRP)) #display that
                    warningLabel.config(bg="yellow", text="Inserted invalid value. \n Rounded to nearest valid increment, " + str(tempVRP) + ".")
                else:
                    success()
                    return
            elif(VRP>VRP_ranges[1]): #if too high
                VRP_menu.delete(0, END)
                VRP_menu.insert(0, str(VRP_ranges[1]))
                warningLabel.config(bg="yellow", text="Inserted value is above the maximum. \n Rounded to " + str(VRP_ranges[1]) + " for patient safety.")
    button = Button(VVI_screen, text = "Select VRP (ms)", command = get_VRP).pack()

    
    default_HRL = 60
    HRL_ranges = [30,50,90,175] #range 1 low, range 1 high
    HRL_increments = [5,1,5] #range 1 increment, range 2 increment, range 3 increment 
    HRLlabel = Label(VVI_screen, text ="HRL selection (ppm):")
    HRLlabel.place(x=CaptionLabelX, y = CaptionLabelY+CaptionLabelYIncrement*6-3)
    HRL_input = StringVar()
    HRL_menu = tkinter.Entry(VVI_screen, textvariable=HRL_input)
    HRL_menu.insert(0, str(default_HRL)) #once saving works, change this to "if a value is saved, insert that value here - if not, load the default."
    HRL_menu.pack()

    warningLabel = Label(VVI_screen, text="")
    warningLabel.pack(side=BOTTOM, padx=0, pady=0, anchor='n')
   # warningLabel.place(x=warningLabelX,y=warningLabelY)

    def get_HRL():
        HRL = tkinter.StringVar(VVI_screen)
        HRL = HRL_menu.get() #get the value from the insert
        warningLabel.config(text = "") #make existing error invisible
        def success():
            HRL = HRL_menu.get() 
            if(str(HRL) == "Off" or str(HRL) == "off" or str(HRL) == "OFF" or float(HRL) == 0):
                warningLabel.config(bg="green", text="Selection of " + str(HRL) + " is Successful. \n You have just turned off Hysterisis pacing.")
            else:
                warningLabel.config(bg="green", text="Selection of " + str(HRL) + " is Successful.")
            file.write(str(HRL)+ '\n')
            # file.close() VSK
        if(str(HRL) == "Off" or str(HRL) == "off" or str(HRL) == "OFF"): #if off
            HRL_menu.delete(0, END) #delete existing value
            HRL_menu.insert(0, 0) #0
            success()
            return
        try: #check if the input is translatable to float
            HRL=float(HRL)
        except ValueError:  
            print("Not a float") #if not, set to default value 
            HRL_menu.delete(0, END) #delete existing value
            HRL_menu.insert(0, default_HRL) #insert default value
            
            warningLabel.config(bg="red", text="Please insert a number. \n" + str(HRL) + " is not a number.")
     #       warningLabel.place(x=warningLabelX,y=warningLabelY)
        else:
            if(float(HRL)==0):
                HRL_menu.delete(0, END) #delete existing value
                HRL_menu.insert(0, 0) #0
                success()
                return 
            if(HRL<HRL_ranges[0]): #if below lowest increment, set to minimum
                HRL_menu.delete(0, END)
                HRL_menu.insert(0, str(HRL_ranges[0]))
                tempHRL = HRL_menu.get() 
                warningLabel.config(bg="yellow", text="Inserted value is below the minimum. \n Rounded to " + str(HRL_ranges[0]) + " for patient safety.")
      #          warningLabel.place(x=warningLabelX,y=warningLabelY)
            elif(HRL_ranges[0]<=HRL<HRL_ranges[1]): #if in the lowest range
                if(HRL%HRL_increments[0] != 0): #and not of a valid value
                    tempHRL = roundToNearest(HRL,HRL_increments[0]) #round to nearest valid value
                    HRL_menu.delete(0, END)
                    HRL_menu.insert(0, str(tempHRL)) #display that
                    warningLabel.config(bg="yellow", text="Inserted invalid value. \n Rounded to nearest valid increment, " + str(tempHRL) + ".")
                else:
                    success()
            elif(HRL_ranges[1]<=HRL<HRL_ranges[2]):
                if(HRL%HRL_increments[1] != 0): #and not of a valid value
                    tempHRL = roundToNearest(HRL,HRL_increments[1]) #round to nearest valid value
                    HRL_menu.delete(0, END)
                    HRL_menu.insert(0, str(tempHRL)) #display that
                    warningLabel.config(bg="yellow", text="Inserted invalid value. \n Rounded to nearest valid increment, " + str(tempHRL) + ".")
                else: #if valid, succeed
                    success()
            elif(HRL_ranges[2]<=HRL<=HRL_ranges[3]):
                if(HRL%HRL_increments[2] != 0): #and not of a valid value
                    tempHRL = roundToNearest(HRL,HRL_increments[2]) #round to nearest valid value
                    HRL_menu.delete(0, END)
                    HRL_menu.insert(0, str(tempHRL))
                    warningLabel.config(bg="yellow", text="Inserted invalid value. \n Rounded to nearest valid increment, " + str(tempHRL) + ".")      
                else:
                    success()
            elif(HRL>HRL_ranges[3]): #too big, round to highest valid 
                HRL_menu.delete(0, END)
                HRL_menu.insert(0, str(HRL_ranges[3]))
                warningLabel.config(bg="yellow", text="Inserted value is above the maximum. \n Rounded to " + str(HRL_ranges[3]) + " for patient safety.")
    button = Button(VVI_screen, text = "Select HRL", command = get_HRL).pack()

    default_RS = 0
    RS_ranges = [0,21,25] #range 1 low, range 1 high
    RS_increments = [3,5] #range 1 increment, range 2 increment, range 3 increment 
    RSlabel = Label(VVI_screen, text ="Rate Smoothing Factor (%):")
    RSlabel.place(x=CaptionLabelX, y = CaptionLabelY+CaptionLabelYIncrement*7-10)
    RS_input = StringVar()
    RS_menu = tkinter.Entry(VVI_screen, textvariable=RS_input)
    RS_menu.insert(0, str(default_RS)) #once saving works, change this to "if a value is saved, insert that value here - if not, load the default."
    RS_menu.pack()

    warningLabel = Label(VVI_screen, text="")
    warningLabel.pack(side=BOTTOM, padx=0, pady=0, anchor='n')
   # warningLabel.place(x=warningLabelX,y=warningLabelY)

    def get_RS():
        RS = tkinter.StringVar(VVI_screen)
        RS = RS_menu.get() #get the value from the insert
        warningLabel.config(text = "") #make existing error invisible
        def success():
            RS = RS_menu.get() 
            if(str(RS) == "Off" or str(RS) == "off" or str(RS) == "OFF" or float(RS) == 0):
                warningLabel.config(bg="green", text="Selection of " + str(RS) + " is Successful. \n You have just turned off Hysterisis pacing.")
            else:
                warningLabel.config(bg="green", text="Selection of " + str(RS) + " is Successful.")
            file.write(str(RS)+ '\n')
            # file.close() VSK
        if(str(RS) == "Off" or str(RS) == "off" or str(RS) == "OFF"): #if off
            RS_menu.delete(0, END) #delete existing value
            RS_menu.insert(0, 0) #0
            success()
            return
        try: #check if the input is translatable to float
            RS=float(RS)
        except ValueError:  
            print("Not a float") #if not, set to default value 
            RS_menu.delete(0, END) #delete existing value
            RS_menu.insert(0, default_RS) #insert default value
            
            warningLabel.config(bg="red", text="Please insert a number. \n" + str(RS) + " is not a number.")
     #       warningLabel.place(x=warningLabelX,y=warningLabelY)
        else:
            if(float(RS)==0):
                RS_menu.delete(0, END) #delete existing value
                RS_menu.insert(0, 0) #0
                success()
                return 
            if(RS<RS_ranges[0]): #if below lowest increment, set to minimum
                RS_menu.delete(0, END)
                RS_menu.insert(0, str(RS_ranges[0]))
                tempRS = RS_menu.get() 
                warningLabel.config(bg="yellow", text="Inserted value is below the minimum. \n Rounded to " + str(RS_ranges[0]) + " for patient safety.")
      #          warningLabel.place(x=warningLabelX,y=warningLabelY)
            elif(RS_ranges[0]<=RS<=RS_ranges[1]): #if in the lowest range
                if(RS%RS_increments[0] != 0): #and not of a valid value
                    tempRS = roundToNearest(RS,RS_increments[0]) #round to nearest valid value
                    RS_menu.delete(0, END)
                    RS_menu.insert(0, str(tempRS)) #display that
                    warningLabel.config(bg="yellow", text="Inserted invalid value. \n Rounded to nearest valid increment, " + str(tempRS) + ".")
                else:
                    success()
            elif(RS_ranges[1]<RS<=RS_ranges[2]):
                if(RS%RS_increments[1] != 0): #and not of a valid value
                    tempRS = roundToNearest(RS,RS_increments[1]) #round to nearest valid value
                    RS_menu.delete(0, END)
                    RS_menu.insert(0, str(tempRS)) #display that
                    warningLabel.config(bg="yellow", text="Inserted invalid value. \n Rounded to nearest valid increment, " + str(tempRS) + ".")
                else: #if valid, succeed
                    success()
                    return
            elif(RS>RS_ranges[2]): #too big, round to highest valid 
                RS_menu.delete(0, END)
                RS_menu.insert(0, str(RS_ranges[2]))
                warningLabel.config(bg="yellow", text="Inserted value is above the maximum. \n Rounded to " + str(RS_ranges[2]) + " for patient safety.")
    button = Button(VVI_screen, text = "Select Rate Smoothing (%):", command = get_RS).pack()


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
 
 
def delete_password_not_recognised():
    password_not_recog_screen.destroy()
 
 
def delete_user_not_found_screen():
    user_not_found_screen.destroy()

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
    userfile.close()
    user_name =filelines[0]
    user_pass = filelines[1]
    user_mode = filelines[2]
    Label(dash_screen, text = "Your Current Settings", bg = "#C70039", font = ("Calibri", 12)).place(x=0,y=120)
    Label(dash_screen, text = "mode = " + user_mode).place(x=0,y=150)
    def edit_selections():
        userfile = open(name, 'w')
        userfile.write(user_name)
        userfile.write(user_pass)
        userfile.write(user_mode)
        
        
        
        
    if user_mode == "AOO"+ '\n':
        user_lrl = filelines[3]
        user_url = filelines[4]
        user_aa = filelines[5]
        user_apw = filelines[6]
        Label(dash_screen, text = "LRL = " + user_lrl).place(x=0,y=165)
        Label(dash_screen, text = "URL = " + user_url).place(x=0,y=180)
        Label(dash_screen, text = "AA = " + user_aa).place(x=0,y=195)
        Label(dash_screen, text = "APW = " + user_apw).place(x=0,y=210)
        Button(dash_screen, text = 'edit selections', command = edit_selections).place(x=0,y=225)
    elif user_mode == "VOO"+ '\n':
        user_lrl = filelines[3]
        user_url = filelines[4]
        user_va = filelines[5]
        user_vpw = filelines[6]
        Label(dash_screen, text = "LRL = " + user_lrl).place(x=0,y=165)
        Label(dash_screen, text = "URL = " + user_url).place(x=0,y=180)
        Label(dash_screen, text = "VA = " + user_va).place(x=0,y=195)
        Label(dash_screen, text = "VPW = " + user_vpw).place(x=0,y=210)
        Button(dash_screen, text = 'edit selections', command = edit_selections).place(x=0,y=225)
        
    elif user_mode == "AAI"+ '\n':
        user_lrl = filelines[3]
        user_url = filelines[4]
        user_aa = filelines[5]
        user_apw = filelines[6]
        user_as = filelines[7]
        user_arp = filelines[8]
        user_pvarp = filelines[9]
        user_hyster = filelines[10]
        user_smooth = filelines[11]
        Label(dash_screen, text = "LRL = " + user_lrl).place(x=0,y=165)
        Label(dash_screen, text = "URL = " + user_url).place(x=0,y=180)
        Label(dash_screen, text = "AA = " + user_aa).place(x=0,y=195)
        Label(dash_screen, text = "APW = " + user_apw).place(x=0,y=210)
        Label(dash_screen, text = "AS = " + user_as).place(x=0,y=225)
        Label(dash_screen, text = "ARP = " + user_arp).place(x=0,y=240)
        Label(dash_screen, text = "PVARP = " + user_pvarp).place(x=0,y=255)
        Label(dash_screen, text = "HYSTER= " + user_hyster).place(x=0,y=270)
        Label(dash_screen, text = "SMOOTH = " + user_smooth).place(x=0,y=285)
        Button(dash_screen, text = 'edit selections', command = edit_selections).place(x=0,y=300)
        
    elif user_mode == "VVI"+ '\n':
        user_lrl = filelines[3]
        user_url = filelines[4]
        user_va = filelines[5]
        user_vpw = filelines[6]
        user_vs = filelines[7]
        user_vrp = filelines[8]
        user_hyster = filelines[9]
        user_smooth = filelines[10]
        Label(dash_screen, text = "LRL = " + user_lrl).place(x=0,y=165)
        Label(dash_screen, text = "URL = " + user_url).place(x=0,y=180)
        Label(dash_screen, text = "VA = " + user_va).place(x=0,y=195)
        Label(dash_screen, text = "VPW = " + user_vpw).place(x=0,y=210)
        Label(dash_screen, text = "VS = " + user_vs).place(x=0,y=225)
        Label(dash_screen, text = "VRP = " + user_vrp).place(x=0,y=240)
        Label(dash_screen, text = "HYSTER= " + user_hyster).place(x=0,y=270)
        Label(dash_screen, text = "SMOOTH = " + user_smooth).place(x=0,y=285)
        Button(dash_screen, text = 'edit selections', command = edit_selections).place(x=0,y=300)
    
        
    


##TO DO: 2-make parameters save to file (after parameters are implemented - andrew), 3-add confirm button to parameters to update files 4- (andrew) make all parameters within guidelines and bound by eachother 5- read files to dashboard and allow edits from there
    
#run start
main_account_screen()
