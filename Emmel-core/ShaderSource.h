#pragma once

#ifndef SHADERSOURCE_H
#define SHADERSOURCE_H

#include <string>

std::string source_vertex =
"#version 330 core\n"
"layout(location = 0) in vec4 position; \n"
"void main()\n"
"{ \n"
"gl_Position = position; \n"
"}\0";

std::string source_fragment =
"#version 330 core\n"
"layout (location = 0) out vec4 color; \n"
"void main()\n"
"{ \n"
"color = vec4(1.0, 0.0, 0.0, 1.0); \n"
"}\n\0";



#endif