///////////////////////////////////////////////////////////
//  system_task.h
//  Implementation of the Class system_task
//  Created on:      2016/04/28 11:21:26
//  Original author: 037789
///////////////////////////////////////////////////////////

#if !defined(EA_B0DE3A01_003D_4139_ABC8_D1E1FF53B040__INCLUDED_)
#define EA_B0DE3A01_003D_4139_ABC8_D1E1FF53B040__INCLUDED_


typedef enum _EmTaskId{
    kTaskMain,
    kTaskHighPriority,
    kTaskEngine,
    kTaskDebugConsole,

    kMaxTaskId
} EmTaskId;

#ifdef __cplusplus
extern "C" {
#endif

// -----------------------------------------------------------------------------
//! @brief main タスク
//!
//! 電源 ON 時カーネルが自動的に起動をかけるタスク.
//! 主な責務は以下.
//!   - 他のタスクを起動する
//!   - ハートビート、ウォッチドッグなどの軽い定常処理.
//! @exception none
// -----------------------------------------------------------------------------
extern void TaskMain();

extern void TaskHighPriority();

extern void TaskEngine();

extern void TaskDebugConsole();

#if 0                       // 未実装.
extern void TaskCommunication();

extern void TaskLongTermOperation();

extern void TaskShortCycleOperation();

#endif


#ifdef __cplusplus
}
#endif


#ifdef __cplusplus
class system_task
{

public:
	system_task();
	virtual ~system_task();

};
#endif //#ifdef __cplusplus
#endif // !defined(EA_B0DE3A01_003D_4139_ABC8_D1E1FF53B040__INCLUDED_)
