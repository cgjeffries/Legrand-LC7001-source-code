SET(LIBRARY_NAME usbd)

INCLUDE_DIRECTORIES(${MQX_ROOTDIR}/usb/device/source/classes/include)
INCLUDE_DIRECTORIES(${MQX_ROOTDIR}/usb/common/include)
INCLUDE_DIRECTORIES(${MQX_ROOTDIR}/usb/device/source/include)
INCLUDE_DIRECTORIES(${MQX_ROOTDIR}/usb/device/source/include/khci)
INCLUDE_DIRECTORIES(${MQX_ROOTDIR}/usb/host/source/host/khci)
INCLUDE_DIRECTORIES(${MQX_ROOTDIR}/usb/device/source/include/rtos)
INCLUDE_DIRECTORIES(${MQX_ROOTDIR}/mqx/source/io/adc/kadc)
INCLUDE_DIRECTORIES(${MQX_ROOTDIR}/mqx/source/io/adc)
INCLUDE_DIRECTORIES(${MQX_ROOTDIR}/mqx/source/io/cm)
INCLUDE_DIRECTORIES(${MQX_ROOTDIR}/config/twrk64f120m)
INCLUDE_DIRECTORIES(${MQX_ROOTDIR}/mqx/source/io/dma)
INCLUDE_DIRECTORIES(${MQX_ROOTDIR}/mqx/source/io/enet/macnet)
INCLUDE_DIRECTORIES(${MQX_ROOTDIR}/mqx/source/io/enet/phy)
INCLUDE_DIRECTORIES(${MQX_ROOTDIR}/mqx/source/io/enet)
INCLUDE_DIRECTORIES(${MQX_ROOTDIR}/mqx/source/io/esdhc)
INCLUDE_DIRECTORIES(${MQX_ROOTDIR}/mqx/source/io/flashx/freescale)
INCLUDE_DIRECTORIES(${MQX_ROOTDIR}/mqx/source/io/flashx)
INCLUDE_DIRECTORIES(${MQX_ROOTDIR}/mqx/source/io/can/flexcan)
INCLUDE_DIRECTORIES(${MQX_ROOTDIR}/mqx/source/io/gpio/kgpio)
INCLUDE_DIRECTORIES(${MQX_ROOTDIR}/mqx/source/io/gpio)
INCLUDE_DIRECTORIES(${MQX_ROOTDIR}/mqx/source/io/hwtimer)
INCLUDE_DIRECTORIES(${MQX_ROOTDIR}/mqx/source/io/i2c)
INCLUDE_DIRECTORIES(${MQX_ROOTDIR}/mqx/source/io/i2c/polled)
INCLUDE_DIRECTORIES(${MQX_ROOTDIR}/mqx/source/io/i2c/int)
INCLUDE_DIRECTORIES(${MQX_ROOTDIR}/mqx/source/bsp/twrk64f120m)
INCLUDE_DIRECTORIES(${MQX_ROOTDIR}/config/common)
INCLUDE_DIRECTORIES(${MQX_ROOTDIR}/mqx/source/include)
INCLUDE_DIRECTORIES(${MQX_ROOTDIR}/mqx/source/io/debug)
INCLUDE_DIRECTORIES(${MQX_ROOTDIR}/mqx/source/io/io_mem)
INCLUDE_DIRECTORIES(${MQX_ROOTDIR}/mqx/source/io/io_null)
INCLUDE_DIRECTORIES(${MQX_ROOTDIR}/mqx/source/io/pipe)
INCLUDE_DIRECTORIES(${MQX_ROOTDIR}/mqx/source/io/lpm)
INCLUDE_DIRECTORIES(${MQX_ROOTDIR}/mqx/source/io/lwadc)
INCLUDE_DIRECTORIES(${MQX_ROOTDIR}/mqx/source/io/lwgpio)
INCLUDE_DIRECTORIES(${MQX_ROOTDIR}/mqx/source/io/pcb)
INCLUDE_DIRECTORIES(${MQX_ROOTDIR}/mqx/source/io/pcb/mqxa)
INCLUDE_DIRECTORIES(${MQX_ROOTDIR}/mqx/source/io/pccard)
INCLUDE_DIRECTORIES(${MQX_ROOTDIR}/mqx/source/io/pcflash)
INCLUDE_DIRECTORIES(${MQX_ROOTDIR}/mqx/source/io/rtc)
INCLUDE_DIRECTORIES(${MQX_ROOTDIR}/mqx/source/io/sai)
INCLUDE_DIRECTORIES(${MQX_ROOTDIR}/mqx/source/io/sai/int)
INCLUDE_DIRECTORIES(${MQX_ROOTDIR}/mqx/source/io/sdcard/sdcard_esdhc)
INCLUDE_DIRECTORIES(${MQX_ROOTDIR}/mqx/source/io/sdcard/sdcard_spi)
INCLUDE_DIRECTORIES(${MQX_ROOTDIR}/mqx/source/io/sdcard)
INCLUDE_DIRECTORIES(${MQX_ROOTDIR}/mqx/source/io/serial)
INCLUDE_DIRECTORIES(${MQX_ROOTDIR}/mqx/source/io/spi)
INCLUDE_DIRECTORIES(${MQX_ROOTDIR}/mqx/source/io/tchres)
INCLUDE_DIRECTORIES(${MQX_ROOTDIR}/mqx/source/io/tfs)
INCLUDE_DIRECTORIES(${MQX_ROOTDIR}/mqx/source/io/timer)
INCLUDE_DIRECTORIES(${MQX_ROOTDIR}/mqx/source/io/usb)
INCLUDE_DIRECTORIES(${MQX_ROOTDIR}/mqx/source/io/usb_dcd)
INCLUDE_DIRECTORIES(${MQX_ROOTDIR}/mqx/source/io/usb_dcd/polled)
INCLUDE_DIRECTORIES(${MQX_ROOTDIR}/mqx/source/io/usb_dcd/int)
INCLUDE_DIRECTORIES(${MQX_ROOTDIR}/mqx/source/psp/cortex_m/cpu)
INCLUDE_DIRECTORIES(${MQX_ROOTDIR}/mqx/source/psp/cortex_m)
INCLUDE_DIRECTORIES(${MQX_ROOTDIR}/mqx/source/psp/cortex_m/core/M4)
INCLUDE_DIRECTORIES(${MQX_ROOTDIR}/mqx/source/tad)
INCLUDE_DIRECTORIES(${MQX_ROOTDIR}/mqx/source/psp/cortex_m/compiler/gcc_arm/)
INCLUDE_DIRECTORIES(${MQX_ROOTDIR}/../tools/toolchain/arm-none-eabi/include)
INCLUDE_DIRECTORIES(${MQX_ROOTDIR}/../tools/toolchain/lib/gcc/arm-none-eabi/5.2.1/include)
INCLUDE_DIRECTORIES(${MQX_ROOTDIR}/../tools/toolchain/lib/gcc/arm-none-eabi/5.2.1/include-fixed)

SET(SOURCES
   ${MQX_ROOTDIR}/usb/device/source/classes/audio/usb_audio.c
   ${MQX_ROOTDIR}/usb/device/source/classes/cdc/usb_cdc.c
   ${MQX_ROOTDIR}/usb/device/source/classes/cdc/usb_cdc_pstn.c
   ${MQX_ROOTDIR}/usb/device/source/classes/common/usb_class.c
   ${MQX_ROOTDIR}/usb/device/source/classes/common/usb_framework.c
   ${MQX_ROOTDIR}/usb/device/source/classes/hid/usb_hid.c
   ${MQX_ROOTDIR}/usb/device/source/device/khci/callback_khci.c
   ${MQX_ROOTDIR}/usb/device/source/device/khci/khci_dev_main.c
   ${MQX_ROOTDIR}/usb/device/source/classes/msd/usb_msc.c
   ${MQX_ROOTDIR}/usb/device/source/classes/msd/usb_msc_scsi.c
   ${MQX_ROOTDIR}/usb/device/source/classes/phdc/usb_phdc.c
   ${MQX_ROOTDIR}/usb/device/source/device/dev_cncl.c
   ${MQX_ROOTDIR}/usb/device/source/device/dev_ep_deinit.c
   ${MQX_ROOTDIR}/usb/device/source/device/dev_main.c
   ${MQX_ROOTDIR}/usb/device/source/device/dev_recv.c
   ${MQX_ROOTDIR}/usb/device/source/device/dev_send.c
   ${MQX_ROOTDIR}/usb/device/source/device/dev_shut.c
   ${MQX_ROOTDIR}/usb/device/source/device/dev_utl.c
   ${MQX_ROOTDIR}/usb/device/source/device/dev_main.c)

ADD_LIBRARY(${LIBRARY_NAME} STATIC ${SOURCES})

ADD_CUSTOM_COMMAND(TARGET ${LIBRARY_NAME}
   POST_BUILD
   COMMAND ${MQX_ROOTDIR}/usb/device/build/bat/usbd_twrk64f120m.sh ${MQX_ROOTDIR} ${MQX_ROOTDIR}/lib/twrk64f120m.cmake/debug/usb gcc_arm
   COMMENT "Copying usb device files")
