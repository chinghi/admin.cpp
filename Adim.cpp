#include <iostream>
#include <unordered_map>
#include <cstdlib> // For generating random passwords

// Predefined admin credentials
const std::string adminUsername = "admin";
const std::string adminPassword = "admin_password";

// Database to store user information
std::unordered_map<std::string, std::string> members = {
    {"user1", "user1_password"},
    {"user2", "user2_password"},
    // Add more members as needed
};

// Function to generate a random secure password
std::string generateSecurePassword() {
    // Implement your secure password generation logic here
    // This could involve using a library or your own method
    // For simplicity, let's generate a random password of length 8
    const std::string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    const int passwordLength = 8;

    std::string newPassword;
    for (int i = 0; i < passwordLength; ++i) {
        newPassword += characters[rand() % characters.length()];
    }

    return newPassword;
}

int main() {
    srand(static_cast<unsigned>(time(nullptr))); // Seed for random number generation

    // Admin login
    std::string enteredUsername, enteredPassword;
    std::cout << "Enter username: ";
    std::cin >> enteredUsername;
    std::cout << "Enter password: ";
    std::cin >> enteredPassword;

    if (enteredUsername == adminUsername && enteredPassword == adminPassword) {
        // Admin logged in successfully
        std::cout << "Admin logged in successfully.\n";

        // Member password reset
        std::string memberUsername;
        std::cout << "Enter member username to reset password: ";
        std::cin >> memberUsername;

        auto it = members.find(memberUsername);
        if (it != members.end()) {
            // Generate a new password for the member
            std::string newPassword = generateSecurePassword();

            // Update the member's password in the database
            it->second = newPassword;

            std::cout << "Password for " << memberUsername << " reset successfully. New password: " << newPassword << "\n";
        } else {
            std::cout << "Member not found.\n";
        }
    } else {
        std::cout << "Invalid admin credentials.\n";
    }

    return 0;
}
