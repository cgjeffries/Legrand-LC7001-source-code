SET(LIBRARY_NAME mfs)

INCLUDE_DIRECTORIES(${MQX_ROOTDIR}/mfs/source/include)
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
   ${MQX_ROOTDIR}/mfs/source/generic/dir_read.c
   ${MQX_ROOTDIR}/mfs/source/generic/mfs_attribute.c
   ${MQX_ROOTDIR}/mfs/source/generic/mfs_cluster.c
   ${MQX_ROOTDIR}/mfs/source/generic/mfs_create.c
   ${MQX_ROOTDIR}/mfs/source/generic/mfs_data_sector.c
   ${MQX_ROOTDIR}/mfs/source/generic/mfs_delete.c
   ${MQX_ROOTDIR}/mfs/source/generic/mfs_dir_entry.c
   ${MQX_ROOTDIR}/mfs/source/generic/mfs_directory.c
   ${MQX_ROOTDIR}/mfs/source/generic/mfs_fat.c
   ${MQX_ROOTDIR}/mfs/source/generic/mfs_format.c
   ${MQX_ROOTDIR}/mfs/source/generic/mfs_handle.c
   ${MQX_ROOTDIR}/mfs/source/generic/mfs_init.c
   ${MQX_ROOTDIR}/mfs/source/generic/mfs_lfn.c
   ${MQX_ROOTDIR}/mfs/source/generic/mfs_misc.c
   ${MQX_ROOTDIR}/mfs/source/generic/mfs_open.c
   ${MQX_ROOTDIR}/mfs/source/generic/mfs_parse.c
   ${MQX_ROOTDIR}/mfs/source/generic/mfs_read.c
   ${MQX_ROOTDIR}/mfs/source/generic/mfs_rename.c
   ${MQX_ROOTDIR}/mfs/source/generic/mfs_rw.c
   ${MQX_ROOTDIR}/mfs/source/generic/mfs_search.c
   ${MQX_ROOTDIR}/mfs/source/generic/mfs_time.c
   ${MQX_ROOTDIR}/mfs/source/generic/mfs_valdev.c
   ${MQX_ROOTDIR}/mfs/source/generic/mfs_write.c
   ${MQX_ROOTDIR}/mfs/source/generic/part_mgr.c)

ADD_LIBRARY(${LIBRARY_NAME} STATIC ${SOURCES})

ADD_CUSTOM_COMMAND(TARGET ${LIBRARY_NAME}
   POST_BUILD
   COMMAND ${MQX_ROOTDIR}/mfs/build/bat/mfs_twrk64f120m.sh ${MQX_ROOTDIR} ${MQX_ROOTDIR}/lib/twrk64f120m.cmake/debug/mfs gcc_arm
   COMMENT "Copying mfs files")
