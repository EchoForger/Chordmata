#ifndef MIXER_H
#define MIXER_H

#include "project.h"
#include "midievent.h"

#include "stk/SineWave.h"
#include "stk/Instrmnt.h"

class Mixer
{
    Project *poj;
public:
    Mixer(Project *poj);

    void GetWave(stk::StkFrames &frame, const MIDIEvent &midiEvent, stk::Instrmnt *instrmnt);
    void GetWave(stk::StkFrames &frame, const MIDIClip &midiClip, stk::Instrmnt *instrmnt);
    void GetWave(stk::StkFrames &frame, const MIDITrack &midiTrack);
    void GetWave(stk::StkFrames &frame);

    //index  第几个采样点
    //beat   第几拍
    //second 第几秒
    inline double Beat2Second(double beat);
    inline int Second2Index(double second);
    inline int Beat2Index(double beat);

    void Mix(stk::StkFrames &origin, const stk::StkFrames &deta, int delayIndex = 0);
    void Gain(stk::StkFrames &origin, double gain, int fromIndex = 0, int endIndex = -1);
};

#endif // MIXER_H
