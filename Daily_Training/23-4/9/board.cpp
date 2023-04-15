/**
 *    author:  HONG-LOU
 *    created: 2023-04-12 18:41:37
**/
#include <bits/stdc++.h>

using namespace std;

#define N 4
int tile = 1;

auto main () -> int {
	cout << "ChessBoard ==>  k=2 ==> " << endl << endl;

  vector<vector<int>> Board(N, vector<int>(N, 0));

	// 棋盘覆盖

  function<void(int, int, int, int, int)> ChessBoard = [&] (int tr, int tc, int dr, int dc, int size) -> void {
    if (size == 1)
      return;

    int t = tile++;		// L型骨牌编号
    int s = size / 2;	// 分割棋盘

    // 覆盖左上角子棋盘
    // 特殊方格在此棋盘中（下面三个if-else同理）
    if (dr < tr + s && dc < tc + s) {
      ChessBoard(tr, tc, dr, dc, s);
    }
    // 此棋盘中无特殊方格（下面三个if-else同理）
    else {
      Board[tr + s - 1][tc + s - 1] = t;				// 用编号为t的骨牌覆盖右下角
      ChessBoard(tr, tc, tr + s - 1, tc + s - 1, s);	// 覆盖其余方格
    }

    // 覆盖右上角子棋盘
    if (dr < tr + s && dc >= tc + s) {
      ChessBoard(tr, tc + s, dr, dc, s);
    }
    else {
      Board[tr + s - 1][tc + s] = t;					// 用编号为t的骨牌覆盖左下角
      ChessBoard(tr, tc + s, tr + s - 1, tc + s, s);	// 覆盖其余方格
    }

    // 覆盖左下角子棋盘
    if (dr >= tr + s && dc < tc + s) {
      ChessBoard(tr + s, tc, dr, dc, s);
    }
    else {
      Board[tr + s][tc + s - 1] = t;					// 用编号为t的骨牌覆盖右上角
      ChessBoard(tr + s, tc, tr + s, tc + s - 1, s);	// 覆盖其余方格
    }

    //覆盖右下角子棋盘
    if (dr >= tr + s && dc >= tc + s) {
      ChessBoard(tr + s, tc + s, dr, dc, s);
    }
    else {
      Board[tr + s][tc + s] = t;						// 用编号为t的骨牌覆盖左上角
      ChessBoard(tr + s, tc + s, tr + s, tc + s, s);	//覆盖其余方格
    }
  };

	ChessBoard(0, 0, 2, 3, N);

	// 打印棋盘覆盖情况
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
      cout << Board[i][j] << " \n"[j == N - 1];
    }
	}

  return 0;
}
