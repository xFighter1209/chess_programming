/*
  Chameleon, a UCI chinese chess playing engine derived from Stockfish
  Copyright (C) 2004-2008 Tord Romstad (Glaurung author)
  Copyright (C) 2008-2015 Marco Costalba, Joona Kiiski, Tord Romstad
  Copyright (C) 2015-2017 Marco Costalba, Joona Kiiski, Gary Linscott, Tord Romstad
  Copyright (C) 2017 Wilbert Lee

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#include "types.h"

namespace PSQT
{
#define S(mg, eg) make_score(mg, eg)

	// Bonus[PieceType][Square / 2] contains Piece-Square scores. For each piece
	// type on a given square a (middlegame, endgame) score pair is assigned. Table
	// is defined for files A..D and white side: it is symmetric for black side and
	// second half of the files.
	const Score Bonus[PIECE_TYPE_NB][SQUARE_NB] =
	{ { },
	{
		// Pawn
		S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0),
		S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0),
		S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0),
		S(70, 180), S(0, 0), S(70, 190), S(0, 0), S(150, 208), S(0, 0), S(70, 190), S(0, 0), S(70, 180),
		S(70, 210), S(0, 0), S(130, 215), S(0, 0), S(160, 238), S(0, 0), S(130, 215), S(0, 0), S(70, 210),

		S(140, 270), S(180, 306), S(200, 308), S(270, 368), S(290, 378), S(270, 368), S(200, 308), S(180, 306), S(140, 270),
		S(190, 336), S(230, 381), S(270, 401), S(290, 410), S(300, 410), S(290, 410), S(270, 401), S(230, 381), S(190, 336),
		S(190, 286), S(240, 336), S(320, 385), S(370, 400), S(370, 400), S(370, 400), S(320, 385), S(240, 336), S(190, 286),
		S(190, 211), S(240, 261), S(340, 336), S(420, 420), S(440, 600), S(420, 420), S(340, 336), S(240, 261), S(190, 211),
		S(90, 95), S(90, 95), S(90, 95), S(110, 330), S(130, 540), S(110, 330), S(90, 95), S(90, 95), S(90, 95)
	},
	{
		// Advisor
		S(0, 0), S(0, 0), S(0, 0), S(200, 260), S(0, 0), S(200, 260), S(0, 0), S(0, 0), S(0, 0),
		S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(230, 270), S(0, 0), S(0, 0), S(0, 0), S(0, 0),
		S(0, 0), S(0, 0), S(0, 0), S(200, 260), S(0, 0), S(200, 260), S(0, 0), S(0, 0), S(0, 0),
		S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0),
		S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0),

		S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0),
		S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0),
		S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0),
		S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0),
		S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0)
	},
	{
		// Bishop
		S(0, 0), S(0, 0), S(200, 240), S(0, 0), S(0, 0), S(0, 0), S(200, 240), S(0, 0), S(0, 0),
		S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0),
		S(180, 230), S(0, 0), S(0, 0), S(0, 0), S(230, 250), S(0, 0), S(0, 0), S(0, 0), S(180, 230),
		S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0),
		S(0, 0), S(0, 0), S(200, 240), S(0, 0), S(0, 0), S(0, 0), S(200, 240), S(0, 0), S(0, 0),

		S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0),
		S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0),
		S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0),
		S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0),
		S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0)
	},
	{
		// Knight
		S(880, 930), S(850, 950), S(900, 970), S(880, 950), S(900, 950), S(880, 950), S(900, 970), S(850, 950), S(880, 930),
		S(850, 950), S(900, 970), S(920, 990), S(930, 970), S(700, 800), S(930, 970), S(920, 990), S(900, 970), S(850, 950),
		S(900, 970), S(920, 990), S(940, 1010), S(950, 1010), S(920, 1010), S(950, 1010), S(940, 1010), S(920, 990), S(900, 970),
		S(920, 990), S(940, 1010), S(980, 1030), S(950, 1030), S(980, 1030), S(950, 1030), S(980, 1030), S(940, 1010), S(920, 990),
		S(900, 990), S(980, 1010), S(1010,1030), S(1020,1030), S(1030, 1030), S(1020,1030), S(1010,1030), S(980, 1010), S(900, 990),

		S(900, 1010), S(1000, 1030), S(990, 1050), S(1030, 1050), S(1040, 1050),S(1030, 1050),S(990, 1050), S(1000, 1030), S(900, 1010),
		S(930, 1010), S(1080, 1030), S(1000, 1050),S(1070,1050), S(1000, 1050),S(1070, 1050), S(1000, 1050),S(1080, 1030), S(930, 1010),
		S(920, 1010), S(980, 1030), S(990, 1050), S(1030, 1050), S(990, 1050), S(1030, 1050),S(990, 1050), S(980, 1030), S(920, 1010),
		S(900, 990), S(960, 1010), S(1030, 1030),S(970, 1030), S(940, 1000), S(970, 1030), S(1030, 1030),S(960, 1010), S(900, 990),
		S(900, 970), S(900, 990), S(900, 1010), S(960, 1010), S(900, 1010), S(960, 1010), S(900, 1010), S(900, 990), S(900, 970)
	},
	{
		// Cannon
		S(960, 1000), S(960, 1000), S(970, 1000), S(990, 1040), S(990, 1060), S(990, 1040), S(970, 1000), S(960, 1000), S(960, 1000),
		S(960, 1000), S(970, 1000), S(980, 1000), S(980, 1040), S(980, 1060), S(980, 1040), S(980, 1000), S(970, 1000), S(960, 1000),
		S(970, 1000), S(960, 1000), S(1000, 1000), S(990, 1020), S(1010, 1040), S(990, 1020), S(1000, 1000), S(960, 1000), S(970, 1000),
		S(960, 1000), S(960, 1000), S(960, 1000), S(960, 1020), S(960, 1040), S(960, 1020), S(960, 1000), S(960, 1000), S(960, 1000),
		S(950, 1000), S(960, 1000), S(990, 1000), S(960, 1020), S(1000, 1040), S(960, 1020), S(990, 1000), S(960, 1000), S(950, 1000),

		S(960, 1000), S(960, 1000), S(960, 1000), S(960, 1020), S(1000, 1040),S(960, 1020), S(960, 1000), S(960, 1000), S(960, 1000),
		S(960, 1000), S(990, 1000), S(990, 1000), S(980, 1020), S(1000, 1040), S(980, 1020), S(990, 1000), S(990, 1000), S(960, 1000),
		S(970, 1000), S(970, 1000), S(960, 1000), S(910, 1000), S(920, 1000), S(910, 1000), S(960, 1000), S(970, 1000), S(970, 1000),
		S(980, 1000), S(980, 1000), S(960, 1000), S(920, 1000), S(890, 1000), S(920, 1000), S(960, 1000), S(980, 1000), S(980, 1000),
		S(1000, 1000), S(1000, 1000), S(960, 1000), S(910, 1000), S(900, 1000), S(910, 1000), S(960, 1000), S(1000, 1000), S(1000, 1000)
	},
	{
		// Rook
		S(1940, 1980), S(2060, 1980), S(2040, 1980), S(2120, 2000), S(2000, 2020), S(2120, 2000), S(2040, 1980), S(2060, 1980), S(1940, 1980),
		S(2000, 1980), S(2080, 1980), S(2060, 1980), S(2120, 2000), S(2000, 2020), S(2120, 2000), S(2060, 1980), S(2080, 1980), S(2000, 1980),
		S(1980, 1980), S(2080, 1980), S(2040, 1980), S(2120, 2000), S(2120, 2020), S(2120, 2000), S(2040, 1980), S(2080, 1980), S(1980, 1980),
		S(2040, 1980), S(2090, 1980), S(2040, 1980), S(2120, 2000), S(2140, 2020), S(2120, 2000), S(2040, 1980), S(2090, 1980), S(2040, 1980),
		S(2080, 1980), S(2120, 1980), S(2120, 1980), S(2140, 2000), S(2150, 2020), S(2140, 2000), S(2120, 1980), S(2120, 1980), S(2080, 1980),

		S(2080, 1980), S(2110, 1980), S(2110, 1980), S(2140, 2000), S(2150, 2020), S(2140, 2000), S(2110, 1980), S(2110, 1980), S(2080, 1980),
		S(2060, 1980), S(2130, 1980), S(2130, 1980), S(2160, 2000), S(2160, 2020), S(2160, 2000), S(2130, 1980), S(2130, 1980), S(2060, 1980),
		S(2060, 2000), S(2080, 2000), S(2070, 2000), S(2140, 2020), S(2160, 2040), S(2140, 2020), S(2070, 2000), S(2080, 2000), S(2060, 2000),
		S(2060, 2020), S(2120, 2020), S(2090, 2020), S(2160, 2040), S(2330, 2080), S(2160, 2040), S(2090, 2020), S(2120, 2020), S(2060, 2020),
		S(2060, 2000), S(2080, 2000), S(2070, 2000), S(2130, 2020), S(2140, 2040), S(2130, 2020), S(2070, 2000), S(2080, 2000), S(2060, 2000)
	},
	{
		// King
		S(0, 0), S(0, 0), S(0, 0), S(1100, 100), S(1500, 200), S(1100, 100), S(0, 0), S(0, 0), S(0, 0),
		S(0, 0), S(0, 0), S(0, 0), S(200, 50), S(200, 100), S(200, 50), S(0, 0), S(0, 0), S(0, 0),
		S(0, 0), S(0, 0), S(0, 0), S(100, 30), S(100, 120), S(100, 30), S(0, 0), S(0, 0), S(0, 0),
		S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0),
		S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0),

		S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0),
		S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0),
		S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0),
		S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0),
		S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0)
	}
	};
#undef S
	Score psq[COLOR_NB][PIECE_TYPE_NB][SQUARE_NB];

	/// init() initializes piece square tables: the white halves of the tables are
	/// copied from Bonus[] adding the piece value, then the black halves of the
	/// tables are initialized by flipping and changing the sign of the white scores.

	void init()
	{
		for (PieceType pt = PAWN; pt <= KING; ++pt)
		{
			PieceValue[MG][make_piece(BLACK, pt)] = PieceValue[MG][pt];
			PieceValue[EG][make_piece(BLACK, pt)] = PieceValue[EG][pt];

			Score v = make_score(PieceValue[MG][pt], PieceValue[EG][pt]);

			for (Square s = SQ_A0; s <= SQ_I9; ++s)
				psq[BLACK][pt][~s] = -(psq[WHITE][pt][s] = v + Bonus[pt][s] / 4);
		}
	}

} // namespace PSQT