#pragma once
class IFourier
{
public:
    float vp;
    float T;
    float w0;
    float offset;
    
    IFourier(float vp, float T, float w0, float offset) : vp(vp), T(T), w0(w0), offset(offset) {};
    virtual void calc();
};