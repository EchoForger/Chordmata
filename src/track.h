#ifndef TRACK_H
#define TRACK_H

#include <stk/Noise.h>
#include <stk/FileWvOut.h>
#include <stk/SineWave.h>
#include <stk/Chorus.h>



class Track //
{
public:
    Track();

    virtual void GetWave(stk::StkFrames *frame) = 0;
};

#endif // TRACK_H
