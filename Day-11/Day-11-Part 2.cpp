#include "Day-11-Isaac.hpp"

  

uint64_t  gcd(uint64_t  a, uint64_t  b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b); 
} 
  
uint64_t  findlcm(std::vector<uint64_t > arr, uint64_t  n) 
{ 
    // Initialize result 
    uint64_t  ans = arr[0]; 

    for (uint64_t  i = 1; i < n; i++) 
        ans = (((arr[i] * ans)) / 
                (gcd(arr[i], ans))); 
  
    return ans; 
} 

class Monkey{
    public:
        std::vector <uint64_t > items; 
        std::function<uint64_t (uint64_t , uint64_t )> op;
        uint64_t  genDiv; 

        uint64_t  operationVal; 
        uint64_t  divisorTest; 
        uint64_t  monkeyInpsectionCounter = 0; 

        std::vector<uint64_t > friendlyMonks;  

        void recieveItems(uint64_t  itemToRecieve){
            items.push_back(itemToRecieve);
        }

        void sendItems(uint64_t  itemToGIve, uint64_t  MonkeyName, std::vector<Monkey> &allMonks){
            allMonks[MonkeyName].items.push_back(itemToGIve);
        }

        uint64_t  inspectOperation(uint64_t  itemToInspect){
            if(operationVal == -100){
                return itemToInspect * itemToInspect; 
            }
            return op(itemToInspect, operationVal); 
        }

        uint64_t  getMonkeyToSend(uint64_t  value, std::vector<Monkey> &allMonks){
            if((value % divisorTest) == 0){
                return friendlyMonks[0];
            }
            else{
                return friendlyMonks[1];
            }
        }

        void inspectItems(std::vector<Monkey> &allMonks){
            while(size(items) > 0){
                uint64_t  inspectedValue = inspectOperation(items[0]) % (genDiv); 
                items.erase(items.begin());               
                uint64_t  monkeyNameToRecieve = getMonkeyToSend(inspectedValue, allMonks); 
                sendItems(inspectedValue, monkeyNameToRecieve, allMonks); 
                monkeyInpsectionCounter++; 
            }
        }
};

int  main(){

    std::string line; 
    std::ifstream input("Day-11-Input.txt");
    std::vector<Monkey> monks;
    Monkey* monkT = new Monkey();  
    std::vector<uint64_t > productOfAllDiv; 
    
    bool completeMonk = false; 

    while (std::getline(input, line)) {

        if(line.find("Starting items") != std::string::npos){
            std::cout << "Starting Items: "; 
            std::string lineSplit = line.substr((line.find(':')+1), -1);
            std::stringstream s(lineSplit); 
            std::string segment;
            std::vector<uint64_t > initItems; 
            while(std::getline(s, segment, ',')){
                initItems.push_back(std::stoi(segment));
            }
            monkT->items = initItems; 
        }
        else if(line.find("Operation") != std::string::npos){
            std::string lineSplit = line.substr((line.find("d")+1), -1);
            std::stringstream s(lineSplit);
            std::string op_val, valWOperator; 
            s >> op_val >> valWOperator; 

            if(valWOperator == "old"){
                monkT->operationVal = -100; 
            }
            else{
                if(op_val == "*"){
                    monkT->op = std::multiplies<uint64_t >();
                }
                else if(op_val == "+"){
                    monkT->op = std::plus<uint64_t >();
                }
                monkT->operationVal = std::stoi(valWOperator);
            }
            
        }
        else if(line.find("divisible") != std::string::npos){
            std::string lineSplit = line.substr((line.find("y")+1), -1);
            productOfAllDiv.push_back(std::stoi(lineSplit)); 
            monkT->divisorTest = std::stoi(lineSplit); 
        }
        else if(line.find("If true:")!= std::string::npos){
            std::string lineSplit_ = line.substr((line.find("y")+1), -1);
            monkT->friendlyMonks.push_back(std::stoi(lineSplit_)); 
        }
        else if(line.find("If false:")!= std::string::npos){
            std::string lineSplit__ = line.substr((line.find("y")+1), -1);
            monkT->friendlyMonks.push_back(std::stoi(lineSplit__)); 
            completeMonk = true; 
        }

        if(completeMonk){
            completeMonk = false;
            monks.push_back(*monkT); 
            free(monkT); 
            Monkey* monkT = new Monkey();  
        }
        
    }

    uint64_t  lcm = findlcm(productOfAllDiv, productOfAllDiv.size());

    for(uint64_t  i = 0; i < size(monks); i++){
            monks[i].genDiv = lcm;
    }

    for(uint64_t  j = 0; j<10000; j++){
        std::cout<<j<<std::endl; 
        for(uint64_t  i = 0; i < size(monks); i++){
            monks[i].inspectItems(monks);
        }
    }

    int largest = 0; 
    int secondLargest = 0; 

    for(uint64_t  i = 0; i < size(monks); i++){
        std::cout << i;
        for(auto c : monks[i].items){
            std::cout<<" "<<c; 
        }
        std::cout << " : "<< monks[i].monkeyInpsectionCounter;
        std::cout << " " << std::endl; 
        if(monks[i].monkeyInpsectionCounter > largest){
            secondLargest = largest; 
            largest = monks[i].monkeyInpsectionCounter;
        }
            
    }
    std::cout<<"Monkey Buisness: " << secondLargest << " " << largest << std::endl; 
}

