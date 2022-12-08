#include "Day-7-Isaac.hpp"


int main(){

    std::string mainString; 
    std::string line; 
    std::ifstream input("Day-7-Input.txt");
    std::unordered_map<std::string, int> freqMap; 
    bool updateMem = false; 

    while (std::getline(input, line)) {
        
        if(line[0] == '$'){
            if(updateMem & (mainString != "-/")){
                std::string tempString = mainString.substr(0, mainString.find_last_of("-"));
                while(tempString != "-/"){
                    freqMap[tempString] += freqMap[mainString];
                    tempString = tempString.substr(0, tempString.find_last_of("-"));
                }
                updateMem= false; 
            }
            if(line.find("cd ..") != std::string::npos){
                mainString= mainString.substr(0, mainString.find_last_of("-1"));
            }
            else if(line.find("cd") != std::string::npos){
                mainString = mainString + "-" + line.substr(line.find("cd")+3,-1);
            }
            else if(line.find("ls") != std::string::npos){
                updateMem = true;
            }
        }
        else if(updateMem){
            std::istringstream s(line);
            std::string firstInput, secondInput;
            s >> firstInput >> secondInput;
            if(firstInput != "dir"){
                freqMap[mainString]+=std::stoi(firstInput); 
            }
        
        }
    }
   
    for (std::pair pairtest : freqMap ) {
        int counter = 0;
        for (auto c: pairtest.first){if (c == '-'){counter++; }}
        if(counter== 2){
            freqMap["-/"] += pairtest.second;
        }
    }
    
    // Part 1
    int returnSize = 0; 
    for ( const auto &pair : freqMap ) {
        if(pair.second <= 100000){
            returnSize += pair.second; 
        }
    }
    std::cout<<returnSize<<std::endl;

    // Part 2 
    int smallestDirectory = 30000000 - (70000000 - freqMap["-/"]);
    int smallestDirFound = 1000000000;

    for ( const auto &pair1 : freqMap ) {
        if((smallestDirectory < pair1.second ) & (pair1.second < smallestDirFound)){
            smallestDirFound = pair1.second;
            
        }
    }
    std::cout<<smallestDirFound<<std::endl;
}
