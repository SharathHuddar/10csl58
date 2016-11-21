yacc -d 5b.y
lex 5b.l
cc lex.yy.c y.tab.c -ll
./a.out
rm -rf lex.yy.c y.tab.c y.tab.h a.out
