#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Product {
    public:
        virtual double get_price() const = 0;
};

class Pen: public Product {
    private:
        double price;
        std::string name;
    public:
        Pen(std::string n, double p) : name(n), price(p) {}

        double get_price() const override {
            return price;
        }
};

class Box: public Product {
    private:
        std::vector<Product*> products;
    public:

        void addProduct(Product* product) {
            products.push_back(product);
        }

        double get_price() const override {
            double total = 0;
            for(const auto& product : products) {
                total += product -> get_price();
            }
            return total;
        }

        void removeProduct(Product* product) {
            products.erase(std::remove(products.begin(), products.end(), product), products.end());
        }
};

int main() {
    Pen pen("Sev grich", 150);
    Box box;
    box.addProduct(&pen);

    Box subbox;
    Pen red_pen("red", 200);

    subbox.addProduct(&red_pen);

    box.addProduct(&subbox);

    double total = box.get_price();
    std::cout << total << std::endl;
    return 0;
}