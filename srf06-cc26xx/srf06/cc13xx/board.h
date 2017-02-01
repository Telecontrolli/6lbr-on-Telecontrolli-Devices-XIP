/*
 * Author: Telecontrolli srl
 * File: button-sensor.c V1.0
 * Description:  Defines related to the SmartRF06 Evaluation Board with a CC1310EM
 *
 * 	 	 This file provides connectivity information on LEDs, Buttons, UART and other peripherals
 *
 * 	         This file can be used as the basis to configure other boards using the
 *               CC13xx/CC26xx code as their basis.
 *
 *               This file is not meant to be modified by the user.
 * Header file with definitions related to the I/O connections on the TI
 * SmartRF06 Evaluation Board with a CC1310EM
 */
/*---------------------------------------------------------------------------*/
#ifndef BOARD_H_
#define BOARD_H_
/*---------------------------------------------------------------------------*/
#include "ioc.h"
/*---------------------------------------------------------------------------*/
/**
 * \name LED configurations
 *
 * Those values are not meant to be modified by the user
 * @{
 */
/* Some files include leds.h before us, so we need to get rid of defaults in
 * leds.h before we provide correct definitions */
#undef LEDS_GREEN
#undef LEDS_YELLOW
#undef LEDS_RED
#undef LEDS_CONF_ALL

#define LEDS_RED       1 /**< LED1 (Red)    */
#define LEDS_YELLOW    2 /**< LED2 (Yellow) */
#define LEDS_GREEN     4 /**< LED3 (Green)  */
#define LEDS_ORANGE    8 /**< LED4 (Orange) */
#define button	         /**< IOID_0 (Input)*/

#define LEDS_CONF_ALL 15

/* Notify various examples that we have LEDs */
#define PLATFORM_HAS_LEDS        1
/** @} */
/*---------------------------------------------------------------------------*/
/**
 * \name LED IOID mappings
 *
 * Those values are not meant to be modified by the user
 * @{
 */
#define BOARD_IOID_LED_1          IOID_13
#define BOARD_IOID_LED_2          IOID_12
#define BOARD_IOID_LED_3          IOID_UNUSED
#define BOARD_IOID_LED_4          IOID_UNUSED	
#define BOARD_LED_1               (1 << BOARD_IOID_LED_1)
#define BOARD_LED_2               (1 << BOARD_IOID_LED_2)
#define BOARD_LED_3               (1 << BOARD_IOID_LED_3)
#define BOARD_LED_4               (1 << BOARD_IOID_LED_4)
#define BOARD_LED_ALL             (BOARD_LED_1 | BOARD_LED_2 | BOARD_LED_3 | \
                                   BOARD_LED_4)
/** @} */
/*---------------------------------------------------------------------------*/
/**
 * \name UART IOID mapping
 *
 * Those values are not meant to be modified by the user
 * @{
 */
#define BOARD_IOID_UART_RX        IOID_8
#define BOARD_IOID_UART_TX        IOID_7
#define BOARD_IOID_UART_CTS       IOID_UNUSED
#define BOARD_IOID_UART_RTS       IOID_UNUSED
#define BOARD_UART_RX             (1 << BOARD_IOID_UART_RX)
#define BOARD_UART_TX             (1 << BOARD_IOID_UART_TX)
#define BOARD_UART_CTS            (1 << BOARD_IOID_UART_CTS)
#define BOARD_UART_RTS            (1 << BOARD_IOID_UART_RTS)
/** @} */
/*---------------------------------------------------------------------------*/
/**
 * \name Button IOID mapping
 *
 * Those values are not meant to be modified by the user
 * @{
 */
#define BOARD_IOID_KEY_LEFT       IOID_14
#define BOARD_IOID_KEY_RIGHT      IOID_UNUSED
#define BOARD_IOID_KEY_UP         IOID_UNUSED
#define BOARD_IOID_KEY_DOWN       IOID_UNUSED
#define BOARD_IOID_KEY_SELECT     IOID_UNUSED
#define BOARD_KEY_LEFT            (1 << BOARD_IOID_KEY_LEFT)
#define BOARD_KEY_RIGHT           (1 << BOARD_IOID_KEY_RIGHT)
#define BOARD_KEY_UP              (1 << BOARD_IOID_KEY_UP)
#define BOARD_KEY_DOWN            (1 << BOARD_IOID_KEY_DOWN)
#define BOARD_KEY_SELECT          (1 << BOARD_IOID_KEY_SELECT)
/** @} */
/*---------------------------------------------------------------------------*/
/**
 * \name 3.3V domain IOID mapping
 *
 * Those values are not meant to be modified by the user
 * @{
 */
#define BOARD_IOID_3V3_EN         IOID_UNUSED
#define BOARD_3V3_EN              (1 << BOARD_IOID_3V3_EN)
/** @} */
/*---------------------------------------------------------------------------*/
/**
 * \name SPI IOID mapping
 *
 * Those values are not meant to be modified by the user
 * @{
 */
#define BOARD_IOID_SPI_SCK        IOID_4
#define BOARD_IOID_SPI_MOSI       IOID_3
#define BOARD_IOID_SPI_MISO       IOID_2
#define BOARD_SPI_SCK             (1 << BOARD_IOID_SPI_SCK)
#define BOARD_SPI_MOSI            (1 << BOARD_IOID_SPI_MOSI)
#define BOARD_SPI_MISO            (1 << BOARD_IOID_SPI_MISO)
/** @} */
/*---------------------------------------------------------------------------*/
/**
 * \name LCD IOID mapping
 *
 * Those values are not meant to be modified by the user
 * @{
 */
#define BOARD_IOID_LCD_MODE       IOID_UNUSED
#define BOARD_IOID_LCD_RST        IOID_UNUSED
#define BOARD_IOID_LCD_CS         IOID_1
#define BOARD_IOID_LCD_SCK        BOARD_IOID_SPI_SCK
#define BOARD_IOID_LCD_MOSI       BOARD_IOID_SPI_MOSI
#define BOARD_LCD_MODE            (1 << BOARD_IOID_LCD_MODE)
#define BOARD_LCD_RST             (1 << BOARD_IOID_LCD_RST)
#define BOARD_LCD_CS              (1 << BOARD_IOID_LCD_CS)
#define BOARD_LCD_SCK             BOARD_SPI_SCK
#define BOARD_LCD_MOSI            BOARD_SPI_MOSI
/** @} */
/*---------------------------------------------------------------------------*/
/**
 * \name SD Card IOID mapping
 *
 * Those values are not meant to be modified by the user
 * @{
 */
#define BOARD_IOID_SDCARD_CS      IOID_UNUSED
#define BOARD_SDCARD_CS           (1 << BOARD_IOID_SDCARD_CS)
#define BOARD_IOID_SDCARD_SCK     BOARD_IOID_SPI_SCK
#define BOARD_SDCARD_SCK          BOARD_SPI_SCK
#define BOARD_IOID_SDCARD_MOSI    BOARD_IOID_SPI_MOSI
#define BOARD_SDCARD_MOSI         BOARD_SPI_MOSI
#define BOARD_IOID_SDCARD_MISO    BOARD_IOID_SPI_MISO
#define BOARD_SDCARD_MISO         BOARD_SPI_MISO
/** @} */
/*---------------------------------------------------------------------------*/
/**
 * \name ALS IOID mapping
 *
 * Those values are not meant to be modified by the user
 * @{
 */
#define BOARD_IOID_ALS_PWR        IOID_5
#define BOARD_IOID_ALS_OUT        IOID_6
#define BOARD_ALS_PWR             (1 << BOARD_IOID_ALS_PWR)
#define BOARD_ALS_OUT             (1 << BOARD_IOID_ALS_OUT)
/** @} */
/*---------------------------------------------------------------------------*/
/**
 * \name ACC IOID mapping
 *
 * Those values are not meant to be modified by the user
 * @{
 */
#define BOARD_IOID_ACC_PWR        IOID_9
#define BOARD_IOID_ACC_INT        IOID_10
#define BOARD_IOID_ACC_INT1       IOID_11
#define BOARD_IOID_ACC_INT2       IOID_UNUSED
#define BOARD_IOID_ACC_CS         IOID_UNUSED
#define BOARD_ACC_PWR             (1 << BOARD_IOID_ACC_PWR)
#define BOARD_ACC_INT             (1 << BOARD_IOID_ACC_INT)
#define BOARD_ACC_INT1            (1 << BOARD_IOID_ACC_INT1)
#define BOARD_ACC_INT2            (1 << BOARD_IOID_ACC_INT2)
#define BOARD_ACC_CS              (1 << BOARD_IOID_ACC_CS)
#define BOARD_IOID_ACC_SCK        BOARD_IOID_SPI_SCK
#define BOARD_ACC_SCK             BOARD_SPI_SCK
#define BOARD_IOID_ACC_MOSI       BOARD_IOID_SPI_MOSI
#define BOARD_ACC_MOSI            BOARD_SPI_MOSI
#define BOARD_IOID_ACC_MISO       BOARD_IOID_SPI_MISO
#define BOARD_ACC_MISO            BOARD_SPI_MISO
/** @} */
/*---------------------------------------------------------------------------*/
/**
 * \brief ROM bootloader configuration
 *
 * Change SET_CCFG_BL_CONFIG_BL_PIN_NUMBER to BOARD_IOID_KEY_xyz to select
 * which button triggers the bootloader on reset.
 *
 * The remaining values are not meant to be modified by the user
 * @{
 */
#if ROM_BOOTLOADER_ENABLE
#define SET_CCFG_BL_CONFIG_BOOTLOADER_ENABLE            0xC5
#define SET_CCFG_BL_CONFIG_BL_LEVEL                     0x00
#define SET_CCFG_BL_CONFIG_BL_PIN_NUMBER                BOARD_IOID_KEY_SELECT
#define SET_CCFG_BL_CONFIG_BL_ENABLE                    0xC5
#else
#define SET_CCFG_BL_CONFIG_BOOTLOADER_ENABLE            0x00
#define SET_CCFG_BL_CONFIG_BL_LEVEL                     0x01
#define SET_CCFG_BL_CONFIG_BL_PIN_NUMBER                0xFF
#define SET_CCFG_BL_CONFIG_BL_ENABLE                    0xFF
#endif
/** @} */
/*---------------------------------------------------------------------------*/
/**
 * \name Device string used on startup
 * @{
 */
#define BOARD_STRING "X.IP4T+EB or XIP5"
/** @} */
/*---------------------------------------------------------------------------*/
#endif /* BOARD_H_ */
/*---------------------------------------------------------------------------*/
/**
 * @}
 * @}
 */
