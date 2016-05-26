///////////////////////////////////////////////////////////
//  RxBuffer.h
//  Implementation of the Class RxBuffer
//  Created on:      2016/05/26 11:59:13
//  Original author: 037789
///////////////////////////////////////////////////////////

#if !defined(EA_18EF57CC_DC04_492c_817A_407FF5DA966C__INCLUDED_)
#define EA_18EF57CC_DC04_492c_817A_407FF5DA966C__INCLUDED_

class RxBuffer
{
private:
	uint8* p_buff;
	uint16 buff_size;
	uint16 read_itr;
	uint16 temp_read_itr;
	uint16 write_itr;
	uint16 tmp_write_itr;

public:
	RxBuffer(uint8* rv_buff, uint16 rv_size);
	virtual ~RxBuffer();

	void doStartRead();
	bool doRead(uint8* rv_character);
	void updateReadItr();
	bool doWrite(uint8 rv_character);

	inline uint16 get_buff_size();
	inline uint8* get_p_buff();
};

inline uint16 RxBuffer::get_buff_size(){
	return buff_size;
}

inline uint8* RxBuffer::get_p_buff(){
	return p_buff;
}
#endif // !defined(EA_18EF57CC_DC04_492c_817A_407FF5DA966C__INCLUDED_)
