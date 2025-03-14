//
// Created by limbo on 2025/3/13.
//

#include <fstream>
#include "Button.hpp"
#include <nlohmann/json.hpp>

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

    glm::vec2 buttonPosition = GetPosition();
    glm::vec2 buttonSize = m_Drawable->GetSize();

    float left = buttonPosition.x;
    float right = buttonPosition.x + buttonSize.x;

    float top = buttonPosition.y;
    float bottom = buttonPosition.y - buttonSize.y;

    bool inLeftAndRight =  position.x >= left && position.x <= right;
    bool inTopAndDown = position.y<= top && position.y >= bottom;

    bool isPositionInside = inLeftAndRight && inTopAndDown;
    return isPositionInside;
}
