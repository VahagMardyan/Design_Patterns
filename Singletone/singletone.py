class Singletone:
    _instance = None
    def __new__(cls):
        if cls._instance is None:
            cls._instance = super().__new__(cls)
            print("Singletone instance created.")
        return cls._instance

    def say_hi(self):
        print("Hi!")

s1 = Singletone()
s1.say_hi()

s2 = Singletone()

print(s1 is s2) # True
