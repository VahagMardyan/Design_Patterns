# Dependency Inversion Principle

# Without DIP
class EmailNotifier:
    def send(self, message: str):
        print(f"Email sent: {message}")

class OrderService:
    """
    If we want to change notifier logic from Email to SMS, we have to change OrderService.
    """
    def __init__(self):
        self._notifier = EmailNotifier()

    def place_order(self, order_id):
        print(f"Order {order_id} placed")
        self._notifier.send("Your order has been placed.")

# With DIP
from abc import ABC, abstractmethod

class Notifier(ABC):
    @abstractmethod
    def send(self, message: str):
        pass

class EmailNotifier(Notifier):
    def send(self, message: str):
        print(f"Email sent: {message}")

class SMSNotifier(Notifier):
    def send(self, message: str):
        print(f"SMS sent: {message}")

class OrderService:
    def __init__(self, notifier: Notifier):
        self._notifier = notifier

    def place_order(self, order_id):
        print(f"Order {order_id} placed")
        self._notifier.send("Your order has been placed")

# Usage

email_service = OrderService(EmailNotifier())
sms_service = OrderService(SMSNotifier())

email_service.place_order(101)
sms_service.place_order(102)
