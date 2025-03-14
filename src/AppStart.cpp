//
// Created by limbo on 2025/3/7.
//

#include "MyApp.hpp"
#include "Util/Logger.hpp"

void MyApp::Start() {
    LOG_TRACE("Start");
    LOG_DEBUG(RESOURCE_DIR"/JSON/background_paths.json");
    m_BM = std::make_shared<BackgroundManger>(
            RESOURCE_DIR"/JSON/background_paths.json");
    m_Root.AddChild(m_BM->GetCurrentBackground());
    m_CurrentState = State::FRONT_PAGE;
    m_Root.Update();
}