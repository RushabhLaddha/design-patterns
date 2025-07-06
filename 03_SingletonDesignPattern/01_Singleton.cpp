// Make the constructor private
// static member variable that holds the only instance of the class
// Create static member function  that will return the static member variable that holds the only instance

#include<iostream>

class Singleton{
public:
    static Singleton* getInstance() { // created as static because there is no need to create an object while calling this function
        if(instance == nullptr) 
            instance = new Singleton();
        return instance;
    }
private:
    static Singleton* instance; // only declaration, no memory is allocated yet. This member is class level not object level
    Singleton(){
        std::cout<<"Singleton instance created"<<std::endl;
    }
};

Singleton* Singleton::instance = nullptr; // initialization. Here the memory is allocated to the static member variable

int main() {
    Singleton *s1 = Singleton::getInstance();
    Singleton *s2 = Singleton::getInstance();
    std::cout<<(s1 == s2)<<std::endl;
    return 0;
}