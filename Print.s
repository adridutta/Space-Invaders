; Print.s
; Student names: change this to your names or look very silly
; Last modification date: change this to the last modification date or look very silly
; Runs on LM4F120 or TM4C123
; EE319K lab 7 device driver for any LCD
;
; As part of Lab 7, students need to implement these LCD_OutDec and LCD_OutFix
; This driver assumes two low-level LCD functions
; ST7735_OutChar   outputs a single 8-bit ASCII character
; ST7735_OutString outputs a null-terminated string 

V0 EQU 0    ;binding
V1 EQU 1	
V2 EQU 2
V3 EQU 3
V4 EQU 4
V5 EQU 5
V6 EQU 6
V7 EQU 7
V8 EQU 8
V9 EQU 9   
	
	
	
	
	
	IMPORT   ST7735_OutChar
    IMPORT   ST7735_OutString
    EXPORT   LCD_OutDec
    EXPORT   LCD_OutFix

    AREA    |.text|, CODE, READONLY, ALIGN=2
    THUMB

  

;-----------------------LCD_OutDec-----------------------
; Output a 32-bit number in unsigned decimal format
; Input: R0 (call by value) 32-bit unsigned number
; Output: none
; Invariables: This function must not permanently modify registers R4 to R11
LCD_OutDec

MOD                    
	PUSH {R4, LR}                   ;allocate space
	SUB SP, #32
	
	CMP R0, #0            ;see if 0
	BEQ STOR
	B MOD1
	  	
STOR                      ;store 0
	ADD R0, #0x30
	STRB R0, [SP, #V0]
	
PRINT                         ;print 0
	LDRB R0, [SP, #V0]
	BL ST7735_OutChar

	ADD SP, #32		; deallocation
	POP { R4, LR}
    BX  LR
	
	
	
MOD1	
	MOV R1, #10               ;store 1 digit
	MOV R2, R0
	UDIV R2,R1		; R2 has quotient
	MUL R3, R1, R2		
	SUB R3, R0, R3 		; R3 has remainder
	ADD R3, #0x30
	STRB R3, [SP, #V0]
	
	MOV R0, R2                    ;store 2 digits
	UDIV R2, R1
	MUL R3, R1, R2
	SUB R3, R0, R3
	CMP R2, #0
	BNE STOR1
	CMP R3, #0
	BNE STOR1
	B PRINT0
STOR1
	ADD R3, #0x30
	STRB R3, [SP, #V1]
		
	
	MOV R0, R2                    ;store 3 digits
	UDIV R2, R1
	MUL R3, R1, R2
	SUB R3, R0, R3
	CMP R2, #0
	BNE STOR2
	CMP R3, #0
	BNE STOR2
	B PRINT1
STOR2
	ADD R3, #0x30
	STRB R3, [SP, #V2]
	
	MOV R0, R2                    ;store 4 digits
	UDIV R2, R1
	MUL R3, R1, R2
	SUB R3, R0, R3
	CMP R2, #0
	BNE STOR3
	CMP R3, #0
	BNE STOR3
	B PRINT2
STOR3
	ADD R3, #0x30
	STRB R3, [SP, #V3]
	
	MOV R0, R2                    ;store 5 digits
	UDIV R2, R1
	MUL R3, R1, R2
	SUB R3, R0, R3
	CMP R2, #0
	BNE STOR4
	CMP R3, #0
	BNE STOR4
	B PRINT3

STOR4
	ADD R3, #0x30
	STRB R3, [SP, #V4]
	
	MOV R0, R2                    ;store 6 digits
	UDIV R2, R1
	MUL R3, R1, R2
	SUB R3, R0, R3
	CMP R2, #0
	BNE STOR5
	CMP R3, #0
	BNE STOR5
	B PRINT4
STOR5
	ADD R3, #0x30
	STRB R3, [SP, #V5]
	
	MOV R0, R2                    ;store 7 digits
	UDIV R2, R1
	MUL R3, R1, R2
	SUB R3, R0, R3
	CMP R2, #0
	BNE STOR6
	CMP R3, #0
	BNE STOR6
	B PRINT5
STOR6
	ADD R3, #0x30
	STRB R3, [SP, #V6]
	
	MOV R0, R2                    ;store 8 digits
	UDIV R2, R1
	MUL R3, R1, R2
	SUB R3, R0, R3
	CMP R2, #0
	BNE STOR7
	CMP R3, #0
	BNE STOR7
	B PRINT6
STOR7
	ADD R3, #0x30
	STRB R3, [SP, #V7]
	
	MOV R0, R2                    ;store 9 digits
	UDIV R2, R1
	MUL R3, R1, R2
	SUB R3, R0, R3
	CMP R2, #0
	BNE STOR8
	CMP R3, #0
	BNE STOR8
	B PRINT7
STOR8
	ADD R3, #0x30
	STRB R3, [SP, #V8]
	
	MOV R0, R2                    ;store 10 digits
	UDIV R2, R1
	MUL R3, R1, R2
	SUB R3, R0, R3
	CMP R2, #0
	BNE STOR9
	CMP R3, #0
	BNE STOR9
	B PRINT8
STOR9
	ADD R3, #0x30
	STRB R3, [SP, #V9]
	



PRINT9                       ;print 10 digits
	LDRB R0, [SP, #V9]
	BL ST7735_OutChar


PRINT8                       ;print 9 digits
	LDRB R0, [SP, #V8]
	BL ST7735_OutChar


PRINT7                       ;print 8 digits
	LDRB R0, [SP, #V7]
	BL ST7735_OutChar


PRINT6                        ;print 7 digits
	LDRB R0, [SP, #V6]
	BL ST7735_OutChar

PRINT5                       ;print 6 digits
	LDRB R0, [SP, #V5]
	BL ST7735_OutChar


PRINT4                       ;print 5 digits
	LDRB R0, [SP, #V4]
	BL ST7735_OutChar


PRINT3                        ;print 4 digits
	LDRB R0, [SP, #V3]
	BL ST7735_OutChar


PRINT2                        ;print 3 digits
	LDRB R0, [SP, #V2]
	BL ST7735_OutChar


PRINT1                         ;print 2 digits
	LDRB R0, [SP, #V1]
	BL ST7735_OutChar


PRINT0                         ;print 1 digit
	LDRB R0, [SP, #V0]
	BL ST7735_OutChar
	ADD SP, #32
	POP {R4, LR}
	BX LR 



      BX  LR
;* * * * * * * * End of LCD_OutDec * * * * * * * *

; -----------------------LCD _OutFix----------------------
; Output characters to LCD display in fixed-point format
; unsigned decimal, resolution 0.001, range 0.000 to 9.999
; Inputs:  R0 is an unsigned 32-bit number
; Outputs: none
; E.g., R0=0,    then output "0.000 "
;       R0=3,    then output "0.003 "
;       R0=89,   then output "0.089 "
;       R0=123,  then output "0.123 "
;       R0=9999, then output "9.999 "
;       R0>9999, then output "*.*** "
; Invariables: This function must not permanently modify registers R4 to R11
LCD_OutFix

     BX   LR
 
     ALIGN
;* * * * * * * * End of LCD_OutFix * * * * * * * *

     ALIGN                           ; make sure the end of this section is aligned
     END                             ; end of file
