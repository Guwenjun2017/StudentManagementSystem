pre = test.o stu.o son_of_main.o mainMenu.o 
last: $(pre) stu.h
	gcc $(pre) -o $@ 

test.o : test.c stu.h
	gcc -c $< -o $@
stu.o : stu.c stu.h
	gcc -c $< -o $@   
son_of_main.o : son_of_main.c stu.h
	gcc -c $< -o $@ 
mainMenu.o : mainMenu.c stu.h
	gcc -c $< -o $@ 
#clean
.PHONY: clean
clean:
	rm *.o last
