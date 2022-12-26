#include "Day-12-Isaac.hpp"

  
int main(){

    std::string line; 
    std::ifstream input("Day-12-Input.txt");
    std::vector<std::vector<int>> data; 

    std::pair<int, int> startPos; 
    std::pair<int, int> endPos; 

    int iCor = 0; 
    int jCor = 0; 

    while (std::getline(input, line)) {
        jCor = 0; 
        std::vector<int> tempVec;
        for(char c: line){
            
            if(c == 'E'){
                endPos = std::make_pair(iCor, jCor); 
                tempVec.push_back(123);
            }
            else if (c=='S'){
                startPos = std::make_pair(iCor, jCor); 
                tempVec.push_back(96);
            }
            else{
                tempVec.push_back((int)c);
            }
            jCor++; 
            
        }
        data.push_back(tempVec);    
        iCor++;  
    }

    int moves = 0; 
    std::pair<int, int> currentPos = startPos;
    std::cout<<endPos.first << endPos.second << std::endl; 
    while (moves < 1000){
        
    }
    

    for(int i = 0; i < size(data); i++){
        for(int j = 0; j < size(data[0]); j++){
            if(data[i][j] < 100){
                std::cout<<data[i][j] << "  "; 
            }
            else{
                std::cout<<data[i][j] << " "; 
            }
            
        }
        std::cout << std::endl; 
    }
}

