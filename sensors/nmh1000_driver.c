/*
 * Copyright 2021 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * @file nmh1000_driver.c
 * @brief The nmh1000_driver.c file implements the sensor driver interface for nmh1000 sensors.

 */

//-----------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------
#include "sensor_comm.h"
#include "nmh1000_driver.h"

#include "sensor_comm.h"
#include "sensor_common.h"

//-----------------------------------------------------------------------
// Global Variables
//-----------------------------------------------------------------------

//-----------------------------------------------------------------------
// Typedefs  and macros
//-----------------------------------------------------------------------

//-----------------------------------------------------------------------
// Functions
//-----------------------------------------------------------------------

/*
   nmh1000_init
 */
uint8_t nmh1000_init(nmh1000_driver_t *pDriver)
{
  // Initial the sensor driver handler and interfaces
    if(NULL == pDriver){
        return SENSOR_INVALIDPARAM_ERR;
    } 
    uint8_t status = SENSOR_SUCCESS;
    // initialize the communication channel
    status = sensor_comm_init(&pDriver->comHandle);
    if(status != SENSOR_SUCCESS){
    	return status;
    }

  	status = sensor_comm_read(&pDriver->comHandle, NMH1000_WHO_AM_I, 1 , &pDriver->whoAMI);

	return status;
}
/*
   nmh1000_read_reg
 */
uint8_t nmh1000_read_reg(nmh1000_driver_t *pDriver, uint16_t address, uint8_t *pReadBuffer)
{
	
	if((NULL == pDriver) || (NULL == pReadBuffer))
	{
		return SENSOR_INVALIDPARAM_ERR;
	}
    uint8_t status = SENSOR_SUCCESS;

	status = sensor_comm_read(&pDriver->comHandle, address, 1, pReadBuffer);
	
    return status;
}
/*
   nmh1000_write_reg
 */
uint8_t nmh1000_write_reg(nmh1000_driver_t *pDriver, uint16_t address, uint8_t data)
{
	if(NULL == pDriver)
	{
		return SENSOR_INVALIDPARAM_ERR;
	}
    uint8_t status = SENSOR_SUCCESS;

 	status = sensor_comm_write(&pDriver->comHandle, address, 1, &data);
	
	return status;	
}

/*
   nmh1000_get_magnetic_data
 */
uint8_t nmh1000_get_magnetic_data(nmh1000_driver_t *pDriver, uint8_t *pMagData)
{
	if(NULL == pDriver)
	{
		return SENSOR_INVALIDPARAM_ERR;
	}
	uint8_t status = SENSOR_SUCCESS;
	status = sensor_comm_read(&pDriver->comHandle, NMH1000_OUT_M_REG, 1, pMagData);
	// last two bits are noise, so discarding those bits.
	*pMagData = *pMagData & 0xFC;

    return status;
}

