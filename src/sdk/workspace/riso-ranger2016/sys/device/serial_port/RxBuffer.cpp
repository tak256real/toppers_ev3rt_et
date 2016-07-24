///////////////////////////////////////////////////////////
//  RxBuffer.cpp
//  Implementation of the Class RxBuffer
//  Created on:      2016/05/26 11:59:13
//  Original author: 037789
///////////////////////////////////////////////////////////

#include "RxBuffer.h"


RxBuffer::RxBuffer(uint8* rv_buff, uint16 rv_size)
    : p_buff(rx_buff),
      buff_size(rv_size),
      read_itr(0),
      temp_read_itr(0),
      write_itr(0),
      temp_write_itr(0)
{
    for (uint16 i = 0; i < buff_size; i++) {
        p_buff[i] = 0;
    }
}



RxBuffer::~RxBuffer(){

}

void RxBuffer::doStartRead(){
	temp_read_itr = read_itr;
	temp_write_itr = write_itr;
}


bool RxBuffer::doRead(uint8* rv_character){
	if(temp_read_itr == temp_write_itr){
		// データ無し.
		return false;
	}
	else {
		// 受信データ 引き渡し.
		*rv_character = p_buff[temp_read_itr];

		temp_read_itr++;
		if(temp_read_itr >= buff_size){
			// リングバッファ的に.
			temp_read_itr -= buff_size;
		}
		return true;
	}
}

void RxBuffer::updateReadItr(){
	read_itr = temp_read_itr;
}


bool RxBuffer::doWrite(uint8 rv_character){

	uint16 at_itr = write_itr;

	// バッファに格納.
	p_buff[at_itr] = rv_character;

	at_itr++;
	
	if(at_itr >= buff_size) {
		at_itr -= buff_size;
	}

	if(at_itr == read_itr) {
		// 未格納データ無し.
		return false;
	}
	else {
		// イテレータ更新.
		write_itr = at_itr;
		return true;
	}
}
