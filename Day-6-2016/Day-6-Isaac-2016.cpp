#include "Day-6-Isaac.hpp"

void iDontKnowHowToExtendStructs(std::map<char, int> &charsinFistLine, int toInsert){
    bool needNewInsert = true; 
    for (auto const& pair : charsinFistLine) {
        auto key = pair.first;
        if(key == toInsert){
            charsinFistLine[key]++; 
            needNewInsert = false; 
            break;
        }
    }
    if(needNewInsert){
        charsinFistLine.insert(std::pair<int, int>(toInsert, 1));
    }
}

int main(){

    std::string line; 
    std::ifstream input("Day-6-Input.txt");
    std::map<char, int> maps[8]; 

    while (std::getline(input, line)) {
        for(int i =0; i<line.length();i++){
            iDontKnowHowToExtendStructs(maps[i], line[i]);
        }
    }

    // Part 1 
    for (auto map : maps) {
        int largestVal = 0 ; 
        char outputChar; 
        for(auto testPair : map){
            if(testPair.second > largestVal){
                largestVal = testPair.second;
                outputChar = testPair.first; 
            }

        }
        std::cout<<outputChar;
    }

    std::cout<<"   "<<std::endl; 

    // Part 2 

    for (auto map : maps) {
        int smallest = 10000000 ; 
        char outputChar; 
        for(auto testPair : map){
            if(testPair.second < smallest){
                smallest = testPair.second;
                outputChar = testPair.first; 
            }
        }
        std::cout<<outputChar;
    }
}
