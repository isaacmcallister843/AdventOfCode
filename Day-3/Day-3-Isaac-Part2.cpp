#include "Day-3-Isaac.hpp"

// std::set<std::string>

std::set<char> convertToSet(std::string stringToConvert){
    std::set<char> outputSet; 
    for(char c: stringToConvert){outputSet.insert(c);}
    return outputSet;
}

std::set<char> GetAllCommonValues(std::string firstString, std::string secondString, std::string thirdString){
    std::set<char> firstSet = convertToSet(firstString);
    std::set<char> secondSet = convertToSet(secondString);
    std::set<char> thirdSet = convertToSet(thirdString);
    
    std::set<char> firstIntersection;  
    std::set<char> secondIntersection;

    std::set_intersection(begin(firstSet), end(firstSet), begin(secondSet), end(secondSet), inserter(firstIntersection, end(firstIntersection)));
    std::set_intersection(begin(firstIntersection), end(firstIntersection), begin(thirdSet), end(thirdSet), inserter(secondIntersection, end(secondIntersection)));

    return secondIntersection;
   
}


int main(){
    

    std::string line;
    std::ifstream input("Day-3-Input.txt");
    std::string firstItems, secondItems, thirdItems;

    int priorityValue;
    int runningTotal = 0; 
    int lineCounter = 0; 
    
    while (std::getline(input, line)) {
        
        switch (lineCounter)
        {
            case 0:
                firstItems = line; 
                lineCounter++;
                break;
            case 1: 
                secondItems = line;
                lineCounter++; 
                break; 
            case 2: 
                thirdItems = line; 
                
                std::set<char> commonValues = GetAllCommonValues(firstItems, secondItems, thirdItems);
                
                std::set<char>::iterator location;  

                for(location=commonValues.begin(); location!=commonValues.end(); ++location){
                    
                    char commonValue_ = *location;
                    std::cout<<commonValue_<<std::endl;
                    int ASCII_Code = int(commonValue_);
                    if(ASCII_Code < 91){
                        priorityValue = ASCII_Code - 38;
                    }
                    else{
                        priorityValue = ASCII_Code - 96;
                    }
                    runningTotal += priorityValue;
                }
                lineCounter=0;

        }
        
            
    }
    
    std::cout<< "Part 2s: "<< runningTotal<<std::endl; 

}
