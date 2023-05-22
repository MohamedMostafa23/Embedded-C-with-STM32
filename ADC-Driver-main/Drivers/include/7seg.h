#ifndef INCLUDE_7SEG_H_
#define INCLUDE_7SEG_H_

void sev_seg(GPIO_TypeDef * GPIOx, char pin[], char val);
void sev_seg_init(GPIO_TypeDef * GPIOx, char x1,char x2,char x3,char x4, char e);
#endif /* INCLUDE_7SEG_H_ */
