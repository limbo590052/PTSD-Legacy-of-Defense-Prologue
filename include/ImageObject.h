//
// Created by limbo on 2025/3/7.
//

#ifndef REPLACE_WITH_YOUR_PROJECT_NAME_IMAGEOBJECT_H
#define REPLACE_WITH_YOUR_PROJECT_NAME_IMAGEOBJECT_H
#include "Util/GameObject.hpp"
#include "Util/Image.hpp"

class ImageObject : public Util::GameObject {

public:
    ImageObject(const std::string& imagePath, float zIndex = 0);

    void SetImagePath(const std::string& imagePath);
    const std::string& GetImagePath() const;

private:
    std::string m_ImagePath;
};
#endif //REPLACE_WITH_YOUR_PROJECT_NAME_IMAGEOBJECT_H
