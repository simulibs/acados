#!/bin/sh

INSTALL_ENCRYPTED_SOFTWARE=1
INSTALL_MATLAB=0

if [ "$INSTALL_ENCRYPTED_SOFTWARE" = "1" ]; then
	if [ ! -d "OOQP" ]; then
		echo "Downloading encrypted software"
		source download_software
	else
		echo "Encrypted software already downloaded"
	fi
else
	echo "Skipping installation of encrypted software"
fi

if [ "$INSTALL_MATLAB" = "1" ]; then
	if [ ! -d "matlab" ]; then
		echo "Downloading MATLAB"
		source download_matlab
	else
		echo "MATLAB already downloaded"
	fi

	pushd matlab/bin
	./matlab -nodesktop -nojvm -nosplash < ../../hello_world.m
	popd
	popd

else
	echo "Skipping MATLAB installation"
fi
