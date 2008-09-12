#include "Cliente.h"

#include <iostream>
#include "ClientSocket.h"
#include "SocketException.h"

Cliente::Cliente()
{

}

Cliente::~Cliente()
{

}

unsigned short int
Cliente::iniciaClienteServidor(std::string _ip, unsigned int _porta)
{
    try
    {
        ClientSocket
        client_socket (_ip, _porta);

        std::string
        resposta;

        try
        {
            client_socket << "INICIO";
            client_socket >> resposta;
        }
        catch ( SocketException& e )
        {
            std::cout << "Excessao lancada: " << e.description() << std::endl;
        }

        std::cout << "Resposta recebida do servidor servidor: " << resposta << std::endl;

        if (resposta == "OK")
        {
            std::cout << "Protocolo aceito... Enviando dados da operacao..." << std::endl;
            client_socket << "DADOS_OPERACAO";
        }
    }
    catch ( SocketException& e )
    {
        std::cout << "Excessão lançada: " << e.description() << std::endl;
    }




    std::string
    dados;

    if ("INICIO_DE_JOGO" == dados)
    {

    }

    else if ("FIM_DE_JOGO" == dados)
    {

    }

    else if ("FIM_DE_TURNO" == dados)
    {

    }

    else if ("STATUS_DO_JOGO" == dados)
    {

    }

    else if ("RECEBE_EXERCITOS" == dados)
    {

    }

    else if ("PERDE_EXERCITOS" == dados)
    {

    }

    else if ("RECEBE_TERRITORIOS" == dados)
    {

    }

    else if ("PERDE_TERRITORIOS" == dados)
    {

    }

    else if ("MENSAGEM" == dados)
    {

    }

    else if ("RECEBE_KICK" == dados)
    {

    }

    else if ("SUCESSO" == dados)
    {

    }

    else if ("FALHA" == dados)
    {

    }

    else
    {
        std::cout << "(Cliente::iniciaClienteServidor) Atenção: Pacote desconhecido recebido..." << std::endl;
    }
}
