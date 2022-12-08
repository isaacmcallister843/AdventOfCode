#include "Day-7-Isaac.hpp"

struct Node{
    int memSpace = 0; 
    std::string name;
    std::vector<struct Node> children; 
    Node *parent = nullptr;

    Node(std::string Name){
        name = Name; 
    }

    void insert(Node& newNode){;

        for(struct Node n: children){
            if(newNode.name == n.name){return; }
        }
        newNode.parent = this; 
        children.push_back(newNode);

        memSpace += newNode.memSpace;
        Node *tempNode = this; 
        while(tempNode->parent != nullptr){
            tempNode->parent->memSpace += newNode.memSpace;
            tempNode = tempNode->parent;  
        }
    }
    void updateMemory(int writeMem){
        memSpace += writeMem; 

        Node *tempNode = this; 
        while(tempNode->parent != nullptr){
            tempNode->parent->memSpace += memSpace;
            tempNode = tempNode->parent;  
        }

    }
    
};

bool goIntoDir(Node& currentDir, std::string nameOfNewDir){
    // Change current dir to the new director 
    // Curent a blank Node if it doesnt exist already 

    // Return true if the directory already exists
    // Return false if the diretory needs to be created and populated 

    
    std::cout << "Step into "<< nameOfNewDir << std::endl;
    for(auto val : currentDir.children){
        if(val.name == nameOfNewDir){
            currentDir = val; 
            return false; 
        }
    }
    Node newCreatedDir = Node(nameOfNewDir);
    currentDir.insert(newCreatedDir);

    return true; 
}

void stepOutofDir(Node& currentDir){
    currentDir = *currentDir.parent; 
}

int main(){

    // Test Case One 
    /*
    Node parent = Node("a"); 
    parent.memSpace = 4; 
    Node child = Node("b");
    child.memSpace = 2;

    std::cout<<"Parent size is: " <<parent.memSpace<<std::endl; 

    parent.insert(&child);

    std::cout<<"Child name is: " <<child.name<<std::endl; 
    std::cout<<"Child parent is: " <<child.parent->name<<std::endl; 
    std::cout<<"Parent child is: " <<parent.children[0].name<<std::endl;
    std::cout<<"Parent size is: " <<parent.memSpace<<std::endl; 

    Node childOfChild = Node("c");
    childOfChild.memSpace = 6; 
    child.insert(&childOfChild);

    std::cout<<"Parent size is: " <<parent.memSpace<<std::endl; 
    std::cout<<"Child size is: " <<child.memSpace<<std::endl; 
    */
    std::string line; 
    std::ifstream input("Day-7-Input.txt");
    std::string firstInput, secondInput;

    std::getline(input, line);
    Node root = Node(line);
    Node* DirNode = &root;
    
    while (std::getline(input, line)) {
        
        if(line.find("ls") != std::string::npos){

        }else if(line[0] == '$'){
            if (line.find("cd ..") != std::string::npos) {
                DirNode = DirNode->parent; 
            }
            else if (line.find("cd") != std::string::npos){
                std::cout << "Step into "<< line.substr(line.find("cd")) << std::endl;
            
                Node newCreatedDir = Node(line.substr(line.find("cd")));
                newCreatedDir.parent = DirNode; 
                DirNode->children.push_back(newCreatedDir);
                //DirNode.insert(newCreatedDir);
                DirNode = &newCreatedDir;  
                // populateDir = goIntoDir(DirNode, line.substr(line.find("cd")));
            }
        }else{
            std::istringstream s(line);
            s >> firstInput >> secondInput;
            if(firstInput != "dir"){
                DirNode->updateMemory(std::stoi(firstInput));
                std::cout<<"New file of mem "<< std::stoi(firstInput) <<std::endl;
            }

        }
        
    }
    
}
