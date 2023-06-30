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
FINAL_IMAGE=${DISTDIR}/Atmega32Avr.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/Atmega32Avr.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
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
SOURCEFILES_QUOTED_IF_SPACED=HAL/KeyPad/keypad_program.c HAL/LCD/LCD_Program.c MCAL/DIO/DIO.c MCAL/HAL_initializations.c Application.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/HAL/KeyPad/keypad_program.o ${OBJECTDIR}/HAL/LCD/LCD_Program.o ${OBJECTDIR}/MCAL/DIO/DIO.o ${OBJECTDIR}/MCAL/HAL_initializations.o ${OBJECTDIR}/Application.o
POSSIBLE_DEPFILES=${OBJECTDIR}/HAL/KeyPad/keypad_program.o.d ${OBJECTDIR}/HAL/LCD/LCD_Program.o.d ${OBJECTDIR}/MCAL/DIO/DIO.o.d ${OBJECTDIR}/MCAL/HAL_initializations.o.d ${OBJECTDIR}/Application.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/HAL/KeyPad/keypad_program.o ${OBJECTDIR}/HAL/LCD/LCD_Program.o ${OBJECTDIR}/MCAL/DIO/DIO.o ${OBJECTDIR}/MCAL/HAL_initializations.o ${OBJECTDIR}/Application.o

# Source Files
SOURCEFILES=HAL/KeyPad/keypad_program.c HAL/LCD/LCD_Program.c MCAL/DIO/DIO.c MCAL/HAL_initializations.c Application.c



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
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/Atmega32Avr.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=ATmega32
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/HAL/KeyPad/keypad_program.o: HAL/KeyPad/keypad_program.c  .generated_files/flags/default/3f81924c47fa1e40ecee0b43f38357a5672b3afb .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/HAL/KeyPad" 
	@${RM} ${OBJECTDIR}/HAL/KeyPad/keypad_program.o.d 
	@${RM} ${OBJECTDIR}/HAL/KeyPad/keypad_program.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -mcodecov=ram -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/HAL/KeyPad/keypad_program.o.d" -MT "${OBJECTDIR}/HAL/KeyPad/keypad_program.o.d" -MT ${OBJECTDIR}/HAL/KeyPad/keypad_program.o -o ${OBJECTDIR}/HAL/KeyPad/keypad_program.o HAL/KeyPad/keypad_program.c 
	
${OBJECTDIR}/HAL/LCD/LCD_Program.o: HAL/LCD/LCD_Program.c  .generated_files/flags/default/833b63e60eb6da5e474217c9bb34bd096edfe606 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/HAL/LCD" 
	@${RM} ${OBJECTDIR}/HAL/LCD/LCD_Program.o.d 
	@${RM} ${OBJECTDIR}/HAL/LCD/LCD_Program.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -mcodecov=ram -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/HAL/LCD/LCD_Program.o.d" -MT "${OBJECTDIR}/HAL/LCD/LCD_Program.o.d" -MT ${OBJECTDIR}/HAL/LCD/LCD_Program.o -o ${OBJECTDIR}/HAL/LCD/LCD_Program.o HAL/LCD/LCD_Program.c 
	
${OBJECTDIR}/MCAL/DIO/DIO.o: MCAL/DIO/DIO.c  .generated_files/flags/default/a058a00eb91991ab3319a07065906dce36239e6b .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/MCAL/DIO" 
	@${RM} ${OBJECTDIR}/MCAL/DIO/DIO.o.d 
	@${RM} ${OBJECTDIR}/MCAL/DIO/DIO.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -mcodecov=ram -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/MCAL/DIO/DIO.o.d" -MT "${OBJECTDIR}/MCAL/DIO/DIO.o.d" -MT ${OBJECTDIR}/MCAL/DIO/DIO.o -o ${OBJECTDIR}/MCAL/DIO/DIO.o MCAL/DIO/DIO.c 
	
${OBJECTDIR}/MCAL/HAL_initializations.o: MCAL/HAL_initializations.c  .generated_files/flags/default/b91c635b9933a34f48ee6723f037335504da40df .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/MCAL" 
	@${RM} ${OBJECTDIR}/MCAL/HAL_initializations.o.d 
	@${RM} ${OBJECTDIR}/MCAL/HAL_initializations.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -mcodecov=ram -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/MCAL/HAL_initializations.o.d" -MT "${OBJECTDIR}/MCAL/HAL_initializations.o.d" -MT ${OBJECTDIR}/MCAL/HAL_initializations.o -o ${OBJECTDIR}/MCAL/HAL_initializations.o MCAL/HAL_initializations.c 
	
${OBJECTDIR}/Application.o: Application.c  .generated_files/flags/default/cf3e27dc4682ce5fa6f2477b7c0308066feb10c6 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Application.o.d 
	@${RM} ${OBJECTDIR}/Application.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -mcodecov=ram -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/Application.o.d" -MT "${OBJECTDIR}/Application.o.d" -MT ${OBJECTDIR}/Application.o -o ${OBJECTDIR}/Application.o Application.c 
	
else
${OBJECTDIR}/HAL/KeyPad/keypad_program.o: HAL/KeyPad/keypad_program.c  .generated_files/flags/default/af483f8301e5c7088d7662a5f91155d21a5fbd8f .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/HAL/KeyPad" 
	@${RM} ${OBJECTDIR}/HAL/KeyPad/keypad_program.o.d 
	@${RM} ${OBJECTDIR}/HAL/KeyPad/keypad_program.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -mcodecov=ram -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/HAL/KeyPad/keypad_program.o.d" -MT "${OBJECTDIR}/HAL/KeyPad/keypad_program.o.d" -MT ${OBJECTDIR}/HAL/KeyPad/keypad_program.o -o ${OBJECTDIR}/HAL/KeyPad/keypad_program.o HAL/KeyPad/keypad_program.c 
	
${OBJECTDIR}/HAL/LCD/LCD_Program.o: HAL/LCD/LCD_Program.c  .generated_files/flags/default/58c64d8c379e554472235c2a680f856806520238 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/HAL/LCD" 
	@${RM} ${OBJECTDIR}/HAL/LCD/LCD_Program.o.d 
	@${RM} ${OBJECTDIR}/HAL/LCD/LCD_Program.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -mcodecov=ram -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/HAL/LCD/LCD_Program.o.d" -MT "${OBJECTDIR}/HAL/LCD/LCD_Program.o.d" -MT ${OBJECTDIR}/HAL/LCD/LCD_Program.o -o ${OBJECTDIR}/HAL/LCD/LCD_Program.o HAL/LCD/LCD_Program.c 
	
${OBJECTDIR}/MCAL/DIO/DIO.o: MCAL/DIO/DIO.c  .generated_files/flags/default/52d8f9d771aae8058f2cd3fc6e55ab7e96985e6e .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/MCAL/DIO" 
	@${RM} ${OBJECTDIR}/MCAL/DIO/DIO.o.d 
	@${RM} ${OBJECTDIR}/MCAL/DIO/DIO.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -mcodecov=ram -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/MCAL/DIO/DIO.o.d" -MT "${OBJECTDIR}/MCAL/DIO/DIO.o.d" -MT ${OBJECTDIR}/MCAL/DIO/DIO.o -o ${OBJECTDIR}/MCAL/DIO/DIO.o MCAL/DIO/DIO.c 
	
${OBJECTDIR}/MCAL/HAL_initializations.o: MCAL/HAL_initializations.c  .generated_files/flags/default/c1339ca2469a01fcf23768067f7ef573c2f73acb .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/MCAL" 
	@${RM} ${OBJECTDIR}/MCAL/HAL_initializations.o.d 
	@${RM} ${OBJECTDIR}/MCAL/HAL_initializations.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -mcodecov=ram -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/MCAL/HAL_initializations.o.d" -MT "${OBJECTDIR}/MCAL/HAL_initializations.o.d" -MT ${OBJECTDIR}/MCAL/HAL_initializations.o -o ${OBJECTDIR}/MCAL/HAL_initializations.o MCAL/HAL_initializations.c 
	
${OBJECTDIR}/Application.o: Application.c  .generated_files/flags/default/1cce6eedb199235022622dc75293d662feb36e6 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Application.o.d 
	@${RM} ${OBJECTDIR}/Application.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -mcodecov=ram -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/Application.o.d" -MT "${OBJECTDIR}/Application.o.d" -MT ${OBJECTDIR}/Application.o -o ${OBJECTDIR}/Application.o Application.c 
	
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
${DISTDIR}/Atmega32Avr.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/Atmega32Avr.X.${IMAGE_TYPE}.map  -D__DEBUG=1  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2 -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -mcodecov=ram -funsigned-char -funsigned-bitfields -Wall -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/Atmega32Avr.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  -o ${DISTDIR}/Atmega32Avr.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -Wl,--start-group  -Wl,-lm -Wl,--end-group  -Wl,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_SIMULATOR=1
	@${RM} ${DISTDIR}/Atmega32Avr.X.${IMAGE_TYPE}.hex 
	
else
${DISTDIR}/Atmega32Avr.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/Atmega32Avr.X.${IMAGE_TYPE}.map  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -mcodecov=ram -funsigned-char -funsigned-bitfields -Wall -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/Atmega32Avr.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  -o ${DISTDIR}/Atmega32Avr.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -Wl,--start-group  -Wl,-lm -Wl,--end-group 
	${MP_CC_DIR}\\avr-objcopy -O ihex "${DISTDIR}/Atmega32Avr.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}" "${DISTDIR}/Atmega32Avr.X.${IMAGE_TYPE}.hex"
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

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
