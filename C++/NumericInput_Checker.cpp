bool isNumeric(const std::string& input) {
    return std::regex_match(input, std::regex("^[0-9]+$"));
}