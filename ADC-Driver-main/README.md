# ADC-Driver (STM32)

An STM32 analog-to-digital converter exercise that converts a temperature sensor reading and displays it on an LCD. The source illustrates polling and interrupt handling around the ADC.

[Application entry point](src/main.c) · [ADC driver](Drivers/src/adc.c) · [Proteus simulation](ADC_simulation.pdsprj).

ADC driver implementing polling and interupts to read temperature of an LM35 and displaying it on an LM016L LCD.

<hr class="rounded">
 <img src= https://user-images.githubusercontent.com/61319952/178343640-a6c2c16b-eef0-4637-a5c6-c1910635812d.gif class="img-responsive" alt=""> </div>
 <hr class="rounded">
 adc.h has the macro to enable or disable the interupt.
