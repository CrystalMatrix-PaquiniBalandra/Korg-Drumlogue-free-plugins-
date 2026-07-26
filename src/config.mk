##############################################################################
# Configuration for Makefile
#

.DEFAULT_GOAL := all

PROJECT := EQVU
PROJECT_TYPE := delfx
PROJECT_DEV_ID := 0x0U
PROJECT_UNIT_ID := 0x0U
MAX_UNIT_SIZE := 33554432
SDRAM_ALLOC_THRESHOLD := 256

ifeq ($(strip $(SDRAM_SIZE)),)
SDRAM_SIZE = 0
endif
ifeq ($(shell [ $(SDRAM_SIZE) -gt 33554432 ] && echo yes || echo no),yes)
$(error Required SDRAM size($(SDRAM_SIZE)bytes) exceeds 33554432bytes)
endif

##############################################################################
# Sources
#

# C sources 
UCSRC = header.c HvMessage.c HvUtils.c HvControlCast.c HvControlVar.c HvControlExpr.c HvSignalLine.c HvControlIf.c HvLightPipe.c HvControlBinop.c HvMessageQueue.c HvTable.c HvSignalBiquad.c HvSignalVar.c HvMessagePool.c HvControlSystem.c HvControlUnop.c

UCSRC += _unit_base.c

# C++ sources 
UCXXSRC = logue_heavy.cpp HvHeavy.cpp Heavy_EQVU.cpp HeavyContext.cpp

# List ASM source files here
UASMSRC = 

UASMXSRC = 

##############################################################################
# Include Paths
#

UINCDIR  = $(PLATFORMDIR)/../common

##############################################################################
# Library Paths
#

ULIBDIR = 

##############################################################################
# Libraries
#

ULIBS  = -lm
ULIBS  += -lstdc++
ULIBS  += -Wl,--gc-sections

##############################################################################
# Macros
#

UDEFS = -DNDEBUG -fvisibility=hidden

UDEFS += -DPROJECT_DEV_ID=$(PROJECT_DEV_ID) -DPROJECT_UNIT_ID=$(PROJECT_UNIT_ID)

# Assume Unix-like to suppress warning messages
UDEFS += -U_WIN32 -U_WIN64 -U_MSC_VER -D__unix

# Try disabling this option when the results are inaccurate.
# UDEFS += -DLOGUE_FAST_MATH

# Enable this to reduce the processing load
# UDEFS += -DRENDER_HALF
