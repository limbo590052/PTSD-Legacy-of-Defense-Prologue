#include "MyApp.hpp"

#include <memory>

#include "Util/Input.hpp"
#include "Util/Keycode.hpp"
#include "Util/Logger.hpp"
#include "Util/Position.hpp"

void MyApp::FrontPage() {
    LOG_TRACE("FrontPage");
    m_CurrentState = State::FRONT_PAGE;

    m_Root.RemoveChild(m_BM->GetCurrentBackground());
    m_BM->ChangeBackground(BackgroundManger::BackgroundName::FRONT_PAGE);
    m_Root.AddChild(m_BM->GetCurrentBackground());

    //TODO Write Buttons var onClick() function
    m_StartButton = std::make_shared<Button>(
            RESOURCE_DIR "/StartButton.png", glm::vec2(0, -100),
            [this]() { LOG_INFO("Start button clicked!"); }, 10);
    m_UpgradeButton = std::make_shared<Button>(
            RESOURCE_DIR "/UpgradeButton.png", glm::vec2(0, -200),
            [this]() { LOG_DEBUG("LevelUp button clicked!"); }, 10);

    m_FrontPageButtons.clear();
    m_FrontPageButtons.push_back(m_StartButton);
    m_FrontPageButtons.push_back(m_UpgradeButton);

    std::vector<std::shared_ptr<Util::GameObject>> gameObjectButtons;
    gameObjectButtons.reserve(m_FrontPageButtons.size());

    for (const auto& button : m_FrontPageButtons) {
        gameObjectButtons.push_back(std::static_pointer_cast<Util::GameObject>(button));
    }

    m_Root.AddChildren(gameObjectButtons);
    m_Root.Update();

    if (Util::Input::IsKeyUp(Util::Keycode::ESCAPE) ||
        Util::Input::IfExit()) {
        m_CurrentState = State::END;
    }

    if (Util::Input::IsKeyPressed(Util::Keycode::MOUSE_LB)) {
        Util::PTSDPosition cursorPTSDPosition = Util::Input::GetCursorPosition();
//        Util::SDLPosition cursorSDLPosition = cursorPTSDPosition.ToSDLPosition();
        for (auto& button : m_FrontPageButtons) {
            if (button->IsPositionInside(cursorPTSDPosition)) {
                button->Click();
                break;
            }
        }
    }
}

void MyApp::Update() {
    
    m_Root.Update();

    /*
     * Do not touch the code below as they serve the purpose for
     * closing the window.
     */
    if (Util::Input::IsKeyUp(Util::Keycode::ESCAPE) ||
        Util::Input::IfExit()) {
        m_CurrentState = State::END;
    }
}

void MyApp::End() { // NOLINT(this method will mutate members in the future)
    LOG_TRACE("End");
}