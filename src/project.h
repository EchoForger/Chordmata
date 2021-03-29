#ifndef PROJECT_H
#define PROJECT_H

#include <vector>
#include "track.h"
#include "miditrack.h"

using namespace std;

class Project
{
public:

    vector<MIDITrack> tracks;

    int BPM;
    int beatLength;
    int sampleRate;


public:
    Project(int BPM, int beatLength, int sampleRate);

};

#endif // PROJECT_H
