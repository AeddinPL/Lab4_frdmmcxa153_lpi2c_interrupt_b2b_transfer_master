/*
 * Copyright 2019-2020 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * @file  sensor_comm.h
 * @brief This header contains common definitions for sensor communication interface function.
   This is virtual definition of the sensor communication interface depends on how it connected to MCU peripherals	
*/

#ifndef SENSOR_COMM_H_
#define SENSOR_COMM_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <stdint.h>

/*  SDK Included Files */
#include "board.h"
#include "fsl_lpi2c.h"
#include "pin_mux.h"
#include "clock_config.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
//
#define NMH1000_I2C_ADDR_VAL  0x60
/* Sensor Interface I2C Bus Configuration */

#define I2C_BAUDRATE             100000U
#define I2C_DEVICE_NAME          LPI2C0
#define I2C_CLOCK_FREQUENCY      CLOCK_GetFreq(kCLOCK_BusClk)
/*******************************************************************************
 * Typedefs
 ******************************************************************************/

/*!
 * @brief Sensor Interface Error Type.
 */
typedef struct sensor_comm_handle
{
    void *pComm;
	uint8_t* parm;
}sensor_comm_handle_t;
/*******************************************************************************
 * Constants
 ******************************************************************************/

/*******************************************************************************
 * Global Variables
 ******************************************************************************/

/*! @brief I2C master handle structure. */
typedef struct sensor_i2c_handle
{
	lpi2c_master_handle_t g_i2cSensorHandle;
	uint16_t slaveAddr;
} sensor_i2c_handle_t;
/*******************************************************************************
 * Prototypes
 ******************************************************************************/
uint8_t sensor_comm_init(sensor_comm_handle_t *pComHandle);
uint8_t sensor_comm_write(sensor_comm_handle_t *pComHandle, uint16_t offset, uint16_t size, uint8_t *pWritebuffer);
uint8_t sensor_comm_read(sensor_comm_handle_t *pComHandle, uint16_t offset, uint16_t size, uint8_t *pReadbuffer);
#endif /* SENSOR_COMM_H_ */
