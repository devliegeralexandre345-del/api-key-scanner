#pragma once
#include <vector>
#include <string>
#include <regex>

class RegexPatterns {
public:
    RegexPatterns();
    
    const std::vector<std::pair<std::string, std::regex>>& get_patterns() const;
    
private:
    std::vector<std::pair<std::string, std::regex>> patterns_;
};