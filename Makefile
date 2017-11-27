pre = obj/test.o obj/mainMenu.o obj/son_of_main.o obj/stu.o obj/stu_C.o 

bin/last: $(pre) inc/stu.h
	gcc $(pre) -o $@ 


obj/test.o : src/test.c inc/stu.h
	gcc -c $< -o $@
obj/mainMenu.o : src/mainMenu.c inc/stu.h
	gcc -c $< -o $@ 
obj/son_of_main.o : src/son_of_main.c inc/stu.h
	gcc -c $< -o $@ 
obj/stu.o : src/stu.c inc/stu.h
	gcc -c $< -o $@   
obj/stu_C.o : src/stu_C.c inc/stu.h
	gcc -c $< -o $@

.PHONY: clean
clean:
	cd obj;rm *.o   #命令在项目根目录执行完后,会自动切换回项目根目录,
	cd bin;rm last  #无需cd ..返回上一级目录
