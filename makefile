compile:
	flex skylang.l && bison -d -v skylang.y && gcc lex.yy.c skylang.tab.c -Wall -o skylang
	
testeCorreto1:
	echo testeCorreto1.txt| ./skylang
	
	
testeCorreto2:
	echo testeCorreto2.txt| ./skylang
	
	
testeErrado1:
	echo testeErro1.txt| ./skylang
	
testeErrado2:	
	echo testeErro1.txt| ./skylang
