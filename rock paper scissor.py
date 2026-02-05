import tkinter as tk
import random

user_score = 0
comp_score = 0

def play(user):
    global user_score, comp_score

    comp = random.choice(["Rock", "Paper", "Scissors"])

    lbl_user.config(text="Your Choice: " + user)
    lbl_comp.config(text="Computer Choice: " + comp)

    if user == comp:
        result = "It's a Tie"
    elif (user == "Rock" and comp == "Scissors") or \
         (user == "Scissors" and comp == "Paper") or \
         (user == "Paper" and comp == "Rock"):
        result = "You Win"
        user_score += 1
    else:
        result = "You Lose"
        comp_score += 1

    lbl_result.config(text="Result: " + result)
    lbl_score.config(text=f"Score → You: {user_score}  Computer: {comp_score}")

# window
root = tk.Tk()
root.title("Rock Paper Scissors")
root.geometry("400x400")

tk.Label(root, text="Rock Paper Scissors Game", font=("Arial", 16)).pack(pady=10)

tk.Label(root, text="Choose one:", font=("Arial", 12)).pack()

btn_frame = tk.Frame(root)
btn_frame.pack(pady=10)

tk.Button(btn_frame, text="Rock", width=10, command=lambda: play("Rock")).grid(row=0, column=0, padx=5)
tk.Button(btn_frame, text="Paper", width=10, command=lambda: play("Paper")).grid(row=0, column=1, padx=5)
tk.Button(btn_frame, text="Scissors", width=10, command=lambda: play("Scissors")).grid(row=0, column=2, padx=5)

lbl_user = tk.Label(root, text="Your Choice: ")
lbl_user.pack(pady=5)

lbl_comp = tk.Label(root, text="Computer Choice: ")
lbl_comp.pack(pady=5)

lbl_result = tk.Label(root, text="Result: ", font=("Arial", 12, "bold"))
lbl_result.pack(pady=10)

lbl_score = tk.Label(root, text="Score → You: 0  Computer: 0")
lbl_score.pack(pady=10)

root.mainloop()
