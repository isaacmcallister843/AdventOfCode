#include "Day-4-Isaac.hpp"

bool checkOverlap(std::pair<int, int> X, std::pair<int, int> Y){
   if((X.first <= Y.second) && (Y.second <= X.second)){return true;}
   if((Y.first <= X.second) && (X.second <= Y.second)){return true;}
   return false; 
} 

int main(){
    
    std::string line;
    std::ifstream input("Day-4-Input.txt");
    int counter=0; 

    while (std::getline(input, line)) {

        std::string firstRange = line.substr(0, line.find(","));
        std::pair<int, int> firstRangePairs(std::stoi(firstRange.substr(0, firstRange.find("-"))), std::stoi(firstRange.substr(firstRange.find("-")+1, -1)));
        std::string secondRange = line.substr(line.find(",")+1, -1);
        std::pair<int, int> secondRangePairs(std::stoi(secondRange.substr(0, secondRange.find("-"))), std::stoi(secondRange.substr(secondRange.find("-")+1, -1)));

        if(checkOverlap(firstRangePairs, secondRangePairs)){counter++;}        
    }

    std::cout<<counter<<std::endl;

}
