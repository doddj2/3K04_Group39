from tkinter import *
from tkinter import ttk
from combineFuncs import combine_funcs
from combineFuncs import roundToNearest
#from functionizeAttempt import combine_funcs
class InputScreenClass:
    def open(self):
        #open = Toplevel(self.screen)  
        button = Button(self.screen, text = "Save all selections",bg = 'green', command = self.save_sel).pack()
        button = Button(self.screen, text = "Back", command = combine_funcs(self.backToSelectMode)).pack()
        
        self.screen.mainloop()
    def close(self):
        print("destroyed")
        #self.screen.destroy()
    def writeSelfToFile(self,whereToSave):

       # with open("open.txt", "a") as new_file:
        #    new_file.write("Hello")
        
        #file = open(username_info, 'a')
        heading = self.name
        #self.whereToSave.open()
       # file = open("testfile",'a')
        whereToSave.write(heading + '\n')
        print(str(whereToSave))
        i = 0
        while(TRUE):
        #for i in range(self.numberOfInputs):
            toSave = self.InputBoxes[i].box.get()
            whereToSave.write(str(toSave) + '\n')
            #self.whereToSave.write(str(toSave) + '\n')
            print(toSave)
            i=i+1
            if i == 2:
                break
        #self.whereToSave.close()
        #self.close()
    def save_sel(self):
        i = 0
        LRL = -1
        URL = -1
        Refractory = -1
        while(i < self.numberOfInputs):
            if(not(self.InputBoxes[i].getOrRound(self.warningLabel))): #if invalid, return and stop checking, don't save
                return
            if(self.InputBoxes[i].isLRL):
                LRL = i
            if(self.InputBoxes[i].isURL):
                URL = i
            if(self.InputBoxes[i].isRefractory):
                Refractory = i
            if( (LRL > -1)): #compare URL to LRL, if URL greater, stop doing stuff
                if(URL > -1):
                    if(self.edgeCaseCompare("LRL",self.InputBoxes[LRL],self.InputBoxes[URL])):
                        return
                if(Refractory > -1):
                    if(self.edgeCaseCompare("Refractory",self.InputBoxes[LRL],self.InputBoxes[Refractory])):
                        return
            i = i+1
        self.warningLabel.config(bg="green", text="All valid values!")
        self.writeSelfToFile(self.whereToSave)
    
    def edgeCaseCompare(self, type, comp1, comp2):
        if(type == "LRL"):
           # comp2value = float(comp2.box.get()) #for debugging transparency
           # comp1value = float(comp1.box.get())
            URLGreaterThanLRL = (float(comp2.box.get()) > float(comp1.box.get()))
            if(not(URLGreaterThanLRL)):
                self.warningLabel.config(bg="red", text="LRL must be lower than URL")
                return TRUE
        if(type == "Refractory"):
            msOfLRL = 60/float(comp1.box.get())*1000 #convert bpm to seconds per beat, convert to milliseconds
            if(msOfLRL < float(comp2.box.get())):
                self.warningLabel.config(bg="red", text="Refractory period cannot be higher than what LRL implies.")
                return TRUE
        return FALSE
    def addInputBox(self,ranges=[0,10],increments=[0,2],name = "default name",defaultDisplay = -69420,offValid=FALSE):
        newBox = InputBox(self.screen,ranges,increments,name,defaultDisplay,offValid)
        self.InputBoxes.append(newBox) #add new box to end of array
        self.InputBoxes[self.numberOfInputs].configLabel(name) #change the corresponding label
        self.InputBoxes[self.numberOfInputs].inputLabel.place(x=20, y=50+self.numberOfInputs*18) #place the corresponding label according to how far down the box is
        self.InputBoxes[self.numberOfInputs].default()
        self.numberOfInputs = self.numberOfInputs+1
    def __init__(self,name,whereToSave):
        self.name = str(name)
        self.whereToSave = whereToSave

        self.screen = Tk()
        self.screen.title(self.name + " Parameters")
        self.screen.geometry('600x600')
        Label(self.screen, text=("" + self.name + " Parameter Selections"), bg="#C70039", width="300", height="2", font=("Calibri", 13)).pack()
        self.numberOfInputs = 0
        self.InputBoxes = []
        self.warningLabel = Label(self.screen, text="")
        self.warningLabel.pack(side=BOTTOM, padx=0, pady=0, anchor='n')
        self.warningLabel.config(text = "testing")
        #self.addInputBox()

    def backToSelectMode(self):
        WarningScreen = Tk()
        WarningScreen.title("Are you sure you wanna go back? \n Unsaved changes will be lost.")
        WarningScreen.geometry('400x200')
        Label(WarningScreen, text=("Are you sure you wanna go back? \n Unsaved changes will be lost."), bg="#58FF33", width="100", height="2", font=("Comic Sans", 13)).pack()
        Button(WarningScreen, text = "Yes - back to select screen", command = combine_funcs(self.close,WarningScreen.destroy)).pack()
        Button(WarningScreen, text = "No - back to edit screen", command = WarningScreen.destroy).pack()
        WarningScreen.mainloop()
        
        print("back to selection - closing self")
        
    
class InputBox:
    def __init__(self,screen,ranges,increments,name,defaultDisplay, offValid):
        self.ranges = ranges
        self.increments = increments
        self.name = name
        self.defaultDisplay = defaultDisplay
        self.offValid = offValid
        self.box = Entry(screen, textvariable=name)
        self.box.pack()
        self.inputLabel = Label(screen, text= name + " input:")
        #self identification flags for comparisons
        self.isLRL = ("LRL" in self.name)
        self.isURL = ("URL" in self.name)
        self.isRefractory = ("Refractory" in self.name)
        #self.inputLabel.pack()
    def configLabel(self, name):
            self.inputLabel.config(text="Selection of " + name + ": ")
    def getOrRound(self,errorLabel): 
            print("getOrRound triggered for " + self.name)
            toCheck = self.box.get() 
            #check for garbage input
            if(self.offValid):
                if(str(toCheck).lower() =='off'):
                    self.box.delete(0, END)
                    self.box.insert(0, 'off')
                    self.success(toCheck)
                    return TRUE
            try: #check if the input is translatable to float
                toCheck=float(toCheck)
            except ValueError:  
                print("Not a float") #if not, set to default value 
                self.box.delete(0, END) #delete existing value
                self.default() #insert default value
                errorLabel.config(bg="red", text="Please insert a number. \n" + str(toCheck) + " is not a number.")
                return FALSE
            if(toCheck<self.ranges[0]): #if below lowest increment, set to minimum
                self.box.delete(0, END)
                self.box.insert(0, str(self.ranges[0]))
                tempLRL = self.box.get() 
                errorLabel.config(bg="yellow", text="Inserted value is below the minimum. \n Rounded to " + str(self.ranges[0]) + " for patient safety.")
                return FALSE
            i = 0 #index variable
            while(i<len(self.ranges)-1):#iterate through all the ranges
                if(self.ranges[i]<=toCheck<=self.ranges[i+1]): #if in the lowest range
                    if((toCheck*1000)%(self.increments[i]*1000) != 0): #and not of a valid value
                        tempLRL = roundToNearest(toCheck,self.increments[i]) #round to nearest valid value
                        self.box.delete(0, END)
                        self.box.insert(0, str(tempLRL)) #display that
                        errorLabel.config(bg="yellow", text="Inserted invalid value. \n Rounded to nearest valid increment, " + str(tempLRL) + ".")
                        return FALSE
                    else:
                        self.success(toCheck)
                        return TRUE
                i=i+1
            if(toCheck>self.ranges[len(self.ranges)-1]): #if above highest increment, set to max 
                self.box.delete(0, END)
                self.box.insert(0, str(self.ranges[len(self.ranges)-1]))
                tempLRL = self.box.get() 
                errorLabel.config(bg="yellow", text="Inserted value is above the maximum. \n Rounded to " + str(self.ranges[len(self.ranges)-1]) + " for patient safety.")
                return FALSE
    def success(self,toCheck):
            print("success triggered for " + self.name + " on input value " + str(toCheck))
            if(str(toCheck).lower() =='off'):
                print("you have now turned " + self.name + " " + str(toCheck))
    def insertEntry(self, input):
        self.box.insert(0, str(self.defaultDisplay))
    def default(self):
        self.insertEntry(self.defaultDisplay)
