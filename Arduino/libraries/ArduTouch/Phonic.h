/*
    Phonic.h  

    Declaration of the Phonic and Stereophonic classes.

    ---------------------------------------------------------------------------
 
    Copyright (C) 2016, Cornfield Electronics, Inc.
 
    This work is licensed under the Creative Commons Attribution-ShareAlike 3.0 
    Unported License.
 
    To view a copy of this license, visit
    http://creativecommons.org/licenses/by-sa/3.0/
 
    Created by Bill Alessi & Mitch Altman.
 
   ---------------------------------------------------------------------------
*/

#ifndef PHONIC_H_INCLUDED
#define PHONIC_H_INCLUDED

#include "Control.h"

class Phonic : public DynaControl
{
   typedef DynaControl super;       // superclass is DynaControl

   public:

   Phonic()
   {
      flags &= ~RSTMUTE;            // by default, a Phonic is not muted
   }

   boolean charEv( char );          // process a character event
   boolean evHandler( obEvent );    // handle an onboard event
   virtual void setVol( byte );     // set the volume level (0-255)

   virtual void output( char* ) 
   {
      // write mono output to an audio buffer
   };     

   protected:

   byte    vol;                     // volume level (0-255)  

} ;

class StereoPhonic : public Phonic
{
   public:

   virtual void output( char*, char* ) 
   {
      // write stereo output to a left-right pair of audio buffers
   };  

} ; 

#endif   // ifndef PHONIC_H_INCLUDED
