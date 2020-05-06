//
// Created by Yujia Li on 2020/5/5.
//

#include "Game.h"

using std::cout;
using std::endl;

std::string Game::start() {
    printBoard();
    while (true) {
        int pos;

        // TODO: duplicate code
        cout << "Player 1: " << endl;
        is >> pos;
        board.submit(Player::_1, pos);
        printBoard();
        if (!board) {
            return "Player1 Win";
        }

        cout << "Player 2: " << endl;
        is >> pos;
        board.submit(Player::_2, pos);
        printBoard();
        if (!board) {
            return "Player2 Win";
        }
    }
}

void Game::printBoard() {
    cout << "Current board:" << endl;
    cout << board << endl;
}
