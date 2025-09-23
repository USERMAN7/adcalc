#!/usr/bin/bash
config=/home/$(whoami)/.config/adcalc # Makes config directory for project. to compile
if [ -d $config ]; then
	rm -rf $(cat $config/dir)/output
	rm -rf $config && echo Removed previous config file.
fi
error() {
	case $1 in
		install)
			echo "Installation failed, might be connectivity problem or etc.."
			exit 1;;
		setup)
			printf "Failed to make "$2"/"$3" fatal!"
			exit 1;;
		*)
			echo "Unknown error!!"
			exit 1;;
	esac
}
echo 'Hi this is setuping proggram...'
#read -r DISTRO #checking distro then installing dependicies.
#debians=(debian ubuntu mint kali)
DISTRO=$(grep "ID=*" /etc/os-release|awk -F_ '{print $1}'|grep "ID="|awk -F= '{print $2}')
#for 
case $DISTRO in
	arch)
		printf "Using arch\n"
		printf "Installing packages for arch\n"
		yes|sudo pacman -S gcc ||error install;;
	debian)
		printf "Using debian\n"
		printf "Installing packages for debian\n"
		sudo apt install gcc g++ -y||error install;;
	ubuntu)
		printf "Using ubuntu\n"
		printf "Installing packages for ubuntu\n"
		sudo apt install gcc g++ -y||error install;;
	fedora)
		printf "Using fedora\n"
		printf "Installing packages for fedora\n"
		sudo dnf install gcc g++ -y||error install;;
	kali)
		printf "Using kali\n"
		printf "Installing packages for kali\n"
		sudo apt install gcc g++ -y||error install;;
	*)
		printf "Failed to know which OS you're using, try to install dependicies yourself.\n"
		printf "SHELL:"
		read -r shell
		eval $shell;;
esac

#==============================================================+
#That all double pipes is just checking for fails then exiting.||
#Nothing serious					       ||
#==============================================================+
mkdir -p "$config" || { error setup "$config" "$config"; exit 1; } 
echo "$PWD" > "$config"/dir
mkdir "$(cat "$config"/dir)/output" || { echo "Failed to make $(cat "$config"/dir)/output"; exit 1; }

"$(cat "$config"/dir)/compile.sh" || { echo "file not found exiting."; exit 1; }

echo 'Use compiled version in output directory!'
echo 'You can also run it with ./run.sh shell file!'

chmod +x "$(cat "$config"/dir)/run.sh" || { echo "Failed to make $(cat "$config"/dir)/run.sh"; exit 1; }

