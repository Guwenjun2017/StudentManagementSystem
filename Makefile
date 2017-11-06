objs = test.c stu.c 

last: $(objs)
	gcc -o last $(objs)
clean:
	rm last
