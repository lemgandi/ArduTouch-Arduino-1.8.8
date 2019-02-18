# ArduTouch Arduino Code Modified to Work with Arduino-1.8.8

This is Arduino code modified to work with Arduino-1.8.8.  The original code had setup() methods in several root objects.
The Arduino IDE after about version 1.8.5 gives the error:

`
Arpology:741:9: error: 'void ArpSynth::setup()' cannot be overloaded
    void setup() 
         ^
Arpology:1208:6: error: with 'void ArpSynth::setup()'
 void setup()
      ^
/home/devel/ArduTouch-master/Arduino/Arpology/Arpology/Arpology.ino: In member function 'void ArpSynth::setup()':
Arpology:743:7: error: 'setup' is not a member of 'ArpSynth::super {aka QuadDualPanSynth}'
       super::setup();
       ^
exit status 1
'void ArpSynth::setup()' cannot be overloaded
`

I presume due to a confusion in namespaces.  This version of the code replaces the "setup()" methods with 
"initialize()", which doesn't tickle this particular bug.

