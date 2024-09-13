/*
 * Copyright 2021 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * @file  nmh1000_driver.h
 * @brief This header contains definitions and interface for the nmh1000 sensor driver.
*/
#ifndef NMH1000_DRIVER_H_
#define NMH1000_DRIVER_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "nmh1000_regdef.h"
#include "sensor_common.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Typedefs
 ******************************************************************************/


/*!
 * @brief nmh1000 error_code
 */
typedef enum nmh1000_error_code
{
    NMH1000_DEVICE_NOT_FOUND       = 1,  /*!< Device not found, wrong who I am value.*/
	NMH1000_DEVICE_ERROR           = 2,  /*!< Device error, Wrong data.*/
}nmh1000_error_code_t;

/*!
* nmh1000 driver handler
*/
typedef struct nmh1000_driver
{
	sensor_comm_handle_t comHandle;               /*!< Pointer to the communication handler*/
	uint8_t whoAMI;								  /*!< Who AMI value of the device*/
}nmh1000_driver_t ;

/*******************************************************************************
 * Constants
 ******************************************************************************/

/*******************************************************************************
 * Global Variables
 ******************************************************************************/

/*******************************************************************************
 * APIs Prototype
 ******************************************************************************/

/*! @brief       The interface function to initialize the nmh1000 sensor.
 *  @details     This function initialize the nmh1000 sensor.
 *  @param[in]   pDriver - Pointer to the driver.
 *  @return      returns the status of the operation.
 *
 */
uint8_t nmh1000_init(nmh1000_driver_t *pDriver);

/*! @brief       The interface function read from the nmh1000 sensor register.
 *  @details     This function read a register value from a nmh1000 sensor register. Note: it supports only single byte read at a time
 *  @param[in]   pDriver - Pointer to the driver.
 *  @param[in]   address - Address from the register to read.
 *  @param[out]  pReadBuffer - a pointer to read buffer to to store the requested data read.
 *  @return      returns the status of the operation.
 */
uint8_t nmh1000_read_reg(nmh1000_driver_t *pDriver, uint16_t address, uint8_t *pReadBuffer);
/*! @brief       The interface function write to a nmh1000 sensor register.
 *  @details     This function write to the nmh1000 sensor register.Note: it supports only single byte write at a time
 *  @param[in]   pDriver - Pointer to the driver.
 *  @param[in]   pWriteAddress - Address from the register to read.
 *  @param[in]   data - data to be written.
 *  @return      returns the status of the operation.
 */
uint8_t nmh1000_write_reg(nmh1000_driver_t *pDriver, uint16_t pWriteAddress, uint8_t data);
/*! @brief       The interface function to get magnetic data.
 *  @details     read magnetic data from the OUT_M_REG register
 *  @param[in]   pDriver - Pointer to the driver.
 *  @param[out]  pPressure - return the pressure data
 *  @return      returns the status of the operation.
 */
uint8_t nmh1000_get_magnetic_data(nmh1000_driver_t *pDriver, uint8_t *pMagData);

#endif /* FXPS7XXX_DRIVER_H_ */
