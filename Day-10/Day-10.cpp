#include "Day-10-Isaac.hpp"

class VM{
    public:
        int clockCycle = 1; 
        int registerVal = 1; 
        int internalCounter = 0;
        std::unordered_map<int, int> freqMap; 
        char screen[40*6]; 
        
        void initializedScreen(){
            std::fill_n(screen, 40*6, '.'); 
        }

        void runCommands(std::vector<std::string> commands){
            int currentCommandIndex = 0; 
            int spriteLowerBound = registerVal-1;
            int spriteUpperBound = registerVal+1;
            std::cout<< clockCycle << ": ";
            for(int j = 0; j < 40; j++){
                if((spriteLowerBound <= j) && (j <=spriteUpperBound)){
                    std::cout<<"#"; 
                }
                else{
                    std::cout<<"."; 
                }
                    
            }
            std::cout<< " " << std::endl;

            while(currentCommandIndex < size(commands)){
                
                std::string currentCommand = commands[currentCommandIndex]; 

                if(currentCommand == "noop"){
                    currentCommandIndex++;
                    
                }
                else if(currentCommand.find("addx") != std::string::npos){
                    internalCounter++;
                    if(internalCounter == 2){
                        std::istringstream s(currentCommand);
                        std::string _, val; 
                        s >> _ >> val;

                        registerVal += std::stoi(val); 
                        currentCommandIndex++;
                        internalCounter=0;
                    }

                }
            
                clockTick();
                // std::cout<<clockCycle << " : "<<registerVal << std::endl;
                if((registerVal > 0) && (registerVal< 40*6)){
                    spriteLowerBound = registerVal-1;
                    spriteUpperBound = registerVal+1;
                    std::cout<< clockCycle << ": ";
                    for(int j = 0; j < 40; j++){
                        if((spriteLowerBound <= j) && (j <=spriteUpperBound)){
                            std::cout<<"#"; 
                        }
                        else{
                            std::cout<<"."; 
                        }
                    }
                    
                    std::cout<<" " << std::endl; 
                    
                    if((spriteLowerBound<=clockCycle) && (clockCycle <=spriteUpperBound)){
                        screen[clockCycle-1] = '#';
                    }
                    
                }


                freqMap[clockCycle] = registerVal;   
            }
        }

        void displayScreen(){
            for(int i = 0; i < 240; i++){
                if((i % 40 == 0) && (i != 0)){
                    std::cout << "" << std::endl; 
                }
                std::cout << screen[i]; 
            }
        }

    private:
        void clockTick(){
            clockCycle++; 
        }
};

int main(){

    std::string line; 
    std::ifstream input("Day-10-Input.txt");
    std::vector<std::string> commands; 
    VM myVm; 
    myVm.initializedScreen();

    while (std::getline(input, line)) {
        commands.push_back(line);
    }

    myVm.runCommands(commands);
    
    std::cout<<myVm.registerVal<<std::endl; 
    std::cout<<myVm.clockCycle<<std::endl; 
    std::cout<<20*myVm.freqMap[20] + 60*myVm.freqMap[60] + 100*myVm.freqMap[100] + 140*myVm.freqMap[140] + 180*myVm.freqMap[180] + 220*myVm.freqMap[220]<<std::endl;
    
    
    myVm.displayScreen();
   
}

