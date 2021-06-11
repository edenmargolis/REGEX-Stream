#include "Generator.h"
#include <iostream>

std::string nth(int n, std::string regex){
    Generator* func = new Generator(regex,n * 2);
    std::vector<std::string> output = func->Get_Generations();
    return output.at(n - 1);

}

int find(std::string word, std::string regex){
    Generator* func = new Generator(regex,word);
    std::vector<std::string> output = func->Get_Generations();
    int count = 0;
    for(std::string curr : output){

        if(curr == word)
            return count + 1;
        count++;
    }
    return count;

}

int main() {
    std::string check = nth(3, "a*");
    std::cout<<check<<std::endl;
    std::cout<<find("aa", "a*")<<std::endl;
    return 0;
}
