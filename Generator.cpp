
#include <iostream>
#include "Generator.h"
#include "Scanner.h"
#include "Parser.h"

Generator::Generator(std::string const& expression, int counter){
    auto tokens = Scanner::Scan(expression);
    m_parse_tree = Parser::Parse(tokens,amount);
    _counter = counter;
    _mode = 0;
}

Generator::Generator(std::string const& expression, std::string const& word){
    auto tokens = Scanner::Scan(expression);
    m_parse_tree = Parser::Parse(tokens,amount);
    _counter = 100000;
    _mode = 1;
    _word = word;
}

Generator::Generator(){}

std::vector<std::string> Generator::Get_Generations(){
    return Generate(m_parse_tree);
}
std::vector<std::string> Generator::Generate(std::vector<std::vector<Node>> const& parse_tree){
    std::vector<std::string> results;
    std::vector<std::string> more;

    for (auto it: parse_tree){
        more = Child_Generate(it);

        results.insert(results.end(), more.begin(), more.end());
        if(_mode == 1 && results.at(results.size() - 1) == _word){
            finished = 1;
            return results;
        }

        _counter--;
        if(_counter < 0 && _mode == 0)
            break;

    }

    return results;
}

std::vector<std::string> Generator::Child_Generate(std::vector<Node> const& nodes){
    std::vector<std::string> results;
    std::vector<std::string> more;
    std::vector<std::string> new_results;

    results.push_back("");
    for (auto it: nodes){

        if (!it.more){
            if(it.value[it.value.size() - 1] == '*' || it.value[it.value.size() - 1] == '+'){
                int mult = 0;
                if(it.value[it.value.size() - 1] == '+')
                    mult = 1;
                while(_counter > 0){
                    if(finished == 1)
                        break;
                    std::string without_star = it.value.substr(0, it.value.size() - 1);
                    std::string temp = "";
                    for (int i = 0; i < mult; i++) {
                        temp += without_star;
                    }
                    for (auto r: results){
                        new_results.push_back(r+temp);
                        if(_mode == 1 && r + temp == _word){
                            finished = 1;
                            break;
                        }

                    }
                    if(_mode == 0)
                        _counter--;
                    mult++;
                }
                results = new_results;

            }else{
                for (auto & result: results){
                    result+=it.value;
                }
            }


        }
        else{

            more = Generate(it.children);
            for (auto m: more){
                for (auto r: results){
                    new_results.push_back(r+m);
                }

            }

            more.clear();
            results = new_results;
            new_results.clear();
            if(finished == 1)
                return results;

        }

    }

    return results;
}
