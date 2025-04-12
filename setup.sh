#!/usr/bin/bash
echo 'Hi this is setuping proggram...'
echo 'assuming you have debian based distro, loading dependencies'
sudo apt update && sudo apt upgrade -y
sudo apt install gcc g++ git -y
./compile.sh
echo 'Use compiled version in output directory!'

