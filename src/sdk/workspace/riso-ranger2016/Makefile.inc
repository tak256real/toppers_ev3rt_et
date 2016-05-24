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
	$(APPLDIR)/sys/arch/OS/RTOS.o \
	$(APPLDIR)/sys/arch/interface/SubsystemBridge.o \
	$(APPLDIR)/sys/arch/interface/SubsystemIf.o \
	$(APPLDIR)/sys/arch/timer/Timer.o \
	$(APPLDIR)/sys/arch/timer/TimerEvent.o \
	$(APPLDIR)/sys/device/init_ev3.o \
	$(APPLDIR)/sys/device/spec_ev3.o \
	$(APPLDIR)/sys/task/Task.o \
	$(APPLDIR)/sys/task/DebugConsole.o \
	$(APPLDIR)/sys/task/Engine.o \
	$(APPLDIR)/sys/task/HighPriority.o \
	$(APPLDIR)/sys/task/Main.o \
	$(APPLDIR)/sys/task/system_task.o


