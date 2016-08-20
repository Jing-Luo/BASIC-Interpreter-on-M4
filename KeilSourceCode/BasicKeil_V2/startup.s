; <<< Use Configuration Wizard in Context Menu >>>
;******************************************************************************
;
; startup_rvmdk.S - Startup code for use with Keil's uVision.
;
; Copyright (c) 2014 Texas Instruments Incorporated.  All rights reserved.
; Software License Agreement
;
; Texas Instruments (TI) is supplying this software for use solely and
; exclusively on TI's microcontroller products. The software is owned by
; TI and/or its suppliers, and is protected under applicable copyright
; laws. You may not combine this software with "viral" open-source
; software in order to form a larger program.
;
; THIS SOFTWARE IS PROVIDED "AS IS" AND WITH ALL FAULTS.
; NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT
; NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
; A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. TI SHALL NOT, UNDER ANY
; CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR CONSEQUENTIAL
; DAMAGES, FOR ANY REASON WHATSOEVER.
;
; This is part of revision 2.1.0.12573 of the EK-TM4C1294XL Firmware Package.
;
;******************************************************************************
; Edited to conform with ISR names as described in
;   "Embedded Systems: Introduction to ARM Cortex M Microcontrollers",
;   ISBN: 978-1469998749, Jonathan Valvano, copyright (c) 2014
;   "Embedded Systems: Real Time Interfacing to ARM Cortex M Microcontrollers",
;   ISBN: 978-1463590154, Jonathan Valvano, copyright (c) 2014
;   "Embedded Systems: Real-Time Operating Systems for ARM Cortex M Microcontrollers",
;   ISBN: 978-1466468863, Jonathan Valvano, copyright (c) 2014
;
;******************************************************************************
;
; <o> Stack Size (in Bytes) <0x0-0xFFFFFFFF:8>
;
;******************************************************************************
Stack   EQU     0x00000400

;******************************************************************************
;
; <o> Heap Size (in Bytes) <0x0-0xFFFFFFFF:8>
;
;******************************************************************************
Heap    EQU     0x00000000

;******************************************************************************
;
; Allocate space for the stack.
;
;******************************************************************************
        AREA    STACK, NOINIT, READWRITE, ALIGN=3
StackMem
        SPACE   Stack
__initial_sp

;******************************************************************************
;
; Allocate space for the heap.
;
;******************************************************************************
        AREA    HEAP, NOINIT, READWRITE, ALIGN=3
__heap_base
HeapMem
        SPACE   Heap
__heap_limit

;******************************************************************************
;
; Indicate that the code in this file preserves 8-byte alignment of the stack.
;
;******************************************************************************
        PRESERVE8

;******************************************************************************
;
; Place code into the reset code section.
;
;******************************************************************************
        AREA    RESET, CODE, READONLY
        THUMB

;******************************************************************************
;
; The vector table.
;
;******************************************************************************
        EXPORT  __Vectors
__Vectors                                   ; vector number
        DCD     StackMem + Stack            ;   0) Top of Stack
        DCD     Reset_Handler               ;   1) Reset Handler
        DCD     NMI_Handler                 ;   2) NMI Handler
        DCD     HardFault_Handler           ;   3) Hard Fault Handler
        DCD     MemManage_Handler           ;   4) MPU Fault Handler
        DCD     BusFault_Handler            ;   5) Bus Fault Handler
        DCD     UsageFault_Handler          ;   6) Usage Fault Handler
        DCD     0                           ;   7) Reserved
        DCD     0                           ;   8) Reserved
        DCD     0                           ;   9) Reserved
        DCD     0                           ;  10) Reserved
        DCD     SVC_Handler                 ;  11) SVCall Handler
        DCD     DebugMon_Handler            ;  12) Debug Monitor Handler
        DCD     0                           ;  13) Reserved
        DCD     PendSV_Handler              ;  14) PendSV Handler
        DCD     SysTick_Handler             ;  15) SysTick Handler
        DCD     GPIOPortA_Handler           ;  16) GPIO Port A
        DCD     GPIOPortB_Handler           ;  17) GPIO Port B
        DCD     GPIOPortC_Handler           ;  18) GPIO Port C
        DCD     GPIOPortD_Handler           ;  19) GPIO Port D
        DCD     GPIOPortE_Handler           ;  20) GPIO Port E
        DCD     UART0_Handler               ;  21) UART0 Rx and Tx
        DCD     UART1_Handler               ;  22) UART1 Rx and Tx
        DCD     SSI0_Handler                ;  23) SSI0 Rx and Tx
        DCD     I2C0_Handler                ;  24) I2C0 Master and Slave
        DCD     PWM0Fault_Handler           ;  25) PWM 0 Fault
        DCD     PWM0Generator0_Handler      ;  26) PWM 0 Generator 0
        DCD     PWM0Generator1_Handler      ;  27) PWM 0 Generator 1
        DCD     PWM0Generator2_Handler      ;  28) PWM 0 Generator 2
        DCD     Quadrature0_Handler         ;  29) Quadrature Encoder 0
        DCD     ADC0Seq0_Handler            ;  30) ADC0 Sequence 0
        DCD     ADC0Seq1_Handler            ;  31) ADC0 Sequence 1
        DCD     ADC0Seq2_Handler            ;  32) ADC0 Sequence 2
        DCD     ADC0Seq3_Handler            ;  33) ADC0 Sequence 3
        DCD     WDT_Handler                 ;  34) Watchdog Timers 0 and 1
        DCD     Timer0A_Handler             ;  35) Timer 0 subtimer A
        DCD     Timer0B_Handler             ;  36) Timer 0 subtimer B
        DCD     Timer1A_Handler             ;  37) Timer 1 subtimer A
        DCD     Timer1B_Handler             ;  38) Timer 1 subtimer B
        DCD     Timer2A_Handler             ;  39) Timer 2 subtimer A
        DCD     Timer2B_Handler             ;  40) Timer 2 subtimer B
        DCD     Comp0_Handler               ;  41) Analog Comp 0
        DCD     Comp1_Handler               ;  42) Analog Comp 1
        DCD     Comp2_Handler               ;  43) Analog Comp 2
        DCD     SysCtl_Handler              ;  44) System Control (PLL, OSC, BO)
        DCD     FlashCtl_Handler            ;  45) Flash Control
        DCD     GPIOPortF_Handler           ;  46) GPIO Port F
        DCD     GPIOPortG_Handler           ;  47) GPIO Port G
        DCD     GPIOPortH_Handler           ;  48) GPIO Port H
        DCD     UART2_Handler               ;  49) UART2 Rx and Tx
        DCD     SSI1_Handler                ;  50) SSI1 Rx and Tx
        DCD     Timer3A_Handler             ;  51) Timer 3 subtimer A
        DCD     Timer3B_Handler             ;  52) Timer 3 subtimer B
        DCD     I2C1_Handler                ;  53) I2C1 Master and Slave
        DCD     CAN0_Handler                ;  54) CAN0
        DCD     CAN1_Handler                ;  55) CAN1
        DCD     Ethernet_Handler            ;  56) Ethernet
        DCD     Hibernate_Handler           ;  57) Hibernate
        DCD     USB0_Handler                ;  58) USB0
        DCD     PWM0Generator3_Handler      ;  59) PWM 0 Generator 3
        DCD     uDMA_Handler                ;  60) uDMA Software Transfer
        DCD     uDMA_Error                  ;  61) uDMA Error
        DCD     ADC1Seq0_Handler            ;  62) ADC1 Sequence 0
        DCD     ADC1Seq1_Handler            ;  63) ADC1 Sequence 1
        DCD     ADC1Seq2_Handler            ;  64) ADC1 Sequence 2
        DCD     ADC1Seq3_Handler            ;  65) ADC1 Sequence 3
        DCD     ExtBus_Handler              ;  66) External Bus Interface 0
        DCD     GPIOPortJ_Handler           ;  67) GPIO Port J
        DCD     GPIOPortK_Handler           ;  68) GPIO Port K
        DCD     GPIOPortL_Handler           ;  69) GPIO Port L
        DCD     SSI2_Handler                ;  70) SSI2 Rx and Tx
        DCD     SSI3_Handler                ;  71) SSI3 Rx and Tx
        DCD     UART3_Handler               ;  72) UART3 Rx and Tx
        DCD     UART4_Handler               ;  73) UART4 Rx and Tx
        DCD     UART5_Handler               ;  74) UART5 Rx and Tx
        DCD     UART6_Handler               ;  75) UART6 Rx and Tx
        DCD     UART7_Handler               ;  76) UART7 Rx and Tx
        DCD     I2C2_Handler                ;  77) I2C2 Master and Slave
        DCD     I2C3_Handler                ;  78) I2C3 Master and Slave
        DCD     Timer4A_Handler             ;  79) Timer 4 subtimer A
        DCD     Timer4B_Handler             ;  80) Timer 4 subtimer B
        DCD     Timer5A_Handler             ;  81) Timer 5 subtimer A
        DCD     Timer5B_Handler             ;  82) Timer 5 subtimer B
        DCD     FPU_Handler                 ;  83) Floating-Point Exception (imprecise)
        DCD     0                           ;  84) Reserved
        DCD     0                           ;  85) Reserved
        DCD     I2C4_Handler                ;  86) I2C4 Master and Slave
        DCD     I2C5_Handler                ;  87) I2C5 Master and Slave
        DCD     GPIOPortM_Handler           ;  88) GPIO Port M
        DCD     GPIOPortN_Handler           ;  89) GPIO Port N
        DCD     0                           ;  90) Reserved
        DCD     Tamper_Handler              ;  91) Tamper
        DCD     GPIOPortP_Handler           ;  92) GPIO Port P (Summary or P0)
        DCD     GPIOPortP1_Handler          ;  93) GPIO Port P1
        DCD     GPIOPortP2_Handler          ;  94) GPIO Port P2
        DCD     GPIOPortP3_Handler          ;  95) GPIO Port P3
        DCD     GPIOPortP4_Handler          ;  96) GPIO Port P4
        DCD     GPIOPortP5_Handler          ;  97) GPIO Port P5
        DCD     GPIOPortP6_Handler          ;  98) GPIO Port P6
        DCD     GPIOPortP7_Handler          ;  99) GPIO Port P7
        DCD     GPIOPortQ_Handler           ; 100) GPIO Port Q (Summary or Q0)
        DCD     GPIOPortQ1_Handler          ; 101) GPIO Port Q1
        DCD     GPIOPortQ2_Handler          ; 102) GPIO Port Q2
        DCD     GPIOPortQ3_Handler          ; 103) GPIO Port Q3
        DCD     GPIOPortQ4_Handler          ; 104) GPIO Port Q4
        DCD     GPIOPortQ5_Handler          ; 105) GPIO Port Q5
        DCD     GPIOPortQ6_Handler          ; 106) GPIO Port Q6
        DCD     GPIOPortQ7_Handler          ; 107) GPIO Port Q7
        DCD     0                           ; 108) Reserved
        DCD     0                           ; 109) Reserved
        DCD     0                           ; 110) Reserved
        DCD     0                           ; 111) Reserved
        DCD     0                           ; 112) Reserved
        DCD     0                           ; 113) Reserved
        DCD     Timer6A_Handler             ; 114) Timer 6 subtimer A
        DCD     Timer6B_Handler             ; 115) Timer 6 subtimer B
        DCD     Timer7A_Handler             ; 116) Timer 7 subtimer A
        DCD     Timer7B_Handler             ; 117) Timer 7 subtimer B
        DCD     I2C6_Handler                ; 118) I2C6 Master and Slave
        DCD     I2C7_Handler                ; 119) I2C7 Master and Slave
        DCD     0                           ; 120) Reserved
        DCD     0                           ; 121) Reserved
        DCD     0                           ; 122) Reserved
        DCD     0                           ; 123) Reserved
        DCD     0                           ; 124) Reserved
        DCD     I2C8_Handler                ; 125) I2C8 Master and Slave
        DCD     I2C9_Handler                ; 126) I2C9 Master and Slave
        DCD     0                           ; 127) Reserved
        DCD     0                           ; 128) Reserved
        DCD     0                           ; 129) Reserved

;******************************************************************************
;
; This is the code that gets called when the processor first starts execution
; following a reset event.
;
;******************************************************************************
        EXPORT  Reset_Handler
Reset_Handler
        ;
        ; Do not enable the floating-point unit.  Un-comment this to handle the
        ; case where main() uses floating-point and the function prologue saves
        ; floating-point registers (which will fault if floating-point is not
        ; enabled).  Any configuration of the floating-point unit using
        ; DriverLib APIs must be done here prior to the floating-point unit
        ; being enabled.
        ;
        ; Note that this does not use DriverLib since it might not be included
        ; in this project.
        ;
;        MOVW    R0, #0xED88
;        MOVT    R0, #0xE000
;        LDR     R1, [R0]
;        ORR     R1, #0x00F00000
;        STR     R1, [R0]

        ;
        ; Call the C library enty point that handles startup.  This will copy
        ; the .data section initializers from flash to SRAM and zero fill the
        ; .bss section.
        ;
        IMPORT  __main
        B       __main

;******************************************************************************
;
; This is the code that gets called when the processor receives a NMI.  This
; simply enters an infinite loop, preserving the system state for examination
; by a debugger.
;
;******************************************************************************
NMI_Handler     PROC
                EXPORT  NMI_Handler               [WEAK]
                B       .
                ENDP

;******************************************************************************
;
; This is the code that gets called when the processor receives a fault
; interrupt.  This simply enters an infinite loop, preserving the system state
; for examination by a debugger.
;
;******************************************************************************
HardFault_Handler\
                PROC
                EXPORT  HardFault_Handler         [WEAK]
                B       .
                ENDP

MemManage_Handler\
                PROC
                EXPORT  MemManage_Handler         [WEAK]
                B       .
                ENDP
BusFault_Handler\
                PROC
                EXPORT  BusFault_Handler          [WEAK]
                B       .
                ENDP
UsageFault_Handler\
                PROC
                EXPORT  UsageFault_Handler        [WEAK]
                B       .
                ENDP
SVC_Handler     PROC
                EXPORT  SVC_Handler               [WEAK]
                B       .
                ENDP
DebugMon_Handler\
                PROC
                EXPORT  DebugMon_Handler          [WEAK]
                B       .
                ENDP
PendSV_Handler  PROC
                EXPORT  PendSV_Handler            [WEAK]
                B       .
                ENDP
SysTick_Handler PROC
                EXPORT  SysTick_Handler           [WEAK]
                B       .
                ENDP
IntDefaultHandler\
                PROC

                EXPORT  GPIOPortA_Handler         [WEAK]
                EXPORT  GPIOPortB_Handler         [WEAK]
                EXPORT  GPIOPortC_Handler         [WEAK]
                EXPORT  GPIOPortD_Handler         [WEAK]
                EXPORT  GPIOPortE_Handler         [WEAK]
                EXPORT  UART0_Handler             [WEAK]
                EXPORT  UART1_Handler             [WEAK]
                EXPORT  SSI0_Handler              [WEAK]
                EXPORT  I2C0_Handler              [WEAK]
                EXPORT  PWM0Fault_Handler         [WEAK]
                EXPORT  PWM0Generator0_Handler    [WEAK]
                EXPORT  PWM0Generator1_Handler    [WEAK]
                EXPORT  PWM0Generator2_Handler    [WEAK]
                EXPORT  Quadrature0_Handler       [WEAK]
                EXPORT  ADC0Seq0_Handler          [WEAK]
                EXPORT  ADC0Seq1_Handler          [WEAK]
                EXPORT  ADC0Seq2_Handler          [WEAK]
                EXPORT  ADC0Seq3_Handler          [WEAK]
                EXPORT  WDT_Handler               [WEAK]
                EXPORT  Timer0A_Handler           [WEAK]
                EXPORT  Timer0B_Handler           [WEAK]
                EXPORT  Timer1A_Handler           [WEAK]
                EXPORT  Timer1B_Handler           [WEAK]
                EXPORT  Timer2A_Handler           [WEAK]
                EXPORT  Timer2B_Handler           [WEAK]
                EXPORT  Comp0_Handler             [WEAK]
                EXPORT  Comp1_Handler             [WEAK]
                EXPORT  Comp2_Handler             [WEAK]
                EXPORT  SysCtl_Handler            [WEAK]
                EXPORT  FlashCtl_Handler          [WEAK]
                EXPORT  GPIOPortF_Handler         [WEAK]
                EXPORT  GPIOPortG_Handler         [WEAK]
                EXPORT  GPIOPortH_Handler         [WEAK]
                EXPORT  UART2_Handler             [WEAK]
                EXPORT  SSI1_Handler              [WEAK]
                EXPORT  Timer3A_Handler           [WEAK]
                EXPORT  Timer3B_Handler           [WEAK]
                EXPORT  I2C1_Handler              [WEAK]
                EXPORT  CAN0_Handler              [WEAK]
                EXPORT  CAN1_Handler              [WEAK]
                EXPORT  Ethernet_Handler          [WEAK]
                EXPORT  Hibernate_Handler         [WEAK]
                EXPORT  USB0_Handler              [WEAK]
                EXPORT  PWM0Generator3_Handler    [WEAK]
                EXPORT  uDMA_Handler              [WEAK]
                EXPORT  uDMA_Error                [WEAK]
                EXPORT  ADC1Seq0_Handler          [WEAK]
                EXPORT  ADC1Seq1_Handler          [WEAK]
                EXPORT  ADC1Seq2_Handler          [WEAK]
                EXPORT  ADC1Seq3_Handler          [WEAK]
                EXPORT  ExtBus_Handler            [WEAK]
                EXPORT  GPIOPortJ_Handler         [WEAK]
                EXPORT  GPIOPortK_Handler         [WEAK]
                EXPORT  GPIOPortL_Handler         [WEAK]
                EXPORT  SSI2_Handler              [WEAK]
                EXPORT  SSI3_Handler              [WEAK]
                EXPORT  UART3_Handler             [WEAK]
                EXPORT  UART4_Handler             [WEAK]
                EXPORT  UART5_Handler             [WEAK]
                EXPORT  UART6_Handler             [WEAK]
                EXPORT  UART7_Handler             [WEAK]
                EXPORT  I2C2_Handler              [WEAK]
                EXPORT  I2C3_Handler              [WEAK]
                EXPORT  Timer4A_Handler           [WEAK]
                EXPORT  Timer4B_Handler           [WEAK]
                EXPORT  Timer5A_Handler           [WEAK]
                EXPORT  Timer5B_Handler           [WEAK]
                EXPORT  FPU_Handler               [WEAK]
                EXPORT  I2C4_Handler              [WEAK]
                EXPORT  I2C5_Handler              [WEAK]
                EXPORT  GPIOPortM_Handler         [WEAK]
                EXPORT  GPIOPortN_Handler         [WEAK]
                EXPORT  Tamper_Handler            [WEAK]
                EXPORT  GPIOPortP_Handler         [WEAK]
                EXPORT  GPIOPortP1_Handler        [WEAK]
                EXPORT  GPIOPortP2_Handler        [WEAK]
                EXPORT  GPIOPortP3_Handler        [WEAK]
                EXPORT  GPIOPortP4_Handler        [WEAK]
                EXPORT  GPIOPortP5_Handler        [WEAK]
                EXPORT  GPIOPortP6_Handler        [WEAK]
                EXPORT  GPIOPortP7_Handler        [WEAK]
                EXPORT  GPIOPortQ_Handler         [WEAK]
                EXPORT  GPIOPortQ1_Handler        [WEAK]
                EXPORT  GPIOPortQ2_Handler        [WEAK]
                EXPORT  GPIOPortQ3_Handler        [WEAK]
                EXPORT  GPIOPortQ4_Handler        [WEAK]
                EXPORT  GPIOPortQ5_Handler        [WEAK]
                EXPORT  GPIOPortQ6_Handler        [WEAK]
                EXPORT  GPIOPortQ7_Handler        [WEAK]
                EXPORT  Timer6A_Handler           [WEAK]
                EXPORT  Timer6B_Handler           [WEAK]
                EXPORT  Timer7A_Handler           [WEAK]
                EXPORT  Timer7B_Handler           [WEAK]
                EXPORT  I2C6_Handler              [WEAK]
                EXPORT  I2C7_Handler              [WEAK]
                EXPORT  I2C8_Handler              [WEAK]
                EXPORT  I2C9_Handler              [WEAK]

GPIOPortA_Handler
GPIOPortB_Handler
GPIOPortC_Handler
GPIOPortD_Handler
GPIOPortE_Handler
UART0_Handler
UART1_Handler
SSI0_Handler
I2C0_Handler
PWM0Fault_Handler
PWM0Generator0_Handler
PWM0Generator1_Handler
PWM0Generator2_Handler
Quadrature0_Handler
ADC0Seq0_Handler
ADC0Seq1_Handler
ADC0Seq2_Handler
ADC0Seq3_Handler
WDT_Handler
Timer0A_Handler
Timer0B_Handler
Timer1A_Handler
Timer1B_Handler
Timer2A_Handler
Timer2B_Handler
Comp0_Handler
Comp1_Handler
Comp2_Handler
SysCtl_Handler
FlashCtl_Handler
GPIOPortF_Handler
GPIOPortG_Handler
GPIOPortH_Handler
UART2_Handler
SSI1_Handler
Timer3A_Handler
Timer3B_Handler
I2C1_Handler
CAN0_Handler
CAN1_Handler
Ethernet_Handler
Hibernate_Handler
USB0_Handler
PWM0Generator3_Handler
uDMA_Handler
uDMA_Error
ADC1Seq0_Handler
ADC1Seq1_Handler
ADC1Seq2_Handler
ADC1Seq3_Handler
ExtBus_Handler
GPIOPortJ_Handler
GPIOPortK_Handler
GPIOPortL_Handler
SSI2_Handler
SSI3_Handler
UART3_Handler
UART4_Handler
UART5_Handler
UART6_Handler
UART7_Handler
I2C2_Handler
I2C3_Handler
Timer4A_Handler
Timer4B_Handler
Timer5A_Handler
Timer5B_Handler
FPU_Handler
I2C4_Handler
I2C5_Handler
GPIOPortM_Handler
GPIOPortN_Handler
Tamper_Handler
GPIOPortP_Handler
GPIOPortP1_Handler
GPIOPortP2_Handler
GPIOPortP3_Handler
GPIOPortP4_Handler
GPIOPortP5_Handler
GPIOPortP6_Handler
GPIOPortP7_Handler
GPIOPortQ_Handler
GPIOPortQ1_Handler
GPIOPortQ2_Handler
GPIOPortQ3_Handler
GPIOPortQ4_Handler
GPIOPortQ5_Handler
GPIOPortQ6_Handler
GPIOPortQ7_Handler
Timer6A_Handler
Timer6B_Handler
Timer7A_Handler
Timer7B_Handler
I2C6_Handler
I2C7_Handler
I2C8_Handler
I2C9_Handler

                B       .

                ENDP

;******************************************************************************
;
; Make sure the end of this section is aligned.
;
;******************************************************************************
        ALIGN

;******************************************************************************
;
; Some code in the normal code section for initializing the heap and stack.
;
;******************************************************************************
        AREA    |.text|, CODE, READONLY

;******************************************************************************
;
; Useful functions.
;
;******************************************************************************
        EXPORT  DisableInterrupts
        EXPORT  EnableInterrupts
        EXPORT  StartCritical
        EXPORT  EndCritical
        EXPORT  WaitForInterrupt

;*********** DisableInterrupts ***************
; disable interrupts
; inputs:  none
; outputs: none
DisableInterrupts
        CPSID  I
        BX     LR

;*********** EnableInterrupts ***************
; disable interrupts
; inputs:  none
; outputs: none
EnableInterrupts
        CPSIE  I
        BX     LR

;*********** StartCritical ************************
; make a copy of previous I bit, disable interrupts
; inputs:  none
; outputs: previous I bit
StartCritical
        MRS    R0, PRIMASK  ; save old status
        CPSID  I            ; mask all (except faults)
        BX     LR

;*********** EndCritical ************************
; using the copy of previous I bit, restore I bit to previous value
; inputs:  previous I bit
; outputs: none
EndCritical
        MSR    PRIMASK, R0
        BX     LR

;*********** WaitForInterrupt ************************
; go to low power mode while waiting for the next interrupt
; inputs:  none
; outputs: none
WaitForInterrupt
        WFI
        BX     LR

;******************************************************************************
;
; The function expected of the C library startup code for defining the stack
; and heap memory locations.  For the C library version of the startup code,
; provide this function so that the C library initialization code can find out
; the location of the stack and heap.
;
;******************************************************************************
    IF :DEF: __MICROLIB
        EXPORT  __initial_sp
        EXPORT  __heap_base
        EXPORT  __heap_limit
    ELSE
        IMPORT  __use_two_region_memory
        EXPORT  __user_initial_stackheap
__user_initial_stackheap
        LDR     R0, =HeapMem
        LDR     R1, =(StackMem + Stack)
        LDR     R2, =(HeapMem + Heap)
        LDR     R3, =StackMem
        BX      LR
    ENDIF

;******************************************************************************
;
; Make sure the end of this section is aligned.
;
;******************************************************************************
        ALIGN

;******************************************************************************
;
; Tell the assembler that we're done.
;
;******************************************************************************
        END
