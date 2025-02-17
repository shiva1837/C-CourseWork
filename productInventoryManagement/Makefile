a.out: project1.cpp
	g++ project1.cpp

test: a.out
	@echo -e "\n"
	@./a.out
	

turnin: project1.cpp
	@/export/home/public/zhang/csc136/turnin/turnin-project1 project1.cpp Makefile productData.txt

clean:
	rm a.out *~

