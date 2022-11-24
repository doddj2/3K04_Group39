import tkinter as tk

# Create Main window.
root = tk.Tk()
root.title('Label Destroyer')
root.geometry('250x100')

# Only use pack or grid can't use both interchangeably on the same frame
# or else you will get a Tkinter Error.

# Create label and grid/pack separately!
myLabel = tk.Label(root, text='This will be destroyed')
#myLabel.grid(row=0, column=0, padx=5, pady=5, sticky='n')
myLabel.pack(side=tk.TOP, padx=5, pady=5, anchor='n')

# Create a function to destroy label, else it'll be destroyed before it's seen.
# If not grid/pack separately you will get a, None Type Error.
def myFunc():
	myLabel.destroy() # <- destory label.
	myButton.config(text='Label destroyed!') # <- change button text.

# Create a button to call myFunc.
myButton = tk.Button(root, text='Destroy Label', command=myFunc)
#myButton.grid(row=1, column=0, padx=5, pady=5, sticky='s')
myButton.pack(side=tk.BOTTOM, padx=5, pady=5, anchor='s')

# Run main window.
root.mainloop()