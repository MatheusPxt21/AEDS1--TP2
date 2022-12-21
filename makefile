all:
	gcc main.c Headers/ARRANJO.h Sources/ARRANJO.c Headers/Funcoes.h Sources/Funcoes.c Headers/ADJACENCIAS.h Sources/ADJACENCIAS.c

Linux:
	./a.out
Windows:
	./a.exe