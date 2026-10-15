#ifndef RECEIVER_H
#define RECEIVER_H

#include "IReceiver.h"
#include <queue>
#include <string>

class Receiver : public IReceiver 
{
public:
	Receiver() = default;
	void send(const std::string& message) override;
	bool hasMessage() const override;
	std::string receive() override;

private:
	std::queue<std::string> messages;
};

#endif
