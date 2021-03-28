#ifndef CLIP_H
#define CLIP_H

#include "stk/SineWave.h"

class Clip
{
public:
    double beginBeat = 0; //beat
    double maintainBeat = 0;
public:
    Clip();

    virtual void GetWave(stk::StkFrames *frame) = 0;
};

#endif // CLIP_H
