#pragma once

#ifndef SHADERSOURCE_H
#define SHADERSOURCE_H

#include <string>

std::string source_vertex =
"#version 330 core\n"
"layout(location = 0) in vec4 iPosition; \n"
"layout(location = 1) in vec3 iColor; \n"
"layout(location = 2) in vec2 iTexCoords; \n"
""
"out vec3 vColor;"
"out vec2 vTexCoords;"
"void main()\n"
"{ \n"
"gl_Position = iPosition; \n"
"vColor = iColor;"
"vTexCoords = iTexCoords;"
"}\0";

std::string source_fragment =
"#version 330 core\n"
"layout (location = 0) out vec4 oFragColor; \n"
""
"in vec3 vColor;"
"in vec2 vTexCoords;"
""
"uniform sampler2D testTexture;"
""
"void main()\n"
"{ \n"
"oFragColor = texture(testTexture, vTexCoords); \n"
"}\n\0";



#endif