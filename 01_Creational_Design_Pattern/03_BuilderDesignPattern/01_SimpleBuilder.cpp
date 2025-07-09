#include<iostream>

class HttpRequest {
private:
    std::string url;
    std::string body;
    int timeout = -1;

    // Making the constructor private limiting the direct construction of object
    HttpRequest() {}
public:
    friend class HttpRequestBuilder;
    void execute() {
        std::cout<<"URL: "<<url<<std::endl;
        std::cout<<"Body: "<<body<<std::endl;
        std::cout<<"Timeout: "<<timeout<<std::endl;
    }

};

class HttpRequestBuilder{
private:
    HttpRequest req;
public:
    HttpRequestBuilder& withUrl(const std::string &u) {
        req.url = u;
        return *this;
    }
    HttpRequestBuilder& withBody(const std::string &b) {
        req.body = b;
        return *this;
    }
    HttpRequestBuilder& withTimeout(int time) {
        req.timeout = time;
        return *this;
    }
    HttpRequest build() {
        // 1. By adding all validations here, we solve the issue of scattered validations
        if(req.url.empty()) throw std::runtime_error("URL cannot be empty");
        if(req.body.empty()) throw std::runtime_error("Body cannot be empty");
        if(req.timeout == -1) throw std::runtime_error("Timeout cannot be negative");
        return req;
    }
};

int main() {
    HttpRequest req = HttpRequestBuilder()
                        .withBody("Hello")               // intermediate method
                        .withTimeout(20)                 // ...
                        .withUrl("https://youtube.com/") // ...
                        .build();                        // terminating method

    // 2. Solves the issue of mutability as there are no setters and to call the with functions, we would've to perform build again
    // 3. No need of constructor overloading because if we miss any of the required field, we will throw the error
    req.execute();
    return 0;
}