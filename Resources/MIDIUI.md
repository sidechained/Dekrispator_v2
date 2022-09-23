https://faustdoc.grame.fr/manual/syntax/#user-interface-primitives-and-configuration
https://github.com/Fr0stbyteR/faust-ui
https://faustdoc.grame.fr/manual/midi/

declare options "[midi:on]";

button Primitive
checkbox Primitive
hslider Primitive
vslider Primitive [style:knob]
nentry Primitive
hgroup Primitive
vgroup Primitive
tgroup Primitive
vbargraph Primitive
hbargraph Primitive
attach Primitive

// FADERS 1-8
CC 0:
CC 1:
CC 2:
CC 3:
CC 4:
CC 5:
CC 6:
CC 7:

// KNOBS 1-8
CC 16:
CC 17:
CC 18:
CC 19:
CC 20:
CC 21:
CC 22:
CC 23:

// SOLO BUTTONS 1-8
CC 32:
CC 33: 
CC 34:
CC 35:
CC 36:
CC 37:
CC 38:
CC 39:

// MUTE BUTTONS 1-8
CC 48:
CC 49:
CC 50:
CC 51:
CC 52:
CC 53:
CC 54:
CC 55:

// RECORD ARM BUTTONS 1-8 (commented out as these currently play notes 96-103)
CC 64:
CC 65:
CC 66:
CC 67:
CC 68:
CC 69:
CC 70:
CC 71:

// LOWER TRANSPORT SECTION
CC 43: // Rewind Button
CC 44: // Fast Forward Button
CC 42: // Stop
CC 41: // Play
CC 45: // Record

// UPPER TRANSPORT SECTION
CC 46: // Cycle 
CC 58: // Track Decrement (<)
CC 59: // Track Increment (>)
CC 60: // Marker Set
CC 61: // Marker Increment (<)
CC 62: // Marker Decrement (>)
