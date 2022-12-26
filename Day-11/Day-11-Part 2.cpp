#include "Day-11-Isaac.hpp"

  

int gcd(int a, int b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b); 
} 
  
int findlcm(std::vector<int> arr, int n) 
{ 
    // Initialize result 
    int ans = arr[0]; 

    for (int i = 1; i < n; i++) 
        ans = (((arr[i] * ans)) / 
                (gcd(arr[i], ans))); 
  
    return ans; 
} 

class Monkey{
    public:
        std::vector <int> items; 
        std::function<int(int, int)> op;
        int genDiv; 

        int operationVal; 
        int divisorTest; 
        int monkeyInpsectionCounter = 0; 

        std::vector<int> friendlyMonks;  

        void recieveItems(int itemToRecieve){
            items.push_back(itemToRecieve);
        }

        void sendItems(int itemToGIve, int MonkeyName, std::vector<Monkey> &allMonks){
            allMonks[MonkeyName].items.push_back(itemToGIve);
            std::cout<< allMonks[MonkeyName].items[size(allMonks[MonkeyName].items)-1] << std::endl; 
        }

        int inspectOperation(int itemToInspect){
            if(operationVal == -100){
                return itemToInspect * itemToInspect; 
            }
            return op(itemToInspect, operationVal); 
        }

        int getMonkeyToSend(int value, std::vector<Monkey> &allMonks){
            if((value % divisorTest) == 0){
                std::cout << "Sending to Monk " << friendlyMonks[0] << std::endl; 
                return friendlyMonks[0];
            }
            else{
                std::cout << "Sending to Monk " << friendlyMonks[1] << std::endl; 
                return friendlyMonks[1];
            }
        }

        void inspectItems(std::vector<Monkey> &allMonks){
            while(size(items) > 0){
                std::cout << "Number of items in inventory: " << size(items) << std::endl; 
                int inspectedValue = inspectOperation(items[0]) % (genDiv); 
                items.erase(items.begin());               
                int monkeyNameToRecieve = getMonkeyToSend(inspectedValue, allMonks); 
                sendItems(inspectedValue, monkeyNameToRecieve, allMonks); 
                std::cout<< "--------" << std::endl;
                monkeyInpsectionCounter++; 
            }
        }
};

int main(){

    std::string line; 
    std::ifstream input("Day-11-Input.txt");
    std::vector<Monkey> monks;
    Monkey* monkT = new Monkey();  
    std::vector<int> productOfAllDiv; 
    
    bool completeMonk = false; 

    while (std::getline(input, line)) {

        if(line.find("Starting items") != std::string::npos){
            std::cout << "Starting Items: "; 
            std::string lineSplit = line.substr((line.find(':')+1), -1);
            std::stringstream s(lineSplit); 
            std::string segment;
            std::vector<int> initItems; 
            while(std::getline(s, segment, ',')){
                std::cout<<std::stoi(segment) << " "; 
                initItems.push_back(std::stoi(segment));
            }
            std::cout << "" << std::endl; 
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
                    monkT->op = std::multiplies<int>();
                }
                else if(op_val == "+"){
                    monkT->op = std::plus<int>();
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
            std::cout << "Divisor: " << monkT->divisorTest << " Opertional: " <<  monkT->operationVal << " Is Divisible: " << monkT->friendlyMonks[0];
            std::cout << " False: " << monkT->friendlyMonks[1] << std::endl; 
            free(monkT); 
            Monkey* monkT = new Monkey();  
        }
        
    }

    int lcm = findlcm(productOfAllDiv, productOfAllDiv.size());
    std::cout<<lcm<<std::endl;

    for(int i = 0; i < size(monks); i++){
            monks[i].genDiv = lcm;
    }

    for(int j = 0; j<20; j++){
        for(int i = 0; i < size(monks); i++){
            std::cout << i << " ---------" <<std::endl; 
            monks[i].inspectItems(monks);
        }

        for(int i = 0; i < size(monks); i++){
            std::cout << i;
            for(auto c : monks[i].items){
                std::cout<<" "<<c; 
            }
            std::cout << " : "<< monks[i].monkeyInpsectionCounter;
            std::cout << " " << std::endl; 
            
        }
    }
    
}

