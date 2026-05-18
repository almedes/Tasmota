# Custom CO2 Display Build

This custom environment builds a compact ESP8266 image for a Wemos D1 mini with:

- I2C enabled
- Sensirion SCD40/SCD41 CO2 sensor support
- Tasmota display support
- Universal display support with an embedded SSD1306 128x64 I2C descriptor at address `0x3c`

No Wi-Fi credentials, MQTT credentials, passwords, or other secrets are included.
The firmware keeps the Tasmota web server enabled and defaults to Wi-Fi Manager,
so after flashing a Wemos D1 mini with empty credentials it starts the setup
access point/captive portal where WLAN credentials can be entered in the web UI.

## Build

```bash
pio run -e tasmota-co2-display
```

## Firmware output

The expected firmware artifacts are written under:

```text
build_output/firmware/tasmota-co2-display.bin
build_output/firmware/tasmota-co2-display.bin.gz
```

PlatformIO also keeps the raw build artifact at:

```text
.pio/build/tasmota-co2-display/firmware.bin
```
