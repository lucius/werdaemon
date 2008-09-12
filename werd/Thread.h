#ifndef THREAD_H_
#define THREAD_H_

#include <pthread.h>

class
Thread
{
	public:
		Thread();
	
		virtual
		~Thread();
		
		bool
		inicia(void*);
		
		bool
		para(bool);
		
		bool
		esperaTermino();
		
	protected:
		int
		roda(void*);
		
		static void*
		pontoDeAcesso(void*);
		
		virtual void*
		configura();
		
		virtual void*
		executa(void*);

		pthread_t
		getID();
		
//		void*
//		getArgumentos() const;
//		
//		void
//		setArgumentos(void*);
//		
	private:
		pthread_t
		id_thread;
		
		void*
		argumentos;
};

#endif
