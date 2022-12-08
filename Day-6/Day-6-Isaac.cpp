#include "Day-6-Isaac.hpp"

int main(){

    std::string line; 
    std::ifstream input("Day-6-Input.txt");
    std::vector<char> last4lines; 
    std::getline(input, line);
    int lineCounter;

    for(auto c: line){
        if((size(last4lines) == 14)){
            std::unordered_map<char, int> freqMap; 
            bool b=true;
            for(char d: last4lines){
                freqMap[d]++; 
                if(freqMap[d]>1){b=false; break;}
            }
            if(b){break;}
            last4lines.erase(last4lines.begin());
        }
        last4lines.push_back(c);
        lineCounter++;
    }
    std::cout<<lineCounter<<std::endl;
}
