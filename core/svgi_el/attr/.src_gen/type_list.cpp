#include <string>
#include <vector>
#include <sstream>
#include <memory>
#include <iostream>
#include <fstream>
#include <regex>
#include <set>
#include <iomanip>
#include <filesystem>
#include "../../../json.hpp"

std::string out_dir = "../../../.attr_def";
std::string json_dir = "../../../.svg_def";

using json = nlohmann::json;
namespace fs = std::filesystem;

std::set<std::string> tset;
std::set<std::string> cset;
std::set<std::string> pset;

void get_class(const std::string &path) {
    fs::path p(path);
    if (p.extension() != ".json" && p.extension() != "._json") return;
    std::ifstream i(path);
    json j; i >> j;

    for (auto i : j["attributes"]) {
        std::stringstream ss;
        ss << i["type"];
        auto g = std::regex_replace(ss.str(), std::regex("\\s"), "");
        tset.insert(g);
    }
}

int main(int argc, char **argv) {
    std::vector<std::string> tags;
    for (const auto &file : fs::directory_iterator(json_dir)) {
        get_class(file.path());
    }
    for (auto &s : tset) {
        auto g = std::regex_replace(s, std::regex("\\)\\("), "|");
        g = std::regex_replace(g, std::regex("\\("), "");
        g = std::regex_replace(g, std::regex("\""), "");
        g = std::regex_replace(g, std::regex("\\)"), "");
        std::stringstream ss(g);
        while(ss.good()) {
            std::string substr;
            getline(ss, substr, '|');
            if (substr[0] == '<') cset.insert(substr);
            else pset.insert(substr);
        }
    }

    for (auto &s : cset) std::cout << s << std::endl;
    std::stringstream ss;
    for (auto &s : pset) ss << s << std::endl;
    std::cout << ss.str();
    std::ofstream o1(out_dir + "/constant");
    o1 << ss.str();
}

// Tuple
// Enumerate
// Basic Type
    // Constant
    // Content Type