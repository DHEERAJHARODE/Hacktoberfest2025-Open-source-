bool isValidDate(const std::string& date) {
    std::regex pattern(R"(^(0[1-9]|[12][0-9]|3[01])-(0[1-9]|1[0-2])-(\d{4})$)");
    return std::regex_match(date, pattern);
}