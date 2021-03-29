#ifndef MIDIEVENT_H
#define MIDIEVENT_H


class MIDIEvent
{
public:
    double beginBeat; //beat
    double maintainBeat;
    int intensity = 80; //rang in [0, 128]
    int tune;
public:
    MIDIEvent(double beginBeat, double maintainBeat, int tuen);
};

#endif // MIDIEVENT_H
