#use the following commands
# 1. make
#    compiles project5.cpp and linkedList.h,  outputs a.out

# 2. make test1
#    compiles testLinkedList.cpp and linkedList.h into an executable file called test
#    and then run ./test under valgrind

# 3. make test2
#	 runs a.out four times with four different input files 

# 4. make clean
#    deletes all the files the compiler generated

# 5. make turnin
#    turns in all the necessary files to the project5 submission folder


a.out: project5.cpp linkedList.h
	g++ project5.cpp linkedList.h

test1: linkedList.h testLinkedList.cpp 
	g++ testLinkedList.cpp linkedList.h -o test
	@valgrind ./test

test2: project5.cpp linkedList.h
	g++ project5.cpp linkedList.h
	@./a.out < input1
	@./a.out < input2
	@./a.out < input3
	@./a.out < input4

clean:
	rm a.out test *.gch *~

turnin: *.cpp *.h
	@/export/home/public/zhang/csc136/turnin/turnin-project5 Makefile *.h *.cpp input*

