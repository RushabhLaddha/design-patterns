// Product has abstraction
// Factory also have concrete factories

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

// Concrete Product
class BasicWheatBurger : public Burger {
public:
    void prepare() override {
        std::cout<<"Prep basic wheat burger"<<std::endl;
    }
};

// Concrete Product
class StandardWheatBurger : public Burger {
public:
    void prepare() override {
        std::cout<<"Prep standard wheat burger"<<std::endl;
    }
};

// Factory <<abstract>>
class BurgerFactory{
public:
    virtual Burger* createBurger(std::string type) = 0; 
};

// Concrete factory
class SinghBurger : public BurgerFactory{
    Burger* createBurger(std::string type) override {
        if(type == "basic") return new BasicBurger;
        else if(type == "standard") return new StandardBurger;
        else return nullptr;
    }
};

// Concrete factory
class KingBurger : public BurgerFactory{
    Burger* createBurger(std::string type) override {
        if(type == "basic") return new BasicWheatBurger;
        else if(type == "standard") return new StandardWheatBurger;
        else return nullptr;
    }
};

int main() {
    BurgerFactory *factory = new KingBurger;
    Burger * burger = factory->createBurger("basic");
    burger->prepare();
}