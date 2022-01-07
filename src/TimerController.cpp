//----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "TimerController.h"

namespace Azul
{
	TimerController::TimerController(AnimTime Delta, AnimTime Min, AnimTime Max)
		: tCurr(AnimTime::Duration::ZERO),
		tDelta(Delta),
		tMax(Max),
		tMin(Min),
		bReverse(false)
	{
	}

	void TimerController::Update()
	{
		//Reverse animation
		if(bReverse) tCurr -= tDelta;
		else tCurr += tDelta;

		// protection for time values for looping
		if (tCurr < tMin)
		{
			tCurr = tMax;
		}
		else if (tCurr > tMax)
		{
			tCurr = tMin;
		}
		else
		{
			// do nothing
		}
	}

	void TimerController::SetCurrTime(const AnimTime time)
	{
		this->tCurr = time;
	}

	AnimTime TimerController::GetCurrTime() const
	{
		return this->tCurr;
	}

	void TimerController::SetDeltaTime(const AnimTime time)
	{
		this->tDelta = time;
	}

	AnimTime TimerController::GetDeltaTime() const
	{
		return this->tDelta;
	}

	void TimerController::SetMaxTime(const AnimTime time)
	{
		this->tMax = time;
	}

	AnimTime TimerController::GetMaxTime() const
	{
		return this->tMax;
	}

	void TimerController::SetMinTime(const AnimTime time)
	{
		this->tMin = time;
	}

	AnimTime TimerController::GetMinTime() const
	{
		return this->tMin;
	}

	void TimerController::Forward()
	{
		this->bReverse = false;
	}

	void TimerController::Reverse()
	{
		this->bReverse =true;
	}
}

// --- End of File ---