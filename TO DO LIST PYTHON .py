from tkinter import *

window = Tk()
window.title("To Do List")
window.geometry("500x500")

tasks = []

def add_task():
    task = entry.get()

    if task == "":
        print("Task is empty")
    else:
        tasks.append(task)
        number = len(tasks)
        listbox.insert(END, str(number) + ". " + task)
        entry.delete(0, END)

def clear_text():
    entry.delete(0, END)

def clear_all():
    if len(tasks) == 0:
        print("No tasks to clear")
    else:
        tasks.clear()
        listbox.delete(0, END)

label = Label(window, text="My To Do List", font=("Arial", 14))
label.pack(pady=10)

entry = Entry(window, width=25)
entry.pack(pady=5)

add_btn = Button(window, text="Add Task", width=18, command=add_task)
add_btn.pack(pady=5)

clear_btn = Button(window, text="Clear Text", width=18, command=clear_text)
clear_btn.pack(pady=5)

clear_all_btn = Button(window, text="Clear All Tasks", width=18, command=clear_all)
clear_all_btn.pack(pady=5)

listbox = Listbox(window, width=30, height=10)
listbox.pack(pady=10)

window.mainloop()
