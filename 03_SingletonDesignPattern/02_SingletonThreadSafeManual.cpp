// Lock the mutex in the static member function which assigns the object if the variable is null

#include<iostream>
#include<mutex>

class Singleton{
public:
    static Singleton* getInstance() { // created as static because there is no need to create an object while calling this function
        std::lock_guard<std::mutex>lock(mtx);
        if(instance == nullptr) 
            instance = new Singleton();
        return instance;
    }
private:
    static Singleton* instance; // only declaration, no memory is allocated yet. This member is class level not object level
    static std::mutex mtx;
    Singleton(){
        std::cout<<"Singleton instance created"<<std::endl;
    }
};

Singleton* Singleton::instance = nullptr; // initialization. Here the memory is allocated to the static member variable
std::mutex Singleton::mtx;

int main() {
    Singleton *s1 = Singleton::getInstance();
    Singleton *s2 = Singleton::getInstance();
    std::cout<<(s1 == s2)<<std::endl;
    return 0;
}