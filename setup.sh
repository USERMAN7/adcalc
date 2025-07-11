#!/usr/bin/bash
config=/home/$(whoami)/.config/adcalc # Makes config directory for project. to compile
if [ -d $config ]; then
	rm -rf $(cat $config/dir)/output
	rm -rf $config && echo Removed previous config file.
fi
echo 'Hi this is setuping proggram...'
echo 'Please input your distro ID, supported distro debian,arch,rhel'
#read -r DISTRO #checking distro then installing dependicies.
#debians=(debian ubuntu mint kali)
DISTRO=$(grep "ID=*" /etc/os-release|awk -F_ '{print $1}'|grep "ID="|awk -F= '{print $2}')
#for 
if [ "$DISTRO" == "debian" ]; then
	echo -e "\nUsing debian"
	echo "Installing packages for ""$DISTRO"" "
	sudo apt update && sudo apt install gcc g++ -y || { echo "Installation failed,
       please try again."; exit 1; }	
elif [ "$DISTRO" == "arch" ]; then
	echo -e "\nUsing arch"
	echo "Installing packages for ""$DISTRO"" "
	yes | sudo pacman -S gcc || { echo "Installation failed, please try again."; exit 1; } 
elif [ "$DISTRO" == "rhel" ]; then
	echo -e "\nUsing rhel"
	echo "Installing packages for ""$DISTRO"" "
	sudo dnf install gcc -y || { echo "Installation failed, please try again."; exit 1; }
else
	echo "Do you have dependicies installed? (gcc,g++)"
	read -r YES_NO
	if [ "$YES_NO" == "yes" ]; then
		echo "going through checks."
	else
		echo "sorry, installation of packages for non supported distros is not yet added"; exit 1
	fi
fi
#==============================================================+
#That all double pipes is just checking for fails then exiting.||
#Nothing serious					       ||
#==============================================================+
mkdir -p "$config" || { echo "Failed to make $config."; exit 1; } 
echo $PWD > "$config"/dir
mkdir $(cat $config/dir)/output || { echo "Failed to make $(cat $config/dir)/output"; exit 1; }
$(cat "$config"/dir)/compile.sh || { echo "file not found exiting."; exit 1 }
echo 'Use compiled version in output directory!'
echo 'You can also run it with ./run.sh shell file!'
chmod +x $(cat "config"/dir)/run.sh || { echo "Failed to make $(cat $config/dir)/run.sh"; exit 1; }
