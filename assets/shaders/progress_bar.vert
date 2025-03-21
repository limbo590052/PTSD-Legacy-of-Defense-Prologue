#version 410 core

layout (location = 0) in vec2 aPos;

layout (std140) uniform Matrices {
    mat4 model;
    mat4 projection;
};

uniform float uProgress;

void main() {
    vec2 pos = aPos;

    // 調整填充矩形的寬度
    if (gl_VertexID >= 4) { // 填充矩形的頂點索引從 4 開始
        if (pos.x > 0.0) {
            pos.x = pos.x * uProgress;
        }
    }

    gl_Position = projection * model * vec4(pos, 0.0f, 1.0f);
}