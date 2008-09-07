//#include "ClientSocket.h"
//#include "SocketException.h"
//#include <iostream>
//#include <string>
//
//unsigned short int
//criaCliente()
//{
//    try
//    {
//        ClientSocket client_socket ( "localhost", 6666 );
//
//        std::string
//        resposta;
//
//        try
//        {
//            client_socket << "INICIO";
//            client_socket >> resposta;
//        }
//        catch ( SocketException& e )
//        {
//            std::cout << "Excessao lancada: " << e.description() << std::endl;
//        }
//
//        std::cout << "Resposta recebida do servidor servidor: " << resposta << std::endl;
//
//        if (resposta == "OK")
//        {
//            std::cout << "Protocolo aceito... Enviando dados da operacao..." << std::endl;
//            client_socket << "DADOS_OPERACAO";
//        }
//    }
//    catch ( SocketException& e )
//    {
//        std::cout << "Excessão lançada: " << e.description() << std::endl;
//    }
//
//  return 0;
//}
//
//unsigned short int
//criaServidor()
//{
//
//}
//
//unsigned short int
//conectaNoServidor()
//{
//
//}
//
//unsigned short int
//enviaMensagem()
//{
//
//}
//
//unsigned short int
//moveExercito()
//{
//
//}
//
//unsigned short int
//ataca()
//{
//
//}
//
//unsigned short int
//passaTurno()
//{
//
//}
