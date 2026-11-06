#include <fstream>
#include <iostream>
#include <algorithm>
#include "scanner.h"

Scanner::Scanner(const std::vector<std::string>& file_extensions)
    : file_extensions_(file_extensions) {}

void Scanner::scan_directory(const std::filesystem::path& directory_path) {
    for (const auto& entry : std::filesystem::recursive_directory_iterator(directory_path)) {
        if (entry.is_regular_file() && is_valid_extension(entry.path())) {
            scan_file(entry.path());
        }
    }
}

void Scanner::scan_file(const std::filesystem::path& file_path) {
    std::ifstream file(file_path);
    if (!file.is_open()) {
        return;
    }
    
    std::string line;
    size_t line_number = 0;
    while (std::getline(file, line)) {
        ++line_number;
        process_line(line, line_number, file_path);
    }
}

bool Scanner::is_valid_extension(const std::filesystem::path& path) const {
    const auto extension = path.extension().string();
    return std::find(file_extensions_.begin(), file_extensions_.end(), extension) != file_extensions_.end();
}

void Scanner::process_line(const std::string& line, size_t line_number, const std::filesystem::path& file_path) {
    for (const auto& [pattern_name, pattern] : regex_patterns_.get_patterns()) {
        std::smatch matches;
        if (std::regex_search(line, matches, pattern)) {
            std::cout << "Found potential \"" << pattern_name << "\" in file: " 
                      << file_path.string() << " at line " << line_number << std::endl;
            for (const auto& match : matches) {
                if (!match.str().empty()) { // Avoid empty matches
                    std::cout << "  Matched value: \"" << match.str() << "\"" << std::endl;
                }
            }
        }
    }
}