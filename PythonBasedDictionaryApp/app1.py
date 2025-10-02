
import json
from difflib import get_close_matches
import tkinter as tk
from tkinter import messagebox

# Load data
try:
    with open("data.json", "r") as file:
        data = json.load(file)
except FileNotFoundError:
    messagebox.showerror("Error", "data.json file not found!")
    exit()

# Function to translate word
def translate(word):
    word = word.lower()
    if word in data:
        return data[word]
    elif word.title() in data:
        return data[word.title()]
    elif word.upper() in data:
        return data[word.upper()]
    else:
        matches = get_close_matches(word, data.keys(), cutoff=0.8)
        if matches:
            yn = messagebox.askyesno(
                "Did you mean?",
                f"Did you mean '{matches[0]}' instead?"
            )
            if yn:
                return data[matches[0]]
            else:
                return ["The word doesn't exist. Please double-check."]
        else:
            return ["The word doesn't exist. Please double-check."]

# Function to handle search
def search_word():
    word = entry.get()
    output_box.delete(1.0, tk.END)
    if word.strip() == "":
        messagebox.showinfo("Input required", "Please enter a word to search.")
        return
    result = translate(word)
    if isinstance(result, list):
        for meaning in result:
            output_box.insert(tk.END, f"- {meaning}\n")
    else:
        output_box.insert(tk.END, f"- {result}\n")

# Function to clear input/output
def clear_all():
    entry.delete(0, tk.END)
    output_box.delete(1.0, tk.END)

# Tkinter GUI
root = tk.Tk()
root.title("Python Dictionary App")
root.geometry("600x400")
root.configure(bg="lightblue")

title = tk.Label(root, text="Python Dictionary App", font=("Arial", 20, "bold"), bg="lightblue")
title.pack(pady=10)

entry_label = tk.Label(root, text="Enter a word:", font=("Arial", 14), bg="lightblue")
entry_label.pack(pady=5)

entry = tk.Entry(root, font=("Arial", 14), width=30)
entry.pack(pady=5)

search_btn = tk.Button(root, text="Search", font=("Arial", 12), command=search_word, bg="green", fg="white")
search_btn.pack(pady=5)

clear_btn = tk.Button(root, text="Clear", font=("Arial", 12), command=clear_all, bg="red", fg="white")
clear_btn.pack(pady=5)

output_box = tk.Text(root, height=10, width=60, font=("Arial", 12))
output_box.pack(pady=10)

root.mainloop()
