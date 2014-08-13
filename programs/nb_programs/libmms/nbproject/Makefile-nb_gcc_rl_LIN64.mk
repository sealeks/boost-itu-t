#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Windows
CND_DLIB_EXT=dll
CND_CONF=nb_gcc_rl_LIN64
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/467100861/ISO-9506-MMS-1.o \
	${OBJECTDIR}/_ext/467100861/ISO-9506-MMS-1A.o \
	${OBJECTDIR}/_ext/467100861/MMS-Environment-1.o \
	${OBJECTDIR}/_ext/467100861/MMS-Object-Module-1.o \
	${OBJECTDIR}/_ext/467100861/MMS-SCI-Module-1.o \
	${OBJECTDIR}/_ext/467100861/mmssocket.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-m64 -fno-strict-aliasing
CXXFLAGS=-m64 -fno-strict-aliasing

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ../../../lib/${CND_CONF}/libmms.a

../../../lib/${CND_CONF}/libmms.a: ${OBJECTFILES}
	${MKDIR} -p ../../../lib/${CND_CONF}
	${RM} ../../../lib/${CND_CONF}/libmms.a
	${AR} -rv ../../../lib/${CND_CONF}/libmms.a ${OBJECTFILES} 
	$(RANLIB) ../../../lib/${CND_CONF}/libmms.a

${OBJECTDIR}/_ext/467100861/ISO-9506-MMS-1.o: ../../../include/mms/ISO-9506-MMS-1.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/467100861
	${RM} $@.d
	$(COMPILE.cc) -O2 -Wall -I../../../include -I${BOOST_DIR} -fno-strict-aliasing -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/467100861/ISO-9506-MMS-1.o ../../../include/mms/ISO-9506-MMS-1.cpp

${OBJECTDIR}/_ext/467100861/ISO-9506-MMS-1A.o: ../../../include/mms/ISO-9506-MMS-1A.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/467100861
	${RM} $@.d
	$(COMPILE.cc) -O2 -Wall -I../../../include -I${BOOST_DIR} -fno-strict-aliasing -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/467100861/ISO-9506-MMS-1A.o ../../../include/mms/ISO-9506-MMS-1A.cpp

${OBJECTDIR}/_ext/467100861/MMS-Environment-1.o: ../../../include/mms/MMS-Environment-1.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/467100861
	${RM} $@.d
	$(COMPILE.cc) -O2 -Wall -I../../../include -I${BOOST_DIR} -fno-strict-aliasing -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/467100861/MMS-Environment-1.o ../../../include/mms/MMS-Environment-1.cpp

${OBJECTDIR}/_ext/467100861/MMS-Object-Module-1.o: ../../../include/mms/MMS-Object-Module-1.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/467100861
	${RM} $@.d
	$(COMPILE.cc) -O2 -Wall -I../../../include -I${BOOST_DIR} -fno-strict-aliasing -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/467100861/MMS-Object-Module-1.o ../../../include/mms/MMS-Object-Module-1.cpp

${OBJECTDIR}/_ext/467100861/MMS-SCI-Module-1.o: ../../../include/mms/MMS-SCI-Module-1.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/467100861
	${RM} $@.d
	$(COMPILE.cc) -O2 -Wall -I../../../include -I${BOOST_DIR} -fno-strict-aliasing -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/467100861/MMS-SCI-Module-1.o ../../../include/mms/MMS-SCI-Module-1.cpp

${OBJECTDIR}/_ext/467100861/mmssocket.o: ../../../include/mms/mmssocket.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/467100861
	${RM} $@.d
	$(COMPILE.cc) -O2 -Wall -I../../../include -I${BOOST_DIR} -fno-strict-aliasing -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/467100861/mmssocket.o ../../../include/mms/mmssocket.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ../../../lib/${CND_CONF}/libmms.a

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
