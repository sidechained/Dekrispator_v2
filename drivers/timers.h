// Author: Xavier Halgand

#ifndef __TIMERS_H
#define __TIMERS_H

#include <audio_conf.h>
#include <stdint.h>
#include <stdbool.h>
#include "CONSTANTS.h"
#include "stm32f4_discovery_audio.h"
#include "stm32f4_discovery.h"
#include "soundGen.h"

void 		TimingDelay_Decrement(void);
void 		setSysTick(void);
uint32_t 	getTime(void);
void 		setTime(uint32_t val);
void 		start_LED_On(Led_TypeDef Led, uint32_t duration);
void 		update_temporized_LED(Led_TypeDef Led);
void 		DebounceUserButton(void);

#endif