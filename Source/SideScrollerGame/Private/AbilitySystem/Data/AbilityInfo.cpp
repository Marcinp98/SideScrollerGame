// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Data/AbilityInfo.h"
#include "MainLogChannels.h"

FMainAbilityInfo UAbilityInfo::FindAbilityInfoForTag(const FGameplayTag& AbilityTag, bool bLogNotFound) const
{
	for (const FMainAbilityInfo& Info : AbilityInformation)
	{
		if (Info.AbilityTag == AbilityTag)
		{
			return Info;
		}
	}
	if (bLogNotFound)
	{
		UE_LOG(MainLog, Error, TEXT("Can't find info for AbilityTag [%s] on Abilityinfo [%s]"), *AbilityTag.ToString(), *GetNameSafe(this));
	}

	return FMainAbilityInfo();
}
