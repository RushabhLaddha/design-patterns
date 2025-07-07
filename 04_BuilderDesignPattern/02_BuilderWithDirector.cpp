// Using Director class for calling the mostly used templates

#include<iostream>

class HttpRequest {
private:
    std::string url;
    std::string body;
    int timeout = -1;
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
        if(req.url.empty()) throw std::runtime_error("URL cannot be empty");
        return req;
    }
};

class HttpRequestDirector{
public:
    static HttpRequest createUrlReq(const std::string &u) {
        return HttpRequestBuilder()
                .withUrl(u)
                .build();
    }
    
    static HttpRequest createBodyReq(const std::string &u, const std::string &b) {
        return HttpRequestBuilder()
                .withUrl(u)
                .withBody(b)
                .build();
    }
};

int main() {

    std::cout<<"======================== Simple Builder Pattern ============================="<<std::endl;
    HttpRequest req1 = HttpRequestBuilder()
    .withBody("Hello")
    .withTimeout(20)                 
    .withUrl("https://youtube.com/") 
    .build();
    req1.execute();
    
    std::cout<<"======================== Director Builder Pattern ==========================="<<std::endl;
    HttpRequest req2 = HttpRequestDirector::createUrlReq("https://google.com/");
    req2.execute();


    return 0;
}