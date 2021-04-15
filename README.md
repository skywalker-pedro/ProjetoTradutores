Para compilar os arquivos .l e .y, em ambiente Linux:


1 - flex skylang.l

2 - bison -d -v skylang.y

3 - gcc lex.yy.c skylang.tab.c -Wall -o skylang


Para executar o programa e realizar a análise dos arquivos de teste, digite o seguinte comando, também no terminal:

1- ./skylang

Por último, quando a mensagem ”Digite o nome do arquivo a ser analisado”
aparecer, digite o nome do arquivo de teste que deverá ser analisado e pressione a tecla ENTER. É necessário digitar a extensão do arquivo também, como exemplificado abaixo: 
1 - testeCorreto1.txt

