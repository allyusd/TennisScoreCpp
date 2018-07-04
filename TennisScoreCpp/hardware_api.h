#pragma once

class HardWareAPI
{
public:
    HardWareAPI() {};
    virtual ~HardWareAPI() {};

    virtual void player1_get() = 0;
    virtual void player2_get() = 0;
};
