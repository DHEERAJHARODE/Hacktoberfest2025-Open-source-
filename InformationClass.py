# Information Class 
class Information:
    def __init__(self,__name,__address,__age,__phone_number):
        self.name = __name
        self.address = __address
        self.age = __age
        self.phoneNum = __phone_number
    def set_name(self,__name):
        self.name = __name
    def set_address(self,__address):
        self.address = __address
    def set_age(self,__age):
        self.age = __age
    def set_phoneNum(self,__phone_number):
        self.phoneNum = __phone_number
    def get_name(self):
        return self.name
    def get_address(self):
        return self.address
    def get_age(self):
        return self.age
    def get_phoneNum(self):
        return self.phoneNum
    def __str__(self) -> str:
        return f'''\n-------------------------------------------
Information
-------------------------------------------
Name: {self.name}
Address: {self.address}
Age: {self.age}
Phone Number: {self.phoneNum}
'''

    