#include "MyApp.hpp"

#include "Core/Context.hpp"

int main(int, char**) {
    auto context = Core::Context::GetInstance();
    MyApp app;

    while (!context->GetExit()) {
        switch (app.GetCurrentState()) {
            case MyApp::State::START:
                app.Start();
                break;

            case MyApp::State::UPDATE:
                app.Update();
                break;

            case MyApp::State::FRONT_PAGE:
                app.FrontPage();
                break;

            case MyApp::State::END:
                app.End();
                context->SetExit(true);
                break;
        }
        context->Update();
    }
    return 0;
}
