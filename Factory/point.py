from math import sin, cos

class Point:
    def __init__(self, x : float, y : float) -> None:
        self.x = x
        self.y = y

    class PointFactory:
        def __init__(self):
            pass

        @staticmethod
        def NewCartesian(x : float, y : float) -> 'Point':
            return Point(x, y)

        @staticmethod
        def NewPolar(r : float, theta : float) -> "Point":
            return Point(r * cos(theta), r * sin(theta))

    def __str__(self):
        return f"{self.x, self.y}"

Point.factory = Point.PointFactory()

point = Point.factory.NewPolar(3, 4)
print(point)
