class String:
    def __init__(self):
        self.input_string = input()

    def printString(self):
        print(self.input_string.upper())





class Shape:
    def area(self):
        return 0
    
class Square(Shape):
    def __init__(self, length):
        self.length = length

    def area(self):
        return self.length**2
    




class Rectangle(Shape):
    def __init__(self, length, width):
        self.length = length
        self.width = width

    def area(self):
        return self.length * self.width







class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y


    def move(self, a, b):
        self.x = a
        self.y = b

    def dist(self, first, second):
        return ((first.x - second.x)**2 + (first.y - second.y)**2)**0.5







class Account:
    def __init__(self, owner, balance=0):
        self.owner = owner
        self.balance = balance

    def deposit(self, a):
        self.balance += a

    def withdraw(self, a):
        if a <= self.balance:
            self.balance -= a
        else:
            print("Mistake")







def prime(num):
    if num < 2:
        return False
    for i in range(2, int(num**0.5) + 1):
        if num % i == 0:
            return False
    return True