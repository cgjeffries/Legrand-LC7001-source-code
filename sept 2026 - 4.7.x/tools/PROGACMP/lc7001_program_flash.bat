@echo off

call lc7001_erase_all_sectors.bat
if %ERRORLEVEL% NEQ 0 (goto end)

echo Programming LC7001 flash...
C:\PEMicro\PROGACMP\cprogacmp.exe lc7001_program_flash.cfg INTERFACE=USBMULTILINK PORT=USB1 hideapp bdm_speed 4 /logfile lc7001_program_flash.log

if %ERRORLEVEL% NEQ 0 (
   echo Error %ERRORLEVEL% from lc7001_program_flash.cfg.  Check lc7001_program_flash.log for details.
   exit /b 1
) else (
   echo LC7001 flash programmed successfully.
   exit /b 0
)

:end