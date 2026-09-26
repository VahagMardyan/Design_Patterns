#include <iostream>
#include <string>

class Entity {
    private:
        std::string m_name;
        int m_age;
    public:
        Entity(const std::string& name) : m_name(name), m_age(-1) {}
        explicit Entity(int age) : m_name("Unknown"), m_age(age) {}
        ~Entity() {}
    friend std::ostream& operator<<(std::ostream& stream, const Entity& e);
    friend void printEntity(const Entity& e);
};

std::ostream& operator<<(std::ostream& stream, const Entity& e) {
    stream << e.m_name << " " << e.m_age;
    return stream;
}

void printEntity(const Entity& e) {
    std::cout << e.m_name << " " << e.m_age << std::endl;
}

int main() {
    Entity e1 = (Entity)22; // line-1
    Entity e2 = std::string("Hello");
    // std::cout<<e1<<std::endl;
    // std::cout<<e2<<std::endl;

    // printEntity(296); // line-2
    
    printEntity(Entity(2960)); // line-3
    return 0;
}

/*
    explicit -> արգելում է կոնստրուկտորին ձևափոխություններ անել
    Եթե տարիքի համար նախատեսված կոնստրուկտորը գրենք explicit-ով, ապա (line-1)-ը չի աշխատի,
    քանի որ compiler-ը կատարում էր ներքին անուղղակի (implicit) ձևափոխություններ: Այժմ պետք է գրենք հետևյալ տարբերակներից մեկը
    1. Entity e1 = Entity(22); // ամենաընդունելին
    2. Entity e1(22);
    3. Entity e1 = (Entity)22; // ցանկալի է չանել C-style cast

    Այժմ նայենք printEntity ֆունկցիան, որը ստանում է Entity տեսակի reference։
    Դիտարկենք նաև (line-2)-ը որը այդ ֆունկցիային փոխանցել է int տիպի արգումենտ:
    Եթե տարիքի կոնստրուկտորը explicit չէ, ապա compiler-ը այդ int արգումենտը դարձնելու է Entity և 
    մեր ծրագիրն առանց սխալի կաշխատի։ Սակայն, սա կոդը կարդացողի մոտ կարող է հարցեր առաջացնել։ Դրա համար գրում են explicit
    և խնդիրը լուծվում է: Ֆունկցիային միայն տարիք փոխանցելը կարող ենք անել (line-3)-ի նման:
*/