#ifndef GLOBAL_H
#define GLOBAL_H

#include "mainwindow.h"
#include "stk/SineWave.h"

int BPM;
int sampleRate;



inline double Beat2Second(double beat);
inline int Second2Index(double second);
inline int Beat2Index(double beat);
inline void Overlay(StkFrames &frame, const StkFrames &deta, int beginIndex = 0);

#endif // GLOBAL_H
