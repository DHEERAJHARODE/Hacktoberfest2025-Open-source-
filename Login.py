def login(username: str, password: str) -> bool:
    is_aunthenticated = False
    
    if username == "admin" and password == "1234":
        is_aunthenticated = True
    
    return is_aunthenticated
#login function checks if the username and password match the hardcoded values.
#it contains username and password as parameters.
#username has str which is string type and password has str which is string type.
#it return to boolean value which is True or False.

user = input("Enter your username:")
passw = input("Enter your password:")

logged_in = login(user, passw)

#message = "login failed, chec again"

#if logged_in:
#    message = "login successful"
    
#print(message)

print("Login successful" if logged_in else "Login failed, check again")
