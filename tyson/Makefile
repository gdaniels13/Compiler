default: clean logger table cpsl

run: default
	./cpsl testFile.cpsl out.txt -v

cpsl: bison lex
	g++ -o cpsl -std=c++11 cpsl.tab.c logger.o table.o lex.yy.c  -ll

lex:
	flex cpsl.l

bison:
	bison -vd cpsl.y


logger: 
	g++ -std=c++11 logger.h logger.cpp -c

table:
	g++ -std=c++11 table.h table.cpp -c

clean:
	-rm -rf out.txt
	-rm -rf cpsl
	-rm -rf cpsl.output
	-rm -rf logger.o
	-rm -rf lex.yy.c
	-rm -rf cpsl.tab.h
	-rm -rf cpsl.tab.c
	-rm -rf logger.h.gch
	-rm -rf table.h.gch
	-rm -rf table.o

