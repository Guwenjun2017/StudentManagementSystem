pre = test.o stu.o son_of_main.o mainMenu.o 
last: $(pre) stu.h
	gcc $(pre) -o $@ 

objs = test.c stu.c son_of_main.c mainMenu.c

test.o : test.c stu.h
	gcc -c $< -o $@
stu.o : stu.c stu.h
	gcc -c $< -o $@   
son_of_main.o : son_of_main.c stu.h
	gcc -c $< -o $@ 
mainMenu.o : mainMenu.c stu.h
	gcc -c $< -o $@ 

.PHONY: clean
clean:
	rm *.o last
