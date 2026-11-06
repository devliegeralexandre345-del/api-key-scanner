#include <iostream>
#include <fstream>
#include <filesystem>
#include "scanner.h"

int main() {
    // Création d'un fichier de test avec des clés potentielles
    std::ofstream test_file("test_file.txt");
    if (!test_file.is_open()) {
        std::cerr << "Failed to create test file" << std::endl;
        return 1;
    }
    
    test_file << "Some text with AKIAIOSFODNN7EXAMPLE in it\n";
    test_file << "Another line with AIzaSyBvOkB5hJx8K9L0M1N2O3P4Q5R6S7T8U9V0W1X2Y3Z4 in it\n";
    test_file.close();
    
    try {
        Scanner scanner({".txt", ".log", ".md", ".py", ".js", ".json", ".yaml", ".yml", ".sh", ".conf", ".cfg", ".env"});
        scanner.scan_file("test_file.txt");
    } catch (const std::exception& e) {
        std::cerr << "Error during test: " << e.what() << std::endl;
        return 1;
    }
    
    // Nettoyage
    if (std::filesystem::exists("test_file.txt")) {
        std::filesystem::remove("test_file.txt");
    }
    
    std::cout << "Test completed successfully." << std::endl;
    return 0;
}