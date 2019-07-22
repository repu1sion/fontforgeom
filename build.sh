#!/bin/bash


#./configure
#./configure --enable-woff2 --enable-gdk=gdk3 CFLAGS='-g -O0'

if [ $# -eq 0 ]; then
	echo "configuring"
	./bootstrap
	./configure --enable-gdk=gdk3 CFLAGS='-g -O0'
else
	echo "skip configuring"
fi
sleep 1
echo "building"
make -j7 && sudo make install && sudo ldconfig && echo "build ok" || "build failed"
