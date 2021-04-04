Para compilar os arquivos .l e y, em ambiente Linux:

 flex skylang.l
 bison -d -v skylang.y
 gcc lex.yy.c skylang.tab.c -o skylang


Infelizmente, a integração entre o arquivo .l e .y ainda não está completa.
