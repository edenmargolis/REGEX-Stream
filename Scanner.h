
#ifndef REGEX_STREAM_SCANNER_H
#define REGEX_STREAM_SCANNER_H


#pragma once
#include <vector>
#include <string>

class Scanner{

public: Scanner() = delete;
public: static std::vector<std::string> Scan(std::string const& expression);

};


#endif 
