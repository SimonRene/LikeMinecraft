#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <vector>

namespace GE {

enum Camera_Movement {
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT,
    UP,
    DOWN
};


class Camera
{
private:
    double m_pitch;
    double m_yaw;

    float m_movementSpeed;
    float m_mouseSensitivity;
    float m_zoom;

    float m_near;
    float m_far;

    glm::vec3 m_position;
    glm::vec3 m_worldUp;

    glm::vec3 m_front;
    glm::vec3 m_up;
    glm::vec3 m_right;

    void updateCameraVectors();


    // Default camera values
    static const float YAW;
    static const float PITCH;
    static const float SPEED;
    static const float SENSITIVITY;
    static const float ZOOM;

public:
    Camera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f), float yaw = YAW, float pitch = PITCH);
    ~Camera();

    void ProcessMouseMovement(float xoffset, float yoffset, GLboolean constrainPitch = true);
    void ProcessKeyboard(Camera_Movement direction, float deltaTime);
    void ProcessMouseScroll(float yoffset);

    glm::mat4 GetViewMatrix();
    glm::mat4 getProjectionMatrix(float screenWidth, float screenHight);

    void setYaw(double yaw);
    void setPitch(double pitch);

    bool setNear(float near);
    bool setFar(float far);

    void setMovementSpeed(double speed);

    double Yaw();
    double Pitch();

    double Zoom();

    glm::vec3 Position();
    glm::vec3 Front();
    glm::vec3 Up();
    glm::vec3 Right();
    glm::vec3 WorldUp();

    static glm::vec3 POSITION;
    
};

}