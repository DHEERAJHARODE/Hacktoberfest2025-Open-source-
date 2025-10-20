#include <iostream>
#include <regex>
#include <string>

bool isValidEmail(const std::string& email) {
    // Basic regex for email validation
    const std::regex pattern(R"(^[a-zA-Z0-9_.+-]+@[a-zA-Z0-9-]+\.[a-zA-Z0-9-.]+$)");
    return std::regex_match(email, pattern);
}

int main() {
    std::string email;
    std::cout << "Enter an email address to check: ";
    std::getline(std::cin, email);

    if (isValidEmail(email)) {
        std::cout << "✅ Valid email address.\n";
    } else {
        std::cout << "❌ Invalid email address.\n";
    }

    return 0;
}