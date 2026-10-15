
#ifndef IRECEIVER_H
#define IRECEIVER_H

#include <string>

class IReceiver 
{
public:
	virtual ~IReceiver() = default;
	virtual void send(const std::string& message) = 0;
	virtual bool hasMessage() const = 0;
	virtual std::string receive() = 0;
};

#endif
