///////////////////////////////////////////////////////////
//  ConsoleCommand.h
//  Implementation of the Class ConsoleCommand
//  Created on:      2016/07/25 9:12:48
//  Original author: 037789
///////////////////////////////////////////////////////////

#if !defined(EA_06738393_BF53_4928_9861_94AB49C4A838__INCLUDED_)
#define EA_06738393_BF53_4928_9861_94AB49C4A838__INCLUDED_

class ConsoleCommand
{

public:
	ConsoleCommand();
	virtual ~ConsoleCommand();
	static void dispHelpCommand();
	static void startCommand();
	static void cmdInvalid();

};
#endif // !defined(EA_06738393_BF53_4928_9861_94AB49C4A838__INCLUDED_)
