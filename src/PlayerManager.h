/* =========================================
			
		FCNPC - Fully Controllable NPC
			----------------------

	- File: PlayerManager.h
	- Author(s): OrMisicL

  =========================================*/

#ifndef PLAYERMANAGER_H
#define PLAYERMANAGER_H

#include "CPlayerData.h"

class CPlayerManager
{
	public:
		CPlayerManager();
		~CPlayerManager();

		bool IsPlayerConnectedEx(WORD playerId)
		{
			if (playerId > MAX_PLAYERS || playerId < 0)
				return false;
			else
				return m_bConnected[playerId];
		};
		inline CPlayerData *GetAt(WORD playerId) { return m_pPlayerData[playerId]; };
		bool SetupPlayer(WORD playerId);
		
		WORD AddPlayer(char *szName);
		bool DeletePlayer(WORD playerId);

		void Process();

		bool IsNPC(int iPlayerId);

	private:
		WORD m_players;
		bool m_bConnected[MAX_PLAYERS];
		CPlayerData *m_pPlayerData[MAX_PLAYERS];
};

#endif
