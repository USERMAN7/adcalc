#!/usr/bin/bash
if [ -d /home ]; then
	CONFIG_PWD=$(cat /home/$(whoami)/.config/adcalc/dir) # Смотрит в файл конфига и переводит путь к файлу проекта, сделано для того чтобы не зависить от симболических команд
else
	CONFIG_PWD=$(cat ~/.config/adcalc/dir)
g++ "$CONFIG_PWD"/sources/calc.cpp -o "$CONFIG_PWD"/output/calc
echo done compiling

