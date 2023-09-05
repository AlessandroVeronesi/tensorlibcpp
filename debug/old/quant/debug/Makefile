############
## VARS
############

TOPDIR    := $(shell pwd)/..

############
## DIRS
############

DEBUGDIR := ${TOPDIR}/debug
OUTDIR := ${TOPDIR}/debug

############
## SRCS
############

SRCS := \
  ${DEBUGDIR}/main.cpp

############
## INCS
############

INCDIRS := \
  -I${TOPDIR} \
  -I${TOPDIR}/.. \
  -I${DEBUGDIR} \

############
## C++
############

LFLAGS := \
  -lm

# C Settings
EXTRAFLAGS ?=
CFLAGS := -g -fPIC -Wall -std=c++11

# Target
DEBUG_TARGET ?= debug.x

############
## CMDS
############

CC := g++
QUIET := @
RM := rm
CHMOD := chmod
ECHO := echo

############
## TARGETS
############

.PHONY: debug clean 

debug:
	${CC} ${CFLAGS} ${DEBUG_FLAGS} ${LFLAGS} ${INCDIRS} ${SRCS} -o ${DEBUG_TARGET}
	${QUIET}${CHMOD} +x ${DEBUG_TARGET}

clean:
	${QUIET}${RM} -f *.o *.log *.out *.x *.so



