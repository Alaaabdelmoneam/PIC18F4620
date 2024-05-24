#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/Projects.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/Projects.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=ECU_LAYER/CHAR_LCD/chr_lcd.c ECU_LAYER/DC_MOTOR_DRIVER/dc_motor.c MCAL_LAYER/EEPROM/EEPROM.c ECU_LAYER/KEYPAD/keypad.c ECU_LAYER/LCD/LCD.c ECU_LAYER/LED/LED.c ECU_LAYER/PUSH_BUTTON/PUSH_BTN.c ECU_LAYER/RELAY/RELAY.c MCAL_LAYER/ADC/adc.c MCAL_LAYER/GPIO/HAL_GPIO.c MCAL_LAYER/interrupts/MCAL_INTERNAL_INTERRUPT.c MCAL_LAYER/interrupts/MCAL_EXTERNAL_INTERRUPT.c MCAL_LAYER/interrupts/MCAL_INTERRUPT_MANAGER.c MCAL_LAYER/TIMER0/timer.c MCAL_LAYER/TIMER1/timer.c MCAL_LAYER/TIMER2/timer2.c MCAL_LAYER/TIMER3/timer3.c MCAL_LAYER/DEVICE_CONFIG.c application.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/ECU_LAYER/CHAR_LCD/chr_lcd.p1 ${OBJECTDIR}/ECU_LAYER/DC_MOTOR_DRIVER/dc_motor.p1 ${OBJECTDIR}/MCAL_LAYER/EEPROM/EEPROM.p1 ${OBJECTDIR}/ECU_LAYER/KEYPAD/keypad.p1 ${OBJECTDIR}/ECU_LAYER/LCD/LCD.p1 ${OBJECTDIR}/ECU_LAYER/LED/LED.p1 ${OBJECTDIR}/ECU_LAYER/PUSH_BUTTON/PUSH_BTN.p1 ${OBJECTDIR}/ECU_LAYER/RELAY/RELAY.p1 ${OBJECTDIR}/MCAL_LAYER/ADC/adc.p1 ${OBJECTDIR}/MCAL_LAYER/GPIO/HAL_GPIO.p1 ${OBJECTDIR}/MCAL_LAYER/interrupts/MCAL_INTERNAL_INTERRUPT.p1 ${OBJECTDIR}/MCAL_LAYER/interrupts/MCAL_EXTERNAL_INTERRUPT.p1 ${OBJECTDIR}/MCAL_LAYER/interrupts/MCAL_INTERRUPT_MANAGER.p1 ${OBJECTDIR}/MCAL_LAYER/TIMER0/timer.p1 ${OBJECTDIR}/MCAL_LAYER/TIMER1/timer.p1 ${OBJECTDIR}/MCAL_LAYER/TIMER2/timer2.p1 ${OBJECTDIR}/MCAL_LAYER/TIMER3/timer3.p1 ${OBJECTDIR}/MCAL_LAYER/DEVICE_CONFIG.p1 ${OBJECTDIR}/application.p1
POSSIBLE_DEPFILES=${OBJECTDIR}/ECU_LAYER/CHAR_LCD/chr_lcd.p1.d ${OBJECTDIR}/ECU_LAYER/DC_MOTOR_DRIVER/dc_motor.p1.d ${OBJECTDIR}/MCAL_LAYER/EEPROM/EEPROM.p1.d ${OBJECTDIR}/ECU_LAYER/KEYPAD/keypad.p1.d ${OBJECTDIR}/ECU_LAYER/LCD/LCD.p1.d ${OBJECTDIR}/ECU_LAYER/LED/LED.p1.d ${OBJECTDIR}/ECU_LAYER/PUSH_BUTTON/PUSH_BTN.p1.d ${OBJECTDIR}/ECU_LAYER/RELAY/RELAY.p1.d ${OBJECTDIR}/MCAL_LAYER/ADC/adc.p1.d ${OBJECTDIR}/MCAL_LAYER/GPIO/HAL_GPIO.p1.d ${OBJECTDIR}/MCAL_LAYER/interrupts/MCAL_INTERNAL_INTERRUPT.p1.d ${OBJECTDIR}/MCAL_LAYER/interrupts/MCAL_EXTERNAL_INTERRUPT.p1.d ${OBJECTDIR}/MCAL_LAYER/interrupts/MCAL_INTERRUPT_MANAGER.p1.d ${OBJECTDIR}/MCAL_LAYER/TIMER0/timer.p1.d ${OBJECTDIR}/MCAL_LAYER/TIMER1/timer.p1.d ${OBJECTDIR}/MCAL_LAYER/TIMER2/timer2.p1.d ${OBJECTDIR}/MCAL_LAYER/TIMER3/timer3.p1.d ${OBJECTDIR}/MCAL_LAYER/DEVICE_CONFIG.p1.d ${OBJECTDIR}/application.p1.d

# Object Files
OBJECTFILES=${OBJECTDIR}/ECU_LAYER/CHAR_LCD/chr_lcd.p1 ${OBJECTDIR}/ECU_LAYER/DC_MOTOR_DRIVER/dc_motor.p1 ${OBJECTDIR}/MCAL_LAYER/EEPROM/EEPROM.p1 ${OBJECTDIR}/ECU_LAYER/KEYPAD/keypad.p1 ${OBJECTDIR}/ECU_LAYER/LCD/LCD.p1 ${OBJECTDIR}/ECU_LAYER/LED/LED.p1 ${OBJECTDIR}/ECU_LAYER/PUSH_BUTTON/PUSH_BTN.p1 ${OBJECTDIR}/ECU_LAYER/RELAY/RELAY.p1 ${OBJECTDIR}/MCAL_LAYER/ADC/adc.p1 ${OBJECTDIR}/MCAL_LAYER/GPIO/HAL_GPIO.p1 ${OBJECTDIR}/MCAL_LAYER/interrupts/MCAL_INTERNAL_INTERRUPT.p1 ${OBJECTDIR}/MCAL_LAYER/interrupts/MCAL_EXTERNAL_INTERRUPT.p1 ${OBJECTDIR}/MCAL_LAYER/interrupts/MCAL_INTERRUPT_MANAGER.p1 ${OBJECTDIR}/MCAL_LAYER/TIMER0/timer.p1 ${OBJECTDIR}/MCAL_LAYER/TIMER1/timer.p1 ${OBJECTDIR}/MCAL_LAYER/TIMER2/timer2.p1 ${OBJECTDIR}/MCAL_LAYER/TIMER3/timer3.p1 ${OBJECTDIR}/MCAL_LAYER/DEVICE_CONFIG.p1 ${OBJECTDIR}/application.p1

# Source Files
SOURCEFILES=ECU_LAYER/CHAR_LCD/chr_lcd.c ECU_LAYER/DC_MOTOR_DRIVER/dc_motor.c MCAL_LAYER/EEPROM/EEPROM.c ECU_LAYER/KEYPAD/keypad.c ECU_LAYER/LCD/LCD.c ECU_LAYER/LED/LED.c ECU_LAYER/PUSH_BUTTON/PUSH_BTN.c ECU_LAYER/RELAY/RELAY.c MCAL_LAYER/ADC/adc.c MCAL_LAYER/GPIO/HAL_GPIO.c MCAL_LAYER/interrupts/MCAL_INTERNAL_INTERRUPT.c MCAL_LAYER/interrupts/MCAL_EXTERNAL_INTERRUPT.c MCAL_LAYER/interrupts/MCAL_INTERRUPT_MANAGER.c MCAL_LAYER/TIMER0/timer.c MCAL_LAYER/TIMER1/timer.c MCAL_LAYER/TIMER2/timer2.c MCAL_LAYER/TIMER3/timer3.c MCAL_LAYER/DEVICE_CONFIG.c application.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/Projects.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=18F4620
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/ECU_LAYER/CHAR_LCD/chr_lcd.p1: ECU_LAYER/CHAR_LCD/chr_lcd.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_LAYER/CHAR_LCD" 
	@${RM} ${OBJECTDIR}/ECU_LAYER/CHAR_LCD/chr_lcd.p1.d 
	@${RM} ${OBJECTDIR}/ECU_LAYER/CHAR_LCD/chr_lcd.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_LAYER/CHAR_LCD/chr_lcd.p1 ECU_LAYER/CHAR_LCD/chr_lcd.c 
	@-${MV} ${OBJECTDIR}/ECU_LAYER/CHAR_LCD/chr_lcd.d ${OBJECTDIR}/ECU_LAYER/CHAR_LCD/chr_lcd.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_LAYER/CHAR_LCD/chr_lcd.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_LAYER/DC_MOTOR_DRIVER/dc_motor.p1: ECU_LAYER/DC_MOTOR_DRIVER/dc_motor.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_LAYER/DC_MOTOR_DRIVER" 
	@${RM} ${OBJECTDIR}/ECU_LAYER/DC_MOTOR_DRIVER/dc_motor.p1.d 
	@${RM} ${OBJECTDIR}/ECU_LAYER/DC_MOTOR_DRIVER/dc_motor.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_LAYER/DC_MOTOR_DRIVER/dc_motor.p1 ECU_LAYER/DC_MOTOR_DRIVER/dc_motor.c 
	@-${MV} ${OBJECTDIR}/ECU_LAYER/DC_MOTOR_DRIVER/dc_motor.d ${OBJECTDIR}/ECU_LAYER/DC_MOTOR_DRIVER/dc_motor.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_LAYER/DC_MOTOR_DRIVER/dc_motor.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/EEPROM/EEPROM.p1: MCAL_LAYER/EEPROM/EEPROM.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER/EEPROM" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/EEPROM/EEPROM.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/EEPROM/EEPROM.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/EEPROM/EEPROM.p1 MCAL_LAYER/EEPROM/EEPROM.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/EEPROM/EEPROM.d ${OBJECTDIR}/MCAL_LAYER/EEPROM/EEPROM.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/EEPROM/EEPROM.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_LAYER/KEYPAD/keypad.p1: ECU_LAYER/KEYPAD/keypad.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_LAYER/KEYPAD" 
	@${RM} ${OBJECTDIR}/ECU_LAYER/KEYPAD/keypad.p1.d 
	@${RM} ${OBJECTDIR}/ECU_LAYER/KEYPAD/keypad.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_LAYER/KEYPAD/keypad.p1 ECU_LAYER/KEYPAD/keypad.c 
	@-${MV} ${OBJECTDIR}/ECU_LAYER/KEYPAD/keypad.d ${OBJECTDIR}/ECU_LAYER/KEYPAD/keypad.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_LAYER/KEYPAD/keypad.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_LAYER/LCD/LCD.p1: ECU_LAYER/LCD/LCD.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_LAYER/LCD" 
	@${RM} ${OBJECTDIR}/ECU_LAYER/LCD/LCD.p1.d 
	@${RM} ${OBJECTDIR}/ECU_LAYER/LCD/LCD.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_LAYER/LCD/LCD.p1 ECU_LAYER/LCD/LCD.c 
	@-${MV} ${OBJECTDIR}/ECU_LAYER/LCD/LCD.d ${OBJECTDIR}/ECU_LAYER/LCD/LCD.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_LAYER/LCD/LCD.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_LAYER/LED/LED.p1: ECU_LAYER/LED/LED.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_LAYER/LED" 
	@${RM} ${OBJECTDIR}/ECU_LAYER/LED/LED.p1.d 
	@${RM} ${OBJECTDIR}/ECU_LAYER/LED/LED.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_LAYER/LED/LED.p1 ECU_LAYER/LED/LED.c 
	@-${MV} ${OBJECTDIR}/ECU_LAYER/LED/LED.d ${OBJECTDIR}/ECU_LAYER/LED/LED.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_LAYER/LED/LED.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_LAYER/PUSH_BUTTON/PUSH_BTN.p1: ECU_LAYER/PUSH_BUTTON/PUSH_BTN.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_LAYER/PUSH_BUTTON" 
	@${RM} ${OBJECTDIR}/ECU_LAYER/PUSH_BUTTON/PUSH_BTN.p1.d 
	@${RM} ${OBJECTDIR}/ECU_LAYER/PUSH_BUTTON/PUSH_BTN.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_LAYER/PUSH_BUTTON/PUSH_BTN.p1 ECU_LAYER/PUSH_BUTTON/PUSH_BTN.c 
	@-${MV} ${OBJECTDIR}/ECU_LAYER/PUSH_BUTTON/PUSH_BTN.d ${OBJECTDIR}/ECU_LAYER/PUSH_BUTTON/PUSH_BTN.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_LAYER/PUSH_BUTTON/PUSH_BTN.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_LAYER/RELAY/RELAY.p1: ECU_LAYER/RELAY/RELAY.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_LAYER/RELAY" 
	@${RM} ${OBJECTDIR}/ECU_LAYER/RELAY/RELAY.p1.d 
	@${RM} ${OBJECTDIR}/ECU_LAYER/RELAY/RELAY.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_LAYER/RELAY/RELAY.p1 ECU_LAYER/RELAY/RELAY.c 
	@-${MV} ${OBJECTDIR}/ECU_LAYER/RELAY/RELAY.d ${OBJECTDIR}/ECU_LAYER/RELAY/RELAY.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_LAYER/RELAY/RELAY.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/ADC/adc.p1: MCAL_LAYER/ADC/adc.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER/ADC" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/ADC/adc.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/ADC/adc.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/ADC/adc.p1 MCAL_LAYER/ADC/adc.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/ADC/adc.d ${OBJECTDIR}/MCAL_LAYER/ADC/adc.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/ADC/adc.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/GPIO/HAL_GPIO.p1: MCAL_LAYER/GPIO/HAL_GPIO.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER/GPIO" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/GPIO/HAL_GPIO.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/GPIO/HAL_GPIO.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/GPIO/HAL_GPIO.p1 MCAL_LAYER/GPIO/HAL_GPIO.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/GPIO/HAL_GPIO.d ${OBJECTDIR}/MCAL_LAYER/GPIO/HAL_GPIO.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/GPIO/HAL_GPIO.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/interrupts/MCAL_INTERNAL_INTERRUPT.p1: MCAL_LAYER/interrupts/MCAL_INTERNAL_INTERRUPT.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER/interrupts" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/interrupts/MCAL_INTERNAL_INTERRUPT.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/interrupts/MCAL_INTERNAL_INTERRUPT.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/interrupts/MCAL_INTERNAL_INTERRUPT.p1 MCAL_LAYER/interrupts/MCAL_INTERNAL_INTERRUPT.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/interrupts/MCAL_INTERNAL_INTERRUPT.d ${OBJECTDIR}/MCAL_LAYER/interrupts/MCAL_INTERNAL_INTERRUPT.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/interrupts/MCAL_INTERNAL_INTERRUPT.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/interrupts/MCAL_EXTERNAL_INTERRUPT.p1: MCAL_LAYER/interrupts/MCAL_EXTERNAL_INTERRUPT.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER/interrupts" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/interrupts/MCAL_EXTERNAL_INTERRUPT.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/interrupts/MCAL_EXTERNAL_INTERRUPT.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/interrupts/MCAL_EXTERNAL_INTERRUPT.p1 MCAL_LAYER/interrupts/MCAL_EXTERNAL_INTERRUPT.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/interrupts/MCAL_EXTERNAL_INTERRUPT.d ${OBJECTDIR}/MCAL_LAYER/interrupts/MCAL_EXTERNAL_INTERRUPT.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/interrupts/MCAL_EXTERNAL_INTERRUPT.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/interrupts/MCAL_INTERRUPT_MANAGER.p1: MCAL_LAYER/interrupts/MCAL_INTERRUPT_MANAGER.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER/interrupts" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/interrupts/MCAL_INTERRUPT_MANAGER.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/interrupts/MCAL_INTERRUPT_MANAGER.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/interrupts/MCAL_INTERRUPT_MANAGER.p1 MCAL_LAYER/interrupts/MCAL_INTERRUPT_MANAGER.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/interrupts/MCAL_INTERRUPT_MANAGER.d ${OBJECTDIR}/MCAL_LAYER/interrupts/MCAL_INTERRUPT_MANAGER.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/interrupts/MCAL_INTERRUPT_MANAGER.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/TIMER0/timer.p1: MCAL_LAYER/TIMER0/timer.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER/TIMER0" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/TIMER0/timer.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/TIMER0/timer.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/TIMER0/timer.p1 MCAL_LAYER/TIMER0/timer.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/TIMER0/timer.d ${OBJECTDIR}/MCAL_LAYER/TIMER0/timer.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/TIMER0/timer.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/TIMER1/timer.p1: MCAL_LAYER/TIMER1/timer.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER/TIMER1" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/TIMER1/timer.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/TIMER1/timer.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/TIMER1/timer.p1 MCAL_LAYER/TIMER1/timer.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/TIMER1/timer.d ${OBJECTDIR}/MCAL_LAYER/TIMER1/timer.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/TIMER1/timer.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/TIMER2/timer2.p1: MCAL_LAYER/TIMER2/timer2.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER/TIMER2" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/TIMER2/timer2.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/TIMER2/timer2.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/TIMER2/timer2.p1 MCAL_LAYER/TIMER2/timer2.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/TIMER2/timer2.d ${OBJECTDIR}/MCAL_LAYER/TIMER2/timer2.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/TIMER2/timer2.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/TIMER3/timer3.p1: MCAL_LAYER/TIMER3/timer3.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER/TIMER3" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/TIMER3/timer3.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/TIMER3/timer3.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/TIMER3/timer3.p1 MCAL_LAYER/TIMER3/timer3.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/TIMER3/timer3.d ${OBJECTDIR}/MCAL_LAYER/TIMER3/timer3.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/TIMER3/timer3.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/DEVICE_CONFIG.p1: MCAL_LAYER/DEVICE_CONFIG.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/DEVICE_CONFIG.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/DEVICE_CONFIG.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/DEVICE_CONFIG.p1 MCAL_LAYER/DEVICE_CONFIG.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/DEVICE_CONFIG.d ${OBJECTDIR}/MCAL_LAYER/DEVICE_CONFIG.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/DEVICE_CONFIG.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/application.p1: application.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/application.p1.d 
	@${RM} ${OBJECTDIR}/application.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/application.p1 application.c 
	@-${MV} ${OBJECTDIR}/application.d ${OBJECTDIR}/application.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/application.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/ECU_LAYER/CHAR_LCD/chr_lcd.p1: ECU_LAYER/CHAR_LCD/chr_lcd.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_LAYER/CHAR_LCD" 
	@${RM} ${OBJECTDIR}/ECU_LAYER/CHAR_LCD/chr_lcd.p1.d 
	@${RM} ${OBJECTDIR}/ECU_LAYER/CHAR_LCD/chr_lcd.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_LAYER/CHAR_LCD/chr_lcd.p1 ECU_LAYER/CHAR_LCD/chr_lcd.c 
	@-${MV} ${OBJECTDIR}/ECU_LAYER/CHAR_LCD/chr_lcd.d ${OBJECTDIR}/ECU_LAYER/CHAR_LCD/chr_lcd.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_LAYER/CHAR_LCD/chr_lcd.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_LAYER/DC_MOTOR_DRIVER/dc_motor.p1: ECU_LAYER/DC_MOTOR_DRIVER/dc_motor.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_LAYER/DC_MOTOR_DRIVER" 
	@${RM} ${OBJECTDIR}/ECU_LAYER/DC_MOTOR_DRIVER/dc_motor.p1.d 
	@${RM} ${OBJECTDIR}/ECU_LAYER/DC_MOTOR_DRIVER/dc_motor.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_LAYER/DC_MOTOR_DRIVER/dc_motor.p1 ECU_LAYER/DC_MOTOR_DRIVER/dc_motor.c 
	@-${MV} ${OBJECTDIR}/ECU_LAYER/DC_MOTOR_DRIVER/dc_motor.d ${OBJECTDIR}/ECU_LAYER/DC_MOTOR_DRIVER/dc_motor.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_LAYER/DC_MOTOR_DRIVER/dc_motor.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/EEPROM/EEPROM.p1: MCAL_LAYER/EEPROM/EEPROM.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER/EEPROM" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/EEPROM/EEPROM.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/EEPROM/EEPROM.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/EEPROM/EEPROM.p1 MCAL_LAYER/EEPROM/EEPROM.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/EEPROM/EEPROM.d ${OBJECTDIR}/MCAL_LAYER/EEPROM/EEPROM.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/EEPROM/EEPROM.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_LAYER/KEYPAD/keypad.p1: ECU_LAYER/KEYPAD/keypad.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_LAYER/KEYPAD" 
	@${RM} ${OBJECTDIR}/ECU_LAYER/KEYPAD/keypad.p1.d 
	@${RM} ${OBJECTDIR}/ECU_LAYER/KEYPAD/keypad.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_LAYER/KEYPAD/keypad.p1 ECU_LAYER/KEYPAD/keypad.c 
	@-${MV} ${OBJECTDIR}/ECU_LAYER/KEYPAD/keypad.d ${OBJECTDIR}/ECU_LAYER/KEYPAD/keypad.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_LAYER/KEYPAD/keypad.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_LAYER/LCD/LCD.p1: ECU_LAYER/LCD/LCD.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_LAYER/LCD" 
	@${RM} ${OBJECTDIR}/ECU_LAYER/LCD/LCD.p1.d 
	@${RM} ${OBJECTDIR}/ECU_LAYER/LCD/LCD.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_LAYER/LCD/LCD.p1 ECU_LAYER/LCD/LCD.c 
	@-${MV} ${OBJECTDIR}/ECU_LAYER/LCD/LCD.d ${OBJECTDIR}/ECU_LAYER/LCD/LCD.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_LAYER/LCD/LCD.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_LAYER/LED/LED.p1: ECU_LAYER/LED/LED.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_LAYER/LED" 
	@${RM} ${OBJECTDIR}/ECU_LAYER/LED/LED.p1.d 
	@${RM} ${OBJECTDIR}/ECU_LAYER/LED/LED.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_LAYER/LED/LED.p1 ECU_LAYER/LED/LED.c 
	@-${MV} ${OBJECTDIR}/ECU_LAYER/LED/LED.d ${OBJECTDIR}/ECU_LAYER/LED/LED.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_LAYER/LED/LED.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_LAYER/PUSH_BUTTON/PUSH_BTN.p1: ECU_LAYER/PUSH_BUTTON/PUSH_BTN.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_LAYER/PUSH_BUTTON" 
	@${RM} ${OBJECTDIR}/ECU_LAYER/PUSH_BUTTON/PUSH_BTN.p1.d 
	@${RM} ${OBJECTDIR}/ECU_LAYER/PUSH_BUTTON/PUSH_BTN.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_LAYER/PUSH_BUTTON/PUSH_BTN.p1 ECU_LAYER/PUSH_BUTTON/PUSH_BTN.c 
	@-${MV} ${OBJECTDIR}/ECU_LAYER/PUSH_BUTTON/PUSH_BTN.d ${OBJECTDIR}/ECU_LAYER/PUSH_BUTTON/PUSH_BTN.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_LAYER/PUSH_BUTTON/PUSH_BTN.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_LAYER/RELAY/RELAY.p1: ECU_LAYER/RELAY/RELAY.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_LAYER/RELAY" 
	@${RM} ${OBJECTDIR}/ECU_LAYER/RELAY/RELAY.p1.d 
	@${RM} ${OBJECTDIR}/ECU_LAYER/RELAY/RELAY.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_LAYER/RELAY/RELAY.p1 ECU_LAYER/RELAY/RELAY.c 
	@-${MV} ${OBJECTDIR}/ECU_LAYER/RELAY/RELAY.d ${OBJECTDIR}/ECU_LAYER/RELAY/RELAY.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_LAYER/RELAY/RELAY.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/ADC/adc.p1: MCAL_LAYER/ADC/adc.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER/ADC" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/ADC/adc.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/ADC/adc.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/ADC/adc.p1 MCAL_LAYER/ADC/adc.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/ADC/adc.d ${OBJECTDIR}/MCAL_LAYER/ADC/adc.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/ADC/adc.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/GPIO/HAL_GPIO.p1: MCAL_LAYER/GPIO/HAL_GPIO.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER/GPIO" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/GPIO/HAL_GPIO.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/GPIO/HAL_GPIO.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/GPIO/HAL_GPIO.p1 MCAL_LAYER/GPIO/HAL_GPIO.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/GPIO/HAL_GPIO.d ${OBJECTDIR}/MCAL_LAYER/GPIO/HAL_GPIO.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/GPIO/HAL_GPIO.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/interrupts/MCAL_INTERNAL_INTERRUPT.p1: MCAL_LAYER/interrupts/MCAL_INTERNAL_INTERRUPT.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER/interrupts" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/interrupts/MCAL_INTERNAL_INTERRUPT.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/interrupts/MCAL_INTERNAL_INTERRUPT.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/interrupts/MCAL_INTERNAL_INTERRUPT.p1 MCAL_LAYER/interrupts/MCAL_INTERNAL_INTERRUPT.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/interrupts/MCAL_INTERNAL_INTERRUPT.d ${OBJECTDIR}/MCAL_LAYER/interrupts/MCAL_INTERNAL_INTERRUPT.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/interrupts/MCAL_INTERNAL_INTERRUPT.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/interrupts/MCAL_EXTERNAL_INTERRUPT.p1: MCAL_LAYER/interrupts/MCAL_EXTERNAL_INTERRUPT.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER/interrupts" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/interrupts/MCAL_EXTERNAL_INTERRUPT.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/interrupts/MCAL_EXTERNAL_INTERRUPT.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/interrupts/MCAL_EXTERNAL_INTERRUPT.p1 MCAL_LAYER/interrupts/MCAL_EXTERNAL_INTERRUPT.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/interrupts/MCAL_EXTERNAL_INTERRUPT.d ${OBJECTDIR}/MCAL_LAYER/interrupts/MCAL_EXTERNAL_INTERRUPT.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/interrupts/MCAL_EXTERNAL_INTERRUPT.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/interrupts/MCAL_INTERRUPT_MANAGER.p1: MCAL_LAYER/interrupts/MCAL_INTERRUPT_MANAGER.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER/interrupts" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/interrupts/MCAL_INTERRUPT_MANAGER.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/interrupts/MCAL_INTERRUPT_MANAGER.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/interrupts/MCAL_INTERRUPT_MANAGER.p1 MCAL_LAYER/interrupts/MCAL_INTERRUPT_MANAGER.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/interrupts/MCAL_INTERRUPT_MANAGER.d ${OBJECTDIR}/MCAL_LAYER/interrupts/MCAL_INTERRUPT_MANAGER.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/interrupts/MCAL_INTERRUPT_MANAGER.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/TIMER0/timer.p1: MCAL_LAYER/TIMER0/timer.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER/TIMER0" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/TIMER0/timer.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/TIMER0/timer.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/TIMER0/timer.p1 MCAL_LAYER/TIMER0/timer.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/TIMER0/timer.d ${OBJECTDIR}/MCAL_LAYER/TIMER0/timer.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/TIMER0/timer.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/TIMER1/timer.p1: MCAL_LAYER/TIMER1/timer.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER/TIMER1" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/TIMER1/timer.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/TIMER1/timer.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/TIMER1/timer.p1 MCAL_LAYER/TIMER1/timer.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/TIMER1/timer.d ${OBJECTDIR}/MCAL_LAYER/TIMER1/timer.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/TIMER1/timer.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/TIMER2/timer2.p1: MCAL_LAYER/TIMER2/timer2.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER/TIMER2" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/TIMER2/timer2.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/TIMER2/timer2.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/TIMER2/timer2.p1 MCAL_LAYER/TIMER2/timer2.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/TIMER2/timer2.d ${OBJECTDIR}/MCAL_LAYER/TIMER2/timer2.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/TIMER2/timer2.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/TIMER3/timer3.p1: MCAL_LAYER/TIMER3/timer3.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER/TIMER3" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/TIMER3/timer3.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/TIMER3/timer3.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/TIMER3/timer3.p1 MCAL_LAYER/TIMER3/timer3.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/TIMER3/timer3.d ${OBJECTDIR}/MCAL_LAYER/TIMER3/timer3.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/TIMER3/timer3.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/DEVICE_CONFIG.p1: MCAL_LAYER/DEVICE_CONFIG.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/DEVICE_CONFIG.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/DEVICE_CONFIG.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/DEVICE_CONFIG.p1 MCAL_LAYER/DEVICE_CONFIG.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/DEVICE_CONFIG.d ${OBJECTDIR}/MCAL_LAYER/DEVICE_CONFIG.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/DEVICE_CONFIG.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/application.p1: application.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/application.p1.d 
	@${RM} ${OBJECTDIR}/application.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/application.p1 application.c 
	@-${MV} ${OBJECTDIR}/application.d ${OBJECTDIR}/application.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/application.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/Projects.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/Projects.${IMAGE_TYPE}.map  -D__DEBUG=1  -mdebugger=none  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits -std=c99 -gcoff -mstack=compiled:auto:auto:auto        $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/Projects.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	@${RM} ${DISTDIR}/Projects.${IMAGE_TYPE}.hex 
	
else
${DISTDIR}/Projects.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/Projects.${IMAGE_TYPE}.map  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits -std=c99 -gcoff -mstack=compiled:auto:auto:auto     $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/Projects.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(wildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
