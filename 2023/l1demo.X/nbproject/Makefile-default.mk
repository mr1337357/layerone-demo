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
MKDIR=mkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/l1demo.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/l1demo.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
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
SOURCEFILES_QUOTED_IF_SPACED=../src/gpu.c ../src/uart.c ../src/audio.c ../src/gfx.c ../src/program.c ../src/io.c ../src/basic_external_functions.c ../src/main.c ../src/editor.c ../src/parser.c ../src/interpreter.c ../src/demo.c ../src/variable.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/1360937237/gpu.o ${OBJECTDIR}/_ext/1360937237/uart.o ${OBJECTDIR}/_ext/1360937237/audio.o ${OBJECTDIR}/_ext/1360937237/gfx.o ${OBJECTDIR}/_ext/1360937237/program.o ${OBJECTDIR}/_ext/1360937237/io.o ${OBJECTDIR}/_ext/1360937237/basic_external_functions.o ${OBJECTDIR}/_ext/1360937237/main.o ${OBJECTDIR}/_ext/1360937237/editor.o ${OBJECTDIR}/_ext/1360937237/parser.o ${OBJECTDIR}/_ext/1360937237/interpreter.o ${OBJECTDIR}/_ext/1360937237/demo.o ${OBJECTDIR}/_ext/1360937237/variable.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/1360937237/gpu.o.d ${OBJECTDIR}/_ext/1360937237/uart.o.d ${OBJECTDIR}/_ext/1360937237/audio.o.d ${OBJECTDIR}/_ext/1360937237/gfx.o.d ${OBJECTDIR}/_ext/1360937237/program.o.d ${OBJECTDIR}/_ext/1360937237/io.o.d ${OBJECTDIR}/_ext/1360937237/basic_external_functions.o.d ${OBJECTDIR}/_ext/1360937237/main.o.d ${OBJECTDIR}/_ext/1360937237/editor.o.d ${OBJECTDIR}/_ext/1360937237/parser.o.d ${OBJECTDIR}/_ext/1360937237/interpreter.o.d ${OBJECTDIR}/_ext/1360937237/demo.o.d ${OBJECTDIR}/_ext/1360937237/variable.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/1360937237/gpu.o ${OBJECTDIR}/_ext/1360937237/uart.o ${OBJECTDIR}/_ext/1360937237/audio.o ${OBJECTDIR}/_ext/1360937237/gfx.o ${OBJECTDIR}/_ext/1360937237/program.o ${OBJECTDIR}/_ext/1360937237/io.o ${OBJECTDIR}/_ext/1360937237/basic_external_functions.o ${OBJECTDIR}/_ext/1360937237/main.o ${OBJECTDIR}/_ext/1360937237/editor.o ${OBJECTDIR}/_ext/1360937237/parser.o ${OBJECTDIR}/_ext/1360937237/interpreter.o ${OBJECTDIR}/_ext/1360937237/demo.o ${OBJECTDIR}/_ext/1360937237/variable.o

# Source Files
SOURCEFILES=../src/gpu.c ../src/uart.c ../src/audio.c ../src/gfx.c ../src/program.c ../src/io.c ../src/basic_external_functions.c ../src/main.c ../src/editor.c ../src/parser.c ../src/interpreter.c ../src/demo.c ../src/variable.c



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
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/l1demo.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=24FJ256DA206
MP_LINKER_FILE_OPTION=,--script=p24FJ256DA206.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1360937237/gpu.o: ../src/gpu.c  .generated_files/flags/default/fd1036d9b355eb74399c03f12cba81f15c4e2920 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/gpu.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/gpu.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/gpu.c  -o ${OBJECTDIR}/_ext/1360937237/gpu.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/gpu.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"../inc" -mlarge-code -mlarge-data -O0 -msmart-io=1 -Wall -msfr-warn=off   -mlarge-arrays 
	
${OBJECTDIR}/_ext/1360937237/uart.o: ../src/uart.c  .generated_files/flags/default/95e3e0e37a7899bb09598c96f5536725a490c9c0 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/uart.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/uart.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/uart.c  -o ${OBJECTDIR}/_ext/1360937237/uart.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/uart.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"../inc" -mlarge-code -mlarge-data -O0 -msmart-io=1 -Wall -msfr-warn=off   -mlarge-arrays 
	
${OBJECTDIR}/_ext/1360937237/audio.o: ../src/audio.c  .generated_files/flags/default/cd22d96fc1d666547fad4c4b1f447f06208bd6fa .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/audio.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/audio.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/audio.c  -o ${OBJECTDIR}/_ext/1360937237/audio.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/audio.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"../inc" -mlarge-code -mlarge-data -O0 -msmart-io=1 -Wall -msfr-warn=off   -mlarge-arrays 
	
${OBJECTDIR}/_ext/1360937237/gfx.o: ../src/gfx.c  .generated_files/flags/default/91bb3bcfe9c78ae5c832142dbc9ebd3e63c88715 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/gfx.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/gfx.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/gfx.c  -o ${OBJECTDIR}/_ext/1360937237/gfx.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/gfx.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"../inc" -mlarge-code -mlarge-data -O0 -msmart-io=1 -Wall -msfr-warn=off   -mlarge-arrays 
	
${OBJECTDIR}/_ext/1360937237/program.o: ../src/program.c  .generated_files/flags/default/e0e6a82229ab90f4a75b45014bc58b82032b4abd .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/program.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/program.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/program.c  -o ${OBJECTDIR}/_ext/1360937237/program.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/program.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"../inc" -mlarge-code -mlarge-data -O0 -msmart-io=1 -Wall -msfr-warn=off   -mlarge-arrays 
	
${OBJECTDIR}/_ext/1360937237/io.o: ../src/io.c  .generated_files/flags/default/f5b23cc24c9ea423f7060cb63a09fad264de5037 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/io.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/io.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/io.c  -o ${OBJECTDIR}/_ext/1360937237/io.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/io.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"../inc" -mlarge-code -mlarge-data -O0 -msmart-io=1 -Wall -msfr-warn=off   -mlarge-arrays 
	
${OBJECTDIR}/_ext/1360937237/basic_external_functions.o: ../src/basic_external_functions.c  .generated_files/flags/default/d6745e32eb49179e459e513811992e2eab3197ce .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/basic_external_functions.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/basic_external_functions.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/basic_external_functions.c  -o ${OBJECTDIR}/_ext/1360937237/basic_external_functions.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/basic_external_functions.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"../inc" -mlarge-code -mlarge-data -O0 -msmart-io=1 -Wall -msfr-warn=off   -mlarge-arrays 
	
${OBJECTDIR}/_ext/1360937237/main.o: ../src/main.c  .generated_files/flags/default/56fc34b4a33bd5d74e9717e72ae8dfe2291bd490 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/main.c  -o ${OBJECTDIR}/_ext/1360937237/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/main.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"../inc" -mlarge-code -mlarge-data -O0 -msmart-io=1 -Wall -msfr-warn=off   -mlarge-arrays 
	
${OBJECTDIR}/_ext/1360937237/editor.o: ../src/editor.c  .generated_files/flags/default/2e8485bfacba2175b3f144df12c3ec6f8a4ff802 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/editor.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/editor.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/editor.c  -o ${OBJECTDIR}/_ext/1360937237/editor.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/editor.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"../inc" -mlarge-code -mlarge-data -O0 -msmart-io=1 -Wall -msfr-warn=off   -mlarge-arrays 
	
${OBJECTDIR}/_ext/1360937237/parser.o: ../src/parser.c  .generated_files/flags/default/5c90406db7869cfcccf149c87956aec06a014d99 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/parser.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/parser.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/parser.c  -o ${OBJECTDIR}/_ext/1360937237/parser.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/parser.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"../inc" -mlarge-code -mlarge-data -O0 -msmart-io=1 -Wall -msfr-warn=off   -mlarge-arrays 
	
${OBJECTDIR}/_ext/1360937237/interpreter.o: ../src/interpreter.c  .generated_files/flags/default/74beb1d94d44cc40e0604de64350900197001537 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/interpreter.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/interpreter.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/interpreter.c  -o ${OBJECTDIR}/_ext/1360937237/interpreter.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/interpreter.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"../inc" -mlarge-code -mlarge-data -O0 -msmart-io=1 -Wall -msfr-warn=off   -mlarge-arrays 
	
${OBJECTDIR}/_ext/1360937237/demo.o: ../src/demo.c  .generated_files/flags/default/e2228c38eeb7941d2733dd607a428631addb9aa5 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/demo.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/demo.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/demo.c  -o ${OBJECTDIR}/_ext/1360937237/demo.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/demo.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"../inc" -mlarge-code -mlarge-data -O0 -msmart-io=1 -Wall -msfr-warn=off   -mlarge-arrays 
	
${OBJECTDIR}/_ext/1360937237/variable.o: ../src/variable.c  .generated_files/flags/default/13ebd3e3b2b42fc8c14f62a4cfe8180ff8b53ebf .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/variable.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/variable.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/variable.c  -o ${OBJECTDIR}/_ext/1360937237/variable.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/variable.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"../inc" -mlarge-code -mlarge-data -O0 -msmart-io=1 -Wall -msfr-warn=off   -mlarge-arrays 
	
else
${OBJECTDIR}/_ext/1360937237/gpu.o: ../src/gpu.c  .generated_files/flags/default/1ba9f5a015e15f5f83a859b074438e0b85d93ba .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/gpu.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/gpu.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/gpu.c  -o ${OBJECTDIR}/_ext/1360937237/gpu.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/gpu.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"../inc" -mlarge-code -mlarge-data -O0 -msmart-io=1 -Wall -msfr-warn=off   -mlarge-arrays 
	
${OBJECTDIR}/_ext/1360937237/uart.o: ../src/uart.c  .generated_files/flags/default/ced290fef9ee1866ab8ffbd59ccfce7ff1811009 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/uart.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/uart.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/uart.c  -o ${OBJECTDIR}/_ext/1360937237/uart.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/uart.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"../inc" -mlarge-code -mlarge-data -O0 -msmart-io=1 -Wall -msfr-warn=off   -mlarge-arrays 
	
${OBJECTDIR}/_ext/1360937237/audio.o: ../src/audio.c  .generated_files/flags/default/6266272e9a1299d2c2ae814ef35b70a287ceb92d .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/audio.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/audio.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/audio.c  -o ${OBJECTDIR}/_ext/1360937237/audio.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/audio.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"../inc" -mlarge-code -mlarge-data -O0 -msmart-io=1 -Wall -msfr-warn=off   -mlarge-arrays 
	
${OBJECTDIR}/_ext/1360937237/gfx.o: ../src/gfx.c  .generated_files/flags/default/d839219d417baa29e2819ed48c3a582821735509 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/gfx.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/gfx.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/gfx.c  -o ${OBJECTDIR}/_ext/1360937237/gfx.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/gfx.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"../inc" -mlarge-code -mlarge-data -O0 -msmart-io=1 -Wall -msfr-warn=off   -mlarge-arrays 
	
${OBJECTDIR}/_ext/1360937237/program.o: ../src/program.c  .generated_files/flags/default/f299f8a35a077f9a341bf7b29406acfcf7a3939b .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/program.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/program.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/program.c  -o ${OBJECTDIR}/_ext/1360937237/program.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/program.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"../inc" -mlarge-code -mlarge-data -O0 -msmart-io=1 -Wall -msfr-warn=off   -mlarge-arrays 
	
${OBJECTDIR}/_ext/1360937237/io.o: ../src/io.c  .generated_files/flags/default/780cc5b63454d634febc2ac1d4287d393cacd889 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/io.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/io.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/io.c  -o ${OBJECTDIR}/_ext/1360937237/io.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/io.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"../inc" -mlarge-code -mlarge-data -O0 -msmart-io=1 -Wall -msfr-warn=off   -mlarge-arrays 
	
${OBJECTDIR}/_ext/1360937237/basic_external_functions.o: ../src/basic_external_functions.c  .generated_files/flags/default/3ad184893e1194766cc9f318a64be54b8b69eeab .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/basic_external_functions.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/basic_external_functions.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/basic_external_functions.c  -o ${OBJECTDIR}/_ext/1360937237/basic_external_functions.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/basic_external_functions.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"../inc" -mlarge-code -mlarge-data -O0 -msmart-io=1 -Wall -msfr-warn=off   -mlarge-arrays 
	
${OBJECTDIR}/_ext/1360937237/main.o: ../src/main.c  .generated_files/flags/default/841ff1a6707b1834c87f9a6d242bf196b140033c .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/main.c  -o ${OBJECTDIR}/_ext/1360937237/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/main.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"../inc" -mlarge-code -mlarge-data -O0 -msmart-io=1 -Wall -msfr-warn=off   -mlarge-arrays 
	
${OBJECTDIR}/_ext/1360937237/editor.o: ../src/editor.c  .generated_files/flags/default/1add4dbb2a9e56ccb11303ccb478aacd29e1074b .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/editor.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/editor.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/editor.c  -o ${OBJECTDIR}/_ext/1360937237/editor.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/editor.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"../inc" -mlarge-code -mlarge-data -O0 -msmart-io=1 -Wall -msfr-warn=off   -mlarge-arrays 
	
${OBJECTDIR}/_ext/1360937237/parser.o: ../src/parser.c  .generated_files/flags/default/c5282d64aa81f0a94b6b987c4309e64c27290ce5 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/parser.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/parser.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/parser.c  -o ${OBJECTDIR}/_ext/1360937237/parser.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/parser.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"../inc" -mlarge-code -mlarge-data -O0 -msmart-io=1 -Wall -msfr-warn=off   -mlarge-arrays 
	
${OBJECTDIR}/_ext/1360937237/interpreter.o: ../src/interpreter.c  .generated_files/flags/default/ede71641a1835a1def79d950b143d795a6a4d0be .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/interpreter.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/interpreter.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/interpreter.c  -o ${OBJECTDIR}/_ext/1360937237/interpreter.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/interpreter.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"../inc" -mlarge-code -mlarge-data -O0 -msmart-io=1 -Wall -msfr-warn=off   -mlarge-arrays 
	
${OBJECTDIR}/_ext/1360937237/demo.o: ../src/demo.c  .generated_files/flags/default/b6e48560d5d152a0804c377c881c40c90599846a .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/demo.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/demo.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/demo.c  -o ${OBJECTDIR}/_ext/1360937237/demo.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/demo.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"../inc" -mlarge-code -mlarge-data -O0 -msmart-io=1 -Wall -msfr-warn=off   -mlarge-arrays 
	
${OBJECTDIR}/_ext/1360937237/variable.o: ../src/variable.c  .generated_files/flags/default/ff55a8f1aa1fac57c73ad78005273d26e91d99ca .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/variable.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/variable.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/variable.c  -o ${OBJECTDIR}/_ext/1360937237/variable.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/variable.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"../inc" -mlarge-code -mlarge-data -O0 -msmart-io=1 -Wall -msfr-warn=off   -mlarge-arrays 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/l1demo.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/l1demo.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG=__DEBUG   -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"../inc"  -mreserve=data@0x800:0x81B -mreserve=data@0x81C:0x81D -mreserve=data@0x81E:0x81F -mreserve=data@0x820:0x821 -mreserve=data@0x822:0x823 -mreserve=data@0x824:0x827 -mreserve=data@0x82A:0x84F   -Wl,--local-stack,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D__DEBUG=__DEBUG,,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,${DISTDIR}/memoryfile.xml$(MP_EXTRA_LD_POST)  
	
else
${DISTDIR}/l1demo.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/l1demo.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"../inc" -Wl,--local-stack,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,${DISTDIR}/memoryfile.xml$(MP_EXTRA_LD_POST)  
	${MP_CC_DIR}/xc16-bin2hex ${DISTDIR}/l1demo.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf   
	
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
