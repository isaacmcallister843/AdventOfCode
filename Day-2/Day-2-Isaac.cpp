#include "Day-2-Isaac.hpp"

int scoreFromRPS(std::string youInput, std::string opponentInput){
    if(youInput == opponentInput){
        return 3; 
    }

    if((youInput=="R") & (opponentInput == "S")){
        return 6; 
    }
    if((youInput=="P") & (opponentInput == "R")){
        return 6;
    }
    if((youInput=="S") & (opponentInput == "P")){
        return 6;
    }

    return 0; 
}

int main(){
    std::ifstream input("Day-2-Input.txt");
    std::string line;

    // Part 1
    int totalScore = 0; 

    std::map<std::string, std::string> Opponent;
    Opponent.insert(std::pair<std::string, std::string>("A", "R")); 
    Opponent.insert(std::pair<std::string, std::string>("B", "P")); 
    Opponent.insert(std::pair<std::string, std::string>("C", "S")); 

    std::map<std::string, std::string> You;
    You.insert(std::pair<std::string, std::string>("X", "R")); 
    You.insert(std::pair<std::string, std::string>("Y", "P")); 
    You.insert(std::pair<std::string, std::string>("Z", "S")); 

    std::map<std::string, int> scroreFromPlay;
    scroreFromPlay.insert(std::pair<std::string, int>("R", 1)); 
    scroreFromPlay.insert(std::pair<std::string, int>("P", 2)); 
    scroreFromPlay.insert(std::pair<std::string, int>("S", 3)); 
    
    
    while (std::getline(input, line)) {
        std::istringstream ss(line);
        std::string Opponent_Pick, You_Pick;
        ss >> Opponent_Pick >> You_Pick;

        std::string inputYou = You[You_Pick];
        std::string inputOpponent = Opponent[Opponent_Pick];
        
        int score = scoreFromRPS(inputYou, inputOpponent) + scroreFromPlay[inputYou];
        totalScore+=score; 

    }

    std::cout<<"Part 1: "<<totalScore<<std::endl; 

    // Part 2 
    std::ifstream input_1("Day-2-Input.txt");
    std::string line_1;
    std::string youPlay;
    totalScore=0;
    
    std::map<std::string, std::string> RPS_General;
    RPS_General.insert(std::pair<std::string, std::string>("RW", "P")); 
    RPS_General.insert(std::pair<std::string, std::string>("RL", "S"));
    RPS_General.insert(std::pair<std::string, std::string>("PW", "S")); 
    RPS_General.insert(std::pair<std::string, std::string>("PL", "R")); 
    RPS_General.insert(std::pair<std::string, std::string>("SL", "P")); 
    RPS_General.insert(std::pair<std::string, std::string>("SW", "R")); 

    std::map<std::string, std::string> NeededOutcome;
    NeededOutcome.insert(std::pair<std::string, std::string>("X", "L")); 
    NeededOutcome.insert(std::pair<std::string, std::string>("Y", "D")); 
    NeededOutcome.insert(std::pair<std::string, std::string>("Z", "W")); 
    
    while (std::getline(input_1, line_1)) {

        std::istringstream ss(line_1);
        std::string Opponent_Pick, Outcome;
        ss >> Opponent_Pick >> Outcome;

        std::string outComeInput = NeededOutcome[Outcome];
        std::string inputOpponent = Opponent[Opponent_Pick];

        if(outComeInput=="D"){
            youPlay = inputOpponent;
        }
        else{
            youPlay = RPS_General[inputOpponent + outComeInput];
            
        }

        int score = scoreFromRPS(youPlay, inputOpponent) + scroreFromPlay[youPlay];
    
        totalScore+=score; 
    }

    std::cout<< "Part 2: " <<totalScore<<std::endl; 

}
