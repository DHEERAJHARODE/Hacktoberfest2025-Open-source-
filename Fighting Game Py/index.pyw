import random
import tkinter as tk

# Read fullscreen setting
with open("settings.txt", "r") as f:
    fs = int(f.read().strip() or 0)

# --- Character Data ---
CHARACTERS = {
    "Boxer": {"pmodifier": 1.5, "kmodifier": 0.5, "gmodifier": 0.25, "health": 125},
    "Muay Thai": {"pmodifier": 0.75, "kmodifier": 1.5, "gmodifier": 0.25, "health": 125},
    "Street Fight": {"pmodifier": 0.5, "kmodifier": 0.5, "gmodifier": 2, "health": 175},
}

# --- Main Menu ---
def main_menu():
    menu = tk.Tk()
    menu.title("Fight Night")
    menu.geometry("500x500")
    menu.configure(bg="green", cursor="dot")

    def toggle_fullscreen():
        global fs
        if fs == 1:
            fs = 0
            fsy.config(text="Disabled")
            menu.attributes("-fullscreen", False)
        else:
            fs = 1
            fsy.config(text="Enabled")
            menu.attributes("-fullscreen", True)
        with open("settings.txt", "w") as f:
            f.write(str(fs))

    def start_game(character):
        menu.destroy()
        game_window(character)

    title = tk.Label(menu, text="Simple Fighting Game", font=("Courier", 26, "bold"), pady=20, bg="green", fg="white")
    title.pack()

    for char in CHARACTERS:
        tk.Button(menu, text=char, command=lambda c=char: start_game(c), pady=15, width=25).pack(pady=5)

    tk.Label(menu, text="Settings", font=("Courier", 20, "bold"), bg="green", fg="white").pack(pady=10)
    tk.Label(menu, text="Fullscreen", font=("Courier", 14), bg="green", fg="white").pack()
    fsy = tk.Button(menu, text="Enabled" if fs else "Disabled", command=toggle_fullscreen)
    fsy.pack()

    tk.Button(menu, text="Exit", command=menu.destroy).pack(side=tk.BOTTOM, fill=tk.X)

    if fs:
        menu.attributes("-fullscreen", True)

    menu.mainloop()

# --- Gameplay Window ---
def game_window(character):
    stats = CHARACTERS[character]
    base_hp = stats["health"]
    health = base_hp
    ehealth = int(round(base_hp * 1.25))

    pmod, kmod, gmod = stats["pmodifier"], stats["kmodifier"], stats["gmodifier"]
    emod = 1.3
    ebasehp = ehealth
    game_over = False

    window = tk.Tk()
    window.title("Fight Night - Match")
    window.geometry("700x500")
    window.configure(bg="green")

    if fs:
        window.attributes("-fullscreen", True)

    # --- Functions ---
    def update_status():
        healthl.config(text=f"Health: {max(0,int(health))}/{base_hp}")
        ehealthl.config(text=f"Health: {max(0,int(ehealth))}/{ebasehp}")

    def check_winner():
        nonlocal game_over
        if not game_over:
            if ehealth <= 0:
                winner.config(text="✅ You Won!")
                game_over = True
            elif health <= 0:
                winner.config(text="❌ Enemy Won!")
                game_over = True

    def enemy_turn():
        nonlocal health, ehealth
        if game_over: return
        move = random.choice(["punch", "kick", "grapple"])
        miss = random.random() < 0.2
        if miss:
            enemymove.config(text="Enemy missed!")
            return
        if move == "punch":
            dmg = random.randint(10,20) * emod
            health -= dmg
            enemymove.config(text=f"Enemy used Punch (-{int(dmg)} HP)")
        elif move == "kick":
            dmg = random.randint(14,26) * emod
            health -= dmg
            enemymove.config(text=f"Enemy used Kick (-{int(dmg)} HP)")
        else:
            dmg = sum(random.randint(2,7) * emod for _ in range(random.randint(1,4)))
            health -= dmg
            enemymove.config(text=f"Enemy used Grapple (-{int(dmg)} HP)")
        update_status()
        check_winner()

    def player_attack(move):
        nonlocal ehealth
        if game_over: return
        miss = random.random() < 0.2
        if miss:
            playerddealt.config(text="You missed!")
        else:
            if move == "punch":
                dmg = random.randint(9,21) * pmod
                ehealth -= dmg
                playerddealt.config(text=f"You punched! (-{int(dmg)} HP)")
            elif move == "kick":
                dmg = random.randint(14,26) * kmod
                ehealth -= dmg
                playerddealt.config(text=f"You kicked! (-{int(dmg)} HP)")
            else: # grapple
                dmg = sum(random.randint(2,7) * gmod for _ in range(random.randint(1,4)))
                ehealth -= dmg
                playerddealt.config(text=f"You grappled! (-{int(dmg)} HP)")
        update_status()
        check_winner()
        if not game_over:
            enemy_turn()

    def restart_game():
        window.destroy()
        main_menu()

    # --- UI Layout ---
    tk.Label(window, text=f"Player ({character})", font=("Courier", 20, "bold")).pack(pady=5)
    healthl = tk.Label(window, text=f"Health: {health}/{base_hp}", font=("Courier", 16))
    healthl.pack()

    tk.Button(window, text="Punch", command=lambda: player_attack("punch"), width=20, pady=5).pack(pady=3)
    tk.Button(window, text="Kick", command=lambda: player_attack("kick"), width=20, pady=5).pack(pady=3)
    tk.Button(window, text="Grapple", command=lambda: player_attack("grapple"), width=20, pady=5).pack(pady=3)

    playerddealt = tk.Label(window, text="", font=("Courier", 14), bg="green", fg="white")
    playerddealt.pack(pady=5)

    tk.Label(window, text="Enemy", font=("Courier", 20, "bold")).pack(pady=5)
    ehealthl = tk.Label(window, text=f"Health: {ehealth}/{ebasehp}", font=("Courier", 16))
    ehealthl.pack()

    enemymove = tk.Label(window, text="", font=("Courier", 14), bg="green", fg="white")
    enemymove.pack(pady=5)

    winner = tk.Label(window, text="", font=("Courier", 16, "bold"), bg="green", fg="white")
    winner.pack(pady=10)

    tk.Button(window, text="Restart to Menu", command=restart_game).pack(side=tk.BOTTOM, fill=tk.X)
    tk.Button(window, text="Exit", command=window.destroy).pack(side=tk.BOTTOM, fill=tk.X)

    window.mainloop()

# Start game
main_menu()
