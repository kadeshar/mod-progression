#include "Config.h"

#include "mod_progression.h"

void Progression::OnAfterConfigLoad(bool reload)
{
    if (reload)
        return;

    sProgression->SetPatchId(sConfigMgr->GetOption<uint32>("Progression.Patch", PATCH_ASSAULT_ON_THE_RUBY_SANCTUM));
    AuraId = sConfigMgr->GetOption<uint32>("Progression.IcecrownCitadel.Aura", 4);
    EnforceQuestInfo = sConfigMgr->GetOption<bool>("Progression.QuestInfo.Enforced", true);
    EnforceDungeonFinder = sConfigMgr->GetOption<bool>("Progression.DungeonFinder.Enforced", true);
    EnforceDualTalent = sConfigMgr->GetOption<bool>("Progression.DualTalent.Enforced", true);

    if (sProgression->GetPatchId() > PATCH_ASSAULT_ON_THE_RUBY_SANCTUM || sProgression->GetPatchId() < PATCH_WORLD_OF_WARCRAFT)
        sProgression->SetPatchId(PATCH_ASSAULT_ON_THE_RUBY_SANCTUM);

    if (sProgression->GetPatchId() < PATCH_BEFORE_THE_STORM)
    {
        sWorld->setIntConfig(CONFIG_EXPANSION, EXPANSION_CLASSIC);
        sWorld->setIntConfig(CONFIG_MAX_PLAYER_LEVEL, 60);
    }
    else if (sProgression->GetPatchId() < PATCH_ECHOES_OF_DOOM)
    {
        sWorld->setIntConfig(CONFIG_EXPANSION, EXPANSION_THE_BURNING_CRUSADE);
        sWorld->setIntConfig(CONFIG_MAX_PLAYER_LEVEL, 70);
    }
    else
    {
        sWorld->setIntConfig(CONFIG_EXPANSION, EXPANSION_WRATH_OF_THE_LICH_KING);
        sWorld->setIntConfig(CONFIG_MAX_PLAYER_LEVEL, 80);
    }

    sWorld->setBoolConfig(CONFIG_LOW_LEVEL_REGEN_BOOST, sProgression->GetPatchId() >= PATCH_FALL_OF_THE_LICH_KING);
    sWorld->setBoolConfig(CONFIG_QUEST_IGNORE_AUTO_ACCEPT, sProgression->GetPatchId() < PATCH_CALL_OF_THE_CRUSADE);
    if (EnforceDungeonFinder)
        sWorld->setIntConfig(CONFIG_LFG_OPTIONSMASK, 0);
    sWorld->setIntConfig(CONFIG_MIN_DUALSPEC_LEVEL, (sProgression->GetPatchId() < PATCH_SECRETS_OF_ULDUAR && EnforceDualTalent ? 255 : 40));
    sWorld->setBoolConfig(CONFIG_OBJECT_QUEST_MARKERS, sProgression->GetPatchId() >= PATCH_THE_GODS_OF_ZUL_AMAN);
    sWorld->setBoolConfig(CONFIG_OBJECT_SPARKLES, sProgression->GetPatchId() >= PATCH_THE_GODS_OF_ZUL_AMAN);
    sWorld->setBoolConfig(CONFIG_QUEST_POI_ENABLED, (sProgression->GetPatchId() >= PATCH_FALL_OF_THE_LICH_KING || !EnforceQuestInfo));
    sWorld->setBoolConfig(CONFIG_SET_BOP_ITEM_TRADEABLE, sProgression->GetPatchId() >= PATCH_CALL_OF_THE_CRUSADE);
    sWorld->setBoolConfig(CONFIG_WEATHER, sProgression->GetPatchId() >= PATCH_STORMS_OF_AZEROTH);
    sWorld->setIntConfig(CONFIG_WATER_BREATH_TIMER, (sProgression->GetPatchId() < PATCH_ECHOES_OF_DOOM ? 60000 : 180000));
    if (sProgression->GetPatchId() < PATCH_ECHOES_OF_DOOM)
        sWorld->setIntConfig(CONFIG_MAX_RECRUIT_A_FRIEND_BONUS_PLAYER_LEVEL, 0);
    sWorld->setIntConfig(CONFIG_WINTERGRASP_ENABLE, (sProgression->GetPatchId() < PATCH_ECHOES_OF_DOOM ? 2 : 1));
    sWorld->setBoolConfig(CONFIG_ARENA_SEASON_IN_PROGRESS, sProgression->GetPatchId() >= PATCH_BEFORE_THE_STORM);

    if (sProgression->GetPatchId() < PATCH_CALL_OF_THE_CRUSADE)
    {
        sWorld->setRate(RATE_XP_BG_KILL_AV, 0.0f);
        sWorld->setRate(RATE_XP_BG_KILL_WSG, 0.0f);
        sWorld->setRate(RATE_XP_BG_KILL_AB, 0.0f);
        sWorld->setRate(RATE_XP_BG_KILL_EOTS, 0.0f);
        sWorld->setRate(RATE_XP_BG_KILL_SOTA, 0.0f);
        sWorld->setRate(RATE_XP_BG_KILL_IC, 0.0f);
    }

    if (sProgression->GetPatchId() <= PATCH_BEFORE_THE_STORM)
    {
        sWorld->setIntConfig(CONFIG_ARENA_SEASON_ID, 1);
    }
    else if (sProgression->GetPatchId() < PATCH_THE_GODS_OF_ZUL_AMAN)
    {
        sWorld->setIntConfig(CONFIG_ARENA_SEASON_ID, 2);
    }
    else if (sProgression->GetPatchId() == PATCH_THE_GODS_OF_ZUL_AMAN)
    {
        sWorld->setIntConfig(CONFIG_ARENA_SEASON_ID, 3);
    }
    else if (sProgression->GetPatchId() == PATCH_FURY_OF_THE_SUNWELL)
    {
        sWorld->setIntConfig(CONFIG_ARENA_SEASON_ID, 4);
    }
    else if (sProgression->GetPatchId() == PATCH_ECHOES_OF_DOOM)
    {
        sWorld->setIntConfig(CONFIG_ARENA_SEASON_ID, 5);
    }
    else if (sProgression->GetPatchId() == PATCH_SECRETS_OF_ULDUAR)
    {
        sWorld->setIntConfig(CONFIG_ARENA_SEASON_ID, 6);
    }
    else if (sProgression->GetPatchId() == PATCH_CALL_OF_THE_CRUSADE)
    {
        sWorld->setIntConfig(CONFIG_ARENA_SEASON_ID, 7);
    }
    else if (sProgression->GetPatchId() >= PATCH_FALL_OF_THE_LICH_KING)
    {
        sWorld->setIntConfig(CONFIG_ARENA_SEASON_ID, 8);
    }

    if (sProgression->GetPatchId() < PATCH_ECHOES_OF_DOOM)
    {
        sWorld->setIntConfig(CONFIG_LEGACY_ARENA_POINTS_CALC, 1);
    }

    if (sProgression->GetPatchId() <= PATCH_BATTLEGROUNDS)
    {
        sWorld->setRate(RATE_HONOR, 0);
        sWorld->setRate(RATE_ARENA_POINTS, 0);
    }
    else if (sProgression->GetPatchId() < PATCH_FALL_OF_THE_LICH_KING)
    {
        sWorld->setRate(RATE_HONOR, 0.5f);
    }

    if (sProgression->GetPatchId() >= PATCH_ASSAULT_ON_THE_RUBY_SANCTUM)
    {
        if (AuraId > 0)
        {
            sWorld->setIntConfig(CONFIG_ICC_BUFF_ALLIANCE, SPELL_ICECROWN_CITADEL_30_A);
            sWorld->setIntConfig(CONFIG_ICC_BUFF_HORDE, SPELL_ICECROWN_CITADEL_30_H);
        }
        else
        {
            sWorld->setIntConfig(CONFIG_ICC_BUFF_ALLIANCE, SPELL_ICECROWN_CITADEL_25_A);
            sWorld->setIntConfig(CONFIG_ICC_BUFF_HORDE, SPELL_ICECROWN_CITADEL_25_H);
        }
    }
    else
    {
        if (AuraId > 3)
        {
            sWorld->setIntConfig(CONFIG_ICC_BUFF_ALLIANCE, SPELL_ICECROWN_CITADEL_20_A);
            sWorld->setIntConfig(CONFIG_ICC_BUFF_HORDE, SPELL_ICECROWN_CITADEL_20_H);
        }
        else if (AuraId > 2)
        {
            sWorld->setIntConfig(CONFIG_ICC_BUFF_ALLIANCE, SPELL_ICECROWN_CITADEL_15_A);
            sWorld->setIntConfig(CONFIG_ICC_BUFF_HORDE, SPELL_ICECROWN_CITADEL_15_H);
        }
        else if (AuraId > 1)
        {
            sWorld->setIntConfig(CONFIG_ICC_BUFF_ALLIANCE, SPELL_ICECROWN_CITADEL_10_A);
            sWorld->setIntConfig(CONFIG_ICC_BUFF_HORDE, SPELL_ICECROWN_CITADEL_10_H);
        }
        else if (AuraId > 0)
        {
            sWorld->setIntConfig(CONFIG_ICC_BUFF_HORDE, SPELL_ICECROWN_CITADEL_5_H);
            sWorld->setIntConfig(CONFIG_ICC_BUFF_ALLIANCE, SPELL_ICECROWN_CITADEL_5_A);
        }
        else
        {
            sWorld->setIntConfig(CONFIG_ICC_BUFF_HORDE, SPELL_ICECROWN_CITADEL_NONE);
            sWorld->setIntConfig(CONFIG_ICC_BUFF_ALLIANCE, SPELL_ICECROWN_CITADEL_NONE);
        }
    }
}
