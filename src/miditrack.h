#ifndef MIDITRACK_H
#define MIDITRACK_H

#include "track.h"
#include "midiclip.h"
#include "stk/Instrmnt.h"
#include <vector>


class MIDITrack : public Track
{

    vector<MIDIClip>midiClips;
    stk::Instrmnt *instrmnt;

public:
    MIDITrack();


    virtual void GetWave(stk::StkFrames *frame);
    void GetClipWave(stk::StkFrames *frame, const MIDIClip &clip);
};

#endif // MIDITRACK_H
