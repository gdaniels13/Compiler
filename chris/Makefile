all: cpsl

cpsl.yy.c: cpsl.l
	flex -o cpsl.yy.c cpsl.l

cpsl: cpsl.yy.c cpsl.tab.c main.cpp
	g++ cpsl.yy.c cpsl.tab.c main.cpp -o cpsl -lfl

cpsl.tab.c: cpsl.y
	bison -vd cpsl.y

clean:
	rm cpsl.yy.c cpsl.tab.c cpsl.tab.h cpsl.output cpsl
