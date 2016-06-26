@ECHO OFF 

:input
set INPUT=
set /P INPUT=Type PIC's IP Last Octet: %=%
if "%INPUT%"=="" goto input

echo tftp: 192.168.100.%INPUT%

tftp.exe -i 192.168.100.%INPUT% put mpfsimg.bin

pause