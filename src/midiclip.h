#ifndef MIDICLIP_H
#define MIDICLIP_H

#include "clip.h"
#include "midievent.h"
#include "stk/Flute.h"

#include <vector>

using namespace std;

class MIDIClip : public Clip
{
public:
    vector<MIDIEvent>midiEvents;
public:
    MIDIClip(double beginBeat, double maintainBeat);
};

#endif // MIDICLIP_H
