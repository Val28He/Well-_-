@echo off
chcp 1251 > log
del log

set CPP_FILES="menu.hpp menu_functions.hpp menu_functions.cpp menu_items.hpp menu_items.cpp main.cpp"
set EXE=RuWriters.exe
set CHARSET="-finput-charset=utf-8 -fexec-charset=windows-1251"

if exist %EXE% del %EXE%

g++ "%CHARSET%" "%CPP_FILES%" -o %EXE%

%EXE%