yacc -d 6.y
lex 6.l
cc lex.yy.c y.tab.c -ll
./a.out
rm -rf lex.yy.c y.tab.c y.tab.h a.out
