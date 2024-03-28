// Fill out your copyright notice in the Description page of Project Settings.


#include "Interfaces/TargetInterface.h"

// Add default functionality here for any ITargetInterface functions that are not pure virtual.

AActor* ITargetInterface::InTargetRadius()
{
	return nullptr;
}

AActor* ITargetInterface::OutsideTargetRadius()
{
	return nullptr;
}

void ITargetInterface::ShowEquipUI()
{
}

void ITargetInterface::HideEquipUI()
{
}
