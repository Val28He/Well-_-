@echo off
setlocal EnableDelayedExpansion

set BUILD_TYPE=Ninja 
set BUILD_SUFFIX=ninja

chcp 65001

set BUILD_FOLDER=build_%BUILD_SUFFIX%
set SORCE_FOLDER=projects

if not exist %BUILD_FOLDER% mkdir %BUILD_FOLDER%

cd %BUILD_FOLDER%

cmake -G %BUILD_TYPE% ..\%SORCE_FOLDER%
cmake --build .

copy ..\%SORCE_FOLDER%\multilevel_menu\run_multilevel_menu.bat .\multilevel_menu

copy ..\run_tests.bat . 