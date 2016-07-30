PROJECT_INCLUDE += \
 	-I../workspace/riso-ranger2016/common/c_include \
 	-I../workspace/riso-ranger2016/sys/arch/interface \
 	-I../workspace/riso-ranger2016/sys/arch \
 	-I../workspace/riso-ranger2016/sys/arch/OS \
 	-I../workspace/riso-ranger2016/sys/arch/timer \
 	-I../workspace/riso-ranger2016/sys/device \
 	-I../workspace/riso-ranger2016/sys/task \
 	-I../workspace/riso-ranger2016/event \
 	-I../workspace/riso-ranger2016/eng/linetrace \
  	-I../workspace/riso-ranger2016/eng/calibration \
 	-I../workspace/riso-ranger2016 \
 	-I./

APPL_COBJS += 

APPL_CXXOBJS += \
../workspace/riso-ranger2016/sys/device/WheelControl.o \
../workspace/riso-ranger2016/sys/device/TailControl.o \
../workspace/riso-ranger2016/sys/device/Motor.o \
../workspace/riso-ranger2016/sys/device/balancer_param.o \
../workspace/riso-ranger2016/sys/device/balancer.o \
../workspace/riso-ranger2016/sys/device/StateObserver.o \
../workspace/riso-ranger2016/sys/device/ColorSensor.o \
../workspace/riso-ranger2016/eng/calibration/Calibration.o \
../workspace/riso-ranger2016/event/TouchSensorListener.o \
../workspace/riso-ranger2016/eng/linetrace/Linetrace.o \
../workspace/riso-ranger2016/eng/linetrace/PIDControl.o \
../workspace/riso-ranger2016/Temp.o

SRCLANG := c++

ifdef CONFIG_EV3RT_APPLICATION

# Include libraries
include $(EV3RT_SDK_LIB_DIR)/libcpp-test/Makefile
include $(EV3RT_SDK_LIB_DIR)/lib2/Makefile

endif
