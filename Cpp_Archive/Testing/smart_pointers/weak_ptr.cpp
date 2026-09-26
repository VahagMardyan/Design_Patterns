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
        void print() {
            std::cout<<"Entity"<<std::endl;
        }
};

// int main() {
//     std::shared_ptr<Entity> shared = std::make_shared<Entity>();
//     std::weak_ptr<Entity> weak = shared; // weak-ը նայում է Entity-ին
//     // weak->print(); // չենք կարող օգտագոծել
//     if(std::shared_ptr<Entity> temp = weak.lock()) {
//         /*
//             Այստեղ weak-ը դառնում է shared_ptr և այն կարող ենք օգտագործել
//         */
//        temp->print();
//     } else {
//         std::cout<<"There's no Entity object"<<std::endl;
//     }
//     return 0;
// }

int main() {
    std::weak_ptr<Entity> weak;
    {
        std::shared_ptr<Entity> shared = std::make_shared<Entity>();
        weak = shared;
        if(auto temp = weak.lock()) {
            std::cout<<"Inside scope: Entity is alive!"<<std::endl;
        }
    }
    if(auto temp = weak.lock()) {
        temp->print();
    } else {
        std::cout<<"Outside scope: Entity is gone!"<<std::endl;
    }
    return 0;
}

/*
3. std::weak_ptr ->
    Այն ծառայում է որպես դիտորդ և չի տիրապետում օբյեկտին։ 
    Այսինքն Control Block-ի հաշվիչը չի ավելանա երբ որ weak_ptr հղվի օբյետկին

    Այս ծրագրում (first main)
        1. Ստեղծվում է shared_ptr shared => cnt=1 -> Created Entity
        2. Ստեղծվում է weak_ptr weak => cnt=1, քանի որ weak է
        weak-ը օբյեկտին չի տիրապետում, հետևաբար class-ի ոչմի օբյետնից չենք կարող օգտվել
        3․ weak.lock()-ը տեսնում է որ cnt=1, այսինքն օբյեկտը դեռ կա և այն դառնում է ժամանակավոր shared_ptr
            Այսինքն կարող ենք օգտվել print() մեթոդից։
        4. main-ի վերջում ջնջվում է shared-ը => cnt=0 => ջնջվում է նաև օբյեկը։ 
            Դրանից հետո ջնջվում է նաև waek-ը:

    Այս ծրագրում (second main)
        1. Scope-ի ներսում ստեղծվում է shared, որը պահում է օբյեկտին։ -> Created Entity
            weak_ptr-ը տեսնում է որ cnt=1 և ստեղծում է ժամանակավոր shared_ptr
            Scope-ի ավարտին shared-ը դուրս է գալիս տեսանելիության տիրույթից և cnt-ն դառնում է 0։
            Օբյեկտը ջնջվում է -> Destroyed Entity
        2. Scope-ից դուրս weak-ը դեռ կա։ Սակայն այն "դատարկ" է քանի որ օբյեկտը ջնջվել է։
            Հետևաբար lock-ը տեսնում է որ cnt=0 և վերադարձնում է nullptr:
*/