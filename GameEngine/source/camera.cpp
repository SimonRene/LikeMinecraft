#include "../include/camera.h"


#include <iostream>


namespace GE {

    glm::vec3 Camera::POSITION = glm::vec3(0.0f, 0.0f, 0.0f);

    Camera::Camera(glm::vec3 position, glm::vec3 up, float yaw, float pitch) : m_pitch(pitch), m_yaw(yaw), m_movementSpeed(SPEED), m_mouseSensitivity(SENSITIVITY), m_zoom(ZOOM), m_near(0.1f), m_far(200.0f), m_position(position), m_worldUp(up), m_front(glm::vec3(0, 0, 0)), m_up(glm::vec3(0, 0, 0)), m_right(glm::vec3(0, 0, 0))
{
    updateCameraVectors();
    POSITION = m_position;
}

Camera::~Camera()
{
}


void Camera::updateCameraVectors()
{
    // calculate the new Front vector
    glm::vec3 front;
    front.x = cos(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
    front.y = sin(glm::radians(m_pitch));
    front.z = sin(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
    m_front = glm::normalize(front);
    // also re-calculate the Right and Up vector
    m_right = glm::normalize(glm::cross(m_front, m_worldUp));  // normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
    m_up    = glm::normalize(glm::cross(m_right, m_front));
}



// processes input received from a mouse input system. Expects the offset value in both the x and y direction.
void Camera::ProcessMouseMovement(float xoffset, float yoffset, GLboolean constrainPitch)
{
    xoffset *= m_mouseSensitivity;
    yoffset *= m_mouseSensitivity;

    m_yaw   += xoffset;

    // TODO: negative yoffset???
    m_pitch -= yoffset;

    // make sure that when pitch is out of bounds, screen doesn't get flipped
    if (constrainPitch)
    {
        if (m_pitch > 89.0f)
            m_pitch = 89.0f;
        if (m_pitch < -89.0f)
            m_pitch = -89.0f;
    }

    // update Front, Right and Up Vectors using the updated Euler angles
    updateCameraVectors();
}

// processes input received from any keyboard-like input system. Accepts input parameter in the form of camera defined ENUM (to abstract it from windowing systems)
void Camera::ProcessKeyboard(Camera_Movement direction, float deltaTime)
{
    float velocity = m_movementSpeed * deltaTime;
    if (direction == FORWARD)
        m_position += m_front * velocity;
    if (direction == BACKWARD)
        m_position -= m_front * velocity;
    if (direction == LEFT)
        m_position -= m_right * velocity;
    if (direction == RIGHT)
        m_position += m_right * velocity;
    if (direction == UP)
        m_position += m_worldUp * velocity;
    if (direction == DOWN)
        m_position -= m_worldUp * velocity;

    POSITION = m_position;
}

// processes input received from a mouse scroll-wheel event. Only requires input on the vertical wheel-axis
void Camera::ProcessMouseScroll(float yoffset)
{
    m_zoom -= (float)yoffset;
    if (m_zoom < 1.0f)
        m_zoom = 1.0f;
    if (m_zoom > 45.0f)
        m_zoom = 45.0f; 

    std::cout << "Camera Zoom: " << m_zoom << std::endl;
} 

// returns the view matrix calculated using Euler Angles and the LookAt Matrix
glm::mat4 Camera::GetViewMatrix()
{
    return glm::lookAt(m_position, m_position + m_front, m_up);
}

glm::mat4 Camera::getProjectionMatrix(float screenWidth, float screenHight) {
    return glm::perspective(glm::radians<float>(m_zoom), screenWidth / screenHight, m_near, m_far);
}


void Camera::setYaw(double yaw) {
    m_yaw = yaw;
    updateCameraVectors();
}

void Camera::setPitch(double pitch) {

    if (pitch > 89.0)
        pitch = 89.0;
    if (pitch < -89.0)
        pitch = -89.0;

    m_pitch = pitch;

    updateCameraVectors();
}

bool Camera::setNear(float near) {
    if (near >= m_far)
        return false; // new near value bigger than current far value

    m_near = near;
    return true;
}

bool Camera::setFar(float far) {
    if (far <= m_near)
        return false; // new far value smaller than current near value

    m_far = far;
    return true;
}


double Camera::Yaw() {
    return m_yaw;
}

double Camera::Pitch() {
    return m_pitch;
}

glm::vec3 Camera::Position() {
    return m_position;    
}

glm::vec3 Camera::Front() {
    return m_front;    
}

glm::vec3 Camera::Up() {
    return m_up;    
}

glm::vec3 Camera::Right() {
    return m_right;    
}

glm::vec3 Camera::WorldUp() {
    return m_worldUp;    
}


double Camera::Zoom() {
    return m_zoom;
}


void Camera::setMovementSpeed(double speed) {
    m_movementSpeed = speed;
}



const float Camera::YAW         = -90.0f;
const float Camera::PITCH       =  0.0f;
const float Camera::SPEED       =  10.0f;
const float Camera::SENSITIVITY =  0.1f;
const float Camera::ZOOM        =  45.0f;

}