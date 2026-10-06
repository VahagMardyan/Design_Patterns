from abc import ABC, abstractmethod

class Product(ABC):
    @property
    @abstractmethod
    def price(self) -> float:
        pass

    def __repr__(self) -> str:
        return f"Price: {self.price}"

class Box(Product):
    def __init__(self):
        self.__products: list[Product] = []

    def add_product(self, *products: Product) -> None:
        self.__products.extend(products)

    def remove_product(self, product: Product) -> None:
        self.__products.remove(product)

    @property
    def price(self):
        return sum(item.price for item in self.__products)

    def __str__(self) -> str:
        return f"Box (Total: {self.price}): {self.__products}"

class Pen(Product):
    def __init__(self, name: str, price: float):
        self._name = name
        self._price = price

    @property
    def price(self) -> float:
        return self._price

    def __repr__(self) -> str:
        return f"Name: {self._name}; {super().__repr__()}"

class Laptop(Product):
    def __init__(self, name: str, price: float):
        self._name = name
        self._price = price

    @property
    def price(self) -> float:
        return self._price

    def __repr__(self) -> str:
        return f"Name: {self._name}; {super().__repr__()}"

# Usage
pen1 = Pen(name="Blue pen", price=150)
pen2 = Pen(name="Black pen", price=120)

box = Box()
box.add_product(pen1)
box.add_product(pen2)

box.add_product(Pen(name='pen', price=124), Laptop(name='HP', price=350_000))

print(box)