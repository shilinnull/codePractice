#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:4996) //vs�ᱨһ���������������ε��������
#include<iostream>
#include<string>
#include<cstring>
#include<thread>
#include<WinSock2.h>

#pragma comment(lib,"ws2_32.lib")

using namespace std;

//������ip,�˿�
const string serverip = "113.44.240.190";
uint16_t serverport = 8080;

int main()
{
	WSAData wsd;//��ʼ����Ϣ

	//����Winsock
	if (WSAStartup(MAKEWORD(2, 2), &wsd) != 0) {/*����WinSocket�ĳ�ʼ��,
		windows ��ʼ��socket����⣬����2, 2�İ汾��windows socket��̱����ȳ�ʼ����*/
		cout << "WSAStartup Error = " << WSAGetLastError() << endl;
		return 0;
	}
	else {
		cout << "WSAStartup Success" << endl;
	}

	//1.�����׽���
	SOCKET sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	if (sockfd == SOCKET_ERROR) {
		cout << "socket Error = " << WSAGetLastError() << endl;
		return 1;
	}
	else {
		cout << "socket Success" << endl;
	}

	//��������Ϣ���߳�
	thread t1([&]()
		{
			char buffer[1024];
			while (true)
			{
				struct sockaddr_in peer;
				int len = sizeof(peer);
				int n = recvfrom(sockfd, buffer, sizeof(buffer) - 1, 0, (struct sockaddr*)&peer, &len);
				if (n > 0)
				{
					buffer[n] = 0;
					cout << "server reponose: " << buffer << endl;
				}
				else break;

			}
		}
	);

	//��
	struct sockaddr_in server;
	memset(&server, 0, sizeof(server));
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = inet_addr(serverip.c_str());
	server.sin_port = htons(serverport);

	string msg;

	while (true)
	{
		cout << "Please Enter# ";
		getline(cin, msg);
		int n = sendto(sockfd, msg.c_str(), msg.size(), 0, (struct sockaddr*)&server, sizeof(server));
		if (n < 0)
		{
			cerr << "sendto error!" << endl;
			break;
		}
	}

	//����
	closesocket(sockfd);
	WSACleanup();

	return 0;
}