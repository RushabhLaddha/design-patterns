// Only Product has the abstract class
// Factory is only single
#include<iostream>
#include<string>

// Product <<abstract>>
class Burger{
public:
    virtual void prepare() = 0;
    virtual ~Burger() {};
};

// Concrete Product
class BasicBurger : public Burger {
public:
    void prepare() override {
        std::cout<<"Prep basic burger"<<std::endl;
    }
};

// Concrete Product
class StandardBurger : public Burger {
public:
    void prepare() override {
        std::cout<<"Prep standard burger"<<std::endl;
    }
};

// Factory
class BurgerFactory{
public:
    Burger* createBurger(std::string type) {
        if(type == "basic") return new BasicBurger;
        else if(type == "standard") return new StandardBurger;
        else return nullptr;
    }
};

int main() {
    BurgerFactory *factory = new BurgerFactory;
    Burger *burger = factory->createBurger("basic");
    burger->prepare();
    burger = factory->createBurger("standard");
    burger->prepare();
    // burger = factory->createBurger("hello");
    // burger->prepare(); // always add nullptr check
}