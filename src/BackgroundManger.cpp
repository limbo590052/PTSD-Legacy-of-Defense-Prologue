#include "BackgroundManger.hpp"
#include "Util/Logger.hpp"
#include <fstream>
#include <nlohmann/json.hpp>

//Public
BackgroundManger::BackgroundManger(const std::string& backgroundConfigPath) {
    Initialize(backgroundConfigPath);
}

void BackgroundManger::ChangeBackground(BackgroundManger::BackgroundName backgroundName) {
    if (m_BackgroundMap.count(backgroundName)) {
        m_CurrentBackground = backgroundName;
        LOG_DEBUG("Changing backgroundName to phase: {}", static_cast<int>(backgroundName));
    } else {
        LOG_ERROR("Invalid backgroundName: {}", static_cast<int>(backgroundName));
    }
}

std::shared_ptr<ImageObject> BackgroundManger::GetCurrentBackground() const {
    if (m_BackgroundMap.count(m_CurrentBackground)) {
        return m_BackgroundMap.at(m_CurrentBackground);
    }
    return nullptr;
}

//Private
void BackgroundManger::LoadJson(const std::string& filePath){
    Initialize(filePath);
}

void BackgroundManger::Initialize(const std::string& filePath) {
    nlohmann::json jsonData = LoadJsonFromFile(filePath);
    if (jsonData.empty()) {
        return;
    }

    try {
        JsonDataStructures::BackgroundPaths backgroundPaths = jsonData.get<JsonDataStructures::BackgroundPaths>();
        CreateBackgroundObjects(backgroundPaths);
    } catch (const std::exception& e) {
        LOG_ERROR("Error parsing JSON: {}", e.what());
    }

    if (m_BackgroundMap.empty()) {
        LOG_ERROR("No backgrounds loaded.");
    }
}

nlohmann::json BackgroundManger::LoadJsonFromFile(const std::string& filePath) {
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

void BackgroundManger::CreateBackgroundObjects(
        const JsonDataStructures::BackgroundPaths& backgroundPaths) {
    const auto& nameToBackground = m_NameToBackground;

    for (const auto& [name, path] : backgroundPaths.paths) {
        if (nameToBackground.count(name)) {
            BackgroundName backgroundName = nameToBackground.at(name); // 使用 .at() 避免預設構造
            m_BackgroundMap[backgroundName] = std::make_shared<ImageObject>(path);
        } else {
            LOG_ERROR("Unknown background name: {}", name);
        }
    }
}
