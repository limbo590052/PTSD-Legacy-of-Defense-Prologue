//
// Created by limbo on 2025/3/7.
//
#include "ImageObject.h"
#include "Util/Logger.hpp"

ImageObject::ImageObject(const std::string& imagePath, float zIndex)
        : GameObject(std::make_unique<Util::Image>(imagePath), zIndex),
          m_ImagePath(imagePath) {
}

// ,m_ImagePath(imagePath) equal {m_ImagePath = imagePath;}

void ImageObject::SetImagePath(const std::string& imagePath) {
    try {
        SetDrawable(std::make_unique<Util::Image>(imagePath));
        m_ImagePath = imagePath;
    } catch (...) {
        LOG_ERROR("Error setting image path: {}",imagePath);
    }
}

const std::string& ImageObject::GetImagePath() const{
    return m_ImagePath;
}