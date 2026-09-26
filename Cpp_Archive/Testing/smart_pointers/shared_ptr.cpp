#include <iostream>
#include <memory>

class Entity {
    public:
        Entity() {
            std::cout<<"Created Entity"<<std::endl;
        }
        ~Entity() {
            std::cout<<"Destroyed Entity"<<std::endl;
        }
};

int main() {
    std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>(); // cnt=1

    {
        std::shared_ptr<Entity> copy = sharedEntity; // cnt=2
        {
            std::shared_ptr<Entity> copy2 = sharedEntity; // cnt=3
        }
    }

    return 0;
}

/*
2. std::shared_ptr ->
    Սա նախատեսված է անվտանգ copy անելու համար: Այն Control Block-ում պահում է հաշվիչ, որը ավելանում է երբ copy ենք անում։
    Դրա շնորհիվ է որ բոլոր shared_ptr-ները տեսնում են նույն թիվը:
    shared_ptr-ը չի ջնջում օբյեկտը քանի դեռ այդ հաշվիչը 0 չէ։ Ցուցիչները ջնջվում են տեսանելիության տիրույթի ավարտից հետո: 

    Օրինակ այս ծրագիրը
    Առաջինը կջնջվի copy2-ը => cnt=2
    Երկրորդը կջնջվի copy-ն => cnt=1
    Վերջինը կջնվի sharedEntity-ն => cnt=0։
    Քանի որ cnt=0, ապա օբյեկտը կջնջվի
*/