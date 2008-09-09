#include "Servidor.h"

#include "ServerSocket.h"

Servidor::Servidor()
{

}

Servidor::~Servidor()
{

}

unsigned short int
Servidor::iniciaServidor(unsigned int _porta = 6666)
{
    std::cout << "Iniciando servidor..." << std::endl;

    try
    {
        ServerSocket
        socketServidor(_porta);

        while (true)
        {
            ServerSocket
            socketTransmissao;

            socketServidor.accept(socketTransmissao);

            try
            {
                while (true)
                {
                    std::string
                    dados;

                    socketTransmissao >> dados;

                    if ("NICK" == dados)
                    {

                    }

                    if ("INICIA_JOGO" == dados)
                    {
                        socketTransmissao << "OK";
                        socketTransmissao >> dados;
                        std::cout << "data: " << dados << std::endl;
                    }

                    if ("ATAQUE" == dados)
                    {

                    }

                    if ("MOVE_EXERCITOS" == dados)
                    {

                    }

                    if ("MENSAGEM" == dados)
                    {

                    }

                    if ("MENSAGEM_MULTICAST" == dados)
                    {

                    }

                    if ("PASSA_TURNO" == dados)
                    {

                    }

                    if ("GET_STATUS" == dados)
                    {

                    }
                }
            }
            catch (SocketException&)
            {

            }
        }
    }
    catch (SocketException& excessao)
    {
        std::cout << "(Servidor::iniciaServidor) Excessao lançada: " << excessao.description() << std::endl;

        return 1;
    }

    return 0;
}

unsigned short int
Servidor::iniciaJogo()
{

}

unsigned short int
Servidor::finalizaJogo()
{

}

unsigned short int
Servidor::finalizaTurno()
{

}

unsigned short int
Servidor::atualizaJogo()
{

}

unsigned short int
Servidor::defineJogadorCorrente()
{

}

unsigned short int
Servidor::enviaMensagem()
{

}

unsigned short int
Servidor::enviaMensagemMultiCast()
{

}

unsigned short int
Servidor::distribuiExercito()
{

}

unsigned short int
Servidor::distribuiExercitoMultiCast()
{

}

static unsigned short int
escutaPorConexoes()
{

}

static unsigned short int
enviaPacote()
{

}

