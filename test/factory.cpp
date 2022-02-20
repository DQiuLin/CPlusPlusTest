#include "common.h"

//定义动物类型
//class Animal {
//public:
//    virtual void say() = 0;
//};
//class Dog: public Animal {
//public:
//    void say() override {
//        std::cout << "dog" << std::endl;
//    }
//};
//class Cat: public Animal {
//public:
//    void say() override {
//        std::cout << "cat" << std::endl;
//    }
//};

//工厂父类
//class AnimalFactory {
//public:
//    Animal *createAnimal(std::string type) {
//        if (type == "dog") {
//            return new Dog();
//        } else if (type == "cat") {
//            return new Cat();
//        }
//        return nullptr;
//    }
//};
//int main() {
//    AnimalFactory *f = new AnimalFactory();
//    f->createAnimal("dog")->say();//输出 dog
//    f->createAnimal("cat")->say();//输出 cat
//}

//工厂父类
//class AnimalFactory {
//public:
//    virtual Animal *createAnimal() = 0;
//};
//
////每一个不同类型的对象都生成使用一个子类工厂
//class DogFactory : public AnimalFactory {
//public:
//    Animal *createAnimal() override {
//        return new Dog();
//    }
//};
//
//class CatFactory : public AnimalFactory {
//public:
//    Animal *createAnimal() override {
//        return new Cat();
//    }
//};
//
//int main() {
//    AnimalFactory *f = new DogFactory();
//    f->createAnimal()->say();//输出 dog
//
//    AnimalFactory *ff = new CatFactory();
//    ff->createAnimal()->say();//输出 cat
//}

//定义动物类型
class Animal {
public:
    virtual void say() = 0;
};
class Dog: public Animal {
public:
    void say() override {
        std::cout << "dog" << std::endl;
    }
};
class FemaleDog : public Dog {
public:
    void say() override {
        std::cout << "female dog" << std::endl;
    }
};
class MaleDog : public Dog {
public:
    void say() override {
        std::cout << "male dog" << std::endl;
    }
};
class Cat: public Animal {
public:
    void say() override {
        std::cout << "cat" << std::endl;
    }
};


//工厂父类
class AnimalFactory {
public:
    virtual Animal *createDog() = 0;

    virtual Animal *createCat() = 0;
};

//只为第一分类的子工厂
class MaleAnimalFactory: public AnimalFactory {
public:
    Animal *createDog() override {
        return new MaleDog();
    }

    Animal *createCat() override {
        //...
    };
};

class FemaleAnimalFactory: public AnimalFactory {
public:
    Animal *createDog() override {
        return new FemaleDog();
    };

    Animal *createCat() override {

    };
};


int main() {
    AnimalFactory *f = new FemaleAnimalFactory();
    f->createDog()->say();//输出 female dog
    AnimalFactory *ff = new MaleAnimalFactory();
    ff->createDog()->say();//输出 male cat
}