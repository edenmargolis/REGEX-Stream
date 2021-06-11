
#ifndef REGEX_STREAM_PARSER_H
#define REGEX_STREAM_PARSER_H


#pragma once
#include <string>
#include <vector>
#include "Node.h"

class Parser{

    Parser() = delete;

public: static std::vector<std::vector<Node>> Parse(std::vector<std::string> const& tokens, unsigned int & amount);
private: static std::vector<std::vector<Node>> Build_Parse_Tree(std::vector<std::string>::const_iterator & it, std::vector<std::string>::const_iterator const& end, unsigned int & amount);
private: static Node Recursive_Build(std::vector<std::string>::const_iterator & it, int & total);

private: static bool Is_Word(std::string const& it);
};


#endif 
