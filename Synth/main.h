// Author: 	Xavier Halgand

#ifndef __MAIN_H
#define __MAIN_H

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "stm32f4xx_hal.h"
#include "stm32f4_discovery.h"
#include "stm32f4_discovery_audio.h"
#include "stm32f4_discovery_accelerometer.h"
#include <stdio.h>
#include "stm32f4xx_it.h"
#include "lis302dl.h"

#include "usbh_MIDI.h"
#include "MIDI_application.h"
#include "timers.h"
#include "random.h"
#include "CONSTANTS.h"

void Error_Handler(void);

#endif