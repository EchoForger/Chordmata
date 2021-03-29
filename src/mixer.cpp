#include "mixer.h"

Mixer::Mixer(Project *poj):poj(poj)
{

}

inline double Mixer::Beat2Second(double beat)
{
    return beat / (poj->BPM) * 60.0;
}

inline int Mixer::Second2Index(double second)
{
    return second * (poj->sampleRate);
}

inline int Mixer::Beat2Index(double beat)
{
    return Second2Index(Beat2Second(beat));
}

void Mixer::Mix(stk::StkFrames &origin, const stk::StkFrames &deta, int delayIndex)
{
    for (int i = 0; i < deta.size(); i++)
    {
        int index = i+delayIndex;
        if(index>=0&&index<origin.size())
            origin[index] += deta[i];
    }
}

void Mixer::Gain(stk::StkFrames &origin, double gain, int fromIndex, int endIndex)
{
    if(endIndex == -1) endIndex = origin.size();
    for(int i = fromIndex; i < endIndex; i++)
    {
        if(i>=0&&i<origin.size())
            origin[i] *= gain;
    }
}

void Mixer::GetWave(stk::StkFrames &frame, const MIDIEvent &midiEvent, stk::Instrmnt *instrmnt)
{
    frame.resize(Beat2Index(midiEvent.maintainBeat));
    instrmnt->noteOn(440 * pow(2,midiEvent.tune/12.0),1);
    instrmnt->tick(frame);
    Gain(frame,midiEvent.intensity/128.0);
}

void Mixer::GetWave(stk::StkFrames &frame, const MIDIClip &midiClip, stk::Instrmnt *instrmnt)
{
    frame.resize(Beat2Index(midiClip.maintainBeat));
    for(int i = 0; i < midiClip.midiEvents.size(); i++)
    {
        const MIDIEvent &event = midiClip.midiEvents.at(i);
        stk::StkFrames eventFrame;
        GetWave(eventFrame,event,instrmnt);
        int beginIndex = Beat2Index(event.beginBeat);
        Mix(frame,eventFrame,beginIndex);
    }
}

void Mixer::GetWave(stk::StkFrames &frame, const MIDITrack &midiTrack)
{
    frame.resize(Beat2Index(poj->beatLength));
    for(int i = 0; i < midiTrack.midiClips.size(); i++)
    {
        const MIDIClip &clip = midiTrack.midiClips.at(i);
        stk::StkFrames clipFrame;
        GetWave(clipFrame,clip,midiTrack.instrmnt);
        int beginIndex = Beat2Index(clip.beginBeat);
        Mix(frame,clipFrame,beginIndex);
    }
    Gain(frame,midiTrack.volume);
}

void Mixer::GetWave(stk::StkFrames &frame)
{
    frame.resize(Beat2Index(poj->beatLength));
    for(int i = 0; i < poj->tracks.size(); i++)
    {
        const MIDITrack &track = poj->tracks.at(i);
        stk::StkFrames trackFrame;
        GetWave(trackFrame,track);

        stk::FileWvOut fileOut("track " + to_string(i) + ".wav");
        fileOut.tick(frame);

        Mix(frame,trackFrame);
    }
}
