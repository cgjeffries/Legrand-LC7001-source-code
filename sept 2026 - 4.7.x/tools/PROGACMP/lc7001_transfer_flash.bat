@echo off

call lc7001_extract_flash.bat
if %ERRORLEVEL% NEQ 0 (goto end)

call lc7001_program_flash.bat
if %ERRORLEVEL% NEQ 0 (goto end)

echo Power down the LC7001, disconnect the MULTILINK, power up the LC7001, and confirm that the blue LED is flashing.

:end