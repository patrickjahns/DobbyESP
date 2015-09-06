#ifndef __RBOOT_SMINGOTA_H__
#define __RBOOT_SMINGOTA_H__

//////////////////////////////////////////////////
// rBoot OTA sample code for ESP8266 Sming API.
// Copyright 2015 Richard A Burton
// richardaburton@gmail.com
// See license.txt for license terms.
// OTA code based on SDK sample from Espressif.
//////////////////////////////////////////////////

#include "rboot-api.h"

#ifdef __cplusplus
extern "C" {
#endif

//TODO: his is stil bad API; need clean HTTP Client, and user configurable base!
// ota server details
#define OTA_IP { 192, 168, 1, 100 }
#define OTA_PORT 8081

#define OTA_ROM0 "rom0.bin"
// OTA_ROM1 is only used for TWO_ROMS mode
#define OTA_ROM1 "rom1.bin"
// OTA_FILE is not required, but is part of the example
// code for writing arbitrary files to flash
#define OTA_FILE "file.bin"

// general http header
#define HTTP_HEADER "Connection: keep-alive\r\n\
Cache-Control: no-cache\r\n\
User-Agent: rBoot-Sample/1.0\r\n\
Accept: */*\r\n\r\n"
/* this comment to keep notepad++ happy */

// timeout for the initial connect and each recv (in ms)
#define OTA_NETWORK_TIMEOUT  10000

// used to indicate a non-rom flash
#define FLASH_BY_ADDR 0xff

// callback method should take this format
typedef void (*ota_callback)(bool result, uint8 rom_slot);

// function to perform the ota update
bool ICACHE_FLASH_ATTR rboot_ota_start(ota_callback callback);

#ifdef __cplusplus
}
#endif

#endif
