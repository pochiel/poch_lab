#include "chatserver.hpp"

void chatserver::start_accept()
{
		// Enqueue Accept Handler
		accept_.async_accept(
						socket_,
						boost::bind( &chatserver::on_accept ,this, ++session_count) ) ;
}

void chatserver::on_accept(uint32_t session_id)
{ 
	printf("accept\n");
}
void chatserver::start_receive()
{
}
void chatserver::on_receive()
{
}
void chatserver::send_message()
{
}
