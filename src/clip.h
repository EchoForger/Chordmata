#ifndef CLIP_H
#define CLIP_H

#include "stk/SineWave.h"

class Clip
{
public:
    double beginBeat; //beat
    double maintainBeat;
public:
    Clip(double beginBeat, double maintainBeat);
};

#endif // CLIP_H
