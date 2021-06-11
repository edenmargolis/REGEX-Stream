
#ifndef REGEX_STREAM_NODE_H
#define REGEX_STREAM_NODE_H


#pragma once
#include <string>
#include <vector>

class Node{

public:
    Node(std::string const& value_in = "", bool const& more_in = false);
    std::string value;
    bool more;
    std::vector<std::vector<Node>> children;

};


#endif 
