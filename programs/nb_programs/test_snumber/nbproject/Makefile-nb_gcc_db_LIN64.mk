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
CND_PLATFORM=MinGW-Windows
CND_DLIB_EXT=dll
CND_CONF=nb_gcc_db_LIN64
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/1103842391/main.o \
	${OBJECTDIR}/_ext/1103842391/rsa_util.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-L../../lib/boost/${CND_CONF} -lboost_date_time -lboost_filesystem -lboost_program_options -lboost_random -lboost_regex -lboost_serialization -lboost_signals -lboost_system -lboost_thread -lboost_chrono -lboost_wserialization -lrt

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ../../../bin/${CND_CONF}/test_snumber.exe

../../../bin/${CND_CONF}/test_snumber.exe: ${OBJECTFILES}
	${MKDIR} -p ../../../bin/${CND_CONF}
	${LINK.cc} -o ../../../bin/${CND_CONF}/test_snumber ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/_ext/1103842391/main.o: ../../../include_programs/test_snumber/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1103842391
	${RM} $@.d
	$(COMPILE.cc) -g -I../../../include -I${BOOST_DIR} -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1103842391/main.o ../../../include_programs/test_snumber/main.cpp

${OBJECTDIR}/_ext/1103842391/rsa_util.o: ../../../include_programs/test_snumber/rsa_util.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1103842391
	${RM} $@.d
	$(COMPILE.cc) -g -I../../../include -I${BOOST_DIR} -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1103842391/rsa_util.o ../../../include_programs/test_snumber/rsa_util.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ../../../bin/${CND_CONF}/test_snumber.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc