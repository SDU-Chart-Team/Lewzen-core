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
#include "../../../.svg_def/json.hpp"

std::string out_dir = ".";
std::string json_dir = "../../../.svg_def";

using json = nlohmann::json;
namespace fs = std::filesystem;

std::set<std::string> tset;

void get_class(const std::string &path) {
    fs::path p(path);
    if (p.extension() != ".json") return;
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
    for (auto &s : tset) std::cout << s << std::endl;
}

// Tuple
// Enumerate
// Basic Type
    // Plain Text
    // Content Type