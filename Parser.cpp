
#include "Parser.h"


bool Parser::Is_Word(std::string const& it){
    return (it != "(" && it != "|" && it != ")");
}
Node Parser::Recursive_Build(std::vector<std::string>::const_iterator & it, int & total){

    Node sub_root("",true);
    std::vector<Node> root;

    std::vector<std::vector<int>> multiplies;
    std::vector<int> adds;
    int sub_amount = 1;

    while(*it != ")"){

        if(Is_Word(*it)){
            root.push_back(Node(*it));
        }

        else if (*it == "("){
            ++it;
            root.push_back(Recursive_Build(it,sub_amount));

        }

        else{
            sub_root.children.push_back(root);
            root.clear();

            adds.push_back(sub_amount);
            sub_amount = 1;
        }

        ++it;
    }

    if (!root.empty()){
        sub_root.children.push_back(root);

        adds.push_back(sub_amount);
    }
    if (!adds.empty()){
        multiplies.push_back(adds);
    }
    int or_count = 0;
    for (auto const& it: multiplies){
        for (auto const& it2: it){
            or_count+=it2;
        }

        if (or_count > 0){
            total*=or_count;
        }
        or_count = 0;
    }

    return sub_root;
}
std::vector<std::vector<Node>> Parser::Build_Parse_Tree(std::vector<std::string>::const_iterator & it, std::vector<std::string>::const_iterator const& end, unsigned int & amount){

    std::vector<std::vector<Node>> full_root;
    std::vector<Node> root;

    std::vector<int> adds;
    int sub_amount = 1;
    int total = 0;

    while (it != end){

        if(Is_Word(*it)){
            root.push_back(Node(*it));
        }
        else if (*it == "("){
            ++it;
            root.push_back(Recursive_Build(it,sub_amount));

        }
        else{
            full_root.push_back(root);
            root.clear();

            adds.push_back(sub_amount);
            sub_amount = 1;
        }

        ++it;
    }

    if (!root.empty()){
        full_root.push_back(root);
        adds.push_back(sub_amount);
        sub_amount = 1;
    }

    for (auto const& it: adds){ total+=it; }

    amount = total;

    return full_root;
}
std::vector<std::vector<Node>> Parser::Parse(std::vector<std::string> const& tokens, unsigned int & amount){

    auto it = tokens.cbegin();
    auto end = tokens.cend();
    auto parse_tree = Build_Parse_Tree(it,end,amount);
    return parse_tree;
}
