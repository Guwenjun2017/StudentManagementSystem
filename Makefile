objs = test.c stu.c 

test: $(objs)
	gcc -o test $(objs)
clean:
	rm test
