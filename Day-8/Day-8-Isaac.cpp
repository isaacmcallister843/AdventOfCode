#include "Day-8-Isaac.hpp"


int main(){

    std::string line; 
    std::ifstream input("Day-8-Input.txt");

    std::getline(input, line);
    int numColumns = line.length(); 
    int numSeen = 0; 
    input.clear();
    input.seekg(0);

    std::vector<std::vector<std::pair<int,int>>> treeVector; 
    std::vector<std::pair<int,int>> blankField(numColumns); 
    for(int i = 0; i != (size(blankField)); i++){blankField[i] = std::pair<int, int>(-1,-1);}

    std::vector<std::pair<int,int>> startLine = blankField; 
    

    while (std::getline(input, line)) {
        std::vector<std::pair<int,int>> tempVec(numColumns+2); 
        tempVec[0] = std::pair<int,int> (-1, -1);
        tempVec[numColumns+1] = std::pair<int,int> (-1, -1);
        
        for(int i = 0; i!=line.length(); i++){
            
            int lineVal = (int)(line[i] - '0');
            tempVec[i+1].first =lineVal;

            if(lineVal > tempVec[0].first){
                tempVec[0].first = lineVal;
                tempVec[i+1].second = 1; 
                numSeen++;
                
            }

            if(lineVal > startLine[i].first){
                startLine[i].first = lineVal;
                if(tempVec[i+1].second != 1){
                    tempVec[i+1].second = 1; 
                    numSeen++;
                }
            }
        }

        // Check L to R 
        
        for(int i = (line.length()-1); i >= 0; i--){
            int lineVal = (int)(line[i] - '0');
            if(lineVal > tempVec[numColumns+1].first){
                tempVec[numColumns+1].first = lineVal;
                if(tempVec[i+1].second != 1){
                    tempVec[i+1].second = 1; 
                    numSeen++;
                }
                
            }
        }
        treeVector.push_back(tempVec);
    }

    std::vector<std::pair<int,int>> endLine = blankField; 

    for(int ii = size(treeVector)-1; ii >= 0; ii--){
        for(int jj = 1; jj != (numColumns+1); jj++){
            if(treeVector[ii][jj].first > endLine[jj].first){
                endLine[jj].first = treeVector[ii][jj].first; 
                if(treeVector[ii][jj].second != 1){
                    treeVector[ii][jj].second = 1; 
                    numSeen++;   
                }  
            }
        }
    }
    
    std::cout<<numSeen<<std::endl;
    // Part 2
    int bestHouse = 0; 

    for(int ii = 0; ii != size(treeVector); ii++){

        // Column Iterator
        for(int jj = 1; jj != (numColumns+1); jj++){

            int topSearchScore = 0; 
            int searchVal = ii-1; 
            while(searchVal >= 0){
                topSearchScore++; 
                if(treeVector[searchVal][jj].first < treeVector[ii][jj].first){
                    searchVal--; 
                }
                else{
                    break; 
                } 
            }
            int bottomSearchScore = 0; 
            int searchVal_ = ii+1; 

            while(searchVal_ <= (size(treeVector)-1)){
                bottomSearchScore++; 
                if(treeVector[searchVal_][jj].first < treeVector[ii][jj].first){
                    searchVal_++; 
                }
                else{
                    break; 
                } 
            }
            int leftSearchScore = 0; 
            int searchVal__ = jj-1; 

            while(searchVal__ >= 1){
                leftSearchScore++; 
                if(treeVector[ii][searchVal__].first < treeVector[ii][jj].first){
                    searchVal__--; 
                }
                else{
                    break; 
                } 
            }

            int rightSearchScore = 0; 
            int searchVal___ = jj+1; 

            while(searchVal___ <= (numColumns)){
                rightSearchScore++; 
                if(treeVector[ii][searchVal___].first < treeVector[ii][jj].first){
                    searchVal___++; 
                }
                else{
                    break; 
                } 
            }
            int totalScore = topSearchScore * bottomSearchScore * leftSearchScore * rightSearchScore;
            
            if(totalScore > bestHouse){
                bestHouse = totalScore; 
                std::cout<<topSearchScore <<  " : " << bottomSearchScore << " : "<<leftSearchScore <<" : " << rightSearchScore << " : " << totalScore << std::endl;
            }
        }
    }
    std::cout<<bestHouse<<std::endl;

}
