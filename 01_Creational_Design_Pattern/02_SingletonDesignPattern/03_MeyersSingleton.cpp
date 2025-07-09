// Use static member function which creates a local static variable of class instance making sure instance is created only once
// Can be used only from C++11 and later

#include<iostream>

class Singleton{
public:
    static Singleton* getInstance() {
        static Singleton instance;
        return &instance;
    }
private:
    Singleton() {
        std::cout<<"Singleton instance created"<<std::endl;
    }
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
};

int main() {
    Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();
    std::cout<<(s1 == s2)<<std::endl;

    // Can't use as we deleted assignment and copy constructor to avoid multiple instances to be created
    // Singleton s3 = *s1;
    // std::cout<<(&s3 == s1)<<std::endl;

    return 0;
}