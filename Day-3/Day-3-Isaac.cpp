#include "Day-3-Isaac.hpp"

// std::set<std::string>
std::set<char> GetAllCommonValues(std::string baseString, std::string stringToCompare){
    
    std::set<char> commonValues; 

    for(char& c:baseString){
        auto res = stringToCompare.find(c);
        if(res != std::string::npos){
            // Found 
            commonValues.insert(c);
        }
    }

    return commonValues;
}

int main(){
    

    // Split string to get the characters in each compartment 
    // Find the characters that both comparments have in common 
    // -- Iterate through every element in the string, see if its in the string its comparing too, if so add to a set 
    // -- For every value in that set find the priority
    // Convert that character to priority 
    // add to a rollin total of priority 

    std::string line;
    std::ifstream input("Day-3-Input.txt");
    int priorityValue;
    int runningTotal = 0; 

    while (std::getline(input, line)) {

        std::string firstCompart = line.substr(0, line.length()/2);
        std::string secondCompart = line.substr(line.length()/2);

        std::set<char> compareValues = GetAllCommonValues(firstCompart, secondCompart);
        std::set<char>::iterator location;  

        for(location=compareValues.begin(); location!=compareValues.end(); ++location){
            char commonValue_ = *location;
            int ASCII_Code = int(commonValue_);
            if(ASCII_Code < 91){
                priorityValue = ASCII_Code - 38;
            }
            else{
                priorityValue = ASCII_Code - 96;
            }

            runningTotal += priorityValue;
        }
    }

    std::cout<< "Part 1: "<< runningTotal<<std::endl; 

    

}
