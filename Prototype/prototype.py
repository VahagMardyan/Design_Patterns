from abc import ABC, abstractmethod
import copy
from math import pi

class Shape(ABC):
    @abstractmethod
    def clone(self) -> "Shape":
        """Returns a copy of the shape."""
        pass
    
    @abstractmethod
    def info(self) -> None:
        """Prints shape details."""
        pass

    @abstractmethod
    def area(self) -> float:
        """Calculates the are of the shape."""
        pass

class Rectangle(Shape):
    def __init__(self, w : float, h : float) -> None:
        self.__width = w
        self.__height = h

    def info(self):
        print(self)

    def clone(self) -> "Rectangle":
        return copy.copy(self)

    @property
    def width(self) -> float:
        return self.__width
    
    @width.setter
    def width(self, w) -> None:
        self.__width = w

    @property
    def height(self) -> float:
        return self.__height

    @height.setter
    def height(self, h) -> None:
        self.__height = h

    def area(self) -> float:
        return self.__width * self.__height

    def __repr__(self):
        return f"Rectangle(width={self.__width}, height={self.__height})"

class Circle(Shape):
    def __init__(self, r : float) -> None:
        self.__radius = r

    @property
    def radius(self) -> float:
        return self.__radius

    @radius.setter
    def radius(self, r) -> None:
        self.__radius = r

    def info(self) -> None:
        print(self)

    def clone(self) -> "Circle":
        return copy.copy(self)

    def area(self) -> float:
        return pi * self.__radius ** 2

    def __repr__(self):
        return f"Circle(radius={self.__radius})"

class Hexagon(Shape):
    def __init__(self, s : float) -> None:
        self.__side = s

    @property
    def side(self) -> float:
        return self.__side

    @side.setter
    def side(self, s1 : float) -> None:
        self.__side = s1

    def info(self) -> None:
        print(self)

    def clone(self) -> "Hexagon":
        return copy.copy(self)

    def area(self) -> float:
        return (3*(3)**0.5) * self.__side **2 / 2 

    def __repr__(self) -> str:
        return f"Hexagon(side={self.__side})"

c = Circle(r=10)
print(c.area())
c1 = c.clone()
c1.info()

# r = Rectangle(w=10, h=9)
# r.info()
# r.clone().info()

h = Hexagon(s=5)
h.info()
print(h.area())
h1 = h.clone()
print(h is h1)
