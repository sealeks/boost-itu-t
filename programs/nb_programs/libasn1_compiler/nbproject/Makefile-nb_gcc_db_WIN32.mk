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
CND_CONF=nb_gcc_db_WIN32
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/787997029/asn1module.o \
	${OBJECTDIR}/_ext/787997029/parser.o \
	${OBJECTDIR}/_ext/787997029/type.o \
	${OBJECTDIR}/_ext/787997029/x680.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-mthreads -fno-strict-aliasing
CXXFLAGS=-mthreads -fno-strict-aliasing

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ../../../lib/${CND_CONF}/libasn1_compiler.a

../../../lib/${CND_CONF}/libasn1_compiler.a: ${OBJECTFILES}
	${MKDIR} -p ../../../lib/${CND_CONF}
	${RM} ../../../lib/${CND_CONF}/libasn1_compiler.a
	${AR} -rv ../../../lib/${CND_CONF}/libasn1_compiler.a ${OBJECTFILES} 
	$(RANLIB) ../../../lib/${CND_CONF}/libasn1_compiler.a

${OBJECTDIR}/_ext/787997029/asn1module.o: ../../../include/boost/itu/x68X/asn1module.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/787997029
	${RM} $@.d
	$(COMPILE.cc) -O2 -D_WIN32_WINNT=0x0601 -DDEBUG -DITUX200_DEBUG -I../../../include -I${BOOST_DIR} -mthreads -fno-strict-aliasing -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/787997029/asn1module.o ../../../include/boost/itu/x68X/asn1module.cpp

${OBJECTDIR}/_ext/787997029/parser.o: ../../../include/boost/itu/x68X/parser.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/787997029
	${RM} $@.d
	$(COMPILE.cc) -O2 -D_WIN32_WINNT=0x0601 -DDEBUG -DITUX200_DEBUG -I../../../include -I${BOOST_DIR} -mthreads -fno-strict-aliasing -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/787997029/parser.o ../../../include/boost/itu/x68X/parser.cpp

${OBJECTDIR}/_ext/787997029/type.o: ../../../include/boost/itu/x68X/type.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/787997029
	${RM} $@.d
	$(COMPILE.cc) -O2 -D_WIN32_WINNT=0x0601 -DDEBUG -DITUX200_DEBUG -I../../../include -I${BOOST_DIR} -mthreads -fno-strict-aliasing -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/787997029/type.o ../../../include/boost/itu/x68X/type.cpp

${OBJECTDIR}/_ext/787997029/x680.o: ../../../include/boost/itu/x68X/x680.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/787997029
	${RM} $@.d
	$(COMPILE.cc) -O2 -D_WIN32_WINNT=0x0601 -DDEBUG -DITUX200_DEBUG -I../../../include -I${BOOST_DIR} -mthreads -fno-strict-aliasing -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/787997029/x680.o ../../../include/boost/itu/x68X/x680.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ../../../lib/${CND_CONF}/libasn1_compiler.a

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
