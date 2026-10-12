# Open Closed Principle

# Without OCP

class DiscountCalculator:
    """
    If we add new discount type (e.g. student), we have to change its calculate method
    """
    def calculate(self, price: float, discount_type: str) -> float:
        if discount_type == "regular":
            return price * 0.1
        elif discount_type == 'premium':
            return price * 0.2
        elif discount_type == 'vip':
            return price * 0.3
        return 0

# With OCP
from abc import ABC, abstractmethod
class Discount(ABC):
    @abstractmethod
    def calculate(self, price: float) -> float:
        pass

class RegularDiscount(Discount):
    def calculate(self, price):
        return price * 0.1

class PremiumDiscount(Discount):
    def calculate(self, price):
        return price * 0.2

class VIPDiscount(Discount):
    def calculate(self, price):
        return price * 0.3

class StudentDiscount(Discount):
    def calculate(self, price):
        return price * 0.15

class DiscountCalculator:
    def calculate_discount(self, price: float, discount: Discount) -> float:
        return discount.calculate(price)

# Usage
calculator = DiscountCalculator()
vip = VIPDiscount()
student = StudentDiscount()

v = calculator.calculate_discount(1000, vip)
print(f"VIP: {v}")
s = calculator.calculate_discount(1000, student)
print(f'Student: {s}')
