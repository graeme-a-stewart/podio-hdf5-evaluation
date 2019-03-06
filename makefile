all: write read clean

write: write.cpp
	@echo "Compiling write.cpp"
	h5c++ write.cpp -o write.out
	@echo "Run using the command './write.out'"

read: write.cpp
	@echo "Compiling read.cpp"
	h5c++ read.cpp -o read.out
	@echo "Run using the command './read.out'"

clean:
	rm *.o

run:
	./write.out
	./read.out