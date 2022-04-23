#include "UdpSocket.h"

UdpSocket::UdpSocket()
{
}

UdpSocket::~UdpSocket()
{
}

void UdpSocket::Send(OutputMemoryStream* _out, Status& _status, IpAddress _address, unsigned int _port)
{
	_status = (Status)(int)sock.send(_out->GetBufferPtr(), _out->GetLength(), *_address.GetAddress(), _port);
}

InputMemoryStream* UdpSocket::Receive(Status& _status, IpAddress _address, unsigned int _port)
{
	void* bufferChar;
	size_t size = 2000;
	size_t received;
	InputMemoryStream* input = new InputMemoryStream((char*)bufferChar, size);

	_status = (Status)(int)sock.receive(bufferChar, size, received, *_address.GetAddress(), _port);
	sock.receive(bufferChar, size, received, *_address.GetAddress(), _port);

	return input;
}

void UdpSocket::Bind(unsigned int _port, Status& _status)
{
	_status = (Status)((int)sock.bind(_port));
}

void UdpSocket::Unbind()
{
	sock.unbind();
}