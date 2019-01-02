#pragma once
#include "nng.h"

namespace nn
{
	class socket
	{
	public:
		socket() = default;
		~socket() = default;

		void init()
		void bind(const char *addr);

	private:
		nng_socket s_;
	};
}

