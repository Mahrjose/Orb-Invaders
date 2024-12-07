#include "includes/GameUI.h"

#include <vector>

GameUI::GameUI(const std::string& shaderFile) : m_Shader(shaderFile), m_LineVB(nullptr) {
    // Generate Line Divider to Seperate Upper Menu & Gameplay
    float left = -1.0f;
    float right = 1.0f;
    float pointCount = 400.0f;
    float spacing = (right - left) / pointCount;

    for (int i = 0; i <= 400; ++i) {
        float x = left + i * spacing;
        m_LineDivider.push_back(x);
        m_LineDivider.push_back(0.8f);  // Y value; Sets how above the line will be drawn
    }

    m_LineVB = new VertexBuffer(m_LineDivider.data(), m_LineDivider.size() * sizeof(float));

    VertexBufferLayout LineBufferLayout;
    LineBufferLayout.Push<float>(2);

    m_LineVA.AddBuffer(*m_LineVB, LineBufferLayout);
}

GameUI::~GameUI() {
    delete m_LineVB;
}

void GameUI::DrawLineDivider() {
    m_Shader.Bind();
    m_LineVA.Bind();
    glPointSize(2.0f);
    glDrawArrays(GL_POINTS, 0, m_LineDivider.size() / 2);
}

void GameUI::Render() {
}
