#use the following commands
# 1. make
#    compiles your complexType class and main.cpp,  generates a.out

# 2. make test1
#    compiles the unit test and your complexType class into an executable file called test
#    and then run ./test

# 3. make test2
#	 runs a.out on an input file called input1

# 4. make clean
#    deletes all the files the compiler generated

# 5. make turnin
#    turns in all the necessary files to the project4 submission folder


a.out: complexType.h complexTypeImp.cpp main.cpp
	g++ main.cpp complexTypeImp.cpp

test1: unitTest.cpp complexType.h complexTypeImp.cpp
	g++ unitTest.cpp complexTypeImp.cpp -o test
	@./test

test2: a.out
	@./a.out < input1

clean:
	rm a.out test *~

turnin: *.cpp *.h
	@/export/home/public/zhang/csc136/turnin/turnin-project4 Makefile input1 complexType.h complexTypeImp.cpp main.cpp unitTest.cpp

