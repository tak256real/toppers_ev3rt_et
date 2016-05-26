///////////////////////////////////////////////////////////
//  TxBuffer.h
//  Implementation of the Class TxBuffer
//  Created on:      2016/05/26 11:59:19
//  Original author: 037789
///////////////////////////////////////////////////////////

#if !defined(EA_872CB182_F961_4123_9112_E6D8CE43914D__INCLUDED_)
#define EA_872CB182_F961_4123_9112_E6D8CE43914D__INCLUDED_

class TxBuffer
{
private:
	uint8* p_buff;
	uint16 buff_size;
	uint16 read_itr;
	uint16 temp_read_itr;
	uint16 write_itr;
	uint16 tmp_write_itr;

public:
	TxBuffer(uint8* rv_buff, uint16 rv_size);
	virtual ~TxBuffer();

	void doStartWrite();
	bool doWrite(uint8 rv_data);
	void updateWriteItr();
	void doStartRead();
	uint8 doRead();
	void updateReadItr();

    inline uint16 get_buff_size()

};

inline uint16 TxBuffer::get_buff_size(){
	return buff_size;
}

#endif // !defined(EA_872CB182_F961_4123_9112_E6D8CE43914D__INCLUDED_)
