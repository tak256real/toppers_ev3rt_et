SRCLANG := c++

# インクルードパスを列挙する.
#   面倒なので、ヘッダファイルが存在し得るパスは全てインクルードパスに含め、
#   include 記述は ヘッダファイル名のみを記述するものとする.
PROJECT_INCLUDE += \
    -I../workspace/riso-ranger2016/common/c_include \
    -I../workspace/riso-ranger2016/sys/arch/interface \
    -I../workspace/riso-ranger2016/sys/arch \
    -I../workspace/riso-ranger2016/sys/arch/OS \
    -I../workspace/riso-ranger2016/sys/arch/timer \
    -I../workspace/riso-ranger2016/sys/device \
    -I../workspace/riso-ranger2016/sys/task \
    -I../workspace/riso-ranger2016 \
    -I./

APPL_CXXOBJS += \
	../workspace/riso-ranger2016/sys/arch/OS/RTOS.o \
	../workspace/riso-ranger2016/sys/arch/interface/SubsystemBridge.o \
	../workspace/riso-ranger2016/sys/arch/interface/SubsystemIf.o \
	../workspace/riso-ranger2016/sys/arch/timer/Timer.o \
	../workspace/riso-ranger2016/sys/arch/timer/TimerEvent.o \
	../workspace/riso-ranger2016/sys/device/init_ev3.o \
	../workspace/riso-ranger2016/sys/device/spec_ev3.o \
	../workspace/riso-ranger2016/sys/task/Task.o \
	../workspace/riso-ranger2016/sys/task/DebugConsole.o \
	../workspace/riso-ranger2016/sys/task/Engine.o \
	../workspace/riso-ranger2016/sys/task/HighPriority.o \
	../workspace/riso-ranger2016/sys/task/Main.o



