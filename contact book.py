import tkinter as tk
from tkinter import messagebox

data = {}

def add():
    name = e_name.get()
    phone = e_phone.get()
    email = e_email.get()
    addr = e_addr.get()

    if name == "" or phone == "":
        messagebox.showwarning("Error", "Name and Phone required")
        return

    data[name] = [phone, email, addr]
    clear()
    show()
    messagebox.showinfo("Done", "Contact Added")

def show():
    box.delete(0, tk.END)
    for name in data:
        box.insert(tk.END, name + " - " + data[name][0])

def find():
    key = e_search.get().lower()
    box.delete(0, tk.END)

    for name in data:
        if key in name.lower() or key in data[name][0]:
            box.insert(tk.END, name + " - " + data[name][0])

def update():
    name = e_name.get()
    if name in data:
        data[name] = [e_phone.get(), e_email.get(), e_addr.get()]
        show()
        messagebox.showinfo("Done", "Contact Updated")
    else:
        messagebox.showwarning("Error", "Contact not found")

def remove():
    sel = box.curselection()
    if not sel:
        messagebox.showwarning("Error", "Select contact")
        return

    text = box.get(sel)
    name = text.split(" - ")[0]
    del data[name]
    clear()
    show()
    messagebox.showinfo("Done", "Contact Deleted")

def clear():
    e_name.delete(0, tk.END)
    e_phone.delete(0, tk.END)
    e_email.delete(0, tk.END)
    e_addr.delete(0, tk.END)

# window
root = tk.Tk()
root.title("Contact App")
root.geometry("400x500")

tk.Label(root, text="Contact Manager", font=("Arial", 16)).pack(pady=10)

f = tk.Frame(root)
f.pack()

tk.Label(f, text="Name").grid(row=0, column=0)
e_name = tk.Entry(f, width=30)
e_name.grid(row=0, column=1)

tk.Label(f, text="Phone").grid(row=1, column=0)
e_phone = tk.Entry(f, width=30)
e_phone.grid(row=1, column=1)

tk.Label(f, text="Email").grid(row=2, column=0)
e_email = tk.Entry(f, width=30)
e_email.grid(row=2, column=1)

tk.Label(f, text="Address").grid(row=3, column=0)
e_addr = tk.Entry(f, width=30)
e_addr.grid(row=3, column=1)

b = tk.Frame(root)
b.pack(pady=10)

tk.Button(b, text="Add", width=10, command=add).grid(row=0, column=0, padx=5)
tk.Button(b, text="Update", width=10, command=update).grid(row=0, column=1, padx=5)
tk.Button(b, text="Delete", width=10, command=remove).grid(row=0, column=2, padx=5)

tk.Label(root, text="Search").pack()
e_search = tk.Entry(root, width=35)
e_search.pack()

tk.Button(root, text="Search", command=find).pack(pady=5)

box = tk.Listbox(root, width=45, height=10)
box.pack(pady=10)

root.mainloop()
