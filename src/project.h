#ifndef PROJECT_H
#define PROJECT_H

//index  第几个采样点
//beat   第几拍
//second 第几秒

#include <vector>
#include "track.h"

using namespace std;

class Project
{
public:

    int BPM = 60;
    int sampleRate = 44100;
    vector<Track> tracks;

public:
    Project();

    void GetWave(stk::StkFrames *frame);
};

#endif // PROJECT_H
