#include <iostream>

class Base {
    public:
        Base() {}
        virtual ~Base() {}
};

class Derived : public Base {
    public:
        Derived() {}
        ~Derived() {}
};

int main() {
    // C-style Cast and Static Cast
    float value = 5.25;
    int c_style = (int)value;
    int s_style = static_cast<int>(value);
    std::cout<<c_style<<", "<<s_style<<std::endl;

    // Dynamic Cast
    Base* base = new Base();
    Derived* q = dynamic_cast<Derived*>(base);
    if(q) {
        std::cout << "True" << std::endl;
    } else {
        std::cout << "Dynamic Cast: Failed (base is not Derived type)" << std::endl;
    }

    Base* basePtr = new Derived(); // իրականում Derived է
    Derived* d = dynamic_cast<Derived*>(basePtr);

    if(d) {
        std::cout << "Dynamic Cast: Success (basePtr is actually Derived type)" << std::endl;
    }

    // Reinterpret Cast
    int* bits = reinterpret_cast<int*>(&value);
    std::cout << *bits << std::endl;

    // Const Cast
    const int readOnly = 10;
    std::cout << readOnly << std::endl;
    // // readOnly = 20; // չենք կարող սա անել const է
    int* mutablePtr = const_cast<int*>(&readOnly); // const-ը հեռացրեցինք
    *mutablePtr = 20;
    std::cout << *mutablePtr << std::endl;

    std::cout<<mutablePtr<<" "<<&readOnly<<std::endl;
    
    delete base;
    delete basePtr;
    return 0;
}

/*
    1. C-style cast -> Ամենավտանգավոր տեսակը։ Այն մի տիպը դարձնում է մի ուրիշ տիպ։
        Թե ինչպես է դա արվում չենք կարող ասել:

        Այս ծրագրում C-style cast-ը նորմալ կաշխատի, քանի որ float-ը և int-ը տրամաբանորեն կապված տիպեր են։
        Բայց խորհուրդ է տրվում նաև այս դեպքում օգտագործել static_cast:
    
    2. static_cast -> Ամենահաճախ օգտագործվողն է։ Այն կատարում է տիպերի ձևափոխություն, 
        որոնք տրամաբանորեն իրար հետ կապված են։ Օրինակ՝ float-ից int, կամ ժառանգ դասից բազային դաս։
        Այստեղ compiler-ը ստուգում է, թե արդյոք նման ձևափոխություն հնարավոր է:

        Այս ծրագրում static_cast-ը նորմալ կաշխատի, քանի որ float-ը և int-ը տրամաբանորեն կապված տիպեր են։
    
    3. dynamic_cast -> Սա օգտագործվում է միայն ժառանգության ժամանակ և  աշխատում է Runtime։
        Այն ստուգում է, թե արդյոք օբյեկտը հանդիսանում է տվյալ տիպի։

        Այս օրինակում basePtr-ը չնայած Base տիպի ցուցիչ է, բայց իրականում այն Derived տիպի է։
        Դրա համար dynamic_cast-ը կաշխատի: Բայց base-ը Derived տիպի չէ, հետևաբար dynamic_cast-ը չի աշխատի։
    
    4. reinterpret_cast -> Սա ամենավտանգավորն է։ Այն ուղղակի վերցնում է մի տիպը և ներկայացնում որպես այլ տիպ։

        Այստեղ float-ը մեկնաբանվում է որպես int:
        5.25-ը IEEE-754 ստանդարտով ներկայացվում է որպես 01000000101010000000000000000000:
        Իսկ այդ թիվը եթե դարձնենք int կստանանք 1084751872։

    5. const_cast -> Սա օգտագործվում է const-ը հանելու կամ ավելացնելու համար:
        Այստեղ readOnly-ի const-ը կարողացանք "հանել" const_cast-ի միջոցով, 
        որի արդյունքում նրա հիշողության հատվածում գրեցինք նոր արդյունք՝ 20։
        const int readOnly = 10; -> Compiler-ը կատարում է օպտիմիզացիաներ 
        (const-ը ենթադրվում է որ readOnly-ի արժեքը միշտ 10 է լինելու) ու readOnly-ին փոխում է 10-ով։
        *mutablePtr-ը և readOnly-ն նույն հասցեի տակ են։ Բայց պետք է հիշել որ const-ի փոխելը C++ ում
        Undefined Behavior է:
*/
