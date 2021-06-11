
#ifndef REGEX_STREAM_GENERATOR_H
#define REGEX_STREAM_GENERATOR_H

#pragma once
#include "Node.h"

class Generator{

public: Generator(std::string const& expression, int counter);
public: Generator(std::string const& expression, std::string const& word);
public: Generator();

public: std::vector<std::string> Get_Generations();
private: std::vector<std::string> Generate(std::vector<std::vector<Node>> const& parse_tree);
private: std::vector<std::string> Child_Generate(std::vector<Node> const& nodes);

private:
    std::vector<std::vector<Node>> m_parse_tree;
    unsigned int amount;
    int _counter;
    int _mode;
    std::string _word;
    int finished = 0;

};


#endif 
