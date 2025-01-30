#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "EEPROM_config.h"
#include "EEPROM_interface.h"
#include "EEPROM_private.h"
#include "TWI_interface.h"




void EEPROM_SendDataByte(u8 Data_Byte,u16 Address)
{
	TWI_SendStartCondition();
	TWI_SendSlaveAddressWithWrite(1010|A2_Its_Value<<2|Address>>8);
	TWI_MasterWriteDataByte((u8)Address);
	TWI_MasterWriteDataByte(Data_Byte);
	TWI_SendStopCondition();
}

void EEPROM_ReadDataByte(u8* Data_Byte,u16 Address)
{

	TWI_SendStartCondition();
	TWI_SendSlaveAddressWithWrite(1010|A2_Its_Value<<2|Address>>8);
	TWI_MasterWriteDataByte((u8)Address);
	TWI_SendRepeatedStart();
	TWI_SendSlaveAddressWithRead(1010|A2_Its_Value<<2|Address>>8);
	TWI_MasterReadDataByte(Data_Byte);
	TWI_SendStopCondition();
}

