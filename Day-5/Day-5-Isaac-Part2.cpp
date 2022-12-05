#include "Day-5-Isaac.hpp"

std::stack<char> reverseStack(std::stack<char> stackToReverse){
    std::stack<char> tempStack; 
    while(!stackToReverse.empty()){
        char t = stackToReverse.top();
        stackToReverse.pop();
        tempStack.push(t);
    }
    return tempStack; 

}

int main(){

    const int numColumns = 9; 
    std::stack<char> crates[numColumns];

    std::string line;
    std::ifstream input("Day-5-Input.txt");
    int counter=0; 

    // Initialze the stacks
    while (std::getline(input, line)) {
        if(line[1]=='1'){break;}
        std::vector<char> returnVec; 
        for(int i =1, j=0; i <= line.length(); i=i+4, j++){
            if(line[i] != ' '){
                crates[j].push(line[i]);
            }
            
        }
    }
    // Reverse all the stacks
    for(int i = 0; i<=numColumns;i++){crates[i] = reverseStack(crates[i]);}

    while (std::getline(input, line)) {
        if(!line.empty()){
            std::stringstream s(line);
            std::string _, numToMove, __, firstStack, ___, secondStack, moveString;
            s >> _>> numToMove>> __>> firstStack>> ___>> secondStack;
            
            for(int l = 0; l < std::stoi(numToMove); l++){
                char move = crates[std::stoi(firstStack)-1].top();  
                moveString = moveString + move; 
                if(crates[std::stoi(firstStack)-1].size() == 0){std::cout<<"ERROR"<<std::endl;}              
                crates[std::stoi(firstStack)-1].pop();
                
            }         
            //crates[std::stoi(secondStack)-1].push(moveString[i]);
            
            for(int i = moveString.size() - 1; i >= 0; i--){crates[std::stoi(secondStack)-1].push(moveString[i]);}
        }
    }
    
    for(std::stack<char> d:crates){
        std::cout<<d.top();
    }


    
} 
