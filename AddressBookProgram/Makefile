#use the following commands
# 1. make person
#    compiles your extPersonTypeImp.cpp file into an object file called person.o

# 2. make test1
#    compiles the unit test and person.o into an executable file called test
#    and then run ./test

# 3. make
#    compiles your project3.cpp and generates a.out

# 4. make test2
#	 runs a.out on an input file called input1

# 5. make clean
#    deletes all the files the compiler generated

# 6. make turnin
#    turns in all the necessary files to the project3 submission folder


a.out: project3.cpp person.o personTypeImp.o addressTypeImp.o dateTypeImp.o
	g++ project3.cpp *.o

test1: unitTest.cpp person.o personTypeImp.o addressTypeImp.o dateTypeImp.o
	g++ unitTest.cpp *.o -o test
	@./test

test2: a.out
	@./a.out < input1

person: extPersonType.h extPersonTypeImp.cpp
	g++ -c extPersonTypeImp.cpp -o person.o

clean:
	rm a.out person.o test *~

turnin: *.cpp *.h *.o 
	@/export/home/public/zhang/csc136/turnin/turnin-project3 Makefile input1 addressData.txt *.h *.cpp *.o

