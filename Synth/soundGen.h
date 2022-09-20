/**
 ******************************************************************************
 * File Name          	: soundGen.h
 * Author				: Xavier Halgand
 * Date               	:
 * Description        	:
 ******************************************************************************
 */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __SOUNDGEN_H
#define __SOUNDGEN_H

/* Includes ------------------------------------------------------------------*/

#include <math.h>
#include <stdint.h>
#include <stdbool.h>
#include "CONSTANTS.h"
#include "MIDI_application.h"
#include "random.h"
#include "notesTables.h"
#include "timers.h"

/* Exported functions ------------------------------------------------------- */

void Synth_Init(void);

void make_sound(uint16_t *buf , uint16_t len);

#endif /* __SOUNDGEN_H */
