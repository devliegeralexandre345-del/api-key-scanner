#include <string>
#include <vector>
#include <regex>
#include "regex_patterns.h"

RegexPatterns::RegexPatterns() {
    patterns_ = {
        {"AWS Access Key ID", std::regex(R"(AKIA[0-9A-Z]{16})")},
        {"Google API Key", std::regex(R"(AIza[0-9A-Za-z\-_]{35})")},
        {"Slack Token", std::regex(R"(xox[baprs]-([0-9a-zA-Z]{10,48})?)")},
        {"GitHub Personal Access Token", std::regex(R"(ghp_[a-zA-Z0-9]{36})")},
        {"GitHub App Token", std::regex(R"(ghu_[a-zA-Z0-9]{36})")},
        {"GitHub Refresh Token", std::regex(R"(ghr_[a-zA-Z0-9]{77})")},
        {"Stripe API Key (Secret)", std::regex(R"(sk_(test|live)_[a-zA-Z0-9]{24})")},
        {"Stripe Public API Key", std::regex(R"(pk_(test|live)_[a-zA-Z0-9]{24})")},
        {"Heroku API Key", std::regex(R"(https://api.heroku.com/([\w\d]+))")},
        {"Mailgun API Key", std::regex(R"(key-[a-zA-Z0-9]{32})")}
    };
}

const std::vector<std::pair<std::string, std::regex>>& RegexPatterns::get_patterns() const {
    return patterns_;
}