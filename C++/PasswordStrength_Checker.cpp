bool isStrongPassword(const std::string& password) {
    return password.length() >= 8 &&
           std::regex_search(password, std::regex("[A-Z]")) &&
           std::regex_search(password, std::regex("[a-z]")) &&
           std::regex_search(password, std::regex("[0-9]")) &&
           std::regex_search(password, std::regex("[^A-Za-z0-9]"));
}