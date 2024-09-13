/*
 * Copyright 2021 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * @file nmn1000_app.c
 * @brief The nmn1000_app.c file implements the component library  example application for nmh1000 sensor
 */

//-----------------------------------------------------------------------
// SDK Includes
//-----------------------------------------------------------------------
#include "board.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "fsl_debug_console.h"
#include "fsl_device_registers.h"
#include "fsl_gpio.h"
#include "fsl_port.h"
#include "nmh1000_driver.h"
#include "MCXA153.h"


//-----------------------------------------------------------------------
// Global Variables
//-----------------------------------------------------------------------
volatile uint32_t msTicks = 0;
//-----------------------------------------------------------------------
// Functions
//-----------------------------------------------------------------------
void SysTick_Handler(void)
{
    msTicks++;
}

void delay_ms(uint32_t ms)
{
    uint32_t currentTicks = msTicks;
    while ((msTicks - currentTicks) < ms);
}

void LEDShow (uint8_t value)
{
	if((value<5) & (value>0))
	{
		 LED_RED_OFF();
		 LED_GREEN_OFF();
		 LED_BLUE_OFF();
		return;
	}

	if((value>5)&(value<10))
	{
		LED_RED_OFF();
		LED_GREEN_ON();
		LED_BLUE_OFF();
		return;
	}

	if((value>10)&(value<100))
	{
		LED_RED_OFF();
		LED_GREEN_OFF();
		LED_BLUE_ON();
		return;
	}

	if(value>40000)
	{
		LED_RED_ON();
		LED_GREEN_OFF();
		LED_BLUE_OFF();
		return;
	}
}

void setColor(uint8_t value) {
    uint8_t red = 0, green = 0, blue = 0;

    if (value <= 125) {
        green = 255 - (value * 2); // Decrease green
        blue = value * 2;          // Increase blue
    } else {
        blue = 255 - ((value - 125) * 2); // Decrease blue
        red = (value - 125) * 2;          // Increase red
    }

/*
    if (red > 0)
		LED_RED_ON();
	else
		LED_RED_OFF();

    if (green > 0)
   		LED_GREEN_ON();
   	else
   		LED_GREEN_OFF();

    if (blue > 0)
   		LED_BLUE_ON();
   	else
   		LED_BLUE_OFF();
*/
    GPIO_PinWrite(BOARD_LED_GREEN_GPIO, BOARD_LED_GREEN_GPIO_PIN, green);
    GPIO_PinWrite(BOARD_LED_BLUE_GPIO, BOARD_LED_BLUE_GPIO_PIN, blue);
    GPIO_PinWrite(BOARD_LED_RED_GPIO, BOARD_LED_RED_GPIO_PIN, red);
}

/*! -----------------------------------------------------------------------
 *  @brief       This is the The main function implementation.
 *  @details     This function invokes board initializes routines, then then brings up the sensor and
 *               finally enters an endless loop to continuously read available samples.
 *  @param[in]   void This is no input parameter.
 *  @return      void  There is no return value.
 *  @constraints None
 *  @reentrant  No
 *  -----------------------------------------------------------------------*/
int main(void)
{
    /*! Initialize the MCU hardware. */
	CLOCK_SetClockDiv(kCLOCK_DivLPI2C0, 1u);
	CLOCK_AttachClk(kFRO12M_to_LPI2C0);
    BOARD_InitPins();
    BOARD_InitBootClocks();
    BOARD_InitDebugConsole();
    // Initialize SysTick
    SysTick_Config(SystemCoreClock / 1000); // 1ms interval

    uint8_t magData = 0;

    nmh1000_driver_t driver;


    PRINTF("\r\n NMH1000 Sensor Example with I2C communication !\r\n");\
    if(SENSOR_SUCCESS != nmh1000_init(&driver))
    {
    	PRINTF("\r\n NMH1000 Initialization failed: Check the connection !\r\n");
    	return 1;
    }

    // set the odr
    nmh1000_write_reg(&driver, NMH1000_ODR, 0x2);
    // active the device in auto mode
    nmh1000_write_reg(&driver, NMH1000_CONTROL_REG1, 0x08);


	for(;;) /* Forever loop */
	{
		// get the mag output data
		nmh1000_get_magnetic_data(&driver, &magData);
		PRINTF("\r\n magnetic data output =  %d\r\n", magData);
		//LEDShow(magData);
		setColor(magData);

		delay_ms(100); // Delay for 100 ms

	}

}
