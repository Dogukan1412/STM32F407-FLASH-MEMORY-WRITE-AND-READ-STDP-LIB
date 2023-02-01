
#include "stm32f4xx.h"
#include "stm32f4_discovery.h"

void Flash_Write(uint32_t address, uint32_t data);
uint32_t Flash_Read(uint32_t address);

uint32_t read_data;

int main(void)
{
	// sector 6 address = 0x0804 0000 - 0x0805 FFFF
	Flash_Write(0x08040000, 0x00000002);                    // we write random data
	read_data = Flash_Read(0x08040000);
  while (1)
  {

  }
}


void Flash_Write(uint32_t address, uint32_t data)
{
	FLASH_Unlock();								// firstly we must unlock the memory
	while(FLASH_GetFlagStatus(FLASH_FLAG_BSY));				// check if flash memory busy
	FLASH_EraseSector(FLASH_Sector_6, VoltageRange_3);    // we have to clear sector before writing , (VoltageRange_3 Device operating range: 2.7V to 3.6V)
	Flash_Write(address, data);					// we write the data to the desired address.
	FLASH_Lock();								// in the end we must lock the memory
}


uint32_t Flash_Read(uint32_t address)
{
	uint32_t data;
	data = *(uint32_t*)address;                 // we read the data at the desired address
	return data;
}


/*
 * Callback used by stm32f4_discovery_audio_codec.c.
 * Refer to stm32f4_discovery_audio_codec.h for more info.
 */
void EVAL_AUDIO_TransferComplete_CallBack(uint32_t pBuffer, uint32_t Size){
  /* TODO, implement your code here */
  return;
}

/*
 * Callback used by stm324xg_eval_audio_codec.c.
 * Refer to stm324xg_eval_audio_codec.h for more info.
 */
uint16_t EVAL_AUDIO_GetSampleCallBack(void){
  /* TODO, implement your code here */
  return -1;
}
