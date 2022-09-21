// Author: 	Xavier Halgand

#include "main.h"

USBH_HandleTypeDef hUSBHost; /* USB Host handle */
MIDI_ApplicationTypeDef Appli_state = APPLICATION_IDLE;

static void SystemClock_Config(void);
static void USBH_UserProcess_callback(USBH_HandleTypeDef *pHost, uint8_t vId);

// prevent annoying arm compile warnings:
void _close(void) {}
void _lseek(void) {}
void _read(void) {}
void _write(void) {}

void ButtonPressed_action(void)
{
	// nothing to do 
}

void ButtonReleased_action(void)
{
	// nothing to do
}

int main(void)
{
	HAL_Init();

	// Initialize LEDs mounted on STM32F4-Discovery board
	BSP_LED_Init(LED3);
	BSP_LED_Init(LED4);
	BSP_LED_Init(LED5);
	BSP_LED_Init(LED6);

	// Configure the system clock
	SystemClock_Config();

	// Initialize User Button
	BSP_PB_Init(BUTTON_KEY, BUTTON_MODE_EXTI);

	Synth_Init();
	audio_init();

	// Init Host Library
	USBH_Init(&hUSBHost, USBH_UserProcess_callback, 0);

	// Add Supported Class
	USBH_RegisterClass(&hUSBHost, USBH_MIDI_CLASS);

	// Start Host Process
	USBH_Start(&hUSBHost);

	while (1)
	{
		MIDI_Application();

		// USBH_Background Process */
		USBH_Process(&hUSBHost);
	}
}

static void USBH_UserProcess_callback(USBH_HandleTypeDef *pHost, uint8_t vId)
{
	switch (vId)
	{
	case HOST_USER_SELECT_CONFIGURATION:
		break;

	case HOST_USER_DISCONNECTION:
		Appli_state = APPLICATION_DISCONNECT;
		BSP_LED_Off(LED_Green);
		BSP_LED_Off(LED_Blue);
		break;

	case HOST_USER_CLASS_ACTIVE:
		Appli_state = APPLICATION_READY;
		BSP_LED_On(LED_Green);
		BSP_LED_Off(LED_Blue);
		//BSP_LED_Off(LED_Red);
		break;

	case HOST_USER_CONNECTION:
		Appli_state = APPLICATION_START;
		BSP_LED_On(LED_Blue);
		break;

	default:
		break;
	}
}

// See original Dekrispator main.c for System Clock Config settings
static void SystemClock_Config(void)
{
	RCC_ClkInitTypeDef RCC_ClkInitStruct;
	RCC_OscInitTypeDef RCC_OscInitStruct;

	/* Enable Power Control clock */
	__PWR_CLK_ENABLE();

	/* The voltage scaling allows optimizing the power consumption when the device is
	 clocked below the maximum system frequency, to update the voltage scaling value
	 regarding system frequency refer to product datasheet.  */
	__HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

	/* Enable HSE Oscillator and activate PLL with HSE as source */
	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
	RCC_OscInitStruct.HSEState = RCC_HSE_ON;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
	RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
	RCC_OscInitStruct.PLL.PLLM = 8;
	RCC_OscInitStruct.PLL.PLLN = 336;
	RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
	RCC_OscInitStruct.PLL.PLLQ = 7;
	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
	{
		Error_Handler();
	}

	/* Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2
	 clocks dividers */
	RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;
	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
	{
		Error_Handler();
	}
}

void Error_Handler(void)
{
	/* Turn LED5 on */
	BSP_LED_On(LED_Red);
	while (1)
	{
	}
}