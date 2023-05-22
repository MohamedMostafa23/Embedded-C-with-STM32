#include<stdint.h>
#include "keypad.h"

int main(void)
{
	KeyPad_INIT();

	// super loop
	while(1)
	{
		KeyPad_MANAGE();
	}
}

