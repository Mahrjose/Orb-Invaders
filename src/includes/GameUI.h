#pragma once

#include "IndexBuffer.h"
#include "Renderer.h"
#include "VertexArray.h"
#include "VertexBufferLayout.h"

class GameUI {
   private:
    std::vector<float> m_LineDivider;
    VertexArray m_LineVA;
    VertexBuffer* m_LineVB;
    Shader m_Shader;

   public:
    GameUI(const std::string& shaderFile);
    ~GameUI();

    void DrawLineDivider();
    void Render();
};
