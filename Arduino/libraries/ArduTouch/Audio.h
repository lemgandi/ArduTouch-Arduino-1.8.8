/*
    Audio.h  

    Declarations for system audio routines and state variables.

    ---------------------------------------------------------------------------
 
    Copyright (C) 2016, Cornfield Electronics, Inc.
 
    This work is licensed under the Creative Commons Attribution-ShareAlike 3.0 
    Unported License.
 
    To view a copy of this license, visit
    http://creativecommons.org/licenses/by-sa/3.0/
 
    Created by Bill Alessi & Mitch Altman.
 
   ---------------------------------------------------------------------------
*/

#ifndef AUDIO_H_INCLUDED
#define AUDIO_H_INCLUDED

#include "Arduino.h"
#include "Console_.h"

#define cbi(sfr, bit) (_SFR_BYTE(sfr) &= ~_BV(bit))
#define sbi(sfr, bit) (_SFR_BYTE(sfr) |= _BV(bit))

/* ------------------------      public vars      -------------------------- */

const  byte  audioBufSz  = 17;         // # of records per audio buffer
extern const double audioRate;         // audio playback rate 
extern const byte   bufsPerDyna;       // # buffers rendered per dynamic update
extern const double dynaRate;          // dynamic update rate
extern const byte   ticksPerDyna;      // # ticks per dynamic update
extern const word   ticksPerSec;       // (int )audioRate

/* ----------------------     public functions     ------------------------- */

namespace audio 
{
   extern void disable();              // disable audio output
   extern void enable();               // enable audio output
   extern bool enabled();              // audio is enabled
   extern void wait( byte );           // wait for buffers to be rendered
}


#endif   // ifndef AUDIO_H_INCLUDED
