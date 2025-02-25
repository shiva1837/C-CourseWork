a.out: project2.cpp employeeType.h employeeTypeImp.cpp
	g++ project2.cpp employeeTypeImp.cpp

test1: employeeType.h employeeTypeImp.cpp unitTest.cpp
	@g++ unitTest.cpp employeeTypeImp.cpp -o unitTest
	@./unitTest

test2: project2.cpp employeeType.h employeeTypeImp.cpp
	@g++ project2.cpp employeeTypeImp.cpp -o project2
	@./project2 < input

turnin: project2.cpp employeeType.h employeeTypeImp.cpp
	@/export/home/public/zhang/csc136/turnin/turnin-project2 project2.cpp Makefile employee.dat employeeType.h employeeTypeImp.cpp unitTest.cpp input

clean:
	rm a.out unitTest project2 *~

