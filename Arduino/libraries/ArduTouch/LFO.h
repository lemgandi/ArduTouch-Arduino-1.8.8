/*
    LFO.h  

    Declaration of the LFO class.

    ---------------------------------------------------------------------------
 
    Copyright (C) 2016, Cornfield Electronics, Inc.
 
    This work is licensed under the Creative Commons Attribution-ShareAlike 3.0 
    Unported License.
 
    To view a copy of this license, visit
    http://creativecommons.org/licenses/by-sa/3.0/
 
    Created by Bill Alessi & Mitch Altman.
 
   ---------------------------------------------------------------------------
*/

#ifndef LFO_H_INCLUDED
#define LFO_H_INCLUDED

#include "Control.h"

class LFO : public Factor
{
   typedef Factor super;         // superclass is Factor

   public:

   boolean charEv( char );       // process a character event
   void    dynamics();           // update object dynamics
   boolean evHandler( obEvent ); // handle an onboard event
   virtual void evaluate();      // compute output value from osc position
   double  getDepth();           // get oscillation depth
   double  getFreq();            // get oscillation frequency
   virtual void iniPos();        // set initial osc position
   void    iniVal();             // set initial osc position and evaluate
   void    iniOsc(double,double);// initialize oscillator
   void    setDepth( double );   // set oscillation depth
   void    setFreq( double );    // set oscillation frequency

   #ifdef KEYBRD_MENUS
   char    menu( key );          // given a key, return a character 
   #endif

   #ifdef CONSOLE_OUTPUT
   const  char  *prompt();       // return object's prompt string
   #endif

   protected:

   double  depth;                // oscillation depth (0.0 - 1.0)
   double  pos;                  // cur position within oscillation range
   double  step;                 // change in pos per dynamic update

   private:

   double  freq;                 // oscillation frequency

   void    calcStep();           // calculate step 

} ;


class FadeLFO : public LFO       // LFO with fade capability
{
   typedef LFO super;            // superclass is LFO

   public:

   enum {  // use these bits in the flags byte: 

         FADEOUT = _RESERVE4     // LFO fades out (if not set, LFO fades in)
                                 
        } ;

   boolean charEv( char );       // process a character event
   void    dynamics();           // update object dynamics

   #ifdef KEYBRD_MENUS
   char    menu( key );          // given a key, return a character 
   #endif

   protected:

   byte     time;                // fade time in 1/8th secs (0-255)
   double   fader;               // current fader value
   double   fadeStep;            // increment fader this much per dynamic upd

   void iniFader();              // initialize fader

} ;


class TermLFO : public LFO       // LFO that terminates after n half-cycles
{                                
   typedef LFO super;            // superclass is LFO

   public:

   enum {  // use these bits in the flags byte: 

           PEAK  = _RESERVE4     // trigger LFO starting at peak value 

        } ;

   boolean charEv( char );       // process a character event
   void    dynamics();           // update object dynamics
   void    iniPos();             // set initial osc position

   #ifdef KEYBRD_MENUS
   char    menu( key );          // given a key, return a character 
   #endif

   protected:

   /* The traversal count is the # of half-cycles the LFO will traverse
      once triggered. For example, a traversal count of 2 means the
      LFO will run for 1 complete cycle (i.e. max -> min -> max, 
      or min -> max -> min), then stop. A traversal count of 0 means the
      LFO is free-running (i.e. does not respond to triggers).
   */

   byte    trav;                 // traversal count (0 - 255)
   byte    runDC;                // downcounter (in traversals) to end of run

} ;

#endif   // ifndef LFO_H_INCLUDED
