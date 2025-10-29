usage:

cmake:
	cd build && cmake -GNinja -DCMAKE_EXPORT_COMPILE_COMMANDS=ON .. && cd ../

ninja:
	cd build && ninja && cd ../

tests:
	ctest --test-dir build --output-on-failure
