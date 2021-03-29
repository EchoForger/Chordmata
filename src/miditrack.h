#ifndef MIDITRACK_H
#define MIDITRACK_H

#include "track.h"
#include "midiclip.h"
#include "stk/Instrmnt.h"
#include <vector>


class MIDITrack : public Track
{
public:
    vector<MIDIClip>midiClips;
    stk::Instrmnt *instrmnt;

public:
    MIDITrack(stk::Instrmnt *instrmnt);

};

#endif // MIDITRACK_H
