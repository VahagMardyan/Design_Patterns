from math import sin, cos, pi

class Point:
    def __init__(self, x: float, y: float):
        self._x = x
        self._y = y

    def __str__(self) -> str:
        return f"Point(x={self._x}, y={self._y})"
    
class PointFactory:
    @staticmethod
    def new_cartesian(x: float, y: float) -> Point:
        return Point(x, y)

    @staticmethod
    def new_polar(r: float, theta: float) -> Point:
        return Point(r * cos(theta), r * sin(theta))

c_point = PointFactory.new_cartesian(x=4, y=5)
print(c_point)

pol_point = PointFactory.new_polar(r=2, theta=pi / 4)
print(pol_point)