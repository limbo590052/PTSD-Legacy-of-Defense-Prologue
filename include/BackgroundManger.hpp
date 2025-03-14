#ifndef REPLACE_WITH_YOUR_PROJECT_NAME_BACKGROUNDMANGER_HPP
#define REPLACE_WITH_YOUR_PROJECT_NAME_BACKGROUNDMANGER_HPP

#include <memory>
#include <vector>
#include <string>
#include <map>
#include "Util/Image.hpp"
#include "ImageObject.h"
#include "Interface/ILoadableFromJson.hpp"
#include "JsonDataStructures/BackgroundPaths.hpp"
#include <nlohmann/json.hpp>

class BackgroundManger : public ILoadableFromJson {
public:
    enum class BackgroundName {
        FRONT_PAGE,
        LEVEL1,
        LEVEL2,
        LEVEL3,
    };

private:
    std::map<BackgroundName, std::shared_ptr<ImageObject>> m_BackgroundMap;
    BackgroundName m_CurrentBackground = BackgroundName::FRONT_PAGE;

    const std::map<std::string, BackgroundName> m_NameToBackground = {
            {"FRONT_PAGE", BackgroundName::FRONT_PAGE},
            {"LEVEL1",     BackgroundName::LEVEL1},
            {"LEVEL2",     BackgroundName::LEVEL2},
            {"LEVEL3",     BackgroundName::LEVEL3}
    };

public:
    /**
     * @brief Constructor. Initializes the BackgroundManager by loading backgrounds from a JSON file.
     * @param backgroundConfigPath Path to the JSON configuration file containing background paths.
     */
    explicit BackgroundManger(const std::string& backgroundConfigPath);

    /**
     * @brief Changes the current backgroundName to the specified backgroundName.
     * @param backgroundName The backgroundName to change to.
     */
    void ChangeBackground(BackgroundName backgroundName);

    /**
     * @brief Gets the currently active background image object.
     * @return A shared pointer to the current ImageObject, or nullptr if no background is loaded.
     */
    [[nodiscard]] std::shared_ptr<ImageObject> GetCurrentBackground() const;

private:
    /**
     * @brief Loads background data from a JSON file. Implements the ILoadableFromJson interface.
     * @param filePath Path to the JSON file.
     */
    void LoadJson(const std::string& filePath) override;

    /**
     * @brief Initializes the BackgroundManager by loading and processing background data.
     * @param filePath Path to the JSON file.
     */
    void Initialize(const std::string &filePath);

    /**
     * @brief Loads JSON data from a file.
     * @param filePath Path to the JSON file.
     * @return The loaded JSON data.
     */
    static nlohmann::json LoadJsonFromFile(const std::string &filePath);

    /**
     * Creates background ImageObjects from given paths and stores them in the BackgroundMap.
     *
     * @param backgroundPaths A struct containing a map of background names to file paths.
     */
    void CreateBackgroundObjects(const JsonDataStructures::BackgroundPaths& backgroundPaths);
};

#endif // REPLACE_WITH_YOUR_PROJECT_NAME_BACKGROUNDMANGER_HPP