#ifndef THREAD_H_
#define THREAD_H_

#include <pthread.h>

class
Thread
{
	public:
        bool
        inicia();

		bool
		inicia(void*);

		// @ TODO Testar
		bool
		para(bool);

		bool
		esperaTermino();

        pthread_t
        getID();

	protected:
        Thread();

        virtual
        ~Thread();

		int
		roda(void*);

		static void*
		pontoDeAcesso(void*);

		virtual void*
		configura()    = 0;

		virtual void*
		executa(void*) = 0;

	private:
		pthread_t
		id_thread;

		void*
		argumentos;
};

#endif
