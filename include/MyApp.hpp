#ifndef APP_HPP
#define APP_HPP

#include "pch.hpp" // IWYU pragma: export
#include "Util/Renderer.hpp"
#include "BackgroundManger.hpp"
#include "Button.hpp"

class MyApp {
public:
    enum class State {
        START,
        FRONT_PAGE,
        UPDATE,
        END,
    };

    [[nodiscard]] State GetCurrentState() const { return m_CurrentState; }

    void Start();

    void FrontPage();

    void Update();

    void End(); // NOLINT(readability-convert-member-functions-to-static)

private:
    //FrontPage
    std::shared_ptr<Button> m_StartButton;
    std::shared_ptr<Button> m_UpgradeButton;
    std::vector<std::shared_ptr<Button>> m_FrontPageButtons;

private:
    State m_CurrentState = State::START;
    Util::Renderer m_Root;
    std::shared_ptr<BackgroundManger> m_BM;
};

#endif
