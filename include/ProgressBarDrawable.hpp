#ifndef UTIL_PROGRESS_BAR_DRAWABLE_HPP
#define UTIL_PROGRESS_BAR_DRAWABLE_HPP

#include "Core/Drawable.hpp"
#include "Util/Color.hpp"
#include <glm/glm.hpp>
#include "Util/Logger.hpp"
#include "Core/VertexArray.hpp"
#include "Core/VertexBuffer.hpp"
#include "Core/IndexBuffer.hpp"
#include "Core/Program.hpp"

namespace Util {
    class ProgressBarDrawable : public Core::Drawable {
    public:
        ProgressBarDrawable(const glm::vec2& size, const Util::Color& fillColor, const Util::Color& borderColor)
                : m_Size(size), m_FillColor(fillColor), m_BorderColor(borderColor), m_Progress(0.0f) {
            if (m_Program == nullptr) {
                InitProgram();
            }
            if (m_VertexArray == nullptr) {
                InitVertexArray();
            }

//            InitUniformBuffer();
        }

        void Draw(const Core::Matrices& data) override {
            LOG_TRACE("ProgressBarDrawable::Draw() m_Size: ({}, {})", m_Size.x, m_Size.y);

            m_UniformBuffer->SetData(0, data);
            m_Program->Bind();
            m_Program->Validate();

            m_VertexArray->Bind();
//            glUniform1i(glGetUniformLocation(m_Program->GetId(), "uTexture"), 0);

            // 繪製填充
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
            glUniform4f(glGetUniformLocation(m_Program->GetId(), "uColor"), m_FillColor.r / 255.0f, m_FillColor.g / 255.0f, m_FillColor.b / 255.0f, m_FillColor.a / 255.0f);
            glUniform1f(glGetUniformLocation(m_Program->GetId(), "uProgress"), m_Progress);
            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (void*)(6 * sizeof(unsigned int))); // 繪製填充矩形，索引從6開始

            // 繪製邊框
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
            glUniform4f(glGetUniformLocation(m_Program->GetId(), "uColor"), m_BorderColor.r / 255.0f, m_BorderColor.g / 255.0f, m_BorderColor.b / 255.0f, m_BorderColor.a / 255.0f);
            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

            m_VertexArray->Unbind();
            m_Program->Unbind();

            GLenum error = glGetError();
            if (error != GL_NO_ERROR) {
                LOG_ERROR("OpenGL error: {}", error);
            }
        }

        glm::vec2 GetSize() const override { return m_Size; }

        void SetProgress(float progress) {
            m_Progress = glm::clamp(progress, 0.0f, 1.0f);
        }

    private:
        void InitVertexArray() {
            m_VertexArray = std::make_unique<Core::VertexArray>();

            std::vector<float> vertices = {
                    -0.5f, 0.5f,  // Top-left (邊框)
                    -0.5f, -0.5f, // Bottom-left (邊框)
                    0.5f, -0.5f,  // Bottom-right (邊框)
                    0.5f, 0.5f,   // Top-right (邊框)

                    -0.5f, 0.5f,  // Top-left (填充)
                    -0.5f, -0.5f, // Bottom-left (填充)
                    0.0f, -0.5f,  // Bottom-right (填充) // 寬度會根據進度調整
                    0.0f, 0.5f    // Top-right (填充) // 寬度會根據進度調整
            };

            std::vector<unsigned int> indices = {
                    0, 1, 2, // 邊框
                    0, 2, 3, // 邊框
                    4, 5, 6, // 填充
                    4, 6, 7  // 填充
            };

            m_VertexArray->AddVertexBuffer(std::make_unique<Core::VertexBuffer>(vertices, 2));
            m_VertexArray->SetIndexBuffer(std::make_unique<Core::IndexBuffer>(indices));
        }

        void InitProgram() {
            m_Program =
                    std::make_unique<Core::Program>(ASSETS_DIR "/shaders/progress_bar.vert", ASSETS_DIR "/shaders/progress_bar.frag");
            m_Program->Bind();
        }

//        void InitUniformBuffer() {
//            m_UniformBuffer = std::make_unique<Core::UniformBuffer<Core::Matrices>>(*m_Program, "Matrices", 0);
//        }

    private:
        glm::vec2 m_Size;
        Util::Color m_FillColor;
        Util::Color m_BorderColor;
        float m_Progress;

        std::unique_ptr<Core::VertexArray> m_VertexArray;
        std::unique_ptr<Core::Program> m_Program;
        std::unique_ptr<Core::UniformBuffer<Core::Matrices>> m_UniformBuffer;
    };
} // namespace Util

#endif // UTIL_PROGRESS_BAR_DRAWABLE_HPP