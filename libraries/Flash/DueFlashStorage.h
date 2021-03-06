/* 
DueFlashStorage saves non-volatile data for Arduino Due.
The library is made to be similar to EEPROM library
Uses flash block 1 per default.

Note: uploading new software will erase all flash so data written to flash
using this library will not survive a new software upload. 

Inspiration from Pansenti at https://github.com/Pansenti/DueFlash
Rewritten and modified by Sebastian Nilsson
Further modified up by David Crocker
*/


#ifndef DUEFLASHSTORAGE_H
#define DUEFLASHSTORAGE_H

#include "Core.h"
#include "sam/services/flash_efc/flash_efc.h"

#if defined(__SAM4E8E__) || defined(__SAM4E8C__)

// 1Kb of data
#define FLASH_DATA_LENGTH   ((IFLASH_PAGE_SIZE/sizeof(byte))*4)

// Choose a start address close to the top of the Flash 1 memory space
#define  FLASH_START  ((uint8_t *)(IFLASH_ADDR + IFLASH_SIZE - FLASH_DATA_LENGTH))

#else

// 1Kb of data
#define FLASH_DATA_LENGTH   ((IFLASH1_PAGE_SIZE/sizeof(byte))*4)

// Choose a start address close to the top of the Flash 1 memory space
#define  FLASH_START  ((uint8_t *)(IFLASH1_ADDR + IFLASH1_SIZE - FLASH_DATA_LENGTH))

#endif

//#define FLASH_DEBUG(x) Serial.print(x);
#define FLASH_DEBUG(x)

//  DueFlash is the main namespace for flash functions
namespace DueFlashStorage
{
	// write() writes the specified amount of data into flash.
	// flashStart is the address in memory where the write should start
	// data is a pointer to the data to be written
	// dataLength is length of data in bytes

	void read(uint32_t address, void *data, uint32_t dataLength);
	bool write(uint32_t address, const void *data, uint32_t dataLength);
};

#endif
