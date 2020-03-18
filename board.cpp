#include <iostream>
#include <string>
#include <sstream>

std::string bstate0() {
    std::string bstate = "|       |       |       |";
    return bstate;
}

std::string bstate1() {
    std::string bstate = "|-------|-------|-------|";
    return bstate;
}

std::string make_string_from_int(int i2s) {
    std::stringstream strStream;
    strStream << i2s;
    return strStream.str();
}

std::string bstate_fn(int i0, int i1, int i2) {
    std::string s0 = make_string_from_int(i0);
    std::string s1 = make_string_from_int(i1);
    std::string s2 = make_string_from_int(i2);
    std::string leftS =  "|   " + s0 + "   |";
    std::string midS = "   " + s1 + "   |";
    std::string rightS = "   " + s2 + "   |";
    return leftS + midS + rightS;
}

void init_board() {
    // create initial states
    std::string boardTop = bstate_fn(1, 2, 3);
    std::string boardMid = bstate_fn(4, 5, 6);
    std::string boardBot = bstate_fn(7, 8, 9);
    // print initial board
    // first third
    std::cout << bstate1() << std::endl;
    std::cout << bstate0() << std::endl;
    std::cout << boardTop << std::endl;
    std::cout << bstate0() << std::endl;
    std::cout << bstate1() << std::endl;
    // second third
    std::cout << bstate0() << std::endl;
    std::cout << boardMid << std::endl;
    std::cout << bstate0() << std::endl;
    std::cout << bstate1() << std::endl;
    // third third
    std::cout << bstate0() << std::endl;
    std::cout << boardBot << std::endl;
    std::cout << bstate0() << std::endl;
    std::cout << bstate1() << std::endl;
}

void print_array(int arr[5], int pn) {
    for (int c = 0; c < pn; ++c) {
        std::cout << arr[c] << " ";
    }
    std::cout << std::endl;
}

int main() {
    // spit out initial board to players
    init_board();
    int playGame = 1; // play state
    int playerInput = 0; // player moves variable
    int player = 0; // tracker for whose turn it is

    // create move history here
    int player1Moves[5] = {0, 0, 0, 0, 0};
    int player2Moves[5] = {0, 0, 0, 0, 0};
    int player1N = 0;
    int player2N = 0;

    // how to quit
    std::cout << "to exit the program enter the number 18303" << std::endl;
    // initial mechanism for keeping the game going
    do {
	// so the way the moves are being stored here is off
	// ok need to go do something actually productive, tbd
        if (player % 2 == 0 ? true : false) {
	    std::cout << "Player 1 enter your move: " << std::endl;
            player1Moves[player1N] = playerInput;
	    ++player1N;
	    print_array(player1Moves, player1N);
	} else {
	    std::cout << "Player 2 enter your move: " << std::endl;
	    player2Moves[player2N] = playerInput;
	    ++player2N;
	    print_array(player2Moves, player2N);
	}
	++player;
	// input from user(s)
	std::cin >> playerInput;
	// check if game should end
        if (playerInput == 18303 || player2N > 4 || player1N > 4) {
	    playGame = 0;
	}
	// print out the new state of the game
	// how do I update the board state?
    } while (playGame == 1);
    // that's all folks
    return 0;
}
