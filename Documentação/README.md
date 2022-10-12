# Trabalho 1 de Sistemas Operacionais

O trabalho consiste em implementar o *rush* (rudimentary shell), ou seja, um interpretador de comandos.
 Será utilizada a linguagem C para a implementação.

 Referências externas ao mural da disciplina no final desse documento.

 ## Makefile

 Makefile é um arquivo que facilita e automatiza a compilação do código, sem precisar saber os diretórios e nem os comandos para a compilação.

 ### Como usar o Makefile?
 
 É bem simples usar o make, o deste projeto em específico tem 3 variações (comandos):
- `make` :    Somente compila o código
- `make run`:     Compila e roda o código automaticamente
- `make clean`:   Limpa os arquivos previamente compilados

> OBS: Se seu sistema não tiver o make é só instalar com `sudo apt install make`

 ## Referências

 - <a href = "https://stackoverflow.com/questions/298510/how-to-get-the-current-directory-in-a-c-program">Como colocar o path atual em uma variável.</a>
 - <a href = "https://www.ibm.com/docs/en/zos/2.3.0?topic=functions-waitpid-wait-specific-child-process-end">Referência da função wait(); </a>
 - <a href = "https://www.delftstack.com/pt/howto/c/execlp-in-c/">Referência e tutorial da função execlp(); </a>
 - <a href = "https://www.tutorialspoint.com/c_standard_library/c_function_strtok.htm#">Referência da função strtok()</a>
 - <a href = "https://www.youtube.com/watch?v=mj2VjcOXXs4">Vídeo sobre Argv e exec</a>