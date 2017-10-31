#include "Shader.h"

//Construct the shader object -- link and compile shaders
Shader::Shader(std::string &source_vertex, std::string &source_fragment)
{

	unsigned int vertexShader, fragmentShader;
	int success;
	char infoLog[512];

	//Convert source to c string
	const char* vSrc = source_vertex.c_str();
	const char* fSrc = source_fragment.c_str();

	/*
		VERTEX SHADER
	*/
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	//Assign source code & compile
	glShaderSource(vertexShader, 1, &vSrc, NULL);
	glCompileShader(vertexShader);

	//Vertex Comp Log
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	};

	/*
		FRAGMENT SHADER
	*/
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	//Assign source code & compile
	glShaderSource(fragmentShader, 1, &fSrc, NULL);
	glCompileShader(fragmentShader);

	//Fragment Comp Log
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
	};

	//Create and link program
	ID = glCreateProgram();
	glAttachShader(ID, vertexShader);
	glAttachShader(ID, fragmentShader);
	glLinkProgram(ID);
	glValidateProgram(ID);

	//Linking Log
	glGetProgramiv(ID, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(ID, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
	}

	//Remove from memory
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}


void Shader::use()
{
	glUseProgram(ID);
}

void Shader::setBool(const std::string &name, bool value) const
{
	glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
}

void Shader::setInt(const std::string &name, int value) const
{
	glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
}

void Shader::setFloat(const std::string &name, float value) const
{
	glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
}