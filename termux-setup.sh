#!/usr/bin/bash
echo 'Пожалуйста запускайте в директории проекта!'
echo 'Hi this is setuping proggram...'
echo 'assuming you have debian based distro, loading dependencies'
apt update && sudo apt upgrade -y
apt install gcc g++ git -y
./compile.sh
echo $PWD > .dir
echo 'Use compiled version in output directory!'

