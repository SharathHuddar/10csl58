yacc -d 5a.y
lex 5a.l
cc lex.yy.c y.tab.c -ll
./a.out
rm -rf lex.yy.c y.tab.c y.tab.h a.out
