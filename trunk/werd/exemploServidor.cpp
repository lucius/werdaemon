#include "ServerSocket.h"
#include "SocketException.h"
#include <iostream>
#include <string>

int
fazServidor()
{
    std::cout << "Rodando..." << std::endl;

    try
    {
        ServerSocket server ( 6666 );

        while ( true )
        {
            ServerSocket new_sock;
            server.accept ( new_sock );

            try
            {
                std::string
                data;

                while ( true )
                {
                    std::string
                    data;

                    new_sock >> data;

                    if (data == "INICIO")
                    {
                        new_sock << "OK";
                        new_sock >> data;
                        std::cout << "data: " << data << std::endl;
                    }
                }

            }
            catch ( SocketException& )
            {

            }
        }
    }
    catch ( SocketException& e )
    {
        std::cout << "Excessao lancada: " << e.description() << std::endl;
    }

    return 0;
}
