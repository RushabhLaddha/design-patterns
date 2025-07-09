// Making abstract classes of mandatory required member variables of the product class
// Using multiple inheritance for Builder class from all the abstract classes
// Defining functions in such a way that the return type of functions make sure all the required member variables get populated before building the final product

#include<iostream>

class HttpRequest {
private:
    std::string url;
    std::string method;
    std::string body;
    int timeout = -1;
    HttpRequest() {}
public:
    friend class HttpRequestBuilder;
    void execute() {
        std::cout<<"URL: "<<url<<std::endl;
        std::cout<<"Method: "<<method<<std::endl;
        std::cout<<"Body: "<<body<<std::endl;
        std::cout<<"Timeout: "<<timeout<<std::endl;
    }

};

// Forward declaration
class UrlStep;
class MethodStep;
class OptionalStep;

// Abstract classes
class UrlStep{
public:
    virtual MethodStep& withUrl(const std::string &u) = 0;
};
class MethodStep{
public:
    virtual OptionalStep& withMethod(const std::string &m) = 0;
};
class OptionalStep{
public:
    virtual OptionalStep& withBody(const std::string &b) = 0;
    virtual OptionalStep& withTimeout(int t) = 0;
    virtual HttpRequest& build() = 0;
};

class HttpRequestBuilder:
        public UrlStep,
        public MethodStep,
        public OptionalStep
{
private:
    HttpRequest req;
public:
    MethodStep& withUrl(const std::string &u) override {
        req.url = u;
        return *this;
    }

    OptionalStep& withMethod(const std::string &m) override {
        req.method = m;
        return *this;
    }

    OptionalStep& withBody(const std::string &b) override {
        req.body = b;
        return *this;
    }

    OptionalStep& withTimeout(int t) override {
        req.timeout = t;
        return *this;
    }

    HttpRequest& build() override {
        return req;
    }

    static UrlStep& startBuilder() {
        return *(new HttpRequestBuilder());
    }
};

int main() {
    HttpRequest req = HttpRequestBuilder::startBuilder()
                        .withUrl("https://youtube.com/")
                        .withMethod("GET")
                        .build();
    req.execute();
}