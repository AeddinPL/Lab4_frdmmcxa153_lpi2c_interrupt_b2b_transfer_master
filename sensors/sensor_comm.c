/*
 * Copyright 2019-2020 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * @file sensor_comm.c
 * @brief The sensor_comm.c file implements the sensor communication virtual interface.
   User application needs to implement/call underlying SDK communication interfaces such i2c/SPI.
   This is the SDK agnostic layer for the sensor for communication.
 */

//-----------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------

/* CompLib Included Files */
#include "sensor_comm.h"
#include "sensor_common.h"
#include "pin_mux.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define TRUE    1
#define FALSE   0

/*******************************************************************************
 * Global Variables
 ******************************************************************************/
volatile bool g_completionFlag = FALSE, g_nakFlag = FALSE;
//extern uint32_t LPI2C0_GetFreq(void);
extern uint32_t LPI2C1_GetFreq(void);
sensor_i2c_handle_t  g_fxps7xxx_i2c_handle;
//lpi2c_master_handle_t g_i2cSensorHandle;
//-----------------------------------------------------------------------
// Functions
//-----------------------------------------------------------------------

/*! @brief I2C Master Event Handler */
void sensor_i2c_handler(LPI2C_Type *base, lpi2c_master_handle_t *handle, status_t status, void *userData)
{
    /* Signal transfer success when received SUCCESS status. */
    if(status == kStatus_Success)
    {
        g_completionFlag = TRUE;
    }
    /* Signal transfer failure when received NAK status. */
    if(status == kStatus_LPI2C_Nak)
    {
        g_nakFlag = TRUE;
    }
}

uint8_t sensor_comm_init(sensor_comm_handle_t *pComHandle)
{
	lpi2c_master_config_t masterConfig;

    /* Initialize I2C Bus. */
	//LPI2C0_InitPins();
	//LPI2C1_InitPins();
    pComHandle->pComm = &g_fxps7xxx_i2c_handle;
    pComHandle->parm = NULL;
    LPI2C_MasterGetDefaultConfig(&masterConfig);
    masterConfig.baudRate_Hz = I2C_BAUDRATE;
    //LPI2C0_GetFreq
    //LPI2C_MasterInit(I2C_DEVICE_NAME, &masterConfig, I2C_CLOCK_FREQUENCY);
    //LPI2C_MasterInit(I2C_DEVICE_NAME, &masterConfig, LPI2C0_GetFreq());
    LPI2C_MasterInit(I2C_DEVICE_NAME, &masterConfig, CLOCK_GetLpi2cClkFreq());
    LPI2C_MasterTransferCreateHandle(I2C_DEVICE_NAME, &((sensor_i2c_handle_t *)pComHandle->pComm)->g_i2cSensorHandle, sensor_i2c_handler, NULL);
    ((sensor_i2c_handle_t *)pComHandle->pComm)->slaveAddr = NMH1000_I2C_ADDR_VAL;
    //I2C_MasterTransferCreateHandle(I2C_DEVICE_NAME, &g_i2cSensorHandle, sensor_i2c_handler, NULL);->
    return SENSOR_SUCCESS;
}

uint8_t sensor_comm_write(sensor_comm_handle_t *pComHandle, uint16_t offset, uint16_t size, uint8_t *pWritebuffer)
{
	LPI2C_Type *base = I2C_DEVICE_NAME;
    status_t reVal = kStatus_Fail;
    lpi2c_master_transfer_t masterXfer;

    memset(&masterXfer, 0, sizeof(masterXfer));
    masterXfer.slaveAddress   = ((sensor_i2c_handle_t *)pComHandle->pComm)->slaveAddr;
    masterXfer.direction      = kLPI2C_Write;
    masterXfer.subaddress     = offset;
    masterXfer.subaddressSize = 1;
    masterXfer.data           = pWritebuffer;
    masterXfer.dataSize       = size;
    masterXfer.flags          = kLPI2C_TransferDefaultFlag;

    g_nakFlag        = FALSE;
    g_completionFlag = FALSE;
    /* Block write registers. */
    reVal = LPI2C_MasterTransferNonBlocking(base, &((sensor_i2c_handle_t *)pComHandle->pComm)->g_i2cSensorHandle, &masterXfer);
    if(reVal != kStatus_Success)
    {
        return SENSOR_WRITE_ERR;
    }

    /*  wait for transfer completion. */
    while((!g_nakFlag) && (!g_completionFlag))
    {
       // SMC_SetPowerModeWait(SMC); // Sleep while waiting for completion
    }

    if(g_nakFlag == FALSE)
    {
        return SENSOR_SUCCESS;;
    }
    else
    {
        return SENSOR_WRITE_ERR;
    }
}

uint8_t sensor_comm_read(sensor_comm_handle_t *pComHandle, uint16_t offset, uint16_t size, uint8_t *pReadbuffer)
{
	LPI2C_Type *base = I2C_DEVICE_NAME;
    status_t reVal = kStatus_Fail;
    lpi2c_master_transfer_t masterXfer;

    memset(&masterXfer, 0, sizeof(masterXfer));
    masterXfer.slaveAddress   = ((sensor_i2c_handle_t *)pComHandle->pComm)->slaveAddr;
    masterXfer.direction      = kLPI2C_Read;
    masterXfer.subaddress     = offset;
    masterXfer.subaddressSize = 1;
    masterXfer.data           = pReadbuffer;
    masterXfer.dataSize       = size;
    masterXfer.flags          = kLPI2C_TransferDefaultFlag;

    g_nakFlag        = FALSE;
    g_completionFlag = FALSE;
    /* Block read registers. */
    reVal = LPI2C_MasterTransferNonBlocking(base, &((sensor_i2c_handle_t *)pComHandle->pComm)->g_i2cSensorHandle, &masterXfer);
    if(reVal != kStatus_Success)
    {
        return SENSOR_READ_ERR;
    }

    /*  Wait for transfer completion. */
    while((!g_nakFlag) && (!g_completionFlag))
    {
        //SMC_SetPowerModeWait(SMC); // Sleep while waiting for completion
    }

    if(g_nakFlag == FALSE)
    {
        return SENSOR_SUCCESS;
    }
    else
    {
        return SENSOR_READ_ERR;
    }
}

