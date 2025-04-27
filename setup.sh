#!/usr/bin/bash
echo 'Hi this is setuping proggram...'
echo 'assuming you have debian based distro, loading dependencies'
sudo apt update && sudo apt upgrade -y
sudo apt install gcc g++ git -y
echo $PWD > .dir
mkdir output
./compile.sh
echo 'Use compiled version in output directory!'
echo ' '
echo ' '
echo 'You can also run it with ./run.sh shell file!'
chmod +x run.sh

