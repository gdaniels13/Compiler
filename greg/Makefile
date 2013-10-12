default: clear logger.o  cpsl

clear:
	clear
	clear

# run: default
# 	echo "factorial"
# 	./cpsl factorial.cpsl
# 	echo "personnel"
# 	./cpsl personnel.cpsl
# 	echo "expressions"
# 	./cpsl expressions.cpsl


cpsl: bison flex SymbolTable.o Table.o Symbols.o
	g++ -o  cpsl -std=c++11 -g logger.o Symbols.o  Table.o SymbolTable.o lex.yy.c cpsl.tab.c -ll

flex: cpsl.l
	flex cpsl.l

logger.o: logger.cpp logger.h
	g++  -g -std=c++11 logger.cpp -c


bison:
	bison -d -v -W'all' cpsl.y

Symbols.o: Symbols.cpp Symbols.h
	g++ -g -std=c++11 Symbols.cpp -c

Table.o: Table.cpp Table.h
	g++ -g -std=c++11 Table.cpp  -c

SymbolTable.o: SymbolTable.cpp SymbolTable.h
	g++ -g -std=c++11 SymbolTable.cpp -c


smallTest: Symbols.o Table.o  SymbolTable.o test.cpp logger.o test.cpp
	g++ -o cpsl -std=c++11 -g logger.o Symbols.o  Table.o SymbolTable.o test.cpp -ll

clean:
	-rm cpsl
	-rm *.o
	-rm lex.yy.c
	-rm out.txt
	-rm gregDaniels.tar
	-rm cpsl.tab.*
	-rm cpsl.output

tar: clean
	mkdir gregDaniels
	-cp * gregDaniels
	tar -cvf gregDaniels.tar *
	rm -r gregDaniels
