#ifndef WER_H_
#define WER_H_

#include "Controlador.h"
#include "Dado.h"
#include "Jogador.h"
#include "Territorio.h"


class Wer
{
	public:

		Wer();

		~Wer();

        void
        atacar(Territorio*, Territorio*);

        void
        contagemExercitos();

        unsigned short int
        contagemTerritorios();

        void
        distribuirTerritorios();

        void
        fimDoJogo();

        unsigned short int
        getQuantidadeExercitos();

        void
		jogo();

        void
        moverExercitos(Territorio*, Territorio*, unsigned short int);

		bool
		objetivoCumprido();

		unsigned short int
		rolarDado();

        void
        turno();

        void
        teste();

	protected:

	private:
		Controlador
		controlador;

		Dado
		dado;

		unsigned short int
		quantidadeExercitos;
};
#endif
