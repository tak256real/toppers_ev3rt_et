SRCLANG := c++

# インクルードパスを列挙する.
#   面倒なので、ヘッダファイルが存在し得るパスは全てインクルードパスに含め、
#   include 記述は ヘッダファイル名のみを記述するものとする.
PROJECT_INCLUDE += \
    -I$(APPLDIR)/common/c_include \
    -I$(APPLDIR)/sys/arch/interface \
    -I$(APPLDIR)/sys/arch \
    -I$(APPLDIR)/sys/arch/OS \
    -I$(APPLDIR)/sys/arch/timer \
    -I$(APPLDIR)/sys/device \
    -I$(APPLDIR)/sys/task \
    -I$(APPLDIR)



APPL_COBJS += app.o
APPL_CXXOBJS += \
             $(APPLDIR)/OS/RTOS.o \
             $(APPLDIR)/interface/SubsystemBridge.o \
             $(APPLDIR)/interface/SubsystemIf.o \

