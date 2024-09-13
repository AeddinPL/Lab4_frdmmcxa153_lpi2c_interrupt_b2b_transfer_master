/*
 * Copyright 2019-2020 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * @file  sensor_common.h
 * @brief This header contains common definitions for generic sensor drivers.
*/

#ifndef SENSOR_COMMON_H_
#define SENSOR_COMMON_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <stdint.h>
#include "sensor_comm.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/
/* Used with the RegisterWriteList types as a list terminator */
#define __END_WRITE_DATA__            \
    {                                 \
        .writeTo = 0xFFFF, .value = 0 \
    }
/* Used with the RegisterReadList types as a list terminator */
#define __END_READ_DATA__                 \
    {                                     \
        .readFrom = 0xFFFF, .numBytes = 0 \
    }	
#define NO_DATA_MASK 0xFF        /*!< No data mask. Completely wirte the register.*/    	
/*******************************************************************************
 * Typedefs
 ******************************************************************************/
/*!
 * @brief Sensor Interface Error Type.
 */
typedef enum sensor_error_type
{
    SENSOR_SUCCESS           = 0,  /*!< Success value returned by sensor APIs. */
    SENSOR_INVALIDPARAM_ERR  = 1,  /*!< Invalid Param Error value by SENSOR APIs. */
    SENSOR_INIT_ERR          = 2,  /*!< SENSOR Init Error value returned by Init API. */
    SENSOR_WRITE_ERR         = 3,  /*!< SENSOR Write Error value returned by Write API. */
    SENSOR_READ_ERR          = 4,  /*!< SENSOR Read Error value returned by Read API. */
	SENSOR_BAD_ADDRESS       = 5,  /*!< SENSOR Error value returned for bad address access. */
} fxos8700_error_type_t;

/*!
 * @brief This structure defines the Write command List.
 */
typedef struct
{
    uint16_t writeTo;              /*!< Address where the value is writes to.*/
    uint8_t value;                 /*!< value. Note that value should be shifted based on the bit position.*/
    uint8_t mask;                  /*!< mask of the field to be set with given value.*/
} registerwritelist_t;

/*!
 * @brief This structure defines the Read command List.
 */
typedef struct
{
    uint16_t readFrom;             /*!< Address where the value is read from .*/
    uint8_t numBytes;              /*!< Number of bytes to read.*/
} registerreadlist_t;

/*******************************************************************************
 * Constants
 ******************************************************************************/

/*******************************************************************************
 * Global Variables
 ******************************************************************************/

/*! @brief       The interface function to do burst write.
 *  @details     This function is helper function and call only once communication interface is initialized.
                 This function initialize perform multiple register write based on the items in the list.
 *  @param[in]   pDriver - Pointer to the driver.
 *  @param[in]   pRegisterList -  List of registers.
 *  @return      returns the status of the operation.
 */ 
uint8_t sensor_burst_write(sensor_comm_handle_t* pCommHandle, const registerwritelist_t *pRegisterList);
/*! @brief       The interface function to do burst read.
 *  @details     This function is helper function and call only once communication interface is initialized.
                 This function initialize perform multiple register read based on the items in the list.
 *  @param[in]   pDriver - Pointer to the driver.
 *  @param[in]   pRegisterList -  List of registers.
 *  @param[in]   pOutBuffer    -  Read buffer. This is an continuous set of data buffer. 
 *  @return      returns the status of the operation.
 */
uint8_t sensor_burst_read(sensor_comm_handle_t* pCommHandle, const registerreadlist_t *pRegisterList, uint8_t* pOutBuffer);
#endif /* SENSOR_COMMON_H_ */
