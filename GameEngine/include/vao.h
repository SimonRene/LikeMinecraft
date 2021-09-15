#pragma once

namespace GE {

class VAO
{
private:
    unsigned int m_id;
public:
    VAO(/* args */);
    ~VAO();

    int bind();
};

}
