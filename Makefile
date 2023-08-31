all:
	make -C ./src
	make -C ./tests

clean:
	make -C ./src clean
	make -C ./tests clean

test:
	make -C ./tests test

#From the root directory copy and past the commands below to download and build Google Test library in your app
# git clone https://github.com/google/googletest.git
# cd googletest
# mkdir build
# cd build
# cmake ..
# make

# Now run to run the unit tests the makefile targets:
# make all
# make test

