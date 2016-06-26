@echo off

rem This makes an MPFS .bin image.  /ll is going to be used, so make sure
rem that you define MPFS as a 32bit integer.  /r0 is used to remove the null
rem header, MPFS_Start already defines the starting block and the MPFS code
rem will ignore the area before MPFS_Start.
sleep 1

mpfs /b /r0 /ll /k ../pages mpfsimg.bin

sleep 1