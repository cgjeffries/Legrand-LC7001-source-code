@echo off

echo Connect MULTILINK to the new LC7001's debug header, then power up the LC7001.
pause

echo Erasing LC7001 flash...
C:\PEMicro\PROGACMP\cprogacmp.exe lc7001_erase_all_sectors.cfg INTERFACE=USBMULTILINK PORT=USB1 hideapp bdm_speed 4 /logfile lc7001_erase_all_sectors.log

if %ERRORLEVEL% NEQ 0 (
   echo Error %ERRORLEVEL% from lc7001_erase_all_sectors.cfg.  Check lc7001_erase_all_sectors.log for details.
   exit /b 1
) else (
   echo LC7001 flash erased successfully.
   exit /b 0
)