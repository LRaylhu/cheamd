@echo off

set CompilerFlags=-O0 -g -Wall -Wextra
pushd build

REM 64-bit build
clang++ %CompilerFlags% ..\src\cheamd.cpp -o cheamd.exe

popd
