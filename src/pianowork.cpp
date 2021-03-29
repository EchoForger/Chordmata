#include "pianowork.h"

Pianowork::Pianowork(double beginBeat, double maintainBeat, Chord chord)
    :MIDIClip(beginBeat,maintainBeat),chord(chord)
{

}
