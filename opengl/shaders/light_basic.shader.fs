#version 330 core
out vec4 FragColor;
in vec3 Normal; 
in vec3 FragPos; 

uniform vec3 lightPos; 
uniform vec3 objectColor;
uniform vec3 lightColor;

void main()
{
    
    vec3 lightDir = normalize(lightPos - FragPos);

    vec3 norm = normalize(Normal);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * lightColor;

    float ambientStrength = 0.1;
    vec3 ambient = ambientStrength * lightColor;
    vec3 result = (ambient + diffuse) * objectColor;
    FragColor = vec4(result, 1.0);
}