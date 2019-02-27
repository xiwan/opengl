#include "./headers/scene_sets.h"

map<string, SCENE_SET> mapScenes;

void initDesertScenes(string name) {
	SCENE_SET DESERT;
	DESERT.clearColor = glm::vec3(0.75f, 0.52f, 0.3f);
	DESERT.directionLightDirection = glm::vec3(-0.2f, -1.0f, -0.3f);
	DESERT.directionLightAmbient = glm::vec3(0.3f, 0.24f, 0.14f);
	DESERT.directionLightDiffuse = glm::vec3(0.7f, 0.42f, 0.26f);
	DESERT.directionLightSpecular = glm::vec3(0.5f, 0.5f, 0.5f);

	DESERT.pointLightPosition[0] = glm::vec3(0.7f, 0.2f, 2.0f);
	DESERT.pointLightPosition[1] = glm::vec3(2.3f, -3.3f, -4.0f);
	DESERT.pointLightPosition[2] = glm::vec3(-4.0f, 2.0f, -12.0f);
	DESERT.pointLightPosition[3] = glm::vec3(0.0f, 0.0f, -3.0f);

	DESERT.pointLightColor[0] = glm::vec3(0.7f, 0.2f, 2.0f);
	DESERT.pointLightColor[1] = glm::vec3(2.3f, -3.3f, -4.0f);
	DESERT.pointLightColor[2] = glm::vec3(-4.0f, 2.0f, -12.0f);
	DESERT.pointLightColor[3] = glm::vec3(0.0f, 0.0f, -3.0f);

	DESERT.pointLightAmbient[0] = DESERT.pointLightColor[0] * glm::vec3(0.1);
	DESERT.pointLightAmbient[1] = DESERT.pointLightColor[1] * glm::vec3(0.1);
	DESERT.pointLightAmbient[2] = DESERT.pointLightColor[2] * glm::vec3(0.1);
	DESERT.pointLightAmbient[3] = DESERT.pointLightColor[3] * glm::vec3(0.1);

	DESERT.pointLightDiffuse[0] = DESERT.pointLightColor[0] * glm::vec3(1.0);
	DESERT.pointLightDiffuse[1] = DESERT.pointLightColor[1] * glm::vec3(1.0);
	DESERT.pointLightDiffuse[2] = DESERT.pointLightColor[2] * glm::vec3(1.0);
	DESERT.pointLightDiffuse[3] = DESERT.pointLightColor[3] * glm::vec3(1.0);

	DESERT.pointLightSpecular[0] = DESERT.pointLightColor[0] * glm::vec3(1.0);
	DESERT.pointLightSpecular[1] = DESERT.pointLightColor[1] * glm::vec3(1.0);
	DESERT.pointLightSpecular[2] = DESERT.pointLightColor[2] * glm::vec3(1.0);
	DESERT.pointLightSpecular[3] = DESERT.pointLightColor[3] * glm::vec3(1.0);

	DESERT.spotLightAmbient = glm::vec3(0.0f, 0.0f, 0.0f);
	DESERT.spotLightDiffuse = glm::vec3(0.8f, 0.8f, 0.0f);
	DESERT.spotLightSpecular = glm::vec3(0.8f, 0.8f, 0.0f);
	DESERT.spotLightCufOff = glm::cos(glm::radians(12.5f));
	DESERT.spotLightOuterCufOff = glm::cos(glm::radians(13.0f));

	DESERT.lightConstant = 1.0f;
	DESERT.lightLinear = 0.09f;
	DESERT.lightQuadratic = 0.032f;

	mapScenes.insert(pair<string, SCENE_SET>(name, DESERT));
};

void initFactoryScenes(string name) {
	SCENE_SET FACTORY;
	FACTORY.clearColor = glm::vec3(0.1f, 0.1f, 0.1f);
	FACTORY.directionLightDirection = glm::vec3(-0.2f, -1.0f, -0.3f);
	FACTORY.directionLightAmbient = glm::vec3(0.05f, 0.05f, 0.1f);
	FACTORY.directionLightDiffuse = glm::vec3(0.2f, 0.2f, 0.7f);
	FACTORY.directionLightSpecular = glm::vec3(0.7f, 0.7f, 0.7f);

	FACTORY.pointLightPosition[0] = glm::vec3(0.7f, 0.2f, 2.0f);
	FACTORY.pointLightPosition[1] = glm::vec3(2.3f, -3.3f, -4.0f);
	FACTORY.pointLightPosition[2] = glm::vec3(-4.0f, 2.0f, -12.0f);
	FACTORY.pointLightPosition[3] = glm::vec3(0.0f, 0.0f, -3.0f);

	FACTORY.pointLightColor[0] = glm::vec3(0.2f, 0.2f, 0.6f);
	FACTORY.pointLightColor[1] = glm::vec3(0.3f, 0.3f, 0.7f);
	FACTORY.pointLightColor[2] = glm::vec3(0.0f, 0.0f, 0.3f);
	FACTORY.pointLightColor[3] = glm::vec3(0.4f, 0.4f, 0.4f);

	FACTORY.pointLightAmbient[0] = FACTORY.pointLightColor[0] * glm::vec3(0.1);
	FACTORY.pointLightAmbient[1] = FACTORY.pointLightColor[1] * glm::vec3(0.1);
	FACTORY.pointLightAmbient[2] = FACTORY.pointLightColor[2] * glm::vec3(0.1);
	FACTORY.pointLightAmbient[3] = FACTORY.pointLightColor[3] * glm::vec3(0.1);

	FACTORY.pointLightDiffuse[0] = FACTORY.pointLightColor[0] * glm::vec3(1.0);
	FACTORY.pointLightDiffuse[1] = FACTORY.pointLightColor[1] * glm::vec3(1.0);
	FACTORY.pointLightDiffuse[2] = FACTORY.pointLightColor[2] * glm::vec3(1.0);
	FACTORY.pointLightDiffuse[3] = FACTORY.pointLightColor[3] * glm::vec3(1.0);

	FACTORY.pointLightSpecular[0] = FACTORY.pointLightColor[0] * glm::vec3(1.0);
	FACTORY.pointLightSpecular[1] = FACTORY.pointLightColor[1] * glm::vec3(1.0);
	FACTORY.pointLightSpecular[2] = FACTORY.pointLightColor[2] * glm::vec3(1.0);
	FACTORY.pointLightSpecular[3] = FACTORY.pointLightColor[3] * glm::vec3(1.0);

	FACTORY.spotLightAmbient = glm::vec3(0.0f, 0.0f, 0.0f);
	FACTORY.spotLightDiffuse = glm::vec3(1.0f, 1.0f, 1.0f);
	FACTORY.spotLightSpecular = glm::vec3(1.0f, 1.0f, 1.0f);
	FACTORY.spotLightCufOff = glm::cos(glm::radians(10.0f));
	FACTORY.spotLightOuterCufOff = glm::cos(glm::radians(12.5f));

	FACTORY.lightConstant = 1.0f;
	FACTORY.lightLinear = 0.09f;
	FACTORY.lightQuadratic = 0.032f;

	mapScenes.insert(pair<string, SCENE_SET>(name, FACTORY));
};

void initHorrorScenes(string name) {
	SCENE_SET HORROR;
	HORROR.clearColor = glm::vec3(0.0f, 0.0f, 0.0f);
	HORROR.directionLightDirection = glm::vec3(-0.2f, -1.0f, -0.3f);
	HORROR.directionLightAmbient = glm::vec3(0.0f, 0.0f, 0.0f);
	HORROR.directionLightDiffuse = glm::vec3(0.05f, 0.05f, 0.05f);
	HORROR.directionLightSpecular = glm::vec3(0.2f, 0.2f, 0.2f);

	HORROR.pointLightPosition[0] = glm::vec3(0.7f, 0.2f, 2.0f);
	HORROR.pointLightPosition[1] = glm::vec3(2.3f, -3.3f, -4.0f);
	HORROR.pointLightPosition[2] = glm::vec3(-4.0f, 2.0f, -12.0f);
	HORROR.pointLightPosition[3] = glm::vec3(0.0f, 0.0f, -3.0f);

	HORROR.pointLightColor[0] = glm::vec3(0.1f, 0.1f, 0.1f);
	HORROR.pointLightColor[1] = glm::vec3(0.1f, 0.1f, 0.1f);
	HORROR.pointLightColor[2] = glm::vec3(0.1f, 0.1f, 0.1f);
	HORROR.pointLightColor[3] = glm::vec3(0.1f, 0.1f, 0.1f);

	HORROR.pointLightAmbient[0] = HORROR.pointLightColor[0] * glm::vec3(0.1);
	HORROR.pointLightAmbient[1] = HORROR.pointLightColor[1] * glm::vec3(0.1);
	HORROR.pointLightAmbient[2] = HORROR.pointLightColor[2] * glm::vec3(0.1);
	HORROR.pointLightAmbient[3] = HORROR.pointLightColor[3] * glm::vec3(0.1);

	HORROR.pointLightDiffuse[0] = HORROR.pointLightColor[0] * glm::vec3(1.0);
	HORROR.pointLightDiffuse[1] = HORROR.pointLightColor[1] * glm::vec3(1.0);
	HORROR.pointLightDiffuse[2] = HORROR.pointLightColor[2] * glm::vec3(1.0);
	HORROR.pointLightDiffuse[3] = HORROR.pointLightColor[3] * glm::vec3(1.0);

	HORROR.pointLightSpecular[0] = HORROR.pointLightColor[0] * glm::vec3(1.0);
	HORROR.pointLightSpecular[1] = HORROR.pointLightColor[1] * glm::vec3(1.0);
	HORROR.pointLightSpecular[2] = HORROR.pointLightColor[2] * glm::vec3(1.0);
	HORROR.pointLightSpecular[3] = HORROR.pointLightColor[3] * glm::vec3(1.0);

	HORROR.spotLightAmbient = glm::vec3(0.0f, 0.0f, 0.0f);
	HORROR.spotLightDiffuse = glm::vec3(1.0f, 1.0f, 1.0f);
	HORROR.spotLightSpecular = glm::vec3(1.0f, 1.0f, 1.0f);
	HORROR.spotLightCufOff = glm::cos(glm::radians(10.0f));
	HORROR.spotLightOuterCufOff = glm::cos(glm::radians(15.0f));

	HORROR.lightConstant = 1.0f;
	HORROR.lightLinear = 0.09f;
	HORROR.lightQuadratic = 0.032f;

	mapScenes.insert(pair<string, SCENE_SET>(name, HORROR));
};


void initBiochemicalLabScenes(string name) {
	SCENE_SET BIOCHEMICAL_LAB;
	BIOCHEMICAL_LAB.clearColor = glm::vec3(0.9f, 0.9f, 0.9f);
	BIOCHEMICAL_LAB.directionLightDirection = glm::vec3(-0.2f, -1.0f, -0.3f);
	BIOCHEMICAL_LAB.directionLightAmbient = glm::vec3(0.5f, 0.5f, 0.5f);
	BIOCHEMICAL_LAB.directionLightDiffuse = glm::vec3(1.0f, 1.0f, 1.0f);
	BIOCHEMICAL_LAB.directionLightSpecular = glm::vec3(1.0f, 1.0f, 1.0f);

	BIOCHEMICAL_LAB.pointLightPosition[0] = glm::vec3(0.7f, 0.2f, 2.0f);
	BIOCHEMICAL_LAB.pointLightPosition[1] = glm::vec3(2.3f, -3.3f, -4.0f);
	BIOCHEMICAL_LAB.pointLightPosition[2] = glm::vec3(-4.0f, 2.0f, -12.0f);
	BIOCHEMICAL_LAB.pointLightPosition[3] = glm::vec3(0.0f, 0.0f, -3.0f);

	BIOCHEMICAL_LAB.pointLightColor[0] = glm::vec3(0.4f, 0.7f, 0.1f);
	BIOCHEMICAL_LAB.pointLightColor[1] = glm::vec3(0.4f, 0.7f, 0.1f);
	BIOCHEMICAL_LAB.pointLightColor[2] = glm::vec3(0.4f, 0.7f, 0.1f);
	BIOCHEMICAL_LAB.pointLightColor[3] = glm::vec3(0.4f, 0.7f, 0.1f);

	BIOCHEMICAL_LAB.pointLightAmbient[0] = BIOCHEMICAL_LAB.pointLightColor[0] * glm::vec3(0.1);
	BIOCHEMICAL_LAB.pointLightAmbient[1] = BIOCHEMICAL_LAB.pointLightColor[1] * glm::vec3(0.1);
	BIOCHEMICAL_LAB.pointLightAmbient[2] = BIOCHEMICAL_LAB.pointLightColor[2] * glm::vec3(0.1);
	BIOCHEMICAL_LAB.pointLightAmbient[3] = BIOCHEMICAL_LAB.pointLightColor[3] * glm::vec3(0.1);

	BIOCHEMICAL_LAB.pointLightDiffuse[0] = BIOCHEMICAL_LAB.pointLightColor[0] * glm::vec3(1.0);
	BIOCHEMICAL_LAB.pointLightDiffuse[1] = BIOCHEMICAL_LAB.pointLightColor[1] * glm::vec3(1.0);
	BIOCHEMICAL_LAB.pointLightDiffuse[2] = BIOCHEMICAL_LAB.pointLightColor[2] * glm::vec3(1.0);
	BIOCHEMICAL_LAB.pointLightDiffuse[3] = BIOCHEMICAL_LAB.pointLightColor[3] * glm::vec3(1.0);

	BIOCHEMICAL_LAB.pointLightSpecular[0] = BIOCHEMICAL_LAB.pointLightColor[0] * glm::vec3(1.0);
	BIOCHEMICAL_LAB.pointLightSpecular[1] = BIOCHEMICAL_LAB.pointLightColor[1] * glm::vec3(1.0);
	BIOCHEMICAL_LAB.pointLightSpecular[2] = BIOCHEMICAL_LAB.pointLightColor[2] * glm::vec3(1.0);
	BIOCHEMICAL_LAB.pointLightSpecular[3] = BIOCHEMICAL_LAB.pointLightColor[3] * glm::vec3(1.0);

	BIOCHEMICAL_LAB.spotLightAmbient = glm::vec3(0.0f, 0.0f, 0.0f);
	BIOCHEMICAL_LAB.spotLightDiffuse = glm::vec3(0.0f, 1.0f, 0.0f);
	BIOCHEMICAL_LAB.spotLightSpecular = glm::vec3(0.0f, 1.0f, 0.0f);
	BIOCHEMICAL_LAB.spotLightCufOff = glm::cos(glm::radians(7.0f));
	BIOCHEMICAL_LAB.spotLightOuterCufOff = glm::cos(glm::radians(10.0f));

	BIOCHEMICAL_LAB.lightConstant = 1.0f;
	BIOCHEMICAL_LAB.lightLinear = 0.07f;
	BIOCHEMICAL_LAB.lightQuadratic = 0.017f;

	mapScenes.insert(pair<string, SCENE_SET>(name, BIOCHEMICAL_LAB));
};

SCENE_SET getScene(string name) {
	return mapScenes[name];
}