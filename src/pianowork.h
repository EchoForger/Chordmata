#ifndef PIANOWORK_H
#define PIANOWORK_H

#include "midiclip.h"
#include "chord.h"

class Pianowork : public MIDIClip
{
    Chord chord;
public:
    Pianowork(double beginBeat, double maintainBeat, Chord chord);
};

#endif // PIANOWORK_H
