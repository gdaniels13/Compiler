all: begin 

begin: lex
	g++ lex.yy.c -o cpsl
lex:
	flex analyzer.lex
run: all
	./cpsl testFile.cpsl
test: all
	./cpsl testFile.cpsl -v
clean:
	rm lex.yy.c
	rm cpsl