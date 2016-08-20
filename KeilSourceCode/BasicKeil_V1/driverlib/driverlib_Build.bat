
SET TMP=C:\Temp
SET TEMP=C:\Temp

SET UVEXE=C:\Keil\UV4\UV4.EXE

%UVEXE% -b driverlib-cm3.uvproj -t"driverlib-cm3" -o"driverlib-cm3.log"
%UVEXE% -b driverlib-cm4f.uvproj -t"driverlib-cm4f" -o"driverlib-cm4f.log"
