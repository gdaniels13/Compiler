default: logger cpsl


log: default
	./cpsl testFile.cpsl > ./out.txt
	subl out.txt

run: default
	./cpsl testFile.cpsl

cpsl: flex
	g++ -o cpsl -std=c++11 logger.o lex.yy.c -ll

flex: cpsl.l
	flex cpsl.l

logger: 
	g++ -std=c++11 logger.h logger.cpp -c

clean:
	-rm cpsl
	-rm logger.o
	-rm logger.h.gch
	-rm lex.yy.c
	-rm out.txt