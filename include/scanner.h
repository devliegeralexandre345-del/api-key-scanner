#pragma once
#include <string>
#include <vector>
#include <filesystem>
#include "regex_patterns.h"

class Scanner {
public:
    explicit Scanner(const std::vector<std::string>& file_extensions);
    
    void scan_directory(const std::filesystem::path& directory_path);
    void scan_file(const std::filesystem::path& file_path);
    
private:
    std::vector<std::string> file_extensions_;
    RegexPatterns regex_patterns_;
    
    bool is_valid_extension(const std::filesystem::path& path) const;
    void process_line(const std::string& line, size_t line_number, const std::filesystem::path& file_path);
};