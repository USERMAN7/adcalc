#!/usr/bin/bash
if [ -d /home ]; then
	$(cat /home/$(whoami)/.config/adcalc/dir)/output/calc
else
	"$(cat ~/.config/adcalc/dir)"/output/calc
fi
