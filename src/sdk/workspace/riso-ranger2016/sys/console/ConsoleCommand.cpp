///////////////////////////////////////////////////////////
//  ConsoleCommand.cpp
//  Implementation of the Class ConsoleCommand
//  Created on:      2016/07/25 9:12:49
//  Original author: 037789
///////////////////////////////////////////////////////////

#include "ConsoleCommand.h"


// -----------------------------------------------
//! @struct T_ComFuncTbl
//! @brief  コンソール用コマンド/関数テーブル用構造体.
//!
//! コマンドと、コマンドに対応する実行関数を設定するためのテーブル構造体.
// -----------------------------------------------
typedef struct {
	uint8* command;		//!< コマンド文字列の先頭アドレス.
	void (*func)(void);		//!< コマンドに対応する実行関数.
} T_ComFuncTbl;

const T_ComFuncTbl c_command_tbl[] = {
    {"s", ConsoleCommand::startCommand}, // ヘルプコマンド.
    {"h", ConsoleCommand::dispHelpCommand}, // ヘルプコマンド.

    {"-", ConsoleCommand::cmdInvalid} // 無効なコマンド、終端.
};

ConsoleCommand::ConsoleCommand(){

}



ConsoleCommand::~ConsoleCommand(){

}



void ConsoleCommand::dispHelpCommand(){

}



void ConsoleCommand::startCommand(){

}



void ConsoleCommand::cmdInvalid(){

}
