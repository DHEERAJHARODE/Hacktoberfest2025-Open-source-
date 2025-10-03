// Single-header JSON: https://github.com/nlohmann/json
#include <nlohmann/json.hpp>
#include <optional>
#include <string>
#include <tuple>
#include <algorithm>

using json = nlohmann::json;

// --- Stub helpers (replace with your real implementations) ---
std::optional<std::string> extract_domain_from_url(const std::string& url) {
    // minimal demo: pull host between "://" and next '/'.
    auto pos = url.find("://");
    if (pos == std::string::npos) return std::nullopt;
    auto start = pos + 3;
    auto slash = url.find('/', start);
    return url.substr(start, slash == std::string::npos ? std::string::npos : slash - start);
}
std::optional<std::string> get_network_name(const std::optional<std::string>& domain) {
    if (!domain) return std::nullopt;
    std::string d = *domain;
    std::transform(d.begin(), d.end(), d.begin(), ::tolower);
    if (d.find("github") != std::string::npos) return "GitHub";
    if (d.find("twitter") != std::string::npos || d == "x.com") return "Twitter";
    if (d.find("linkedin") != std::string::npos) return "LinkedIn";
    return std::nullopt;
}
std::optional<std::string> extract_username_from_url(const std::string& url,
                                                     const std::optional<std::string>& domain) {
    if (!domain) return std::nullopt;
    auto host_pos = url.find(*domain);
    if (host_pos == std::string::npos) return std::nullopt;
    auto path_start = url.find('/', host_pos + domain->size());
    if (path_start == std::string::npos) return std::nullopt;
    auto path = url.substr(path_start + 1);
    if (path.empty()) return std::nullopt;
    // take first segment
    auto next = path.find('/');
    auto user = path.substr(0, next);
    // strip leading '@'
    if (!user.empty() && user[0] == '@') user.erase(0, 1);
    return user.empty() ? std::nullopt : std::optional<std::string>(user);
}
// -------------------------------------------------------------

static std::pair<std::optional<std::string>, std::optional<std::string>>
safe_extract(const std::string& url) {
    try {
        auto domain = extract_domain_from_url(url);
        auto network = get_network_name(domain);
        auto username = extract_username_from_url(url, domain);
        return {network, username};
    } catch (...) {
        return {std::nullopt, std::nullopt};
    }
}

json transform_basics(const json& basics_data) {
    if (!basics_data.is_object()) return basics_data;

    json result = basics_data; // copy
    const json* profiles = basics_data.contains("profiles") ? &basics_data["profiles"] : nullptr;
    if (!profiles || !profiles->is_array()) return result;

    json out_profiles = json::array();
    for (const auto& profile : *profiles) {
        if (!profile.is_object()) { out_profiles.push_back(profile); continue; }
        json p = profile; // copy

        const std::string url = p.value("url", "");
        const bool network_missing = !p.contains("network") || p["network"].is_null() || p["network"].get<std::string>().empty();
        const bool username_missing = !p.contains("username") || p["username"].is_null() || p["username"].get<std::string>().empty();

        if (!url.empty() && (network_missing || username_missing)) {
            auto [network, username] = safe_extract(url);
            if (network_missing && network)  p["network"]  = *network;
            if (username_missing && username) p["username"] = *username;
        }
        out_profiles.push_back(std::move(p));
    }

    result["profiles"] = std::move(out_profiles);
    return result;
}

// ---------------- Demo ----------------
#include <iostream>
int main() {
    json basics = {
        {"name", "Alice"},
        {"profiles", json::array({
            json{{"url","https://github.com/alice"}, {"username",""}},      // fills network+username
            json{{"url","https://www.linkedin.com/in/alice/"}},             // fills network+username
            json{{"network","Twitter"}, {"url","https://twitter.com/@alice"}} // fills username only
        })}
    };

    json transformed = transform_basics(basics);
    std::cout << transformed.dump(2) << "\n";
}
