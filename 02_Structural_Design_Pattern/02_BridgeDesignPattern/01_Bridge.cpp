/*  Here we've taken an exmaple of Cars and Engines
    Before Bridge Design Pattern:
        If we've 3 car types (SUV, HatchBack, Sedan) and 3 Engine Types (Petrol, Diesel, CNG)
        If we want to pair up all the combinations it'll take 9 different classes to accomodate all
        m * n where m = types of cars and n = types of engines
    After Bridge Design Pattern:
        Here we separate car and engine. 
        Car has a Engine relationship
        That way we can reduce the m * n combinations into m + n. 
*/

#include<iostream>

// Implementation Hierarchy : Engine LLL
class Engine{
public:
    virtual void start() = 0;
};

// Concrete Implementers
class Petrol : public Engine {
    public:
    void start() override {
        std::cout<<"Starting Petrol Engine"<<std::endl;
    }
};

// Concrete Implementers
class Diesel : public Engine {
public:
    void start() override {
        std::cout<<"Starting Diesel Engine"<<std::endl;
    }
};

// Abstraction Hierarchy : Car HLL
class Car{
protected:
    Engine *engine;
public:
    Car(Engine *e) {
        engine = e;
    }
    virtual void drive() = 0;
};

// Refined Abstraction
class SUV : public Car{
public:
    SUV(Engine *engine) : Car(engine) {}
    void drive() override {
        engine->start();
        std::cout<<"SUV started driving"<<std::endl;
    }
};

// Refined Abstraction
class HatchBack : public Car{
public:
    HatchBack(Engine *engine) : Car(engine) {}
    void drive() override {
        engine->start();
        std::cout<<"HatchBack started driving"<<std::endl;
    }
};


int main() {
    Engine *engine = new Petrol();
    Car* car = new HatchBack(engine);
    car->drive();
    delete(car);
    car = new SUV(engine);
    car->drive(); 
    delete(car);
    delete(engine);
}