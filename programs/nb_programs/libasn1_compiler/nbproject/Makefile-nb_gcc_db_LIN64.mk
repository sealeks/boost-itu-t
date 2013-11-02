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
CND_PLATFORM=GNU-Linux-x86
CND_DLIB_EXT=so
CND_CONF=nb_gcc_db_LIN64
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/787997029/assignmentCl.o \
	${OBJECTDIR}/_ext/787997029/assignmentO.o \
	${OBJECTDIR}/_ext/787997029/assignmentOS.o \
	${OBJECTDIR}/_ext/787997029/assignmentT.o \
	${OBJECTDIR}/_ext/787997029/assignmentV.o \
	${OBJECTDIR}/_ext/787997029/assignmentVS.o \
	${OBJECTDIR}/_ext/787997029/debug_cout.o \
	${OBJECTDIR}/_ext/787997029/modules.o \
	${OBJECTDIR}/_ext/787997029/parser.o \
	${OBJECTDIR}/_ext/787997029/sem_assignment.o \
	${OBJECTDIR}/_ext/787997029/sem_classassignment.o \
	${OBJECTDIR}/_ext/787997029/sem_objectassignment.o \
	${OBJECTDIR}/_ext/787997029/sem_objectsetassignment.o \
	${OBJECTDIR}/_ext/787997029/sem_typeassignment.o \
	${OBJECTDIR}/_ext/787997029/sem_valueassignment.o \
	${OBJECTDIR}/_ext/787997029/sem_valuesetassignment.o \
	${OBJECTDIR}/_ext/787997029/semantics.o \
	${OBJECTDIR}/_ext/787997029/setters.o \
	${OBJECTDIR}/_ext/787997029/x680.o


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
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ../../../lib/${CND_CONF}/libasn1_compiler.a

../../../lib/${CND_CONF}/libasn1_compiler.a: ${OBJECTFILES}
	${MKDIR} -p ../../../lib/${CND_CONF}
	${RM} ../../../lib/${CND_CONF}/libasn1_compiler.a
	${AR} -rv ../../../lib/${CND_CONF}/libasn1_compiler.a ${OBJECTFILES} 
	$(RANLIB) ../../../lib/${CND_CONF}/libasn1_compiler.a

${OBJECTDIR}/_ext/787997029/assignmentCl.o: ../../../include/boost/itu/x68X/assignmentCl.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/787997029
	${RM} $@.d
	$(COMPILE.cc) -g -DDEBUG -DITUX200_DEBUG -I../../../include -I${BOOST_DIR} -fno-strict-aliasing -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/787997029/assignmentCl.o ../../../include/boost/itu/x68X/assignmentCl.cpp

${OBJECTDIR}/_ext/787997029/assignmentO.o: ../../../include/boost/itu/x68X/assignmentO.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/787997029
	${RM} $@.d
	$(COMPILE.cc) -g -DDEBUG -DITUX200_DEBUG -I../../../include -I${BOOST_DIR} -fno-strict-aliasing -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/787997029/assignmentO.o ../../../include/boost/itu/x68X/assignmentO.cpp

${OBJECTDIR}/_ext/787997029/assignmentOS.o: ../../../include/boost/itu/x68X/assignmentOS.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/787997029
	${RM} $@.d
	$(COMPILE.cc) -g -DDEBUG -DITUX200_DEBUG -I../../../include -I${BOOST_DIR} -fno-strict-aliasing -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/787997029/assignmentOS.o ../../../include/boost/itu/x68X/assignmentOS.cpp

${OBJECTDIR}/_ext/787997029/assignmentT.o: ../../../include/boost/itu/x68X/assignmentT.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/787997029
	${RM} $@.d
	$(COMPILE.cc) -g -DDEBUG -DITUX200_DEBUG -I../../../include -I${BOOST_DIR} -fno-strict-aliasing -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/787997029/assignmentT.o ../../../include/boost/itu/x68X/assignmentT.cpp

${OBJECTDIR}/_ext/787997029/assignmentV.o: ../../../include/boost/itu/x68X/assignmentV.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/787997029
	${RM} $@.d
	$(COMPILE.cc) -g -DDEBUG -DITUX200_DEBUG -I../../../include -I${BOOST_DIR} -fno-strict-aliasing -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/787997029/assignmentV.o ../../../include/boost/itu/x68X/assignmentV.cpp

${OBJECTDIR}/_ext/787997029/assignmentVS.o: ../../../include/boost/itu/x68X/assignmentVS.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/787997029
	${RM} $@.d
	$(COMPILE.cc) -g -DDEBUG -DITUX200_DEBUG -I../../../include -I${BOOST_DIR} -fno-strict-aliasing -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/787997029/assignmentVS.o ../../../include/boost/itu/x68X/assignmentVS.cpp

${OBJECTDIR}/_ext/787997029/debug_cout.o: ../../../include/boost/itu/x68X/debug_cout.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/787997029
	${RM} $@.d
	$(COMPILE.cc) -g -DDEBUG -DITUX200_DEBUG -I../../../include -I${BOOST_DIR} -fno-strict-aliasing -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/787997029/debug_cout.o ../../../include/boost/itu/x68X/debug_cout.cpp

${OBJECTDIR}/_ext/787997029/modules.o: ../../../include/boost/itu/x68X/modules.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/787997029
	${RM} $@.d
	$(COMPILE.cc) -g -DDEBUG -DITUX200_DEBUG -I../../../include -I${BOOST_DIR} -fno-strict-aliasing -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/787997029/modules.o ../../../include/boost/itu/x68X/modules.cpp

${OBJECTDIR}/_ext/787997029/parser.o: ../../../include/boost/itu/x68X/parser.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/787997029
	${RM} $@.d
	$(COMPILE.cc) -g -DDEBUG -DITUX200_DEBUG -I../../../include -I${BOOST_DIR} -fno-strict-aliasing -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/787997029/parser.o ../../../include/boost/itu/x68X/parser.cpp

${OBJECTDIR}/_ext/787997029/sem_assignment.o: ../../../include/boost/itu/x68X/sem_assignment.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/787997029
	${RM} $@.d
	$(COMPILE.cc) -g -DDEBUG -DITUX200_DEBUG -I../../../include -I${BOOST_DIR} -fno-strict-aliasing -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/787997029/sem_assignment.o ../../../include/boost/itu/x68X/sem_assignment.cpp

${OBJECTDIR}/_ext/787997029/sem_classassignment.o: ../../../include/boost/itu/x68X/sem_classassignment.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/787997029
	${RM} $@.d
	$(COMPILE.cc) -g -DDEBUG -DITUX200_DEBUG -I../../../include -I${BOOST_DIR} -fno-strict-aliasing -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/787997029/sem_classassignment.o ../../../include/boost/itu/x68X/sem_classassignment.cpp

${OBJECTDIR}/_ext/787997029/sem_objectassignment.o: ../../../include/boost/itu/x68X/sem_objectassignment.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/787997029
	${RM} $@.d
	$(COMPILE.cc) -g -DDEBUG -DITUX200_DEBUG -I../../../include -I${BOOST_DIR} -fno-strict-aliasing -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/787997029/sem_objectassignment.o ../../../include/boost/itu/x68X/sem_objectassignment.cpp

${OBJECTDIR}/_ext/787997029/sem_objectsetassignment.o: ../../../include/boost/itu/x68X/sem_objectsetassignment.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/787997029
	${RM} $@.d
	$(COMPILE.cc) -g -DDEBUG -DITUX200_DEBUG -I../../../include -I${BOOST_DIR} -fno-strict-aliasing -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/787997029/sem_objectsetassignment.o ../../../include/boost/itu/x68X/sem_objectsetassignment.cpp

${OBJECTDIR}/_ext/787997029/sem_typeassignment.o: ../../../include/boost/itu/x68X/sem_typeassignment.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/787997029
	${RM} $@.d
	$(COMPILE.cc) -g -DDEBUG -DITUX200_DEBUG -I../../../include -I${BOOST_DIR} -fno-strict-aliasing -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/787997029/sem_typeassignment.o ../../../include/boost/itu/x68X/sem_typeassignment.cpp

${OBJECTDIR}/_ext/787997029/sem_valueassignment.o: ../../../include/boost/itu/x68X/sem_valueassignment.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/787997029
	${RM} $@.d
	$(COMPILE.cc) -g -DDEBUG -DITUX200_DEBUG -I../../../include -I${BOOST_DIR} -fno-strict-aliasing -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/787997029/sem_valueassignment.o ../../../include/boost/itu/x68X/sem_valueassignment.cpp

${OBJECTDIR}/_ext/787997029/sem_valuesetassignment.o: ../../../include/boost/itu/x68X/sem_valuesetassignment.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/787997029
	${RM} $@.d
	$(COMPILE.cc) -g -DDEBUG -DITUX200_DEBUG -I../../../include -I${BOOST_DIR} -fno-strict-aliasing -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/787997029/sem_valuesetassignment.o ../../../include/boost/itu/x68X/sem_valuesetassignment.cpp

${OBJECTDIR}/_ext/787997029/semantics.o: ../../../include/boost/itu/x68X/semantics.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/787997029
	${RM} $@.d
	$(COMPILE.cc) -g -DDEBUG -DITUX200_DEBUG -I../../../include -I${BOOST_DIR} -fno-strict-aliasing -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/787997029/semantics.o ../../../include/boost/itu/x68X/semantics.cpp

${OBJECTDIR}/_ext/787997029/setters.o: ../../../include/boost/itu/x68X/setters.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/787997029
	${RM} $@.d
	$(COMPILE.cc) -g -DDEBUG -DITUX200_DEBUG -I../../../include -I${BOOST_DIR} -fno-strict-aliasing -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/787997029/setters.o ../../../include/boost/itu/x68X/setters.cpp

${OBJECTDIR}/_ext/787997029/x680.o: ../../../include/boost/itu/x68X/x680.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/787997029
	${RM} $@.d
	$(COMPILE.cc) -g -DDEBUG -DITUX200_DEBUG -I../../../include -I${BOOST_DIR} -fno-strict-aliasing -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/787997029/x680.o ../../../include/boost/itu/x68X/x680.cpp

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
