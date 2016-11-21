yacc -d 4b.y
lex 4b.l
cc lex.yy.c y.tab.c -ll
./a.out
rm -rf lex.yy.c y.tab.c y.tab.h a.out
