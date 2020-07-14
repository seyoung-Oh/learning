#pragma once
#include "Stage.h"
class CStagenormal :
	public CStage
{
public:
	CStagenormal();
	~CStagenormal();


public:
	virtual bool Init();
	virtual void Run();
};

