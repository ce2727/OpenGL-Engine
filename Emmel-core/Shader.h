#pragma once

#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>//Gets OpenGL headers
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

///Helps to handle shaders we've created in a cleaner way
class Shader
{
public:
	unsigned int ID;

	Shader(std::string &source_vertex, std::string &source_fragment);//Constructor takes in vertex and fragment shaders

	void use();
	void setBool(const std::string &name, bool value) const;
	void setInt(const std::string &name, int value) const;
	void setFloat(const std::string &name, float value) const;
};


#endif