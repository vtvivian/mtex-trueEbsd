###########################################################################
## Makefile generated for component 'fDIC_xcf_mat'. 
## 
## Makefile     : fDIC_xcf_mat_rtw.mk
## Generated on : Fri Oct 17 12:27:18 2025
## Final product: ./fDIC_xcf_mat.a
## Product type : static-library
## 
###########################################################################

###########################################################################
## MACROS
###########################################################################

# Macro Descriptions:
# PRODUCT_NAME            Name of the system to build
# MAKEFILE                Name of this makefile
# MODELLIB                Static library target

PRODUCT_NAME              = fDIC_xcf_mat
MAKEFILE                  = fDIC_xcf_mat_rtw.mk
MATLAB_ROOT               = /usr/local/MATLAB/R2025a
MATLAB_BIN                = /usr/local/MATLAB/R2025a/bin
MATLAB_ARCH_BIN           = $(MATLAB_BIN)/glnxa64
START_DIR                 = /home/rock/Documents/Git-projects/mtex-trueEbsd/trueEbsd/funcsV0/codegen
TGT_FCN_LIB               = ISO_C
SOLVER_OBJ                = 
CLASSIC_INTERFACE         = 0
MODEL_HAS_DYNAMICALLY_LOADED_SFCNS = 
RELATIVE_PATH_TO_ANCHOR   = ../../..
C_STANDARD_OPTS           = -fwrapv
CPP_STANDARD_OPTS         = -fwrapv
MODELLIB                  = fDIC_xcf_mat.a

###########################################################################
## TOOLCHAIN SPECIFICATIONS
###########################################################################

# Toolchain Name:          GNU gcc/g++ | gmake (64-bit Linux)
# Supported Version(s):    
# ToolchainInfo Version:   2025a
# Specification Revision:  1.0
# 
#-------------------------------------------
# Macros assumed to be defined elsewhere
#-------------------------------------------

# C_STANDARD_OPTS
# CPP_STANDARD_OPTS

#-----------
# MACROS
#-----------

WARN_FLAGS         = -Wall -W -Wwrite-strings -Winline -Wstrict-prototypes -Wnested-externs -Wpointer-arith -Wcast-align -Wno-stringop-overflow
WARN_FLAGS_MAX     = $(WARN_FLAGS) -Wcast-qual -Wshadow
CPP_WARN_FLAGS     = -Wall -W -Wwrite-strings -Winline -Wpointer-arith -Wcast-align -Wno-stringop-overflow
CPP_WARN_FLAGS_MAX = $(CPP_WARN_FLAGS) -Wcast-qual -Wshadow

TOOLCHAIN_SRCS = 
TOOLCHAIN_INCS = 
TOOLCHAIN_LIBS = 

#------------------------
# BUILD TOOL COMMANDS
#------------------------

# C Compiler: GNU C Compiler
CC = gcc

# Linker: GNU Linker
LD = g++

# C++ Compiler: GNU C++ Compiler
CPP = g++

# C++ Linker: GNU C++ Linker
CPP_LD = g++

# Archiver: GNU Archiver
AR = ar

# MEX Tool: MEX Tool
MEX_PATH = $(MATLAB_ARCH_BIN)
MEX = "$(MEX_PATH)/mex"

# Download: Download
DOWNLOAD =

# Execute: Execute
EXECUTE = $(PRODUCT)

# Builder: GMAKE Utility
MAKE_PATH = %MATLAB%/bin/glnxa64
MAKE = "$(MAKE_PATH)/gmake"


#-------------------------
# Directives/Utilities
#-------------------------

CDEBUG              = -g
C_OUTPUT_FLAG       = -o
LDDEBUG             = -g
OUTPUT_FLAG         = -o
CPPDEBUG            = -g
CPP_OUTPUT_FLAG     = -o
CPPLDDEBUG          = -g
OUTPUT_FLAG         = -o
ARDEBUG             =
STATICLIB_OUTPUT_FLAG =
MEX_DEBUG           = -g
RM                  = @rm -f
ECHO                = @echo
MV                  = @mv
RUN                 =

#--------------------------------------
# "Faster Runs" Build Configuration
#--------------------------------------

ARFLAGS              = ruvs
CFLAGS               = -c $(C_STANDARD_OPTS) -fPIC \
                       -O3
CPPFLAGS             = -c $(CPP_STANDARD_OPTS) -fPIC \
                       -O3
CPP_LDFLAGS          =
CPP_SHAREDLIB_LDFLAGS  = -shared -Wl,--no-undefined
DOWNLOAD_FLAGS       =
EXECUTE_FLAGS        =
LDFLAGS              =
MEX_CPPFLAGS         =
MEX_CPPLDFLAGS       =
MEX_CFLAGS           =
MEX_LDFLAGS          =
MAKE_FLAGS           = -j $(MAX_MAKE_JOBS) -l $(MAX_MAKE_LOAD_AVG) -f $(MAKEFILE)
SHAREDLIB_LDFLAGS    = -shared -Wl,--no-undefined



###########################################################################
## OUTPUT INFO
###########################################################################

PRODUCT = ./fDIC_xcf_mat.a
PRODUCT_TYPE = "static-library"
BUILD_TYPE = "Static Library"

###########################################################################
## INCLUDE PATHS
###########################################################################

INCLUDES_BUILDINFO = -I$(START_DIR)/codegen/lib/fDIC_xcf_mat -I$(START_DIR) -I$(MATLAB_ROOT)/extern/include

INCLUDES = $(INCLUDES_BUILDINFO)

###########################################################################
## DEFINES
###########################################################################

DEFINES_CUSTOM = 
DEFINES_STANDARD = -DMODEL=fDIC_xcf_mat

DEFINES = $(DEFINES_CUSTOM) $(DEFINES_STANDARD)

###########################################################################
## SOURCE FILES
###########################################################################

SRCS = $(START_DIR)/codegen/lib/fDIC_xcf_mat/fDIC_xcf_mat_data.c $(START_DIR)/codegen/lib/fDIC_xcf_mat/rt_nonfinite.c $(START_DIR)/codegen/lib/fDIC_xcf_mat/rtGetNaN.c $(START_DIR)/codegen/lib/fDIC_xcf_mat/rtGetInf.c $(START_DIR)/codegen/lib/fDIC_xcf_mat/fDIC_xcf_mat_initialize.c $(START_DIR)/codegen/lib/fDIC_xcf_mat/fDIC_xcf_mat_terminate.c $(START_DIR)/codegen/lib/fDIC_xcf_mat/fDIC_xcf_mat.c $(START_DIR)/codegen/lib/fDIC_xcf_mat/blockedSummation.c $(START_DIR)/codegen/lib/fDIC_xcf_mat/std.c $(START_DIR)/codegen/lib/fDIC_xcf_mat/FFTImplementationCallback.c $(START_DIR)/codegen/lib/fDIC_xcf_mat/colon.c $(START_DIR)/codegen/lib/fDIC_xcf_mat/fReg.c $(START_DIR)/codegen/lib/fDIC_xcf_mat/ifft2.c $(START_DIR)/codegen/lib/fDIC_xcf_mat/minOrMax.c $(START_DIR)/codegen/lib/fDIC_xcf_mat/relop.c $(START_DIR)/codegen/lib/fDIC_xcf_mat/abs.c $(START_DIR)/codegen/lib/fDIC_xcf_mat/eml_fftshift.c $(START_DIR)/codegen/lib/fDIC_xcf_mat/ifftshift.c $(START_DIR)/codegen/lib/fDIC_xcf_mat/exp.c $(START_DIR)/codegen/lib/fDIC_xcf_mat/fDIC_xcf_mat_emxutil.c $(START_DIR)/codegen/lib/fDIC_xcf_mat/fDIC_xcf_mat_emxAPI.c $(START_DIR)/codegen/lib/fDIC_xcf_mat/fDIC_xcf_mat_rtwutil.c

ALL_SRCS = $(SRCS)

###########################################################################
## OBJECTS
###########################################################################

OBJS = fDIC_xcf_mat_data.o rt_nonfinite.o rtGetNaN.o rtGetInf.o fDIC_xcf_mat_initialize.o fDIC_xcf_mat_terminate.o fDIC_xcf_mat.o blockedSummation.o std.o FFTImplementationCallback.o colon.o fReg.o ifft2.o minOrMax.o relop.o abs.o eml_fftshift.o ifftshift.o exp.o fDIC_xcf_mat_emxutil.o fDIC_xcf_mat_emxAPI.o fDIC_xcf_mat_rtwutil.o

ALL_OBJS = $(OBJS)

###########################################################################
## PREBUILT OBJECT FILES
###########################################################################

PREBUILT_OBJS = 

###########################################################################
## LIBRARIES
###########################################################################

LIBS = 

###########################################################################
## SYSTEM LIBRARIES
###########################################################################

SYSTEM_LIBS = -L$(MATLAB_ROOT)/sys/os/glnxa64 -lm -liomp5

###########################################################################
## ADDITIONAL TOOLCHAIN FLAGS
###########################################################################

#---------------
# C Compiler
#---------------

CFLAGS_OPTS = -fopenmp
CFLAGS_TFL = -msse2 -fno-predictive-commoning
CFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CFLAGS += $(CFLAGS_OPTS) $(CFLAGS_TFL) $(CFLAGS_BASIC)

#-----------------
# C++ Compiler
#-----------------

CPPFLAGS_OPTS = -fopenmp
CPPFLAGS_TFL = -msse2 -fno-predictive-commoning
CPPFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CPPFLAGS += $(CPPFLAGS_OPTS) $(CPPFLAGS_TFL) $(CPPFLAGS_BASIC)

###########################################################################
## INLINED COMMANDS
###########################################################################

###########################################################################
## PHONY TARGETS
###########################################################################

.PHONY : all build clean info prebuild download execute


all : build
	@echo "### Successfully generated all binary outputs."


build : prebuild $(PRODUCT)


prebuild : 


download : $(PRODUCT)


execute : download


###########################################################################
## FINAL TARGET
###########################################################################

#---------------------------------
# Create a static library         
#---------------------------------

$(PRODUCT) : $(OBJS) $(PREBUILT_OBJS)
	@echo "### Creating static library "$(PRODUCT)" ..."
	$(AR) $(ARFLAGS)  $(PRODUCT) $(OBJS)
	@echo "### Created: $(PRODUCT)"


###########################################################################
## INTERMEDIATE TARGETS
###########################################################################

#---------------------
# SOURCE-TO-OBJECT
#---------------------

%.o : %.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : %.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : %.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : %.cp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : %.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : %.CPP
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : %.c++
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : %.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.cp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.CPP
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.c++
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/codegen/lib/fDIC_xcf_mat/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/codegen/lib/fDIC_xcf_mat/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/codegen/lib/fDIC_xcf_mat/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/codegen/lib/fDIC_xcf_mat/%.cp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/codegen/lib/fDIC_xcf_mat/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/codegen/lib/fDIC_xcf_mat/%.CPP
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/codegen/lib/fDIC_xcf_mat/%.c++
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/codegen/lib/fDIC_xcf_mat/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.cp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.CPP
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.c++
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


fDIC_xcf_mat_data.o : $(START_DIR)/codegen/lib/fDIC_xcf_mat/fDIC_xcf_mat_data.c
	$(CC) $(CFLAGS) -o "$@" "$<"


rt_nonfinite.o : $(START_DIR)/codegen/lib/fDIC_xcf_mat/rt_nonfinite.c
	$(CC) $(CFLAGS) -o "$@" "$<"


rtGetNaN.o : $(START_DIR)/codegen/lib/fDIC_xcf_mat/rtGetNaN.c
	$(CC) $(CFLAGS) -o "$@" "$<"


rtGetInf.o : $(START_DIR)/codegen/lib/fDIC_xcf_mat/rtGetInf.c
	$(CC) $(CFLAGS) -o "$@" "$<"


fDIC_xcf_mat_initialize.o : $(START_DIR)/codegen/lib/fDIC_xcf_mat/fDIC_xcf_mat_initialize.c
	$(CC) $(CFLAGS) -o "$@" "$<"


fDIC_xcf_mat_terminate.o : $(START_DIR)/codegen/lib/fDIC_xcf_mat/fDIC_xcf_mat_terminate.c
	$(CC) $(CFLAGS) -o "$@" "$<"


fDIC_xcf_mat.o : $(START_DIR)/codegen/lib/fDIC_xcf_mat/fDIC_xcf_mat.c
	$(CC) $(CFLAGS) -o "$@" "$<"


blockedSummation.o : $(START_DIR)/codegen/lib/fDIC_xcf_mat/blockedSummation.c
	$(CC) $(CFLAGS) -o "$@" "$<"


std.o : $(START_DIR)/codegen/lib/fDIC_xcf_mat/std.c
	$(CC) $(CFLAGS) -o "$@" "$<"


FFTImplementationCallback.o : $(START_DIR)/codegen/lib/fDIC_xcf_mat/FFTImplementationCallback.c
	$(CC) $(CFLAGS) -o "$@" "$<"


colon.o : $(START_DIR)/codegen/lib/fDIC_xcf_mat/colon.c
	$(CC) $(CFLAGS) -o "$@" "$<"


fReg.o : $(START_DIR)/codegen/lib/fDIC_xcf_mat/fReg.c
	$(CC) $(CFLAGS) -o "$@" "$<"


ifft2.o : $(START_DIR)/codegen/lib/fDIC_xcf_mat/ifft2.c
	$(CC) $(CFLAGS) -o "$@" "$<"


minOrMax.o : $(START_DIR)/codegen/lib/fDIC_xcf_mat/minOrMax.c
	$(CC) $(CFLAGS) -o "$@" "$<"


relop.o : $(START_DIR)/codegen/lib/fDIC_xcf_mat/relop.c
	$(CC) $(CFLAGS) -o "$@" "$<"


abs.o : $(START_DIR)/codegen/lib/fDIC_xcf_mat/abs.c
	$(CC) $(CFLAGS) -o "$@" "$<"


eml_fftshift.o : $(START_DIR)/codegen/lib/fDIC_xcf_mat/eml_fftshift.c
	$(CC) $(CFLAGS) -o "$@" "$<"


ifftshift.o : $(START_DIR)/codegen/lib/fDIC_xcf_mat/ifftshift.c
	$(CC) $(CFLAGS) -o "$@" "$<"


exp.o : $(START_DIR)/codegen/lib/fDIC_xcf_mat/exp.c
	$(CC) $(CFLAGS) -o "$@" "$<"


fDIC_xcf_mat_emxutil.o : $(START_DIR)/codegen/lib/fDIC_xcf_mat/fDIC_xcf_mat_emxutil.c
	$(CC) $(CFLAGS) -o "$@" "$<"


fDIC_xcf_mat_emxAPI.o : $(START_DIR)/codegen/lib/fDIC_xcf_mat/fDIC_xcf_mat_emxAPI.c
	$(CC) $(CFLAGS) -o "$@" "$<"


fDIC_xcf_mat_rtwutil.o : $(START_DIR)/codegen/lib/fDIC_xcf_mat/fDIC_xcf_mat_rtwutil.c
	$(CC) $(CFLAGS) -o "$@" "$<"


###########################################################################
## DEPENDENCIES
###########################################################################

$(ALL_OBJS) : rtw_proj.tmw $(MAKEFILE)


###########################################################################
## MISCELLANEOUS TARGETS
###########################################################################

info : 
	@echo "### PRODUCT = $(PRODUCT)"
	@echo "### PRODUCT_TYPE = $(PRODUCT_TYPE)"
	@echo "### BUILD_TYPE = $(BUILD_TYPE)"
	@echo "### INCLUDES = $(INCLUDES)"
	@echo "### DEFINES = $(DEFINES)"
	@echo "### ALL_SRCS = $(ALL_SRCS)"
	@echo "### ALL_OBJS = $(ALL_OBJS)"
	@echo "### LIBS = $(LIBS)"
	@echo "### MODELREF_LIBS = $(MODELREF_LIBS)"
	@echo "### SYSTEM_LIBS = $(SYSTEM_LIBS)"
	@echo "### TOOLCHAIN_LIBS = $(TOOLCHAIN_LIBS)"
	@echo "### CFLAGS = $(CFLAGS)"
	@echo "### LDFLAGS = $(LDFLAGS)"
	@echo "### SHAREDLIB_LDFLAGS = $(SHAREDLIB_LDFLAGS)"
	@echo "### CPPFLAGS = $(CPPFLAGS)"
	@echo "### CPP_LDFLAGS = $(CPP_LDFLAGS)"
	@echo "### CPP_SHAREDLIB_LDFLAGS = $(CPP_SHAREDLIB_LDFLAGS)"
	@echo "### ARFLAGS = $(ARFLAGS)"
	@echo "### MEX_CFLAGS = $(MEX_CFLAGS)"
	@echo "### MEX_CPPFLAGS = $(MEX_CPPFLAGS)"
	@echo "### MEX_LDFLAGS = $(MEX_LDFLAGS)"
	@echo "### MEX_CPPLDFLAGS = $(MEX_CPPLDFLAGS)"
	@echo "### DOWNLOAD_FLAGS = $(DOWNLOAD_FLAGS)"
	@echo "### EXECUTE_FLAGS = $(EXECUTE_FLAGS)"
	@echo "### MAKE_FLAGS = $(MAKE_FLAGS)"


clean : 
	$(ECHO) "### Deleting all derived files ..."
	$(RM) $(PRODUCT)
	$(RM) $(ALL_OBJS)
	$(ECHO) "### Deleted all derived files."


