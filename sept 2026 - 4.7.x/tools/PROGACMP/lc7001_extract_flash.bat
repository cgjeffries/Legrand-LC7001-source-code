@echo off

echo Connect MULTILINK to the original LC7001's debug header, then power up the LC7001.
pause

echo Extracting flash from LC7001...
C:\PEMicro\PROGACMP\cprogacmp.exe lc7001_extract_flash.cfg INTERFACE=USBMULTILINK PORT=USB1 hideapp bdm_speed 4 /logfile lc7001_extract_flash.log

if %ERRORLEVEL% NEQ 0 (
   echo Error %ERRORLEVEL% from lc7001_extract_flash.cfg.  Check lc7001_extract_flash.log for details.
   exit /b 1
) else (
   echo LC7001 flash extracted successfully.
   exit /b 0
)