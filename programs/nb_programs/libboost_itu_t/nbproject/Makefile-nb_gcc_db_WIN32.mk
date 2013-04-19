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
	${OBJECTDIR}/_ext/787372092/asnbase.o \
	${OBJECTDIR}/_ext/787372092/utf8.o \
	${OBJECTDIR}/_ext/1359548930/base_coder.o \
	${OBJECTDIR}/_ext/823522712/error.o \
	${OBJECTDIR}/_ext/689007315/rfc1006.o \
	${OBJECTDIR}/_ext/1342771574/temlate.o \
	${OBJECTDIR}/_ext/1342771574/utils.o \
	${OBJECTDIR}/_ext/787992999/selectors.o \
	${OBJECTDIR}/_ext/787992999/x224.o \
	${OBJECTDIR}/_ext/787992999/x225.o \
	${OBJECTDIR}/_ext/787992999/x226.o \
	${OBJECTDIR}/_ext/787992999/x227.o \
	${OBJECTDIR}/_ext/787997060/x690.o


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
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ../../../lib/${CND_CONF}/libboost_itu_t.a

../../../lib/${CND_CONF}/libboost_itu_t.a: ${OBJECTFILES}
	${MKDIR} -p ../../../lib/${CND_CONF}
	${RM} ../../../lib/${CND_CONF}/libboost_itu_t.a
	${AR} -rv ../../../lib/${CND_CONF}/libboost_itu_t.a ${OBJECTFILES} 
	$(RANLIB) ../../../lib/${CND_CONF}/libboost_itu_t.a

${OBJECTDIR}/_ext/787372092/asnbase.o: ../../../include/boost/itu/asn1/asnbase.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/787372092
	${RM} $@.d
	$(COMPILE.cc) -O2 -DDEBUG -DITUX200_DEBUG -I../../../include -I${BOOST_DIR} -mthreads -fno-strict-aliasing -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/787372092/asnbase.o ../../../include/boost/itu/asn1/asnbase.cpp

${OBJECTDIR}/_ext/787372092/utf8.o: ../../../include/boost/itu/asn1/utf8.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/787372092
	${RM} $@.d
	$(COMPILE.cc) -O2 -DDEBUG -DITUX200_DEBUG -I../../../include -I${BOOST_DIR} -mthreads -fno-strict-aliasing -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/787372092/utf8.o ../../../include/boost/itu/asn1/utf8.cpp

${OBJECTDIR}/_ext/1359548930/base_coder.o: ../../../include/boost/itu/coder/base_coder.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1359548930
	${RM} $@.d
	$(COMPILE.cc) -O2 -DDEBUG -DITUX200_DEBUG -I../../../include -I${BOOST_DIR} -mthreads -fno-strict-aliasing -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1359548930/base_coder.o ../../../include/boost/itu/coder/base_coder.cpp

${OBJECTDIR}/_ext/823522712/error.o: ../../../include/boost/itu/detail/error.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/823522712
	${RM} $@.d
	$(COMPILE.cc) -O2 -DDEBUG -DITUX200_DEBUG -I../../../include -I${BOOST_DIR} -mthreads -fno-strict-aliasing -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/823522712/error.o ../../../include/boost/itu/detail/error.cpp

${OBJECTDIR}/_ext/689007315/rfc1006.o: ../../../include/boost/itu/rfc1006/rfc1006.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/689007315
	${RM} $@.d
	$(COMPILE.cc) -O2 -DDEBUG -DITUX200_DEBUG -I../../../include -I${BOOST_DIR} -mthreads -fno-strict-aliasing -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/689007315/rfc1006.o ../../../include/boost/itu/rfc1006/rfc1006.cpp

${OBJECTDIR}/_ext/1342771574/temlate.o: ../../../include/boost/itu/utils/temlate.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1342771574
	${RM} $@.d
	$(COMPILE.cc) -O2 -DDEBUG -DITUX200_DEBUG -I../../../include -I${BOOST_DIR} -mthreads -fno-strict-aliasing -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1342771574/temlate.o ../../../include/boost/itu/utils/temlate.cpp

${OBJECTDIR}/_ext/1342771574/utils.o: ../../../include/boost/itu/utils/utils.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1342771574
	${RM} $@.d
	$(COMPILE.cc) -O2 -DDEBUG -DITUX200_DEBUG -I../../../include -I${BOOST_DIR} -mthreads -fno-strict-aliasing -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1342771574/utils.o ../../../include/boost/itu/utils/utils.cpp

${OBJECTDIR}/_ext/787992999/selectors.o: ../../../include/boost/itu/x22X/selectors.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/787992999
	${RM} $@.d
	$(COMPILE.cc) -O2 -DDEBUG -DITUX200_DEBUG -I../../../include -I${BOOST_DIR} -mthreads -fno-strict-aliasing -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/787992999/selectors.o ../../../include/boost/itu/x22X/selectors.cpp

${OBJECTDIR}/_ext/787992999/x224.o: ../../../include/boost/itu/x22X/x224.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/787992999
	${RM} $@.d
	$(COMPILE.cc) -O2 -DDEBUG -DITUX200_DEBUG -I../../../include -I${BOOST_DIR} -mthreads -fno-strict-aliasing -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/787992999/x224.o ../../../include/boost/itu/x22X/x224.cpp

${OBJECTDIR}/_ext/787992999/x225.o: ../../../include/boost/itu/x22X/x225.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/787992999
	${RM} $@.d
	$(COMPILE.cc) -O2 -DDEBUG -DITUX200_DEBUG -I../../../include -I${BOOST_DIR} -mthreads -fno-strict-aliasing -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/787992999/x225.o ../../../include/boost/itu/x22X/x225.cpp

${OBJECTDIR}/_ext/787992999/x226.o: ../../../include/boost/itu/x22X/x226.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/787992999
	${RM} $@.d
	$(COMPILE.cc) -O2 -DDEBUG -DITUX200_DEBUG -I../../../include -I${BOOST_DIR} -mthreads -fno-strict-aliasing -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/787992999/x226.o ../../../include/boost/itu/x22X/x226.cpp

${OBJECTDIR}/_ext/787992999/x227.o: ../../../include/boost/itu/x22X/x227.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/787992999
	${RM} $@.d
	$(COMPILE.cc) -O2 -DDEBUG -DITUX200_DEBUG -I../../../include -I${BOOST_DIR} -mthreads -fno-strict-aliasing -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/787992999/x227.o ../../../include/boost/itu/x22X/x227.cpp

${OBJECTDIR}/_ext/787997060/x690.o: ../../../include/boost/itu/x69X/x690.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/787997060
	${RM} $@.d
	$(COMPILE.cc) -O2 -DDEBUG -DITUX200_DEBUG -I../../../include -I${BOOST_DIR} -mthreads -fno-strict-aliasing -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/787997060/x690.o ../../../include/boost/itu/x69X/x690.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ../../../lib/${CND_CONF}/libboost_itu_t.a

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
