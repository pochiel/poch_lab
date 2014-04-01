#ifndef __CHATSERVER_HPP_
#define __CHATSERVER_HPP_
#include <stdint.h>
#include <boost/asio.hpp>
#include <boost/bind.hpp>

class chatserver
{
		private:
				boost::asio::io_service & io_ ;
				boost::asio::ip::tcp::acceptor accept_ ;
				boost::asio::streambuf buf ;
				boost::asio::ip::tcp::socket socket_ ;
				uint32_t session_count;
		public:
				chatserver(boost::asio::io_service & io , uint32_t port ) : session_count(0),io_(io),accept_(io,boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(),port)),socket_(io){}
				void start_accept();
				void on_accept(uint32_t session_id);
				void start_receive();
				void on_receive();
				void send_message();
};

#endif //__CHATSERVER_HPP_
