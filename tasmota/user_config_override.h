/*
  user_config_override.h - custom minimal ESP8266 CO2 display build

  Wemos D1 mini build with I2C SCD40/SCD41 and SSD1306 OLED support.
  Intentionally contains no Wi-Fi, MQTT, password, or other secret values.
*/

#ifndef _USER_CONFIG_OVERRIDE_H_
#define _USER_CONFIG_OVERRIDE_H_

// Identify this image and default to the Wemos D1 mini style module.
// FIRMWARE_MINICUSTOM also prevents the ESP8266_4M post-config defaults from
// re-enabling UFS/FTP/SD-card support for this dedicated no-filesystem build.
#ifndef FIRMWARE_MINICUSTOM
#define FIRMWARE_MINICUSTOM
#endif
#ifndef CODE_IMAGE_STR
#define CODE_IMAGE_STR "co2-display"
#endif
#undef MODULE
#define MODULE WEMOS

// Keep network/security features minimal while retaining normal Tasmota setup access.
#undef USE_ARDUINO_OTA
#undef USE_MQTT_TLS
#undef USE_DOMOTICZ
#undef USE_HOME_ASSISTANT
#undef USE_KNX
#undef USE_DISCOVERY
#undef USE_TASMOTA_DISCOVERY
#undef USE_EMULATION
#undef USE_EMULATION_HUE
#undef USE_EMULATION_WEMO
#undef USE_CUSTOM
#define USE_SCRIPT
#undef USE_RULES
#undef USE_TIMERS
#undef USE_TIMERS_WEB
#undef USE_SUNRISE
#undef USE_WEBSEND_RESPONSE
#undef USE_ENHANCED_GUI_WIFI_SCAN
#undef USE_TASMOTA_CLIENT
#undef USE_SERIAL_BRIDGE
#undef USE_MODBUS_BRIDGE
#undef USE_TCP_BRIDGE
#undef USE_FTP
#undef USE_UFILESYS
#undef USE_SDCARD
#undef USE_INFLUXDB
#undef USE_PROMETHEUS

// Keep core RGB light control, but disable unrelated drivers to keep the ESP8266 firmware small.
#define USE_LIGHT
#undef USE_WS2812
#undef USE_MY92X1
#undef USE_SM16716
#undef USE_SM2135
#undef USE_SM2335
#undef USE_BP5758D
#undef USE_SONOFF_L1
#undef USE_SONOFF_D1
#undef USE_PWM_DIMMER
#undef USE_PWM_DIMMER_REMOTE
#undef USE_SHELLY_DIMMER
#undef USE_EXS_DIMMER
#undef USE_SHUTTER
#undef USE_COUNTER
#undef USE_ENERGY_SENSOR
#undef USE_PZEM004T
#undef USE_PZEM_AC
#undef USE_PZEM_DC
#undef USE_MCP39F501
#undef USE_SDM72
#undef USE_SDM120
#undef USE_SDM230
#undef USE_SDM630
#undef USE_DDS2382
#undef USE_DDSU666
#undef USE_SOLAX_X1
#undef USE_LE01MR
#undef USE_TELEINFO
#undef USE_IEM3000
#undef USE_BL6523
#undef USE_WE517
#undef USE_MODBUS_ENERGY
#undef USE_DHT
#undef USE_DS18x20
#undef USE_MHZ19
#undef USE_SENSEAIR
#undef USE_PMS5003
#undef USE_NOVA_SDS
#undef USE_HPMA
#undef USE_SR04
#undef USE_ME007
#undef USE_DYP
#undef USE_AZ7798
#undef USE_PN532_HSU
#undef USE_ZIGBEE
#undef USE_RDM6300
#undef USE_GPS
#undef USE_HM10
#undef USE_HRXL
#undef USE_OPENTHERM
#undef USE_MIEL_HVAC
#undef USE_PROJECTOR_CTRL
#undef USE_AS608
#undef USE_TFMINIPLUS
#undef USE_HRG15
#undef USE_VINDRIKTNING
#undef USE_LOX_O2
#undef USE_MAX31855
#undef USE_MAX31865
#undef USE_LMT01
#undef USE_WIEGAND
#undef USE_IR_REMOTE
#undef USE_SHIFT595
#undef USE_TM1638
#undef USE_HX711
#undef USE_TX20_WIND_SENSOR
#undef USE_TX23_WIND_SENSOR
#undef USE_WINDMETER
#undef USE_FTC532
#undef USE_RC_SWITCH
#undef USE_RF_SENSOR
#undef USE_SONOFF_RF
#undef USE_RF_FLASH
#undef USE_HRE
#undef USE_A4988_STEPPER
#undef USE_NEOPOOL
#undef USE_THERMOSTAT
#undef USE_DEBUG_DRIVER
#undef DEBUG_THEO

// Required hardware support: one I2C bus, SCD40/SCD41 CO2 sensor, and display core.
#define USE_I2C
#define USE_SCD40
#define USE_DISPLAY
#define USE_DISPLAY_SSD1306
#undef USE_DISPLAY_MODES1TO5
#undef USE_DISPLAY_LCD
#undef USE_DISPLAY_MATRIX
#undef USE_DISPLAY_SEVENSEG
#undef USE_DISPLAY_TM1637
#undef USE_DISPLAY_MAX7219
#undef USE_UNIVERSAL_TOUCH
#define USE_UNIVERSAL_DISPLAY

// Universal-display ROM descriptor for a common 128x64 SSD1306 OLED at I2C address 0x3c.
// This avoids LittleFS/display.ini overhead for this dedicated build.
#undef DISPDESC_SIZE
#define DISPDESC_SIZE 256
#define DSP_ROM_DESC \
  ":H,SSD1306,128,64,1,I2C,3c,*,*,*\n" \
  ":S,0,2,1,0,30,20\n" \
  ":I\n" \
  "AE\n" \
  "D5,80\n" \
  "A8,3F\n" \
  "D3,00\n" \
  "40\n" \
  "8D,14\n" \
  "20,00\n" \
  "A1\n" \
  "C8\n" \
  "DA,12\n" \
  "81,9F\n" \
  "D9,F1\n" \
  "DB,40\n" \
  "A4\n" \
  "A6\n" \
  "AF\n" \
  ":o,AE\n" \
  ":O,AF\n" \
  ":A,00,10,40,00,00\n" \
  ":i,A6,A7\n" \
  "#\n"

#endif  // _USER_CONFIG_OVERRIDE_H_
