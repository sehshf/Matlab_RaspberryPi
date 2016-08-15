setenv('MINGWROOT','C:\SysGCC\MinGW64')
mex -setup:C:\Users\ses\Documents\MATLAB\RaspberryPi\mex_mingw64_C.xml C

mex -v dgio_sfun.c gpio.c mman.c

