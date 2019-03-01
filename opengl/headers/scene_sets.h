#pragma once
#include <map> 
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
using namespace std;

#define POINT_LIGHT_NUMBER 4  
struct SCENE_SET 
{
	glm::vec3 clearColor;
	glm::vec3 directionLightDirection;
	glm::vec3 directionLightAmbient;
	glm::vec3 directionLightDiffuse;
	glm::vec3 directionLightSpecular;

	glm::vec3 pointLightPosition[POINT_LIGHT_NUMBER];
	glm::vec3 pointLightColor[POINT_LIGHT_NUMBER];
	glm::vec3 pointLightAmbient[POINT_LIGHT_NUMBER];
	glm::vec3 pointLightDiffuse[POINT_LIGHT_NUMBER];
	glm::vec3 pointLightSpecular[POINT_LIGHT_NUMBER];

	glm::vec3 spotLightAmbient;
	glm::vec3 spotLightDiffuse;
	glm::vec3 spotLightSpecular;
	float spotLightCufOff;
	float spotLightOuterCufOff;

	float lightConstant;
	float lightLinear;
	float lightQuadratic;
};

void initDesertScenes(string name);
void initFactoryScenes(string name);
void initHorrorScenes(string name);
void initBiochemicalLabScenes(string name);

SCENE_SET getScene(string name);
