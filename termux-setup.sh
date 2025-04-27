#!/usr/bin/bash
echo 'Пожалуйста запускайте в директории проекта!'
echo 'Hi this is setuping proggram...'
echo 'loading dependencies'
apt update && sudo apt upgrade -y
apt install gcc g++ git -y
mkdir output
./compile.sh
echo $PWD > .dir
echo 'Use compiled version in output directory!'
echo 'Для быстрого запуска запустите ./run.sh это вспомогательный файл'
chmod +x run.sh
