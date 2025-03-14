//
// Created by limbo on 2025/3/11.
//
#include <string>
#include <nlohmann/json.hpp>
#include <fstream>
#include "Util/Logger.hpp"

using json = nlohmann::json;

#ifndef PTSD_LEGACY_OF_DEFENSE_PROLOGUE_ILOADABLEFROMJSON_HPP
#define PTSD_LEGACY_OF_DEFENSE_PROLOGUE_ILOADABLEFROMJSON_HPP
class ILoadableFromJson {
public:
    virtual ~ILoadableFromJson() = default;
    virtual void LoadJson(const std::string& filePath) = 0;

protected:
    /**
 * @brief Loads JSON data from a file.
 * @param filePath Path to the JSON file.
 * @return The loaded JSON data.
 */
    static nlohmann::json LoadJsonFromFile(const std::string& filePath) {
        std::ifstream file(filePath);
        if (!file.is_open()) {
            LOG_ERROR("Unable to open file: {}", filePath);
            return {}; // Returns an empty json object, indicating an error
        }

        nlohmann::json jsonData;
        file >> jsonData;
        file.close();
        return jsonData;
    }
};
#endif //PTSD_LEGACY_OF_DEFENSE_PROLOGUE_ILOADABLEFROMJSON_HPP
