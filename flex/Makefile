default: logger cpsl


log: default
	./cpsl testFile.cpsl > ./out.txt
	subl out.txt

run: default
	echo "factorial"
	./cpsl factorial.cpsl
	echo "personnel"
	./cpsl personnel.cpsl
	echo "expressions"
	./cpsl expressions.cpsl


cpsl: flex bison
	g++ -o cpsl -std=c++11 logger.o lex.yy.c cpsl.tab.c -ll

flex: cpsl.l
	flex cpsl.l

logger: 
	g++ -std=c++11 logger.h logger.cpp -c


bison:
	bison -d -v -W'all' cpsl.y



clean:
	-rm cpsl
	-rm logger.o
	-rm logger.h.gch
	-rm lex.yy.c
	-rm out.txt
	-rm gregDaniels.tar


tar: clean
	mkdir gregDaniels
	-cp * gregDaniels
	tar -cvf gregDaniels.tar *
	rm -r gregDaniels
