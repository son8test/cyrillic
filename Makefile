.PHONY: usage cmake build ctest clean

usage:
	cat Makefile.usage.txt

cmake:
	cd build && cmake -GNinja -DCMAKE_EXPORT_COMPILE_COMMANDS=ON .. && cd ../

build:
	cd build && ninja && cd ../

ctest:
	ctest --test-dir build --output-on-failure

clean:
	rm -rf build/ && git restore build/.gitignore
