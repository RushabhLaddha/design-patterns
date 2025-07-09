#include<iostream>

// Target Interface expected by client
class IReport{
public:
    virtual std::string getJsonData(const std::string &data) = 0;
};

// Adaptee: provides xml data
class XMLDataProvider{
public:
    // data = "Name:id"
    std::string getXMLData(const std::string &data) {
        auto sep = data.find(':');
        std::string name = data.substr(0, sep);
        std::string id = data.substr(sep + 1);
        return "<user>"
                "<name>" + name + "</name>"
                "<id>" + id + "</id>"
                "</user>";
    }
};

// Adapter: provides JSON data from xml data coming from adaptee
class XMLDataProviderAdapter : public IReport{
private:
    XMLDataProvider* provider;
public:
    XMLDataProviderAdapter(XMLDataProvider* instance) {
        provider = instance;
    }
    std::string getJsonData(const std::string &data) {
        std::string xmlData = provider->getXMLData(data);

        auto startName = xmlData.find("<name>") + 6;
        auto endName = xmlData.find("</name>");
        std::string name = xmlData.substr(startName, endName - startName);
        
        auto startId = xmlData.find("<id>") + 4;
        auto endId = xmlData.find("</id>");
        std::string id = xmlData.substr(startId, endId - startId);

        return "{\"name\":\"" + name + "\", \"id\":" + id + "}";
    }
};

class Client{
public:
    void getReport(IReport* report, const std::string &data) {
        std::cout<<"JSON Report -> "<<report->getJsonData(data)<<std::endl;
    }
};

int main() {
    XMLDataProvider* adaptee = new XMLDataProvider();
    IReport* adapter = new XMLDataProviderAdapter(adaptee);
    std::string rawData = "Alice:15";
    Client* client = new Client();
    client->getReport(adapter, rawData);

    return 0;
}