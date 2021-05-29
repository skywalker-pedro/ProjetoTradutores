Para as gerações futuras dos alunos de Tradures da UnB: Boa sorte.




Para compilar os arquivos .l e .y, em ambiente Linux:


1 - flex skylang.l

2 - bison -d -v skylang.y

3 - gcc lex.yy.c skylang.tab.c -Wall -o skylang


Para executar o programa e realizar a análise dos arquivos de teste, digite o seguinte comando, também no terminal:

1- echo testeCorreto1.txt | ./skylang

Alternativamente, pode-se utilizar o comando make compile para realizar a compilação e os comandos make testeCorreto1, make testeCorreto2, make testeErrado1 e make testeErrado2 para 
executar os testes.
