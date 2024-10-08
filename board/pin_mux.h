/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

#ifndef _PIN_MUX_H_
#define _PIN_MUX_H_

/*!
 * @addtogroup pin_mux
 * @{
 */

/***********************************************************************************************************************
 * API
 **********************************************************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @brief Calls initialization functions.
 *
 */
void BOARD_InitBootPins(void);

#define PCR_DSE_dse0 0x00u          /*!<@brief Drive Strength Enable: Low */
#define PCR_IBE_ibe1 0x01u          /*!<@brief Input Buffer Enable: Enables */
#define PCR_INV_inv0 0x00u          /*!<@brief Invert Input: Does not invert */
#define PCR_ODE_ode1 0x01u          /*!<@brief Open Drain Enable: Enables */
#define PCR_PE_pe1 0x01u            /*!<@brief Pull Enable: Enables */
#define PCR_PS_ps1 0x01u            /*!<@brief Pull Select: Enables internal pullup resistor */
#define PCR_SRE_sre0 0x00u          /*!<@brief Slew Rate Enable: Fast */
#define PORT3_PCR27_MUX_mux10 0x02u /*!<@brief Pin Multiplex Control: Alternative 2 (chip-specific) */
#define PORT3_PCR28_MUX_mux10 0x02u /*!<@brief Pin Multiplex Control: Alternative 2 (chip-specific) */

/*! @name PORT3_0 (number 46), LED_BLUE
  @{ */

/* Symbols to be used with GPIO driver */
#define BOARD_INITPINS_LED_BLUE_GPIO GPIO3               /*!<@brief GPIO peripheral base pointer */
#define BOARD_INITPINS_LED_BLUE_GPIO_PIN 0U              /*!<@brief GPIO pin number */
#define BOARD_INITPINS_LED_BLUE_GPIO_PIN_MASK (1U << 0U) /*!<@brief GPIO pin mask */

/* Symbols to be used with PORT driver */
#define BOARD_INITPINS_LED_BLUE_PORT PORT3               /*!<@brief PORT peripheral base pointer */
#define BOARD_INITPINS_LED_BLUE_PIN 0U                   /*!<@brief PORT pin number */
#define BOARD_INITPINS_LED_BLUE_PIN_MASK (1U << 0U)      /*!<@brief PORT pin mask */
                                                         /* @} */

/*! @name PORT3_12 (number 38), LED_RED
  @{ */

/* Symbols to be used with GPIO driver */
#define BOARD_INITPINS_LED_RED_GPIO GPIO3                /*!<@brief GPIO peripheral base pointer */
#define BOARD_INITPINS_LED_RED_GPIO_PIN 12U              /*!<@brief GPIO pin number */
#define BOARD_INITPINS_LED_RED_GPIO_PIN_MASK (1U << 12U) /*!<@brief GPIO pin mask */

/* Symbols to be used with PORT driver */
#define BOARD_INITPINS_LED_RED_PORT PORT3                /*!<@brief PORT peripheral base pointer */
#define BOARD_INITPINS_LED_RED_PIN 12U                   /*!<@brief PORT pin number */
#define BOARD_INITPINS_LED_RED_PIN_MASK (1U << 12U)      /*!<@brief PORT pin mask */
                                                         /* @} */

/*! @name PORT3_13 (number 37), LED_GREEN
  @{ */

/* Symbols to be used with GPIO driver */
#define BOARD_INITPINS_LED_GREEN_GPIO GPIO3                /*!<@brief GPIO peripheral base pointer */
#define BOARD_INITPINS_LED_GREEN_GPIO_PIN 13U              /*!<@brief GPIO pin number */
#define BOARD_INITPINS_LED_GREEN_GPIO_PIN_MASK (1U << 13U) /*!<@brief GPIO pin mask */

/* Symbols to be used with PORT driver */
#define BOARD_INITPINS_LED_GREEN_PORT PORT3                /*!<@brief PORT peripheral base pointer */
#define BOARD_INITPINS_LED_GREEN_PIN 13U                   /*!<@brief PORT pin number */
#define BOARD_INITPINS_LED_GREEN_PIN_MASK (1U << 13U)      /*!<@brief PORT pin mask */
                                                           /* @} */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitPins(void);

#if defined(__cplusplus)
}
#endif

/*!
 * @}
 */
#endif /* _PIN_MUX_H_ */

/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
