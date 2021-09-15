#pragma once

namespace GE {
    
class VBO
{
private:
    unsigned int m_id;
public:
    VBO(/* args */);
    ~VBO();


    int bind();
};

}