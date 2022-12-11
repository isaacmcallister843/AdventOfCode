#include "Day-9-Isaac.hpp"

#define SIZE 15
#define lengthofRope 10

void dispGraph(unsigned int input[SIZE][SIZE]){
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            std::cout << " ";
            if(input[i][j] == 0){
                std:: cout << "-" ;
            }
            else{
                std::cout << 1;
            }
            
            std::cout << " "; 
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

    // each pair now holds the x and y coordinate of its position 
    
    std::pair<int, int> H_and_T_pos[lengthofRope];

    for(int i = 0; i<lengthofRope; i++){
        H_and_T_pos[i] = std::pair<int, int> (SIZE/2, SIZE/2);
    }
 
    field[H_and_T_pos[0].first][H_and_T_pos[0].second] = 1; 

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
            H_and_T_pos[0].first += freqMap[dir].first;
            H_and_T_pos[0].second  += freqMap[dir].second;
            unitsCount--; 
            //std::cout << "--Head Moved--" << std::endl;

            //dispGraph(field);

            // Tail Movement 
            for(int i=1; i<lengthofRope; i++){

                int deltaY = H_and_T_pos[i].first - H_and_T_pos[i-1].first;
                int deltaX = H_and_T_pos[i].second - H_and_T_pos[i-1].second;

                // Simple x and y correction 

                if(abs(deltaX) > 1){
                    
                    H_and_T_pos[i].second += -1*getSign(deltaX);
                    if(deltaY != 0){
                        H_and_T_pos[i].first = H_and_T_pos[i-1].first;
                    }
        
                }
                if(abs(deltaY) > 1){
                    H_and_T_pos[i].first += -1*getSign(deltaY);
                    if(deltaX != 0){
                        H_and_T_pos[i].second = H_and_T_pos[i-1].second;
                    }

                    
                }
                
                std::cout << " " << std::endl;

                field[H_and_T_pos[i].first][H_and_T_pos[i].second] = 1; 
                //std::cout<<lineCounter <<": Head Pos " <<  H_and_T_pos[0].first <<" : "<<H_and_T_pos[0].second << std::endl; 

                    
            }
            dispGraph(field);
            
            //std::cout << "--Tail Moved--" << std::endl;
            //dispGraph(field);
        }
    }
    dispGraph(field);
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


