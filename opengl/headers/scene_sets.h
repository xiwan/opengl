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

//glm::vec3 clearColors[] = {
//	glm::vec3(0.75f, 0.52f, 0.3f),
//	glm::vec3(0.1f, 0.1f, 0.1f),
//	glm::vec3(0.0f, 0.0f, 0.0f),
//	glm::vec3(0.9f, 0.9f, 0.9f)
//};
//
//glm::vec3 directionLightDirections[] = {
//	glm::vec3(-0.2f, -1.0f, -0.3f),
//	glm::vec3(-0.2f, -1.0f, -0.3f),
//	glm::vec3(-0.2f, -1.0f, -0.3f),
//	glm::vec3(-0.2f, -1.0f, -0.3f)
//};
//
//glm::vec3 directionLightAmbients[] = {
//	glm::vec3(0.3f, 0.24f, 0.14f),
//	glm::vec3(0.05f, 0.05f, 0.1f),
//	glm::vec3(0.0f, 0.0f, 0.0f),
//	glm::vec3(0.5f, 0.5f, 0.5f)
//};
//
//glm::vec3 directionLightDiffuses[] = {
//	glm::vec3(0.7f, 0.42f, 0.26f),
//	glm::vec3(0.2f, 0.2f, 0.7f),
//	glm::vec3(0.05f, 0.05f, 0.05),
//	glm::vec3(1.0f, 1.0f, 1.0f)
//};
//
//glm::vec3 directionLightSpeculars[] = {
//	glm::vec3(0.5f, 0.5f, 0.5f),
//	glm::vec3(0.7f, 0.7f, 0.7f),
//	glm::vec3(0.2f, 0.2f, 0.2f),
//	glm::vec3(1.0f, 1.0f, 1.0f)
//};
//
//glm::vec3 pointLightPositions[] = {
//	glm::vec3(0.7f,  0.2f,  2.0f),
//	glm::vec3(2.3f, -3.3f, -4.0f),
//	glm::vec3(-4.0f,  2.0f, -12.0f),
//	glm::vec3(0.0f,  0.0f, -3.0f)
//};
//
//glm::vec3 pointLightColors[][4] = {
//
//	{glm::vec3(1.0f, 0.6f, 0.0f),
//	glm::vec3(1.0f, 0.0f, 0.0f),
//	glm::vec3(1.0f, 1.0, 0.0),
//	glm::vec3(0.2f, 0.2f, 1.0f)},
//
//	{glm::vec3(0.2f, 0.2f, 0.6f),
//	glm::vec3(0.3f, 0.3f, 0.7f),
//	glm::vec3(0.0f, 0.0f, 0.3f),
//	glm::vec3(0.4f, 0.4f, 0.4f)},
//
//	{glm::vec3(0.1f, 0.1f, 0.1f),
//	glm::vec3(0.1f, 0.1f, 0.1f),
//	glm::vec3(0.1f, 0.1f, 0.1f),
//	glm::vec3(0.3f, 0.1f, 0.1f)},
//
//	{ glm::vec3(0.4f, 0.7f, 0.1f),
//	glm::vec3(0.4f, 0.7f, 0.1f),
//	glm::vec3(0.4f, 0.7f, 0.1f),
//	glm::vec3(0.4f, 0.7f, 0.1f)}
//
//};
//
//glm::vec3 pointLightAmbients[][4] = {
//	{pointLightColors[0][0] * glm::vec3(0.1), 
//	pointLightColors[0][1] * glm::vec3(0.1), 
//	pointLightColors[0][2] * glm::vec3(0.1), 
//	pointLightColors[0][3] * glm::vec3(0.1)},
//
//	{pointLightColors[1][0] * glm::vec3(0.1),
//	pointLightColors[1][1] * glm::vec3(0.1),
//	pointLightColors[1][2] * glm::vec3(0.1),
//	pointLightColors[1][3] * glm::vec3(0.1)},
//
//	{pointLightColors[2][0] * glm::vec3(0.1),
//	pointLightColors[2][1] * glm::vec3(0.1),
//	pointLightColors[2][2] * glm::vec3(0.1),
//	pointLightColors[2][3] * glm::vec3(0.1)},
//
//	{pointLightColors[3][0] * glm::vec3(0.1),
//	pointLightColors[3][1] * glm::vec3(0.1),
//	pointLightColors[3][2] * glm::vec3(0.1),
//	pointLightColors[3][3] * glm::vec3(0.1)},
//};
//
//glm::vec3 pointLightDiffuses[][4] = {
//	{pointLightColors[0][0] * glm::vec3(1.0),
//	pointLightColors[0][1] * glm::vec3(1.0),
//	pointLightColors[0][2] * glm::vec3(1.0),
//	pointLightColors[0][3] * glm::vec3(1.0)},
//
//	{pointLightColors[1][0] * glm::vec3(1.0),
//	pointLightColors[1][1] * glm::vec3(1.0),
//	pointLightColors[1][2] * glm::vec3(1.0),
//	pointLightColors[1][3] * glm::vec3(1.0)},
//
//	{pointLightColors[2][0] * glm::vec3(1.0),
//	pointLightColors[2][1] * glm::vec3(1.0),
//	pointLightColors[2][2] * glm::vec3(1.0),
//	pointLightColors[2][3] * glm::vec3(1.0)},
//
//	{pointLightColors[3][0] * glm::vec3(1.0),
//	pointLightColors[3][1] * glm::vec3(1.0),
//	pointLightColors[3][2] * glm::vec3(1.01),
//	pointLightColors[3][3] * glm::vec3(1.0)},
//};
//
//glm::vec3 pointLightSpecular[][4] = {
//	{pointLightColors[0][0] * glm::vec3(1.0),
//	pointLightColors[0][1] * glm::vec3(1.0),
//	pointLightColors[0][2] * glm::vec3(1.0),
//	pointLightColors[0][3] * glm::vec3(1.0)},
//
//	{pointLightColors[1][0] * glm::vec3(1.0),
//	pointLightColors[1][1] * glm::vec3(1.0),
//	pointLightColors[1][2] * glm::vec3(1.0),
//	pointLightColors[1][3] * glm::vec3(1.0)},
//
//	{pointLightColors[2][0] * glm::vec3(1.0),
//	pointLightColors[2][1] * glm::vec3(1.0),
//	pointLightColors[2][2] * glm::vec3(1.0),
//	pointLightColors[2][3] * glm::vec3(1.0)},
//
//	{pointLightColors[3][0] * glm::vec3(1.0),
//	pointLightColors[3][1] * glm::vec3(1.0),
//	pointLightColors[3][2] * glm::vec3(1.01),
//	pointLightColors[3][3] * glm::vec3(1.0)},
//};
//
//float lightConstants[] = {
//	1.0, 1.0, 1.0, 1.0
//};
//
//float lightLinears[] = {
//	0.09, 0.09, 0.14, 0.07
//};
//
//float lightQuadratics[] = {
//	 0.032,  0.032,  0.07,  0.017
//};
//
//glm::vec3 spotLightAmbients[] = {
//	glm::vec3(0.0f, 0.0f, 0.0f),
//	glm::vec3(0.0f, 0.0f, 0.0f),
//	glm::vec3(0.0f, 0.0f, 0.0f),
//	glm::vec3(0.0f, 0.0f, 0.0f)
//};
//
//glm::vec3 spotLightDiffuses[] = {
//	glm::vec3(0.8f, 0.8f, 0.0f),
//	glm::vec3(1.0f, 1.0f, 1.0f),
//	glm::vec3(0.0f, 1.0f, 0.0f),
//	glm::vec3(0.8f, 0.8f, 0.0f)
//};
//
//glm::vec3 spotLightSpeculars[] = {
//	glm::vec3(0.8f, 0.8f, 0.0f),
//	glm::vec3(1.0f, 1.0f, 1.0f),
//	glm::vec3(1.0f, 1.0f, 1.0f),
//	glm::vec3(0.0f, 1.0f, 0.0f)
//};
//
//float spotLightCufOffs[] = {
//	glm::cos(glm::radians(12.5f)),
//	glm::cos(glm::radians(10.0f)),
//	glm::cos(glm::radians(10.0f)),
//	glm::cos(glm::radians(7.0f))
//};
//
//float spotLightOuterCufOffs[] = {
//	glm::cos(glm::radians(13.0f)),
//	glm::cos(glm::radians(12.5f)),
//	glm::cos(glm::radians(15.0f)),
//	glm::cos(glm::radians(10.0f))
//};
