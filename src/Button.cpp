//
// Created by limbo on 2025/3/13.
//

#include <fstream>
#include "Button.hpp"
#include <nlohmann/json.hpp>
#include "Util/Position.hpp"

Button::Button(const std::string &ImagePath, const glm::vec2 &position, const std::function<void()> &onClick,
               float zIndex):m_OnClick(onClick){
    SetZIndex(zIndex);
    SetImage(ImagePath);
    SetPosition(position);
}

void Button::SetImage(const std::string& ImagePath) {
    m_ImagePath = ImagePath;
    m_Drawable = std::make_shared<Util::Image>(m_ImagePath);
}

void Button::Click() {
    if (m_OnClick) {
        m_OnClick();
    }
}

bool Button::IsPositionInside(const Util::PTSDPosition &position) const {
    if (!m_Drawable) {
        return false;
    }

    glm::vec2 buttonVec2 = GetPosition();
    auto buttonPosition = Util::PTSDPosition(buttonVec2.x,buttonVec2.y);
    glm::vec2 buttonSize = m_Drawable->GetSize();

    float left = buttonPosition.x - buttonSize.x / 2.0f; // Adjust left for center origin
    float right = buttonPosition.x + buttonSize.x / 2.0f; // Adjust right for center origin

    float top = buttonPosition.y + buttonSize.y / 2.0f; // Adjust top for center origin
    float bottom = buttonPosition.y - buttonSize.y / 2.0f; // Adjust bottom for center origin

    bool inLeftAndRight =  position.x >= left && position.x <= right;
    bool inTopAndDown = position.y<= top && position.y >= bottom;

    bool isPositionInside = inLeftAndRight && inTopAndDown;
    return isPositionInside;
}
