echo cmd.bat path : %~dp0
cd path
dir    %~dp0\*.proto /B > list.txt              

for  /f  %%a  in  (list.txt)  do (
echo %%a
protoc --cpp_out=../message/ ./%%a
)
echo done