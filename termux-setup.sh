#!/usr/bin/bash
echo 'Пожалуйста запускайте в директории проекта!'
echo 'Hi this is setuping proggram...'
echo 'loading dependencies'
yes | pkg install clang
mkdir output
mkdir -p ~/.config/adcalc
echo $PWD > ~/.config/adcalc/dir
./compile.sh
echo 'Use compiled version in output directory!'
echo 'Для быстрого запуска запустите ./run.sh это вспомогательный файл'
chmod +x run.sh
