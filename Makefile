objs = test.c stu.c son_of_main.c mainMenu.c

last: $(objs)
	gcc -o last $(objs)
clean:
	rm last
