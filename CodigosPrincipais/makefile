all: Principal/principal.o Cadastro/cadastro.o Captura/captura.o NovoJogo/novojogo.o
	gcc Principal/principal.o Cadastro/cadastro.o Captura/captura.o NovoJogo/novojogo.o -o main

Principal/principal.o: ./Principal/principal.c ./Cadastro/cadastroPokemon.h ./Captura/captura.h ./NovoJogo/novojogo.h ./Principal/verificaWinLinux.c
	gcc ./Principal/principal.c ./Principal/verificaWinLinux.c -o Principal/principal.o

Cadastro/cadastro.o: ./Cadastro/cadastroPokemon.c ./Cadastro/CriaVetorPokedex.c ./Cadastro/pesquisaTipoGen.c
	gcc ./Cadastro/cadastroPokemon.c ./Cadastro/CriaVetorPokedex.c ./Cadastro/pesquisaTipoGen.c -o Cadastro/cadastro.o

Captura/captura.o: ./Captura/gerenciaPokemon.c ./Captura/lugarDeCaptura.c ./Captura/salvaHD.c
	gcc ./Captura/gerenciaPokemon.c ./Captura/lugarDeCaptura.c ./Captura/salvaHD.c -o Captura/captura.o

NovoJogo/novojogo.o: ./NovoJogo/novojogo.c ./NovoJogo/allocJogo.c ./NovoJogo/mecanicasDeJogo.c
	gcc ./NovoJogo/novojogo.c ./NovoJogo/allocJogo.c ./NovoJogo/mecanicasDeJogo.c -o NovoJogo/novojogo.o

clean:
	rm -f *.o main

run:
	./all