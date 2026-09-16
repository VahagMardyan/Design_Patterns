# SOLID Refactoring Analysis Report

**Project:** Smart Cafe System
**Language:** C++17

## Ամփոփում

Այս փաստաթուղթը ներկայացնում է **Smart Cafe System**-ի սկզբնական (`wrong_solid.cpp`) կոդում առկա SOLID ճարտարապետական խախտումները և refactoring-ից հետո կատարված բարելավումները:

---

## SOLID Սկզբունքների Խախտումներ և Լուծումներ

### 1. Single Responsibility Principle (SRP)

* **Խնդիրը սկզբնական կոդում:**`CafeSystem` դասը կատարում էր 3 տարբեր պատասխանատվություն՝
  1. Ըմպելիքի պատրաստման տրամաբանություն (`brewDrink`)
  2. Վճարման մշակում (`processPayment`)
  3. Տվյալների պահպանում DB-ում (`saveOrderToDatabase`)
* **Լուծում:**
  Պատասխանատվությունները բաժանվեցին առանձին ինտերֆեյսների և դասերի միջև՝ `IDrink`, `IPaymentMethod`, `IDatabase`:

---

### 2. Open/Closed Principle (OCP)

* **Խնդիրը սկզբնական կոդում:**`brewDrink()`-ում օգտագործված էր `if-else` տրամաբանություն ըստ `DrinkType` enum-ի: Նոր ըմպելիք (օրինակ՝ `Latte`) ավելացնելու համար ստիպված էինք լինելու փոփոխել `CafeSystem` դասի ներսի կոդը:
* **Լուծում:**
  Ստեղծվեցին `IDrink` և `IDiscountStrategy` աբստրակտ ինտերֆեյսները: Այժմ նոր ըմպելիք կամ զեղչի տեսակ ավելացվում է պարզապես նոր դաս ստեղծելով (extensible)՝ առանց հին կոդը փոփոխելու:

---

### 3. Liskov Substitution Principle (LSP)

* **Խնդիրը սկզբնական կոդում:**`VIPCafeSystem`-ը ժառանգվում էր `CafeSystem`-ից, սակայն `processPayment()`-ում նետում էր `std::runtime_error` բացառություն (արգելելով կանխիկ վճարումը): Սա խախտում էր բազային դասի սպասվող վարքագիծը (subsumption):
* **Լուծում:**
  Վճարման մեխանիզմը առանձնացվեց `IPaymentMethod` ինտերֆեյսի տակ (`CashPayment`, `CardPayment`): Այժմ վճարման եղանակները լիարժեք փոխարինելի են և չեն խախտում ծրագրի կայունությունը:

---

### 4. Interface Segregation Principle (ISP)

* **Խնդիրը սկզբնական կոդում:**`IAllInOneMachine`-ը «հաստ» (fat) ինտերֆեյս էր: `BasicTeaMaker`-ը ստիպված էր իրականացնել `makeCoffee()` և `steamMilk()` մեթոդները՝ նետելով `std::logic_error`:
* **Լուծում:**
  Ինտերֆեյսը տրոհվեց 3 փոքր, specialized ինտերֆեյսների՝ `IBasicTeaMaker`, `ICoffeeMaker`, `IMilkSteamer`: Յուրաքանչյուր սարք իրականացնում է միայն իրեն անհրաժեշտ մեթոդները:

---

### 5. Dependency Inversion Principle (DIP)

* **Խնդիրը սկզբնական կոդում:**`OrderManager` բարձր մակարդակի դասը ուղղակիորեն կախված էր կոնկրետ `CafeSystem` դասից (ցածր մակարդակի detail):
* **Լուծում:**
  `OrderManager`-ը այժմ կախված է բացառապես աբստրակցիաներից (`IDrink`, `IPaymentMethod`, `IDatabase`, `IDiscountStrategy`)՝ կախվածությունները ստանալով **Dependency Injection** (constructor-ի) միջոցով:

---

## Վերանախագծված Կոդի Կառուցվածքը

| Մոդուլ / Abstraction                               | Concrete Implementations                             |
| :------------------------------------------------------- | :--------------------------------------------------- |
| `IDrink`                                               | `Espresso`, `Latte`                              |
| `IPaymentMethod`                                       | `CashPayment`, `CardPayment`                     |
| `IDiscountStrategy`                                    | `StandardDiscount`, `VIPDiscount`                |
| `IDatabase`                                            | `MySQLDatabase`                                    |
| `IBasicTeaMaker` / `ICoffeeMaker` / `IMilkSteamer` | `TeaMachine`, `CoffeeMachine`, `MilkSteamer`   |
| `OrderManager`                                         | *High-level coordinator depending on abstractions* |

---

## Եզրակացություն

Վերանախագծման (Refactoring) արդյունքում․

- Կոդը դարձել է **Loosely Coupled** (թույլ կապակցված):
- Հեշտացել է **Unit Testing**-ը (հնարավոր է փոխանցել mock օբյեկտներ):
- Համակարգը պատրաստ է անսահմանափակ ընդլայնման (**Extensible**) առանց գոյություն ունեցող կոդը վնասելու:
