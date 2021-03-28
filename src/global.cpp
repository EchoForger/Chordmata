#include "global.h"

double Beat2Second(double beat)
{
    return beat/BPM*60.0;
}

int Second2Index(double second)
{
    return second*sampleRate;
}

int Beat2Index(double beat)
{
    return Second2Index(Beat2Second(beat));
}

void Overlay(StkFrames &frame, const StkFrames &deta, int beginIndex)
{
    for(int i = 0; i < deta.size(); i++)
    {
        frame[i+beginIndex] += deta[i];
    }
}
