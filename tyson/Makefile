default: clean output logger table cpsl

run: default
	./cpsl testFile.cpsl out.asm -v
	java -jar Mars4_3.jar out.asm

cpsl: bison lex
	g++ -o cpsl -std=c++11 -g OutputFile.o table.o cpsl.tab.c logger.o  lex.yy.c  -ll

lex:
	flex cpsl.l

bison:
	bison -vd cpsl.y


logger: 
	g++ -std=c++11 logger.cpp -c

table:
	g++ -std=c++11 table.cpp -c

test: test.cpp
	g++ -std=c++11 table.o test.cpp
	./a.out

output:
	g++ -std=c++11 OutputFile.cpp -c

clean:
	-rm -rf out.txt
	-rm -rf cpsl
	-rm -rf cpsl.output
	-rm -rf logger.o
	-rm -rf lex.yy.c
	-rm -rf cpsl.tab.h
	-rm -rf cpsl.tab.c
	-rm -rf table.o
	-rm -rf OutputFile.o
	-rm -rf cpsl.dSYM/
	-rm -rf out.asm

