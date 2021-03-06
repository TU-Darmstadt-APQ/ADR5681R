/*    
 *  The ADR5681R library is free software: you can redistribute it and/or
 *  modify it under the terms of the GNU General Public License as 
 *  published by the Free Software Foundation, either version 3 of the 
 *  License, or (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef ADR5681R_H
#define ADR5681R_H

// include the Arduino standard library.
#include <Arduino.h>
// include the SPI library.
#include <SPI.h>

class ADR5681R
{  
public:

	//The pins that are used are declared in the constructor.
	//ADR5681R(uint8_t mosiPin, uint8_t sckPin, uint8_t syncPin);
  	ADR5681R(uint8_t,uint8_t);
	//ADR5681R(uint8_t syncPin);
	
	//Output stuff

	//The output has capacity of 12 bit
	//void writeInputRegister(uint16_t value);
	
	//void updateDACRegister();
	
	//This method was tested and works.
	void writeAndUpdateRegisters(uint16_t value);
	
	//Control register stuff
	void genericSendFunction(bool mode,uint16_t mask);

	void setDaisyChain(bool mode);
	
	//This method was tested and works.
	void setGain(bool mode);
	
	void setRef(bool mode);
	
	void setPD0(bool mode);
	
	void setPD1(bool mode);

	//This method was tested and works.
	void resetDAC();
  
	uint16_t getControlRegister();
	
	//Initialze everything with begin().
	void beginDAC(uint32_t clockSpeed);

private:

	//The bits that changes the input register.
	//static const uint16_t WRITE_INPUT_REGISTER_BIT=0b00010000000000000000;
	//The bits that produces an output of the DA with the value in the input register.
	//static const uint16_t WRITE_DAC_REGISTER_BIT=0b0010000000000000;
	//Changes the input register and outputs the written values.
	static const uint16_t WRITE_AND_UPDATE_REGISTER_BITS=0b0011000000000000;
	//The bits that are send to write control register.
	static const uint16_t WRITE_CONTROL_REGISTER_BIT=0b0100000000000000;
	//The maximal that can be entered has a size of 12 Bit.
	static const uint16_t MAX_VALUE=4096;

	static const uint16_t DAISY_CHAIN_BIT=0b0000000001000000;	

	static const uint16_t GAIN_BIT=0b0000000010000000;

	static const uint16_t REFERENCE_BIT=0b0000000100000000;

	static const uint16_t PD0_BIT=0b0000001000000000;

	static const uint16_t PD1_BIT=0b0000010000000000;

	static const uint16_t RESET_BIT=0b0000100000000000;

	//This byte is send when the first 16 Bits of the 24 for the control register were send.
	static const uint8_t ZERO_BIT=0;

	//Save the control register of the DAC so that the other values are not changed when write a new value it.
	//The control register is 0 by default.
	uint16_t controlRegister;
	uint8_t mosiPin;
	uint8_t sckPin;
	uint8_t syncPin;
};
#endif
