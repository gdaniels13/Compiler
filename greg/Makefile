default: clean bison lex output logger table cpsl

run: default
	./cpsl TestFile/expressions.cpsl default.asm
	java -jar ~/otherprograms/Mars4_4.jar default.asm

cpsl: 
	g++ -g -o cpsl -std=c++11 -g OutputFile.o table.o cpsl.tab.c logger.o  lex.yy.c  -ll

lex:
	flex cpsl.l

bison:
	bison -vd cpsl.y

logger: 
	g++ -g -std=c++11 logger.cpp -c

table:
	g++ -g -std=c++11 table.cpp -c

test: 
		./cpsl TestFiles/expressions.cpsl default.asm
		java -jar ~/otherprograms/Mars4_4.jar default.asm
output:
	g++ -g -c -std=c++11 OutputFile.cpp -c

debug:
	gdb -tui --args ./cpsl TestFiles/expressions.cpsl run

clean:
	-rm -rf *.asm
	-rm -rf out.txt
	-rm -rf cpsl
	-rm -rf cpsl.output
	-rm -rf logger.o
	-rm -rf lex.yy.c
	-rm -rf cpsl.tab.h
	-rm -rf cpsl.tab.c
	-rm -rf table.o
	-rm -rf Outputfile.o

tar: clean
	mkdir gregDaniels
	-cp * gregDaniels
	tar -cvf gregDaniels.tar *
	rm -r gregDaniels
