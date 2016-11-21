yacc -d 4a.y
lex 4a.l
cc lex.yy.c y.tab.c -ll
./a.out
rm -rf lex.yy.c y.tab.c y.tab.h a.out
