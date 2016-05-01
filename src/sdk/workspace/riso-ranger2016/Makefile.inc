SRCLANG := c++

APPL_COBJS += app.o
APPL_CXXOBJS += \
             $(APPLDIR)/OS/RTOS.o \
             $(APPLDIR)/interface/SubsystemBridge.o \
             $(APPLDIR)/interface/SubsystemIf.o \

