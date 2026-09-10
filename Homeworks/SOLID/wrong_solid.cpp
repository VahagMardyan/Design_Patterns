#include <iostream>
#include <string>
#include <vector>

enum class DrinkType { Espresso, Cappuccino, Tea };

class CafeSystem {
public:
    DrinkType type;

    CafeSystem(DrinkType t) : type(t) {}

    // 1. Ըմպելիքի պատրաստում
    void brewDrink() {
        if (type == DrinkType::Espresso) {
            std::cout << "Brewing strong espresso...\n";
        } else if (type == DrinkType::Cappuccino) {
            std::cout << "Brewing espresso and adding steamed milk...\n";
        } else if (type == DrinkType::Tea) {
            std::cout << "Steeping tea leaves...\n";
        }
    }

    // 2. Վճարման մշակում
    void processPayment(double amount) {
        std::cout << "Processing cash payment of $" << amount << "...\n";
    }

    // 3. Տվյալների պահպանում DB-ում
    void saveOrderToDatabase() {
        std::cout << "Saving order details to local MySQL DB...\n";
    }

    // 4. Զեղչի հաշվարկ
    virtual double calculateDiscount(double price) {
        return price * 0.05; // 5% զեղչ ստանդարտ հաճախորդի համար
    }
};

// VIP Հաճախորդի դաս
class VIPCafeSystem : public CafeSystem {
public:
    VIPCafeSystem(DrinkType t) : CafeSystem(t) {}

    // Խնդրահարույց override. VIP-ի դեպքում կանխիկ վճարումն արգելված է
    void processPayment(double amount) {
        throw std::runtime_error("VIP clients cannot pay with cash! Use Card.");
    }

    double calculateDiscount(double price) override {
        return price * 0.20; // 20% զեղչ VIP-ի համար
    }
};

// Սարքավորումների ինտերֆեյս
class IAllInOneMachine {
public:
    virtual void makeCoffee() = 0;
    virtual void makeTea() = 0;
    virtual void steamMilk() = 0;
};

// Պարզ թեյնիկ, որը ստիպված է իրականացնել սուրճի մեթոդները
class BasicTeaMaker : public IAllInOneMachine {
public:
    void makeTea() override {
        std::cout << "Making simple tea...\n";
    }

    void makeCoffee() override {
        // Չի աջակցվում
        throw std::logic_error("Tea maker cannot make coffee!");
    }

    void steamMilk() override {
        // Չի աջակցվում
        throw std::logic_error("Tea maker cannot steam milk!");
    }
};

// Պատվերի կառավարման բարձր մակարդակի դաս
class OrderManager {
private:
    CafeSystem cafe; // Կախված է կոնկրետ դասից, այլոչ թե աբստրակցիայից

public:
    OrderManager(DrinkType type) : cafe(type) {}

    void processOrder(double price) {
        cafe.brewDrink();
        cafe.processPayment(price);
        cafe.saveOrderToDatabase();
    }
};