#ifndef LED_H
#define LED_H

/* LED Definitions */
#define LED_NUM     4                        /* Number of user LEDs          */

extern void LED_Initialize(void);
extern void LED_On        (int num);
extern void LED_Off       (int num);
extern void LED_Out       (int value);

#endif
