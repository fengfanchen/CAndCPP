#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <amqp.h>
#include <amqp_framing.h>
#include <amqp_tcp_socket.h>
using namespace std;


int main(int *argc, int *argv[]){

	string hostName = "127.0.0.1";
	int port = 5672;
	amqp_socket_t *socket = nullptr;
	amqp_connection_state_t conn;

	conn = amqp_new_connection();
	socket = amqp_tcp_socket_new(conn);

	if(!socket){

		cout << "create socket failed!";
		exit(1);
	}

	if(amqp_socket_open(socket, hostName.c_str(), port)){

		cout << "opening TCP socket failed" << endl;
		exit(1);
	}

	//µÇÂ¼
	if(1 != amqp_login(conn, "/vhost_cff", 0, 131072, 0, AMQP_SASL_METHOD_PLAIN, "cff", "123").reply_type){

		cout << "login failed" << endl;
	}
	
	//¹ÜµÀ

	amqp_channel_open(conn, 1);

	while(1){

		char message[64] = {'\0'};
		cout << "please input the msg: ";
		cin.getline(message, sizeof(message));
		amqp_bytes_t  message_bytes;
		message_bytes.len = sizeof(message);
		message_bytes.bytes = message;

		amqp_basic_publish(conn, 1, amqp_cstring_bytes(""), amqp_cstring_bytes("test_simple_queue"), 0, 0, nullptr, message_bytes);

		cout << "send msg over!" << endl;
	}

	getchar();
	return 0;
}