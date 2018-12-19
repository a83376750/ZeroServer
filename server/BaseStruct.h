#pragma once

#include <google/protobuf/message.h>
#include "Header.h"

class UnitMessage
{
public:
	typedef google::protobuf::Message gMessage;
	enum
	{
		E_ARGV = 0x01,
		E_MSG = 0x02,
		E_SP_DATA = 0x03,
	};

	struct HeadMsg
	{
		HeadMsg() :msgNum_(0) {}
		size_t msgNum_;
	};

	struct SpData
	{
		SpData() :sData_(nullptr), len_(0) {}
		size_t len_;
		void *sData_;
	};

	union Data
	{
		void *argv_;
		gMessage *proto_msg_;
		SpData *special_data_;
	};

	void reset() { ZERO_MEMORY(this, sizeof(UnitMessage)); }

	void SetArgv(void *argv)
	{
		type_ = E_ARGV;
		body_.argv_ = argv;
	}

	void SetMsg(gMessage *msg)
	{
		type_ = E_MSG;
		body_.proto_msg_ = msg;
	}

	void SetSpData(void *d, size_t l)
	{
		type_ = E_SP_DATA;
		body_.special_data_->sData_ = d;
		body_.special_data_->len_ = l;
	}

	gMessage* GetMsg()
	{
		JUDGE_RETURN(type_ & E_MSG, nullptr);
		return body_.proto_msg_;
	}

	void* GetSpData()
	{
		JUDGE_RETURN(type_ & E_SP_DATA, nullptr);
		return body_.special_data_->sData_;
	}

	size_t GetSpDataLen()
	{
		JUDGE_RETURN(type_ & E_SP_DATA, 0);
		return body_.special_data_->len_;
	}

	size_t GetMsgNum() { return head_.msgNum_; }

private:
	uint8_t type_;
	HeadMsg head_;
	Data body_;
};
