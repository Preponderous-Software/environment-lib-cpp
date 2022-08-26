all: testing

testing: src/testing.cpp
	@echo "---"
	@echo "Compiling testing.cpp"

	g++ src/testing.cpp src/entity.cpp -o testing

	@echo "Finished compiling testing.cpp"