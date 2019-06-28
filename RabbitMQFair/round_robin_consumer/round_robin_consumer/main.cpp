#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <amqp.h>
#include <time.h>
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

	string name = (char *)argv[1];
	string delayStr = (char*)argv[2];
	//cout << "The delayStr is : " << delayStr << endl;
	int delay = std::stoi(delayStr);
	//cout << "The delay is : " << delay << endl;
	//string name = "one";
	//int delay = 1;

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
		exit(1);
	}

	amqp_channel_open(conn, 1);

	while(1){

		amqp_basic_get(conn, 1, amqp_cstring_bytes("test_work_queue"), 1);
		amqp_message_t *msg = new amqp_message_t;
		amqp_read_message(conn, 1, msg, 0);
		cout << "¡¾" << name << "¡¿ The result is : " << (char *)msg->body.bytes << endl;
		amqp_destroy_message(msg);
		delete msg;
		delay_msec(1000 * delay);
	}

	amqp_channel_close(conn, 1, AMQP_REPLY_SUCCESS);
	amqp_connection_close(conn, AMQP_REPLY_SUCCESS);

	getchar();
	return 0;
}