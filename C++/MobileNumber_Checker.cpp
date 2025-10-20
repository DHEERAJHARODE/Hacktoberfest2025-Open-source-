bool isValidPhone(const std::string& phone) {
    std::regex pattern(R"(^(\+91)?[6-9]\d{9}$)");
    return std::regex_match(phone, pattern);
}