#include <iostream>
#include <string>
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
    std::unique_ptr<Entity> entity = std::make_unique<Entity>();
    {
        std::unique_ptr<Entity> e1 = std::move(entity);
    }
    return 0;
}

/*
    1. std::unique_ptr -> 
       սա միակն է որ կարողանում է հղվել տվյալ հասցեին։ 
       unique_ptr-ը միանգամից ջնջում է օբյեկտը երբ ավարտվում է իր տեսանելիության տիրույթը։
       Այդ պատճառով մենք չենք կարող այն copy անել, հակառակ դեպքում երկրորդ ptr-ն նույնպես կփորձի 
       ջնջել արդեն իսկ ջնջված օբյեկտը և ծրագիրը crash կլինի: Այն կարող ենք միայն տեղափոխել (std::move())

    Օրինակ այս ծրագիրը
        1. Heap-ում ստեղծվում է entity-ն: Stack-ում պահվում է այդ օբյեկտի հասցեն -> Created Entity
        2. std::move-ը entity-ից վերցնում է օբյեկտի հասցեն և այն տալիս է e1-ին։ Սրա արդյունքում 
            e1-ը դառնում է միակ pointer-ը որը պահում է օբյեկտի հասցեն, իսկ entity-ն դառնում է nullptr:
        3. e1-ի տեսանելիության տիրույթի ավարտից հետո e1-ը ջնջվում է և քանի որ այն միակն էր, որը հղված էր այդ օբյեկտի վրա
            ջնջվում է նաև այդ օբյեկտը։ -> Destroyed Entity
        4. main-ի ավարտից հետո ջնջվում է նաև entity-ն
*/

