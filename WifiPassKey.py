import subprocess

# Open the command prompt and run the command "netsh wlan show profiles"
process = subprocess.Popen(["netsh", "wlan", "show", "profiles"], stdout=subprocess.PIPE)
output, error = process.communicate()

# Print the output of the command
output = output.decode()
lines = output.split("\n")
profiles = []
for line in lines:
    if "All User Profile" in line:
        profiles.append(line.split(":")[1].strip())

# Print the list of WiFi profiles
print("List of WiFi profiles:")
for i, profile in enumerate(profiles):
    print("{}. {}".format(i + 1, profile))

# Ask the user to choose a WiFi profile
selected_profile = None
while selected_profile is None:
    try:
        choice = int(input("Choose a WiFi profile (enter the number): "))
        if 1 <= choice <= len(profiles):
            selected_profile = profiles[choice - 1]
        else:
            print("Invalid choice. Please choose a number between 1 and {}.".format(len(profiles)))
    except ValueError:
        print("Invalid input. Please enter a valid number.")

# Display the security key for the selected WiFi profile
command = 'netsh wlan show profile "{}" key=clear | findstr Key'.format(selected_profile)
process = subprocess.Popen(command, stdout=subprocess.PIPE, shell=True)
output, error = process.communicate()

# Print the output of the command
print(output.decode())
