#ifndef AUDIO_ENGINE_CONSTANTS_H
#define AUDIO_ENGINE_CONSTANTS_H

// center value of PAN, BEND, TUNE (-64 ~ +63)
#define C_V 	0x40

// imi.echo vol   ***lib
#define xIECV	0x08
// imi.echo len   ***lib
#define xIECL	0x09

// fine
#define FINE 	0xb1
// goto
#define GOTO 	0xb2
// pattern play
#define PATT 	0xb3
// pattern end
#define PEND 	0xb4
// repeat
#define REPT 	0xb5
// memacc op adr dat ***lib
#define MEMACC 	0xb9
// priority
#define PRIO 	0xba
// tempo (BPM/2)
#define TEMPO 	0xbb
// key shift
#define KEYSH 	0xbc
// voice #
#define VOICE 	0xbd
// volume
#define VOL 	0xbe
// panpot (c_v+??)
#define PAN 	0xbf
// pitch bend (c_v+??)
#define BEND 	0xc0
// bend range
#define BENDR 	0xc1
// LFO speed
#define LFOS 	0xc2
// LFO delay
#define LFODL 	0xc3
// modulation depth
#define MOD 	0xc4
// modulation type
#define MODT 	0xc5
// micro tuning (c_v+??)
#define TUNE 	0xc8
// extend command  ***lib
#define XCMD 	0xcd
// End of Tie
#define	EOT 	0xce
// Tie
#define	TIE 	0xcf

#endif /* AUDIO_ENGINE_CONSTANTS_H */
