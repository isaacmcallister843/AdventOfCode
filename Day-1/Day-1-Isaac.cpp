#include "Day-1-Isaac.hpp"

int main(){

    int currentElfCalories = 0;
    std::string line;
    std::set<int> elfCal; 

    std::ifstream input("Day-1-Input.txt");

    while (std::getline(input, line)) {
        if(line==""){
            elfCal.insert(currentElfCalories);
            currentElfCalories=0;
        }
        else{
            currentElfCalories += std::stoi(line);
        }
    }

    elfCal.insert(currentElfCalories);

    std::cout<<"Exercise 1: " << *elfCal.rbegin() << std::endl;
    
    int three_sum = *(elfCal.rbegin()) + *(++elfCal.rbegin()) + *(++++elfCal.rbegin());
    std::cout<<"Exercise 2: " << three_sum << std::endl; 
}