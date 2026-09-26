from abc import ABC
from datetime import datetime

class Person(ABC):
    def __init__(self, name: str, person_id: str = "") -> None:
        self._name = name
        self._id = person_id


class Librarian(Person):
    def __init__(self, name: str, person_id: str = "") -> None:
        super().__init__(name, person_id)

    def processLoan(self, member: "Member", book: "Book") -> "Loan":
        return Loan(member, book)


class Member(Person):
    def __init__(self, name: str, member_id: str = "") -> None:
        super().__init__(name, member_id)

    def borrowBook(self, book: "Book") -> None:
        pass


class Book:
    def __init__(self, title: str, isbn: str = "") -> None:
        self.__title = title
        self.__isbn = isbn


class Shelf:
    def __init__(self, shelf_id: str = "") -> None:
        self.__shelfId = shelf_id
        self.books: list[Book] = []


class Library:
    def __init__(self, name: str) -> None:
        self.__name = name
        self.shelves: list[Shelf] = []


class DateTime:
    @staticmethod
    def getCurrentTime() -> datetime:
        return datetime.now()


class Loan:
    def __init__(self, member: Member, book: Book) -> None:
        self.member = member
        self.book = book
        self.loanDate = DateTime.getCurrentTime()
        self.dueDate = None

    def checkDueDate(self, date_time: DateTime) -> bool:
        pass

