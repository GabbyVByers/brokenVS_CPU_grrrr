

#include "rose.h"

typedef uint8_t  BYTE;
typedef uint16_t WORD;

WORD STACK_POINTER;
WORD PROGRAM_COUNTER;
WORD GENERAL_PURPOSE_REGISTERS[4];
WORD* RANDOM_ACCESS_MEMORY;

_Bool FLAG_ZERO;
_Bool FLAG_EQUAL;
_Bool FLAG_GREATER_THAN;
_Bool FLAG_LESS_THAN;

#define OPCODE_MASK(x) (((x) & ((WORD)0b1111111100000000)) >> 8)
#define DST_MASK(x)    (((x) & ((WORD)0b0000000011000000)) >> 6)
#define SRC_MASK(x)    (((x) & ((WORD)0b0000000000110000)) >> 4)
#define FLAG_MASK(x)   (((x) & ((WORD)0b0000000000001111)) >> 0)

#define LDI ((BYTE)0x00) // Load Immediate
#define LDR ((BYTE)0x01) // Load from Memory with Memory Address
#define STR ((BYTE)0x02) // Store to Memory with Memory Address
#define LDX ((BYTE)0x03) // Load from Memory with Pointer in Register
#define STX ((BYTE)0x04) // Store to Memory with Pointer in Register
#define MOV ((BYTE)0x05) // Move
#define SHR ((BYTE)0x06) // Bit Shift Right
#define SHL ((BYTE)0x07) // Bit Shift Left
#define ADI ((BYTE)0x08) // Immediate Addition
#define ADD ((BYTE)0x09) // Addition
#define SUB ((BYTE)0x0A) // Subtraction
#define AND ((BYTE)0x0B) // Bitwise AND
#define ORR ((BYTE)0x0C) // Bitwise OR
#define XOR ((BYTE)0x0D) // Bitwise XOR
#define CMP ((BYTE)0x0E) // Compare
#define KIN ((BYTE)0x0F) // Read Keyboard Input
#define DRW ((BYTE)0x10) // Write to Video Memory
#define JMP ((BYTE)0x11) // Jump
#define JSR ((BYTE)0x12) // Jump to Subroutine
#define RTS ((BYTE)0x13) // Return from Subroutine
#define GSP ((BYTE)0x14) // Get Stack Pointer
#define PSH ((BYTE)0x15) // Push
#define POP ((BYTE)0x16) // Pop

void step(void)
{
	WORD INSTRUCTION = RANDOM_ACCESS_MEMORY[PROGRAM_COUNTER];
	PROGRAM_COUNTER++;
	
	WORD OPCODE = OPCODE_MASK(INSTRUCTION);
	WORD DST    = DST_MASK(INSTRUCTION);
	WORD SRC    = SRC_MASK(INSTRUCTION);
	WORD FLAGS  = FLAG_MASK(INSTRUCTION);

	_Bool FETCH_OPERAND =
		(OPCODE == LDI) ||
		(OPCODE == LDR) ||
		(OPCODE == STR) ||
		(OPCODE == ADI) ||
		(OPCODE == JMP) ||
		(OPCODE == JSR);

	_Bool FLAGS_MUST_BE_TESTED = ((FLAGS & ((WORD)0b1000)) == ((WORD)0b1000));
	_Bool FLAGS_ARE_NEGATED = ((FLAGS & ((WORD)0b0100)) == ((WORD)0b0100));
	WORD FLAG_SELECTION = (FLAGS & ((WORD)0b0011));

	if (FLAGS_MUST_BE_TESTED)
	{

	}

	switch (OPCODE)
	{
		case (LDI):
		{
			
		}
		break;
		case (LDR):
		{
			
		}
		break;
		case (STR):
		{
			
		}
		break;
		case (LDX):
		{
			
		}
		break;
		case (STX):
		{
			
		}
		break;
		case (MOV):
		{
			
		}
		break;
		case (SHR):
		{
			
		}
		break;
		case (SHL):
		{
			
		}
		break;
		case (ADI):
		{
			
		}
		break;
		case (ADD):
		{
			
		}
		break;
		case (SUB):
		{
			
		}
		break;
		case (AND):
		{
			
		}
		break;
		case (ORR):
		{
			
		}
		break;
		case (XOR):
		{
			
		}
		break;
		case (CMP):
		{
			
		}
		break;
		case (KIN):
		{
			
		}
		break;
		case (DRW):
		{
			
		}
		break;
		case (JMP):
		{
			
		}
		break;
		case (JSR):
		{
			
		}
		break;
		case (RTS):
		{
			
		}
		break;
		case (GSP):
		{
			
		}
		break;
		case (PSH):
		{
			
		}
		break;
		case (POP):
		{
			
		}
		break;
		default:
		assert(false);
		break;
	}
}

int main(void)
{
	WORD* RAM = malloc(UINT16_MAX * sizeof(WORD));

	ROSE_Init("CPU", 1200, 700);
	while (ROSE_WindowPollEvents()) {

	} free(RAM);
	ROSE_Quit();
}

