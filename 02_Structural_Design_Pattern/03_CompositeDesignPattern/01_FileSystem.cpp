#include<iostream>
#include<vector>

class FileSystem{
public:
    virtual std::string getName() = 0;
    virtual void openAll(int indent = 0) = 0;
    virtual void ls() = 0;
};

class File : public FileSystem {
private:
    std::string name;
public:
    File(const std::string &name) {
        this->name = name;
    }
    std::string getName() override {
        return name;
    }
    void openAll(int indent = 0) override {
        for(int i = 0; i < indent; i++) {
            std::cout<<" ";
        }
        std::cout<<getName()<<std::endl;
    }
    void ls() override {
        std::cout<<getName()<<std::endl;
    }
};

class Folder : public FileSystem {
private:
    std::string name;
    std::vector<FileSystem *>list;
public:
    Folder(const std::string &name) {
        this->name = name;
    }
    void push(FileSystem* file) {
        list.push_back(file);
    }
    std::string getName() override {
        return name + "/";
    }
    void openAll(int indent = 0) override {
        for(int i = 0; i < indent; i++) {
            std::cout<<" ";
        }
        std::cout<<getName()<<std::endl;
        for(int i = 0; i < list.size(); i++) {
            list[i]->openAll(indent + 4);
        }
    }
    void ls() override {
        for(int i = 0; i < list.size(); i++) {
            std::cout<<list[i]->getName()<<std::endl;
        }
    }
};

int main() {
    Folder* sunil = new Folder("sunil");
    File* rushabh = new File("rushabh.txt");
    File* rutuja = new File("rutuja.pdf");
    sunil->push(rushabh);
    sunil->push(rutuja);
    
    Folder* prasad = new Folder("prasad");
    File* arya = new File("arya.txt");
    File* arushi = new File("arushi.pdf");
    prasad->push(arya);
    prasad->push(arushi);

    File* niraj = new File("niraj.jpeg");
    
    Folder* root = new Folder("subhash");
    root->push(sunil);
    root->push(prasad);
    root->push(niraj);

    root->openAll();
    // root->ls();
}
