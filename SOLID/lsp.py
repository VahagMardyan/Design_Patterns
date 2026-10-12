# Liskov Substitution Principle

# Without LSP
class Rectangle:
    def __init__(self, w: float, h: float):
        self._width = w
        self._height = h

    def set_width(self, w):
        self._width = w

    def set_height(self, h):
        self._height = h

    def area(self) -> float:
        return self._width * self._height

class Square(Rectangle):
    def set_width(self, w):
        self._width = self._height = w

    def set_height(self, h):
        self._height = self._width = h

def get_area(rect: Rectangle):
    """
    If we pass Square, we will get a wrong behavior
    """
    rect.set_width(5)
    rect.set_height(10)
    print(rect.area()) # 100 for square

r = Rectangle(w=6, h=9)
get_area(r) # 50

s = Square(w=8, h=8)
get_area(s) # 100

# With LSP
from abc import ABC, abstractmethod
class Shape(ABC):
    @abstractmethod
    def area(self):
        pass

class Rectangle(Shape):
    def __init__(self, width: float, height: float):
        self._width = width
        self._height = height

    def area(self) -> float:
        return self._width * self._height

class Square(Shape):
    def __init__(self, side: float):
        self._side = side

    def area(self):
        return self._side ** 2

def get_area(shape: Shape):
    print(f"Area: {shape.area()}")

r = Rectangle(width=5, height=6)
get_area(r) # 30
s = Square(side=10)
get_area(s) # 100

