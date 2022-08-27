all: tests

tests: src/tests.cpp
	@echo "---"
	@echo "Compiling tests.cpp"

	g++ src/*.cpp -o tests

	@echo "Finished compiling tests.cpp"