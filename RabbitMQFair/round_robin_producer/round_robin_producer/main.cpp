#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <time.h>
#include <amqp.h>
#include <windows.h>
#include <amqp_framing.h>
#include <amqp_tcp_socket.h>
using namespace std;

void delay_msec(int msec)
{ 
	clock_t now = clock();
	while(clock() - now < msec);
}

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

	int i = 0;
	while(1){

		string str = "Hello " + to_string(i);
		char message[64] = {'\0'};
		strcpy(message, str.c_str());
		amqp_bytes_t  message_bytes;
		message_bytes.len = sizeof(message);
		message_bytes.bytes = message;

		amqp_basic_publish(conn, 1, amqp_cstring_bytes(""), amqp_cstring_bytes("test_work_queue"), 0, 0, nullptr, message_bytes);

		cout << "send msg over!" << str << endl;
		i++;
		delay_msec(100);
		if(i == 10000)
			break;
	}

	amqp_channel_close(conn, 1, AMQP_REPLY_SUCCESS);
	amqp_connection_close(conn, AMQP_REPLY_SUCCESS);

	getchar();
	return 0;
}