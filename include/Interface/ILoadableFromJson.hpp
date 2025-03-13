//
// Created by limbo on 2025/3/11.
//
#include <string>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

#ifndef PTSD_LEGACY_OF_DEFENSE_PROLOGUE_ILOADABLEFROMJSON_HPP
#define PTSD_LEGACY_OF_DEFENSE_PROLOGUE_ILOADABLEFROMJSON_HPP
class ILoadableFromJson {
public:
    virtual ~ILoadableFromJson() = default;
    virtual void LoadJson(const std::string& filePath) = 0;
};
#endif //PTSD_LEGACY_OF_DEFENSE_PROLOGUE_ILOADABLEFROMJSON_HPP
