
#include "Scanner.h"

std::vector<char> get_range(char start, char end){
    std::vector<char> res;
    for(int i = int(start);i <= int(end);i++) {
        res.push_back(char(i));
    }
    return res;
}

std::vector<std::string> Scanner::Scan(std::string const& expression){

    std::vector<std::string> tokens;
    std::string temp;

    for (int j = 0;j<expression.length();j++){

        char it = expression[j];
        if (it == '(') {
            tokens.push_back(temp);
            tokens.push_back("(");
            if (j + 2 < expression.length() && expression[j+2]== '-') {
                char start = expression[j+1];
                char end = expression[j+3];

                std::vector<char> res = get_range(start, end);
                int i;
                for (i = 0; i < res.size() - 1; i++) {
                    std::string s(1, res.at(i));
                    tokens.push_back(s);
                    tokens.push_back("|");
                }
                std::string s(1, res.at(i));
                tokens.push_back(s);
                j+=3;
            }

            temp.clear();

            }

        else if (it == '|'){
            tokens.push_back(temp);
            tokens.push_back("|");
            temp.clear();
        }
        else if (it == ')'){
            tokens.push_back(temp);

            if(expression[j+1] == '*' || expression[j+1] == '+'){
                //tokens.push_back(temp + "*");
                int i = tokens.size() - 1;
                while(tokens.at(i) != "("){
                    if(tokens.at(i) != "|"){
                        tokens.at(i) += expression[j + 1];
                    }
                    i--;
                }
                j++;
            }

            tokens.push_back(")");
            temp.clear();
        }

        else if (isalpha(it) || it == ' ' || it == '*' || it == '+'){
            temp+=it;
        }

    }

    tokens.push_back(temp);

    return tokens;
}
