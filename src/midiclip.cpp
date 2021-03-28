#include "midiclip.h"
#include "global.h"

MIDIClip::MIDIClip()
{

}


void MIDIClip::GetWave(stk::StkFrames *frame)
{
   stk::Flute instrument(20);

   for(int i = 0; i < midiEvents.size(); i++)
   {
       MIDIEvent event = midiEvents.at(i);
       int maintainIndex = Beat2Index(event.maintainBeat);
       stk::StkFrames eventFrame(maintainIndex);

       instrument.tick(eventFrame);

       int beginIndex = Beat2Index(event.beginBeat);

       Overlay(*frame,eventFrame,beginIndex);
   }

   instrument.tick(*frame);
}
