//
// Created by limbo on 2025/3/11.
//

#ifndef PTSD_LEGACY_OF_DEFENSE_PROLOGUE_BACKGROUNDPATHS_HPP
#define PTSD_LEGACY_OF_DEFENSE_PROLOGUE_BACKGROUNDPATHS_HPP
#include <vector>
#include <string>
#include "nlohmann/json.hpp"

namespace JsonDataStructures {

    struct BackgroundPaths {
        std::map<std::string, std::string> paths;
    };

    inline void to_json(nlohmann::json &j, const BackgroundPaths &bp) {
        j = nlohmann::json{{"backgrounds", bp.paths}};
    }

    inline void from_json(const nlohmann::json &j, BackgroundPaths &bp) {
        bp.paths = j.at("backgrounds").get<std::map<std::string, std::string>>();
    }

} // namespace JsonDataStructures

#endif //PTSD_LEGACY_OF_DEFENSE_PROLOGUE_BACKGROUNDPATHS_HPP
