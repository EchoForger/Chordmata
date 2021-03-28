#ifndef MIDIEVENT_H
#define MIDIEVENT_H


class MIDIEvent
{
public:
    double beginBeat = 0; //beat
    double maintainBeat = 0;
    int intensity = 80; //rang in [0, 127]
public:
    MIDIEvent(double beginBeat, double maintainBeat);
};

#endif // MIDIEVENT_H
