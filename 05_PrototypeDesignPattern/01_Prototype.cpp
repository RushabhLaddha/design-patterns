#include<iostream>

class Clonable{ // can also be named as Prototype
public:
    virtual Clonable* clone() = 0;
};

class NPC : public Clonable{
private:
    std::string name;
    int health;
    int attack;
public:

    // Parameterized constructor
    NPC(const std::string &name, int attack, int health) {
        // This can be time consuming as there might be a chances that connection to database is made or some complex calculations can be performed.
        std::cout<<"Parameterized constructor called"<<std::endl;
        this->name = name;
        this->attack = attack;
        this->health = health;
    }
    
    // Copy constructor
    NPC(const NPC& other) {
        std::cout<<"Copy constructor called"<<std::endl;
        name = other.name;
        health = other.health;
        attack = other.attack;
    }

    // To clone the current object call this
    Clonable* clone() override {
        return new NPC(*this);
    }
    
    // To tweak the cloned object
    void setName(const std::string &name) {
        this->name = name;
    }
    void setHealth(int health) {
        this->name = name;
    }
    void setAttack(int attack) {
        this->attack = attack;
    }

    void describe() {
        std::cout<<"Name: "<<name<<std::endl;
        std::cout<<"Health: "<<health<<std::endl;
        std::cout<<"Attack: "<<attack<<std::endl;
        std::cout<<std::endl;
    }
};

int main() {
    NPC* alien1 = new NPC("Small Alein", 50, 10);
    alien1->describe();

    NPC* alien2 = dynamic_cast<NPC*>(alien1->clone());
    alien2->setName("Medium Alien");
    alien2->describe();
    
    NPC* alien3 = dynamic_cast<NPC*>(alien1->clone());
    alien3->setName("Biggest Alien");
    alien3->setAttack(100);
    alien3->describe();
}