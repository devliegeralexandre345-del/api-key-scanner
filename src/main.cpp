#include <iostream>
#include <filesystem>
#include "scanner.h"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <directory_path>" << std::endl;
        return 1;
    }
    
    try {
        const auto directory = std::filesystem::path(argv[1]);
        if (!std::filesystem::exists(directory)) {
            std::cerr << "Directory does not exist: " << directory << std::endl;
            return 1;
        }
        
        Scanner scanner({".txt", ".log", ".md", ".py", ".js", ".json", ".yaml", ".yml", ".sh", ".conf", ".cfg", ".env"});
        scanner.scan_directory(directory);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}