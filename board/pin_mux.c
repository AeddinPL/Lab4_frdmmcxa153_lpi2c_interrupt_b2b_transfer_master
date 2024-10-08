/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!GlobalInfo
product: Pins v16.0
processor: MCXA153
package_id: MCXA153VLH
mcu_data: ksdk2_0
processor_version: 16.1.0
pin_labels:
- {pin_num: '38', pin_signal: P3_12/LPUART2_RTS_B/CT1_MAT2/PWM0_X0, label: LED_RED, identifier: LED_RED}
- {pin_num: '46', pin_signal: P3_0/WUU0_IN22/TRIG_IN0/CT_INP16/PWM0_A0, label: LED_BLUE, identifier: LED_BLUE}
- {pin_num: '37', pin_signal: P3_13/LPUART2_CTS_B/CT1_MAT3/PWM0_X1, label: LED_GREEN, identifier: LED_GREEN}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

#include "fsl_common.h"
#include "fsl_port.h"
#include "fsl_gpio.h"
#include "pin_mux.h"

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitBootPins
 * Description   : Calls initialization functions.
 *
 * END ****************************************************************************************************************/
void BOARD_InitBootPins(void)
{
    BOARD_InitPins();
}

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitPins:
- options: {callFromInitBoot: 'true', coreID: cm33_core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '52', peripheral: LPUART0, signal: TX, pin_signal: P0_3/TDI/LPUART0_TXD/LPSPI0_SDO/CT0_MAT1/UTICK_CAP1/CMP0_OUT/CMP1_IN1, slew_rate: fast, open_drain: disable,
    drive_strength: low, pull_select: up, pull_enable: enable, input_buffer: enable, invert_input: normal}
  - {pin_num: '51', peripheral: LPUART0, signal: RX, pin_signal: P0_2/TDO/SWO/LPUART0_RXD/LPSPI0_SCK/CT0_MAT0/UTICK_CAP0/I3C0_PUR, slew_rate: fast, open_drain: disable,
    drive_strength: low, pull_select: up, pull_enable: enable, input_buffer: enable, invert_input: normal}
  - {pin_num: '34', peripheral: LPI2C0, signal: SCL, pin_signal: P3_27/TRIG_OUT7/LPI2C0_SCL/CT_INP13, slew_rate: fast, open_drain: enable, drive_strength: low, pull_select: up,
    pull_enable: enable, input_buffer: enable, invert_input: normal}
  - {pin_num: '33', peripheral: LPI2C0, signal: SDA, pin_signal: P3_28/WUU0_IN26/TRIG_IN11/LPI2C0_SDA/CT_INP12, slew_rate: fast, open_drain: enable, drive_strength: low,
    pull_select: up, pull_enable: enable, input_buffer: enable, invert_input: normal}
  - {pin_num: '46', peripheral: GPIO3, signal: 'GPIO, 0', pin_signal: P3_0/WUU0_IN22/TRIG_IN0/CT_INP16/PWM0_A0, direction: OUTPUT, gpio_init_state: 'false'}
  - {pin_num: '38', peripheral: GPIO3, signal: 'GPIO, 12', pin_signal: P3_12/LPUART2_RTS_B/CT1_MAT2/PWM0_X0, direction: OUTPUT}
  - {pin_num: '37', peripheral: GPIO3, signal: 'GPIO, 13', pin_signal: P3_13/LPUART2_CTS_B/CT1_MAT3/PWM0_X1, direction: OUTPUT}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD_InitPins(void)
{
    /* Write to GPIO3: Peripheral clock is enabled */
    CLOCK_EnableClock(kCLOCK_GateGPIO3);
    /* Write to PORT0: Peripheral clock is enabled */
    CLOCK_EnableClock(kCLOCK_GatePORT0);
    /* Write to PORT3: Peripheral clock is enabled */
    CLOCK_EnableClock(kCLOCK_GatePORT3);
    /* GPIO3 peripheral is released from reset */
    RESET_ReleasePeripheralReset(kGPIO3_RST_SHIFT_RSTn);
    /* LPUART0 peripheral is released from reset */
    RESET_ReleasePeripheralReset(kLPUART0_RST_SHIFT_RSTn);
    /* PORT0 peripheral is released from reset */
    RESET_ReleasePeripheralReset(kPORT0_RST_SHIFT_RSTn);
    /* PORT3 peripheral is released from reset */
    RESET_ReleasePeripheralReset(kPORT3_RST_SHIFT_RSTn);
    /* LPI2C0 peripheral is released from reset */
    RESET_ReleasePeripheralReset(kLPI2C0_RST_SHIFT_RSTn);

    gpio_pin_config_t LED_BLUE_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PIO3_0 (pin 46)  */
    GPIO_PinInit(BOARD_INITPINS_LED_BLUE_GPIO, BOARD_INITPINS_LED_BLUE_PIN, &LED_BLUE_config);

    gpio_pin_config_t LED_RED_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PIO3_12 (pin 38)  */
    GPIO_PinInit(BOARD_INITPINS_LED_RED_GPIO, BOARD_INITPINS_LED_RED_PIN, &LED_RED_config);

    gpio_pin_config_t LED_GREEN_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PIO3_13 (pin 37)  */
    GPIO_PinInit(BOARD_INITPINS_LED_GREEN_GPIO, BOARD_INITPINS_LED_GREEN_PIN, &LED_GREEN_config);

    const port_pin_config_t port0_2_pin51_config = {/* Internal pull-up resistor is enabled */
                                                    kPORT_PullUp,
                                                    /* Low internal pull resistor value is selected. */
                                                    kPORT_LowPullResistor,
                                                    /* Fast slew rate is configured */
                                                    kPORT_FastSlewRate,
                                                    /* Passive input filter is disabled */
                                                    kPORT_PassiveFilterDisable,
                                                    /* Open drain output is disabled */
                                                    kPORT_OpenDrainDisable,
                                                    /* Low drive strength is configured */
                                                    kPORT_LowDriveStrength,
                                                    /* Normal drive strength is configured */
                                                    kPORT_NormalDriveStrength,
                                                    /* Pin is configured as LPUART0_RXD */
                                                    kPORT_MuxAlt2,
                                                    /* Digital input enabled */
                                                    kPORT_InputBufferEnable,
                                                    /* Digital input is not inverted */
                                                    kPORT_InputNormal,
                                                    /* Pin Control Register fields [15:0] are not locked */
                                                    kPORT_UnlockRegister};
    /* PORT0_2 (pin 51) is configured as LPUART0_RXD */
    PORT_SetPinConfig(PORT0, 2U, &port0_2_pin51_config);

    const port_pin_config_t port0_3_pin52_config = {/* Internal pull-up resistor is enabled */
                                                    kPORT_PullUp,
                                                    /* Low internal pull resistor value is selected. */
                                                    kPORT_LowPullResistor,
                                                    /* Fast slew rate is configured */
                                                    kPORT_FastSlewRate,
                                                    /* Passive input filter is disabled */
                                                    kPORT_PassiveFilterDisable,
                                                    /* Open drain output is disabled */
                                                    kPORT_OpenDrainDisable,
                                                    /* Low drive strength is configured */
                                                    kPORT_LowDriveStrength,
                                                    /* Normal drive strength is configured */
                                                    kPORT_NormalDriveStrength,
                                                    /* Pin is configured as LPUART0_TXD */
                                                    kPORT_MuxAlt2,
                                                    /* Digital input enabled */
                                                    kPORT_InputBufferEnable,
                                                    /* Digital input is not inverted */
                                                    kPORT_InputNormal,
                                                    /* Pin Control Register fields [15:0] are not locked */
                                                    kPORT_UnlockRegister};
    /* PORT0_3 (pin 52) is configured as LPUART0_TXD */
    PORT_SetPinConfig(PORT0, 3U, &port0_3_pin52_config);

    /* PORT3_0 (pin 46) is configured as P3_0 */
    PORT_SetPinMux(BOARD_INITPINS_LED_BLUE_PORT, BOARD_INITPINS_LED_BLUE_PIN, kPORT_MuxAlt0);

    PORT3->PCR[0] = ((PORT3->PCR[0] &
                      /* Mask bits to zero which are setting */
                      (~(PORT_PCR_IBE_MASK)))

                     /* Input Buffer Enable: Enables. */
                     | PORT_PCR_IBE(PCR_IBE_ibe1));

    /* PORT3_12 (pin 38) is configured as P3_12 */
    PORT_SetPinMux(BOARD_INITPINS_LED_RED_PORT, BOARD_INITPINS_LED_RED_PIN, kPORT_MuxAlt0);

    PORT3->PCR[12] = ((PORT3->PCR[12] &
                       /* Mask bits to zero which are setting */
                       (~(PORT_PCR_IBE_MASK)))

                      /* Input Buffer Enable: Enables. */
                      | PORT_PCR_IBE(PCR_IBE_ibe1));

    /* PORT3_13 (pin 37) is configured as P3_13 */
    PORT_SetPinMux(BOARD_INITPINS_LED_GREEN_PORT, BOARD_INITPINS_LED_GREEN_PIN, kPORT_MuxAlt0);

    PORT3->PCR[13] = ((PORT3->PCR[13] &
                       /* Mask bits to zero which are setting */
                       (~(PORT_PCR_IBE_MASK)))

                      /* Input Buffer Enable: Enables. */
                      | PORT_PCR_IBE(PCR_IBE_ibe1));

    PORT3->PCR[27] =
        ((PORT3->PCR[27] &
          /* Mask bits to zero which are setting */
          (~(PORT_PCR_PS_MASK | PORT_PCR_PE_MASK | PORT_PCR_SRE_MASK | PORT_PCR_ODE_MASK | PORT_PCR_DSE_MASK | PORT_PCR_MUX_MASK | PORT_PCR_IBE_MASK | PORT_PCR_INV_MASK)))

         /* Pull Select: Enables internal pullup resistor. */
         | PORT_PCR_PS(PCR_PS_ps1)

         /* Pull Enable: Enables. */
         | PORT_PCR_PE(PCR_PE_pe1)

         /* Slew Rate Enable: Fast. */
         | PORT_PCR_SRE(PCR_SRE_sre0)

         /* Open Drain Enable: Enables. */
         | PORT_PCR_ODE(PCR_ODE_ode1)

         /* Drive Strength Enable: Low. */
         | PORT_PCR_DSE(PCR_DSE_dse0)

         /* Pin Multiplex Control: PORT3_27 (pin 34) is configured as LPI2C0_SCL. */
         | PORT_PCR_MUX(PORT3_PCR27_MUX_mux10)

         /* Input Buffer Enable: Enables. */
         | PORT_PCR_IBE(PCR_IBE_ibe1)

         /* Invert Input: Does not invert. */
         | PORT_PCR_INV(PCR_INV_inv0));

    PORT3->PCR[28] =
        ((PORT3->PCR[28] &
          /* Mask bits to zero which are setting */
          (~(PORT_PCR_PS_MASK | PORT_PCR_PE_MASK | PORT_PCR_SRE_MASK | PORT_PCR_ODE_MASK | PORT_PCR_DSE_MASK | PORT_PCR_MUX_MASK | PORT_PCR_IBE_MASK | PORT_PCR_INV_MASK)))

         /* Pull Select: Enables internal pullup resistor. */
         | PORT_PCR_PS(PCR_PS_ps1)

         /* Pull Enable: Enables. */
         | PORT_PCR_PE(PCR_PE_pe1)

         /* Slew Rate Enable: Fast. */
         | PORT_PCR_SRE(PCR_SRE_sre0)

         /* Open Drain Enable: Enables. */
         | PORT_PCR_ODE(PCR_ODE_ode1)

         /* Drive Strength Enable: Low. */
         | PORT_PCR_DSE(PCR_DSE_dse0)

         /* Pin Multiplex Control: PORT3_28 (pin 33) is configured as LPI2C0_SDA. */
         | PORT_PCR_MUX(PORT3_PCR28_MUX_mux10)

         /* Input Buffer Enable: Enables. */
         | PORT_PCR_IBE(PCR_IBE_ibe1)

         /* Invert Input: Does not invert. */
         | PORT_PCR_INV(PCR_INV_inv0));
}
/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
