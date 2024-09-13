/*
 * Copyright 2019-2020 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * @file sensor_common.c
 * @brief The sensor_comm.c file implements the sensor common interface across various sensors. 
 */

//-----------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------
#include "sensor_common.h"

//-----------------------------------------------------------------------
// Global Variables
//-----------------------------------------------------------------------

//-----------------------------------------------------------------------
// Functions
//-----------------------------------------------------------------------
/*
   sensor_burst_write
 */
uint8_t sensor_burst_write(sensor_comm_handle_t* pCommHandle, const registerwritelist_t *pRegisterList)
{
    uint8_t status, tempReg = 0;
	
	if((NULL == pCommHandle) || (NULL == pRegisterList))
	{
		return SENSOR_INVALIDPARAM_ERR;
	}
    const registerwritelist_t *pCmd = pRegisterList;
	for(;pCmd->writeTo != 0xFFFF; pCmd++)
	{
	    if(pCmd->mask != NO_DATA_MASK)
		{
			status = sensor_comm_read(pCommHandle, pCmd->writeTo, 1, &tempReg);
		}
		tempReg = (tempReg & ~ pCmd->mask) | pCmd->value;
		status = sensor_comm_write(pCommHandle, pCmd->writeTo, 1, &tempReg);
		if(status != SENSOR_SUCCESS)
		{
			return status;
		}
	
	}
    return SENSOR_SUCCESS;
}

/*
   sensor_burst_read
 */
uint8_t sensor_burst_read(sensor_comm_handle_t* pCommHandle, const registerreadlist_t *pRegisterList, uint8_t* pOutBuffer)
{
    uint8_t status;
	uint8_t* pBuff;
	if((NULL == pCommHandle) || (NULL == pRegisterList))
	{
		return SENSOR_INVALIDPARAM_ERR;
	}
    const registerreadlist_t *pCmd = pRegisterList;
	
	for( pBuff = pOutBuffer ; pCmd->readFrom != 0xFFFF; pCmd++)
	{
		status = sensor_comm_read(pCommHandle, pCmd->readFrom, pCmd->numBytes, pBuff);
		pBuff += pCmd->numBytes;
		if(status != SENSOR_SUCCESS)
		{
			return status;
		}
	}
    return SENSOR_SUCCESS;
}
