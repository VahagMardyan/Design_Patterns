from abc import ABC, abstractmethod
import copy

class Enemy(ABC):
    @abstractmethod
    def clone(self) -> "Enemy":
        pass

    @abstractmethod
    def display_status(self) -> None:
        pass

class Monster(Enemy):
    def __init__(self, m_type : str, health : int, equipment : dict, position : list[int]) -> None:
        self.__monster_type = m_type
        self.__health = health
        self.__equipment = equipment
        self.__position = position

    def clone(self) -> "Monster":
        return copy.deepcopy(self)

    def display_status(self) -> None:
        print(self)

    def __repr__(self) -> str:
        info = {
            "Monster Type": self.__monster_type,
            "Health" : self.__health,
            "Equipment" : self.__equipment,
            "Position" : self.__position
        }
        return f"{info}"

    @property
    def monster_type(self):
        return self.__monster_type
    @monster_type.setter
    def monster_type(self, mt):
        self.__monster_type = mt

    @property
    def health(self):
        return self.__health
    @health.setter
    def health(self, h):
        self.__health = h

    @property
    def equipment(self):
        return self.__equipment
    @equipment.setter
    def equipment(self, eqp):
        self.__equipment = eqp

    @property
    def position(self):
        return self.__position
    @position.setter
    def position(self, pos):
        self.__position = pos

class EnemyRegistry:

    def __init__(self):
        self._prototypes = {}

    def register_prototype(self, name : str, enemy : Enemy):
        self._prototypes[name] = enemy

    def spawn(self, name : str) -> Enemy:
        prototype = self._prototypes.get(name)
        if not prototype:
            raise KeyError(f"Prototype '{name}' not registered.")
        return prototype.clone()

registry = EnemyRegistry()

goblin_template = Monster(
    "Goblin Scout", 50, {"weapon": "Dagger", "armor": "Leather"}, [0, 0]
)
registry.register_prototype("goblin_scout", goblin_template)

goblin1 = registry.spawn("goblin_scout")
goblin2 = registry.spawn("goblin_scout")

goblin1.position = [10, 20]
goblin1.health = 35

goblin2.equipment["weapon"] = "Shortsword"
goblin2.position = [50, 80]

print("Template:", goblin_template)
print("Goblin 1:", goblin1)
print("Goblin 2:", goblin2)