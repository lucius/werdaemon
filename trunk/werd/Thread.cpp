#include "Thread.h"

#include <iostream>
#include <pthread.h>
#include <signal.h>

Thread::Thread()
{

}

Thread::~Thread()
{

}

bool
Thread::inicia(void* _argumentos)
{
	this->argumentos = _argumentos;

	return !((bool) pthread_create(&(this->id_thread), NULL, Thread::pontoDeAcesso, (void*) this));
}

bool
Thread::inicia()
{
    this->inicia(NULL);
}

bool
Thread::para(bool _matar_a_thread = false)
{
	if (_matar_a_thread)
	{
		return !((bool) pthread_kill(this->id_thread, 9));
	}

	return !((bool) pthread_cancel(this->id_thread));
}

bool
Thread::esperaTermino()
{
	std::cout << "(Thread::esperaTermino) Thread " << this->id_thread << ". Aguardando o término da execução da thread " << this->id_thread << std::endl;

	return !((bool) pthread_join(this->id_thread, NULL));
}

int
Thread::roda(void* _argumentos)
{
	this->configura();
	return ((int) this->executa(_argumentos));
}

void*
Thread::pontoDeAcesso(void* _this)
{
    Thread*
    thread = (Thread*) _this;

    std::cout << "(Thread::pontoDeAcesso) Thread " << thread->getID() << ". Iniciando a execução em thread." << std::endl;

    return ((void*) thread->roda(thread->argumentos));
}

pthread_t
Thread::getID()
{
	return this->id_thread;
}
