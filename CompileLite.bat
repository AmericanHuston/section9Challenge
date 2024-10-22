@echo off
forfiles /M *.cpp /c "cmd /c g++ -Wall -Wextra -Wpedantic -g -std=c++20 *.cpp -o @fname.exe"
start main.exe
pause