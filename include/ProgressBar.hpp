#ifndef UTIL_PROGRESS_BAR_HPP
#define UTIL_PROGRESS_BAR_HPP

#include "Util/GameObject.hpp"
#include "ProgressBarDrawable.hpp"
#include "Util/Color.hpp"
#include <memory>

namespace Util {
    class ProgressBar : public GameObject {
    public:
        ProgressBar(const glm::vec2& position, const glm::vec2& size, const Util::Color& fillColor, const Util::Color& borderColor, float zIndex = 0.0f)
                : GameObject(std::make_shared<ProgressBarDrawable>(size, fillColor, borderColor), zIndex) {
            m_Transform.translation = position;
        }

        void SetProgress(float progress) {
            std::static_pointer_cast<ProgressBarDrawable>(m_Drawable)->SetProgress(progress);
        }
    };
} // namespace Util

#endif // UTIL_PROGRESS_BAR_HPP