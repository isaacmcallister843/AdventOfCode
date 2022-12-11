#include "Day-9-Isaac.hpp"

#define SIZE 300
#define lengthofRope 10

void dispGraph(std::pair<std::string, int> input[SIZE][SIZE]){
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            std::cout << " " <<input[i][j].first[0] << input[i][j].first[1] << " "; 
        }
        std::cout<<std::endl; 
    }

}

int getSign(int x){
    if (x > 0) return 1;
    if (x < 0) return -1;
    return 0;
}

int main(){

    std::string line; 
    std::ifstream input("Day-9-Input.txt");

    // Information needed to store: 
    // Position of H and T 
    // If T has landed at least once 
    // 2D array of pairs, if T has landed at least once,
    // and string containing what currently lies in that pos 

    unsigned int field[SIZE][SIZE];
    for(int i =0; i!= SIZE; i++){
        for(int j =0; j!= SIZE; j++){
            field[i][j] = 0;
        }
    }
    // First is the position of the head, second is position of the tail
    // Store it seperate so we can easily access it 
    std::pair<std::pair<int, int>, std::pair<int, int>> H_and_T_pos;
    H_and_T_pos.first = std::pair<int, int> (SIZE/2, SIZE/2);
    H_and_T_pos.second = std::pair<int, int> (SIZE/2,SIZE/2); 
    field[H_and_T_pos.first.first][H_and_T_pos.first.second] = 1; 

    std::unordered_map<std::string, std::pair<int, int>> freqMap; 
    freqMap["R"] = std::pair<int, int> (0, 1);
    freqMap["L"] = std::pair<int, int> (0, -1);
    freqMap["U"] = std::pair<int, int> (-1, 0);
    freqMap["D"] = std::pair<int, int> (1, 0);

    // columns, rows 
    int lineCounter=0; 

    while (std::getline(input, line)) {
        lineCounter++;
        std::stringstream s(line);
        std::string dir, numUnits;
        s >> dir >> numUnits; 
        int unitsCount = std::stoi(numUnits);

        while(unitsCount > 0){
            // Head Movement Code
            H_and_T_pos.first.first += freqMap[dir].first;
            H_and_T_pos.first.second  += freqMap[dir].second;
            unitsCount--; 
            //std::cout << "--Head Moved--" << std::endl;

            //dispGraph(field);

            // Tail Movement 
            int deltaY = H_and_T_pos.second.first - H_and_T_pos.first.first;
            int deltaX = H_and_T_pos.second.second - H_and_T_pos.first.second;

            // Simple x and y correction 

            if(abs(deltaX) > 1){
                
                H_and_T_pos.second.second += -1*getSign(deltaX);
                if(deltaY != 0){
                    H_and_T_pos.second.first = H_and_T_pos.first.first;
                }
    
            }
            if(abs(deltaY) > 1){
                H_and_T_pos.second.first += -1*getSign(deltaY);
                if(deltaX != 0){
                    H_and_T_pos.second.second = H_and_T_pos.first.second;
                }

                
            }

            field[H_and_T_pos.second.first][H_and_T_pos.second.second] = 1; 
            std::cout<<lineCounter <<": Head Pos " <<  H_and_T_pos.first.first <<" : "<<H_and_T_pos.first.second << std::endl; 

            //std::cout << "--Tail Moved--" << std::endl;
            //dispGraph(field);
        }
    }
    int visitCounter = 0; 

    for(int i = 0; i<SIZE; ++i){
        for(int j =0; j<SIZE; ++j){
            if(field[i][j] == 1){
                visitCounter++; 
            }
        }
    }
    std::cout<<"Tail visted a total of "<< visitCounter <<std::endl; 
}


