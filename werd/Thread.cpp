#include "Thread.h"

#include <pthread.h>
#include <signal.h>

Thread::Thread()
{
	
}

Thread::~Thread()
{
	
}

bool
Thread::inicia(void* _argumentos = NULL)
{
	this->argumentos = _argumentos;
	
	return (bool) pthread_create(&(this->id_thread), NULL, Thread::pontoDeAcesso, (void*) this);
}

bool
Thread::para(bool _matar_a_thread = false)
{
	if (_matar_a_thread)
	{
		return !pthread_kill(this->id_thread, 9);
	}
	
	return !pthread_cancel(this->id_thread);
}

bool
Thread::esperaTermino()
{
	int*
	resultado;
	
	pthread_join(this->id_thread, ((void**) &resultado));
	
	return !(*resultado);
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

//    return ((void*) thread->roda(thread->getArgumentos()));
    return ((void*) thread->roda(thread->argumentos));
}

void*
Thread::configura()
{
	return NULL;
}

void*
Thread::executa(void* _argumentos)
{
	return NULL;
}

pthread_t
Thread::getID()
{
	return this->id_thread;
}

//void*
//Thread::getArgumentos() const
//{
//	return this->argumentos;
//}
//
//void
//Thread::setArgumentos(void* _argumentos)
//{
//	this->argumentos = _argumentos;
//}
