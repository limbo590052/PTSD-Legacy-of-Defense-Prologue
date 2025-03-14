#include "MyApp.hpp"

#include "Util/Image.hpp"
#include "Util/Input.hpp"
#include "Util/Keycode.hpp"
#include "Util/Logger.hpp"

void MyApp::FrontPage() {
    LOG_TRACE("FrontPage");
    m_CurrentState = State::FRONT_PAGE;

    m_Root.RemoveChild(m_BM->GetCurrentBackground());
    m_BM->ChangeBackground(BackgroundManger::BackgroundName::FRONT_PAGE);
    m_Root.AddChild(m_BM->GetCurrentBackground());

    m_Root.Update();
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