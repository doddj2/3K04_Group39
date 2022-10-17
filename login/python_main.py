#import modules

from tkinter import *
import os
import time
import tkinter
 
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
            file = open(username_info, "w")
            file.write(username_info + "\n")
            file.write(password_info)
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
        if mode == "AOO":
            AOO_selections()
            delete_mode_screen()
        elif mode == "VOO":
            VOO_selections()
            delete_mode_screen()
        elif mode == "AAI":
            AAI_selections()
            delete_mode_screen()
        elif mode == "VVI":
            VVI_selections()
            delete_mode_screen()
        
 
    Label(text="Before Starting, please select a pacing mode", bg="maroon", width="300", height="2", font=("Calibri", 13)).pack()
    mode_sel= StringVar()
    mode_sel.set("AOO")
    ModeOptions = ["AOO","VOO","AAI","VVI"]
    drop= tkinter.OptionMenu(mode_screen, mode_sel, *ModeOptions) #andrew this is the type of line youre gonna wanna edit,
    drop.pack()
    button = Button(mode_screen, text = "Select", command = get_mode).pack()
#when completed, these four functions will add the parameters to the txt file created upon register. I have not done that yet but probably will soon
    
def AOO_selections():
    AOO_screen = tkinter.Tk()
    AOO_screen.title("AOO Parameters")
    AOO_screen.geometry('600x600')
    Label(AOO_screen, text="AOO Parameter Selections", bg="maroon", width="300", height="2", font=("Calibri", 13)).pack()
    def delete_AOO_screen():
        AOO_screen.destroy() #warning unsaved changes might be a good idea to implement here.  
    button = Button(AOO_screen, text = "Back", command = combine_funcs(select_mode_register, delete_AOO_screen)).pack()
    # add "unsaved changes warning" option on the back button
    ### FROM HERE TO NEXT COMMENT IS CRITICAL LRL ###
    label = Label(AOO_screen, text ="LRL selection:")
    label.place(x=150,y=50)
    LRL_options_list = ["30", "35", "40", "45", "50", "51", "52", "53", "54", "55", "56", "57", "58", "59", "60", "61", "62", "63", "64", "65", "66", "67", "68", "69", "70", "71", "72", "73", "74", "75", "76", "77", "78", "79", "80", "81", "82", "83", "84", "85", "86", "87", "88", "89", "90", "95", "100", "105", "110", "115", "120", "125", "130", "135", "140", "145", "150", "155", "160", "165", "170", "175"]
    value_LRL = tkinter.StringVar(AOO_screen)
    value_LRL.set("Select a LRL value")
    
    LRL_menu = tkinter.OptionMenu(AOO_screen, value_LRL, *LRL_options_list)
    LRL_menu.pack()

    def get_LRL():
        LRL = tkinter.StringVar(AOO_screen)
        LRL = value_LRL.get()
        label2 = Label(AOO_screen, bg="green", text="Selection of " + LRL + " is Successful");
        label2.place(x=350,y=50)
    button = Button(AOO_screen, text = "Select LRL", command = get_LRL).pack()
    
   ### FROM HERE TO NEXT COMMENT IS CRITICAL URL ###
    label3 = Label(AOO_screen, text ="URL selection:")
    label3.place(x=150,y=100)
    URL_options_list = ["placeholder 1", "placeholder 2"]
    value_URL = tkinter.StringVar(AOO_screen)
    value_URL.set("Select a URL value")
    

    URL_menu = tkinter.OptionMenu(AOO_screen, value_URL, *URL_options_list)
    URL_menu.pack()
    

    def get_URL():
        URL = tkinter.StringVar(AOO_screen)
        URL = value_URL.get()
        label4 = Label(AOO_screen, bg="green", text="Selection of " + URL + " is Successful")
        label4.place(x=350,y=100)
    button = Button(AOO_screen, text = "Select URL", command = get_URL).pack()
    ### ADD ALL THE OTHER PARAMETERS BY FOLLOWING FORMAT OF ABOVE TWO ###

## NOW DO THE SAME AS ABOVE FOR THE FOLLOWING OTHER MODES, good luck have fun##    
def VOO_selections():
    VOO_screen = tkinter.Tk()
    VOO_screen.title("VOO Parameters")
    VOO_screen.geometry('600x600')
    Label(VOO_screen, text="VOO Parameter Selections", bg="maroon", width="300", height="2", font=("Calibri", 13)).pack()
    def delete_VOO_screen():
        VOO_screen.destroy() #warning unsaved changes might be a good idea to implement here.  
    button = Button(VOO_screen, text = "Back", command = combine_funcs(select_mode_register, delete_VOO_screen)).pack()
                     
def AAI_selections():
    AAI_screen = tkinter.Tk()
    AAI_screen.title("AAI Parameters")
    AAI_screen.geometry('600x600')
    Label(AAI_screen, text="AAI Parameter Selections", bg="maroon", width="300", height="2", font=("Calibri", 13)).pack()
    def delete_AAI_screen():
        AAI_screen.destroy() #warning unsaved changes might be a good idea to implement here.  
    button = Button(AAI_screen, text = "Back", command = combine_funcs(select_mode_register, delete_AAI_screen)).pack()

def VVI_selections():
    VVI_screen = tkinter.Tk()
    VVI_screen.title("VVI Parameters")
    VVI_screen.geometry('600x600')
    Label(VVI_screen, text="VVI Parameter Selections", bg="maroon", width="300", height="2", font=("Calibri", 13)).pack()
    def delete_VVI_screen():
        VVI_screen.destroy() #warning unsaved changes might be a good idea to implement here.  
    button = Button(VVI_screen, text = "Back", command = combine_funcs(select_mode_register, delete_VVI_screen)).pack()


def login_verify():
    username1 = username_verify.get()
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
    Label(text="Select Your Choice", bg="maroon", width="300", height="2", font=("Calibri", 13)).pack()
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
    Label(text="Welcome to the Dashboard", bg="maroon", width="300", height="2", font=("Calibri", 13)).pack() #adding which user it is would be nice
    button = Button(dash_screen, text = "Back to Login", command = combine_funcs(delete_dashboard, main_account_screen)).pack()
##TO DO: 1-make modes save to file, 2-make parameters save to file (probably same code for both), 3-add confirm button to parameters to update files 4- (andrew) make all parameters within guidelines and bound by eachother 5- read files to dashboard and allow edits from there 6-ask ta's about status of device
    
#run start
main_account_screen()
