class Burger:
    def __init__(self, builder : "BurgerBuilder" ) -> None:
        self.__bread_type = builder.bread_type
        self.__meat_type = builder.meat_type
        self.__has_cheese = builder.has_cheese
        self.__has_tomato = builder.has_tomato

    def __str__(self) -> str:
        cheese_str = "with Cheese" if self.__has_cheese else "no Cheese"
        tomato_str = "with Tomato" if self.__has_tomato else "no Tomato"
        meat_str = self.__meat_type if self.__meat_type else "no Meat"
        return f"Burger [{self.__bread_type} bread, {meat_str}, {cheese_str}, {tomato_str}]"

class BurgerBuilder:
    def __init__(self, bread_type : str) -> None:
        self.has_cheese = False
        self.has_tomato = False
        self.bread_type = bread_type

    def add_meat(self, meat_type : str) -> "BurgerBuilder":
        self.meat_type = meat_type
        return self

    def add_cheese(self) -> "BurgerBuilder":
        self.has_cheese = True
        return self

    def add_tomato(self) -> "BurgerBuilder":
        self.has_tomato = True
        return self

    def build(self) -> Burger:
        return Burger(self)

myCustomBurger = (
    BurgerBuilder("Brioche")
                  .add_meat("Chicken")
                  .add_cheese()
                  .add_tomato()
                  .build()
                  )
print(myCustomBurger)
