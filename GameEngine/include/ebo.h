#pragma once

namespace GE {

class EBO
{
private:
    unsigned int m_id;
public:
    EBO(/* args */);
    ~EBO();

    int bind();
};

}
