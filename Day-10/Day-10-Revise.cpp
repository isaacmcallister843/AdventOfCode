#include "Day-10-Isaac.hpp"

class VM{
    public:
        int clockCycle = 1; 
        int registerVal = 1; 
        int cyclesForExicution;
        int updateRegister;
        char screen[6][40]; 
        
        void initializedScreen(){
            for(int i = 0; i < 6; i++){
                for(int j =0; j<40; j++){
                    screen[i][j] = '.';
                }
            }
            
        }

        void runCommands(std::vector<std::string> commands){

            int currentCommandIndex = 0; 
           
            int currentLine = 0;
            int lowerBound = registerVal - 1; 
            int upperBound = registerVal + 1; 
            std::string currentString = ""; 

            while(currentCommandIndex < size(commands)){
                // Read the command 
                std::string currentCommand = commands[currentCommandIndex];    

                if(currentCommand == "noop"){
                    updateRegister = 0; 
                    cyclesForExicution = 1; 
                }
                
                if(currentCommand.find("addx") != std::string::npos){
                    std::istringstream s(currentCommand);
                    std::string _, val; 
                    s >> _ >> val;
                    updateRegister =  std::stoi(val); 
                    cyclesForExicution = 2; 
                    
                }   

                // -------- Begin the cycle
                
                while(cyclesForExicution > 0){

                    // -------- Start Cycle 
                    std::cout << "Start of cycle: " << clockCycle << " : Register is: " << registerVal << std::endl; 

                    // -------- During Cycle
                    // Write to screen 
                    if((lowerBound<=(clockCycle-1)) && ((clockCycle-1)<=upperBound)){
                        screen[currentLine][clockCycle-1] = '#'; 
                        currentString += "#";
                        //displayScreen();
                    }
                    else{
                        currentString += ".";
                    }
                    // Display Screen 
                    std::cout << "Current String: " << std::endl; 
                    for(auto c : currentString){
                        std::cout << c; 
                    } 
                    std::cout << " " << std::endl; 
                    
                    // * Not sure about this being here
                    if(clockCycle > 40){
                        clockCycle = 1; 
                        currentLine++;
                    }

                    // -------- End Cycle
                    
                    // Update the register value at the end of the cycle 
                    cyclesForExicution--;
                    clockTick();

                    if(cyclesForExicution == 0){
                        registerVal += updateRegister;
                    }

                    // Update the pixel position based on the register
                    lowerBound = registerVal - 1; 
                    upperBound = registerVal + 1; 
                    for(int i = 0; i<40; i++){
                        if((lowerBound <= i) && (i <= upperBound)){
                            std::cout<<"#"; 
                        }
                        else{
                            std::cout<<".";
                        }
                    }
                    std::cout << " " << std::endl; 
                    
                    
                    // Move onto the next command 
                    
                }
                // Move onto the next command 
                currentCommandIndex++;
            }
        }

        void displayScreen(){
            for(int i = 0; i < 6; i++){
                for(int j =0; j<40; j++){
                    std::cout<<screen[i][j];
                }
                std::cout << " " << std::endl; 
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
    //std::cout<<20*myVm.freqMap[20] + 60*myVm.freqMap[60] + 100*myVm.freqMap[100] + 140*myVm.freqMap[140] + 180*myVm.freqMap[180] + 220*myVm.freqMap[220]<<std::endl;
    
    
    myVm.displayScreen();
   
}

