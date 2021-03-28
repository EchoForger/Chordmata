#ifndef MIDICLIP_H
#define MIDICLIP_H

#include "clip.h"
#include "midievent.h"
#include "stk/Flute.h"

#include <vector>

using namespace std;

class MIDIClip : public Clip
{
    vector<MIDIEvent>midiEvents;
public:
    MIDIClip();

    virtual void GetWave(stk::StkFrames *frame);
};

#endif // MIDICLIP_H
