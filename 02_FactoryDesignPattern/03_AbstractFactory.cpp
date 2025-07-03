// Product has abstraction
// Factory also have concrete factories
// But now, factories can create two or more types of products

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

class Garlic {
public:
    virtual void prepare() = 0;
    virtual ~Garlic() {};
};

class BasicGarlic : public Garlic {
public:
    void prepare() {
        std::cout<<"Prep basic garlic bread"<<std::endl;
    }
};

class StandardGarlic : public Garlic {
public:
    void prepare() {
        std::cout<<"Prep standard garlic bread"<<std::endl;
    }
};

class BasicWheatGarlic : public Garlic {
public:
    void prepare() {
        std::cout<<"Prep basic wheat garlic bread"<<std::endl;
    }
};

class StandardWheatGarlic : public Garlic {
public:
    void prepare() {
        std::cout<<"Prep standard wheat garlic bread"<<std::endl;
    }
};

// Factory <<abstract>>
class MealFactory{
public:
    virtual Burger* createBurger(std::string type) = 0; 
    virtual Garlic* createGarlic(std::string type) = 0;
};

// Concrete factory
class SinghBurger : public MealFactory{
    Burger* createBurger(std::string type) override {
        if(type == "basic") return new BasicBurger;
        else if(type == "standard") return new StandardBurger;
        else return nullptr;
    }

    Garlic* createGarlic(std::string type) override {
        if(type == "basic") return new BasicGarlic;
        else if(type == "standard") return new StandardGarlic;
        else return nullptr;
    }
};

// Concrete factory
class KingBurger : public MealFactory{
    Burger* createBurger(std::string type) override {
        if(type == "basic") return new BasicWheatBurger;
        else if(type == "standard") return new StandardWheatBurger;
        else return nullptr;
    }

    Garlic* createGarlic(std::string type) override {
        if(type == "basic") return new BasicWheatGarlic;
        else if(type == "standard") return new StandardWheatGarlic;
        else return nullptr;
    }
};

int main() {
    MealFactory *factory = new SinghBurger;
    Burger * burger = factory->createBurger("basic");
    Garlic * garlic = factory->createGarlic("basic");
    burger->prepare();
    garlic->prepare();
}