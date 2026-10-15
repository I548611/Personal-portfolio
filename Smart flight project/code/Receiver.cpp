#include "Receiver.h"
#include <utility>

void Receiver::send(const std::string& message) 
{
	messages.push(message);
}

bool Receiver::hasMessage() const 
{
	return !messages.empty();
}

std::string Receiver::receive() 
{
	if (messages.empty()) return std::string();
	std::string m = messages.front();
	messages.pop();
	return m;
}
