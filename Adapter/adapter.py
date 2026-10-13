from abc import ABC, abstractmethod

class PaymentProcessor(ABC):
    @abstractmethod
    def pay(self, amount: float) -> None:
        pass

class StripePaymentProcessor(PaymentProcessor):
    def pay(self, amount: float) -> None:
        print(f"Processing payment of {amount:.2f} via Stripe.")

class PayPalService:
    def send_payment(self, amount_in_cents: int, currency: str) -> None:
        print(f"PayPal Service: Sent {amount_in_cents} cents in {currency}.")

class PayPalAdapter(PaymentProcessor):
    def __init__(self, paypal_service: PayPalService, currency: str = 'USD'):
        self._paypal_service = paypal_service
        self._currency = currency

    def pay(self, amount: float) -> None:
        amount_in_cents = int(amount * 100)
        self._paypal_service.send_payment(amount_in_cents, self._currency)

def checkout(processor: PaymentProcessor, total: float) -> None:
    processor.pay(total)

stripe = StripePaymentProcessor()
checkout(stripe, 49.99)

paypal_service = PayPalService()
paypal_adapter = PayPalAdapter(paypal_service=paypal_service)
checkout(paypal_adapter, 49.99)

