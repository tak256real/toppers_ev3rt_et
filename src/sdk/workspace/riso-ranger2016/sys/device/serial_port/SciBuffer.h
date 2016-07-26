///////////////////////////////////////////////////////////
//  SciBuffer.h
//  Implementation of the Class SciBuffer
//  Created on:      2016/07/25 11:37:58
//  Original author: 037789
///////////////////////////////////////////////////////////

#if !defined(EA_B8FFC425_E5DD_4902_8F39_648C0C6CAF86__INCLUDED_)
#define EA_B8FFC425_E5DD_4902_8F39_648C0C6CAF86__INCLUDED_

class SciBuffer
{

public:
	SciBuffer();
	virtual ~SciBuffer();

	inline uint16 get_buff_size();
	inline uint8* get_p_buff();

    virtual void doStartWrite();
    virtual void doStartRead();
    virtual bool doWrite(uint8 rv_character);
    virtual bool doRead(uint8* rv_character);
    virtual void updateWriteItr();
    virtual void updateReadItr();

protected:
	uint8* p_buff;
	uint16 buff_size;
	uint16 read_itr;
	uint16 temp_read_itr;
	uint16 write_itr;
	uint16 tmp_write_itr;



};

inline uint16 SciBuffer::get_buff_size(){
	return buff_size;
}

inline uint8* SciBuffer::get_p_buff(){
	return p_buff;
}

#endif // !defined(EA_B8FFC425_E5DD_4902_8F39_648C0C6CAF86__INCLUDED_)
