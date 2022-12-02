#include <iostream> 
#include <fstream>
#include <string>
using namespace std; 

int main(){

    int currentElfNum = 1;
    int currentElfCalories, elfMaxCalories=0;
    int elfMaxCaloriesNum;

    std::ifstream input("Day-1-Input.txt");
    std::string line;

    while (std::getline(input, line)) {
        if(line==""){
            if(currentElfCalories>elfMaxCalories){
                elfMaxCalories = currentElfCalories;
                elfMaxCaloriesNum = currentElfNum;
            }
            currentElfCalories=0;
            currentElfNum++; 
        }
        else{
            currentElfCalories += std::stoi(line);
        }
    }
    std::cout<<"Elf With Most Calories: " << elfMaxCaloriesNum << " He has: " << elfMaxCalories <<std::endl;
}