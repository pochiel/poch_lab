#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include "test.pb.h"
#include "chatserver.hpp"

int main()
{
	p2pchat::chatMessage msg;
	boost::asio::io_service io;
	chatserver * serv = new chatserver( io , 50000 );

	serv->start_accept();

	io.run();

	msg.set_name("pochiel");
	msg.set_message("hello world\n");

	return 0;
}
