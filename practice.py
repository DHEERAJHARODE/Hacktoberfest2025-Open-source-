class Student :
    Class = 0
    def __init__(self,x,y,z):
        self.name = x
        self.roll_name = y
        Student.Class = z
        
obj = Student("Mia",4578,10)
print(obj.__dict__)  