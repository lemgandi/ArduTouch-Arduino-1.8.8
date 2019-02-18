/*
    Vibrato.h  

    Declaration of Vibrato classes.

    ---------------------------------------------------------------------------
 
    Copyright (C) 2018, Cornfield Electronics, Inc.
 
    This work is licensed under the Creative Commons Attribution-ShareAlike 3.0 
    Unported License.
 
    To view a copy of this license, visit
    http://creativecommons.org/licenses/by-sa/3.0/
 
    Created by Bill Alessi & Mitch Altman.
 
   ---------------------------------------------------------------------------
*/

#ifndef VIBRATO_H_INCLUDED
#define VIBRATO_H_INCLUDED

#include "LFO.h"

/******************************************************************************
 *
 *                               Vibrato 
 *                                                                            
 ******************************************************************************/

class Vibrato : public FadeLFO      // stock vibrato
{
   public:

   Vibrato()
   {
      shortcut = 'v';
   }

   void   evaluate();               // set output val (as a function of LFO pos)
   void   iniPos();                 // set initial osc position

   #ifdef CONSOLE_OUTPUT
   const char*  prompt();           // return object's prompt string
   #endif

} ;

/******************************************************************************
 *
 *                               DelayVibrato 
 *
 ******************************************************************************/

class DelayVibrato : public Vibrato
{
   typedef Vibrato super;           // superclass is Vibrato

   word  delay;                     // delay this many updates before engaging vibrato 
   word  delayDC;                   // downcounter to engaging vibrato
   
   public:
   
   bool charEv( char );             // handle a character event
   void dynamics();                 // perform a dynamic update

} ;

#endif   // ifndef VIBRATO_H_INCLUDED
