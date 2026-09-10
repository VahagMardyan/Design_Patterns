#include <iostream>
#include <string>
#include <vector>

// Drinks

class IDrink {
    public:
        virtual ~IDrink() = default;
        virtual void brew() const = 0;
};

class Espresso : public IDrink {
    public:
        void brew() const override {
            std::cout << "Brewing strong espresso..." << std::endl;
        }
};

class Latte : public IDrink {
    public:
        void brew() const override {
            std::cout << "Brewing Latte..." << std::endl;
        }
};

// Payment

class IPaymentMethod {
    public:
        virtual ~IPaymentMethod() = default;
        virtual void processPayment(double amount) const = 0;
};

class CashPayment : public IPaymentMethod {
    public:
        void processPayment(double amount) const override {
            std::cout << "Processing payment by cash..." << amount << "$" << std::endl;
        };
};

class CardPayment : public IPaymentMethod {
    public:
        void processPayment(double amount) const override {
            std::cout << "Processing payment by card... $" << amount << std::endl;
        };
};

// Discounts

class IDiscountStrategy {
    public:
        virtual ~IDiscountStrategy() = default;
        virtual double calculateDiscount(double price) const = 0;
};

class StandardDiscount : public IDiscountStrategy {
    public:
        double calculateDiscount(double price) const override {
            return price * 0.05;
        }
};

class VIPDiscount : public IDiscountStrategy {
    public:
        double calculateDiscount(double price) const override {
            return price * 0.20;
        }
};

// Databases

class IDatabase {
    public:
        virtual ~IDatabase() = default;
        virtual void saveOrder() const = 0;
};

class MySQLDatabase : public IDatabase {
    public:
        void saveOrder() const override {
            std::cout << "Saving order to MySQL..."<<std::endl;
        }
};

// Machines

class IBasicTeaMaker {
    public:
        virtual ~IBasicTeaMaker() = default;
        virtual void makeTea() = 0;
};

class TeaMachine : public IBasicTeaMaker {
    public:
        void makeTea() override {
            std::cout << "Making tea..." << std::endl;
        };
};

class ICoffeeMaker {
    public:
        virtual ~ICoffeeMaker() = default;
        virtual void makeCoffee() = 0;
};

class CoffeeMachine : public ICoffeeMaker {
    public:
        void makeCoffee() override {
            std::cout << "Making coffee..." << std::endl;
        };
};  

class IMilkSteamer {
    public:
        virtual ~IMilkSteamer() = default;
        virtual void steamMilk() = 0;
};

class MilkSteamer : public IMilkSteamer {
    public:
        void steamMilk() override {
            std::cout << "Steaming Milk..." << std::endl;
        };
};

// Manage Order

class OrderManager {
    private:
        const IDrink& drink;
        const IPaymentMethod& paymentMethod;
        const IDatabase& database;
        const IDiscountStrategy& discountStrategy;
    public:
        OrderManager(
            const IDrink& d,
            const IPaymentMethod& payment,
            const IDatabase& d_base,
            const IDiscountStrategy& dsc
        ) : drink(d), paymentMethod(payment), database(d_base), discountStrategy(dsc) {}

        void processOrder(double rawPrice) const {
            drink.brew();
            double discount = discountStrategy.calculateDiscount(rawPrice);
            double finalPrice = rawPrice - discount;
            std::cout << "Discount Applied: $" << discount << std::endl;
            paymentMethod.processPayment(finalPrice);
            database.saveOrder();
        }
};

int main() {
    Espresso espresso;
    CardPayment card;
    MySQLDatabase db;
    VIPDiscount vip;
    OrderManager order(espresso, card, db, vip);
    order.processOrder(10.0);
    return 0;
}
