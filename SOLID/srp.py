# Single Responsibility Principle

# Without SRP
class Wrong_Employee:
    """
    This class has a few responsibilities.
    If bonus calculating rule changes, we must change the class.
    """
    def __init__(self, name: str, salary: float):
        self._name = name
        self._salary = salary

    def calculate_bonus(self):
        return self._salary * 0.1

    def save_to_file(self, filename: str):
        with open(filename, 'w', encoding='utf-8') as f:
            f.write(f"{self._name}, {self._salary}")

# With SRP
class Employee:
    """
    This class is only responsible for data keeping.
    """
    def __init__(self, name: str, salary: float):
        self._name = name
        self._salary = salary

    @property
    def name(self):
        return self._name
    @property
    def salary(self):
        return self._salary

class BonusCalculator:
    """
    This class is only responsible for bonus.
    """
    def calculate_bonus(self, employee: Employee) -> float:
        return employee.salary * 0.1

class EmployeeRepository:
    """
    This class is only responsible for data saving.
    """
    def save_to_file(self, filename: str, employee: Employee):
        with open(filename, 'w', encoding='utf-8') as f:
            f.write(f"{employee.name}, {employee.salary}")

# Usage
employee = Employee(name="Jack", salary=1500)
bonus = BonusCalculator()
repo = EmployeeRepository()

a = bonus.calculate_bonus(employee)
print(a)
repo.save_to_file(filename="data.txt", employee=employee)

