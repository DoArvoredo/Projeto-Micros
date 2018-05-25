#include <reg52.h>
#include "timers.h"
#include "serial.h"

int i=0;

void main()
{
serial_config ();
envia_serial("b");
while(1);
}