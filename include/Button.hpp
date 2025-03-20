//
// Created by limbo on 2025/3/13.
//

#ifndef PTSD_LEGACY_OF_DEFENSE_PROLOGUE_BUTTON_HPP
#define PTSD_LEGACY_OF_DEFENSE_PROLOGUE_BUTTON_HPP


#include <vector>
#include <string>
#include <memory>

#include "Util/Animation.hpp"
#include "Util/GameObject.hpp"
#include <functional>
#include "Util/Position.hpp"
#include "Interface/ILoadableFromJson.hpp"

class Button : public Util::GameObject{
public:
    Button(const std::string& ImagePath,
           const glm::vec2& position,
           const std::function<void()>& onClick,
           float zIndex = 0.0f);

public:
    [[maybe_unused]] void SetImage(const std::string& ImagePath);

    void SetPosition(const glm::vec2& Position) { m_Transform.translation = Position; }

    [[nodiscard]] const glm::vec2& GetPosition() const { return m_Transform.translation; }

    [[nodiscard]] bool IsPositionInside(const Util::PTSDPosition& position) const;

public:
    void Click();

private:
    std::string m_ImagePath;
    std::function<void()> m_OnClick;
};


#endif //PTSD_LEGACY_OF_DEFENSE_PROLOGUE_BUTTON_HPP
