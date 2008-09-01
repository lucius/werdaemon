#ifndef WER_H_
#define WER_H_

#include "Controlador.h"
#include "Territorio.h"
#include "Jogador.h"

class Wer
{
	public:

		Wer();

		~Wer();

		void
		jogo();

		void
		distribuirTerritorios();

		void
		contagemExercitos();

		unsigned short int
		getQuantidadeExercitos();

		bool
		objetivoCumprido();

		void
		turno();

		void
		fimDoJogo();

		void
		atacar(Territorio*, Territorio*);

		void
		moverExercitos(Territorio*, Territorio*, unsigned short int);

		unsigned short int
		rolarDado();

	protected:

	private:
		Controlador
		controlador;

		unsigned short int
		quantidadeExercitos;
};
#endif /*WER_H_*/
