#include "miditrack.h"
#include "global.h"


MIDITrack::MIDITrack()
{

}

void MIDITrack::GetWave(stk::StkFrames *frame)
{
    for (int i = 0; i < midiClips.size(); i++)
    {
        stk::StkFrames clipFrame;
        midiClips.at(i).GetWave(&clipFrame);
        int beginIndex = Beat2Index(midiClips.at(i).beginBeat);
        Overlay(*frame, clipFrame, beginIndex);
    }
}
