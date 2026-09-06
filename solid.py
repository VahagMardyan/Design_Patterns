from abc import ABC, abstractmethod

# S --> Single Responsibility Principle
# Class must have only one reason to be changed
"""
The bank account class is responsible only for the balance, not for printing statements or calculating interest.
"""
class BankAccount:
    def __init__(self, account_number : str, balance : float):
        self.account_number = account_number
        self.balance = balance

    def deposit(self, amount : float) -> None:
        self.balance += amount

    def withdraw(self, amount : float) -> None:
        if amount <= self.balance:
            self.balance -= amount
        else:
            raise ValueError("No enough funds")

class StatementPrinter:
    def print_statement(self, account : BankAccount) -> None:
        print(f"Account: {account.account_number} | Balance: {account.balance}")

# O --> Open/Closed Principle
"""
The loan interest calculation is open to adding new loan types, 
but closed to changing the logic of the existing calculation.
"""
class Loan(ABC):
    def __init__(self, amount : float):
        self.amount = amount

    @abstractmethod
    def calculate_interest(self) -> float:
        pass

class PersonalLoan(Loan):
    def calculate_interest(self):
        return self.amount * 0.15

class MortgateLoan(Loan):
    def calculate_interest(self):
        return self.amount * 0.24

class LoanService:
    def get_total_service(self, loan : Loan) -> float:
        return loan.calculate_interest()

# L --> Liskov Substitution Principle
"""
If we have a base Account class, then all derived accounts must adhere to its contracts. 
If a DepositAccount is frozen for a fixed term and does not permit withdrawals, 
it should not inherit from the withdrawable account.
"""
class Account(ABC):
    @abstractmethod
    def get_balance(self) -> float:
        pass

class WithdrawableAccount(Account):
    @abstractmethod
    def withdraw(self, amount : float) -> float:
        pass

class CheckingAccount(WithdrawableAccount):
    def __init__(self, balance : float):
        self.balance = balance
    
    def get_balance(self):
        return self.balance
    
    def withdraw(self, amount : float) -> float:
        self.balance -= amount

class FixedDepositAccount(Account):
    def __init__(self, balance : float):
        self.balance = balance

    def get_balance(self):
        return self.balance

# I --> Interface Segregation Principle
"""
Different bank customers have different entitlements. You shouldn't create one massive interface for all transactions.
"""

class ClientOperations(ABC):
    @abstractmethod
    def view_balance(self):
        pass

class TransferOperations(ABC):
    @abstractmethod
    def transfer_money(self, target_account : str, amount : float) -> None:
        pass

# A standard user can both see the balance and make a transfer.
class StandardUser(ClientOperations, TransferOperations):
    def view_balance(self):
        print("Viewing balance...")

    def transfer_money(self, target_account : str, amount : float) -> None:
        print(f"Transfering {amount} AMD --> {target_account}")

# The auditor only has the right to observe.
class Auditor(ClientOperations):
    def view_balance(self):
        print('Audit inspection: observation of the balance...')

# D --> Dependency Inversion Principle
"""
The high-level transaction processing system (TransactionProcessor) depends on 
the database abstraction (AccountRepository), rather than on a specific PostgreSQL or Oracle database.
"""

class AccountRepository(ABC):
    @abstractmethod
    def save(self, account_id : str, balance : float) -> None:
        pass

class PostgresAccountRepository(AccountRepository):
    def save(self, account_id : str, balance : float) -> None:
        print(f"Saving into Postgres database: {account_id} --> {balance}")

class MongoAccountRepository(AccountRepository):
    def save(self, account_id : str, balance : float) -> None:
        print(f"Saving into MongoDB database: {account_id} --> {balance}")

class TransactionProcessor:
    def __init__(self, repository : AccountRepository):
        self.repository = repository

    def process_deposit(self, account_id : str, amount : float) -> None:
        self.repository.save(account_id, amount)

db = PostgresAccountRepository()
processor = TransactionProcessor(repository=db)
processor.process_deposit("ACC12345", 45000)
