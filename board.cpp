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

bool is_valid(int pinp, int endr, int p1arr[5], int p2arr[5]) {
    bool found = false;
    bool fi = true;

    for (int r = 1; r < endr; ++r) {
	if (pinp == r) {
	    found = true;
	    break;
	}
    }

    for (int qq = 0; qq < 5; ++qq) {
	if (p1arr[qq] == pinp || p2arr[qq] == pinp) {
	    fi = false;
	    break;
	}
    }

    return (found && fi);
}

int main() {
    // spit out initial board to players
    init_board();
    int playGame = 1; // play state
    int playerInput = 0; // player moves variable
    int player = -1; // tracker for whose turn it is
    int EXIT_COMMAND = 18303;
    // create move history here
    int player1Moves[5] = {0, 0, 0, 0, 0};
    int player2Moves[5] = {0, 0, 0, 0, 0};
    int player1N = 0;
    int player2N = 0;
    int curPlayer = 1;
    int MAX_INP_ALLOWED = 10;
    bool valid_move = false;
    // how to quit
    std::cout << "to exit the program enter the number " << EXIT_COMMAND << std::endl;
    // initial mechanism for keeping the game going
    do {
	curPlayer = player % 2 == 0 ? 1 : 2;
	std::cout << "Player " << curPlayer << " enter your move: ";
	std::cin >> playerInput;
	// ok this is sorta getting to the correct place
	if (!std::cin.fail()) {
	    valid_move = is_valid(playerInput, MAX_INP_ALLOWED, player1Moves, player2Moves);
	    while (!valid_move) {
		std::cout << "invalid move, try again" << std::endl;
		std::cin >> playerInput;
		valid_move = is_valid(playerInput, MAX_INP_ALLOWED, player1Moves, player2Moves);
	    }
	} else {
	    std::cout << "cant use letters, game is ending" << std::endl;
	    playGame = 0;
	}
	++player;
	// temporary hack to get rid of infinite strange behavior
	if (curPlayer == 1) {
	    player1Moves[player1N] = playerInput;
	    ++player1N;
	} else {
	    player2Moves[player2N] = playerInput;
	    ++player2N;
	}
	// check if game should end
        if (playerInput == EXIT_COMMAND || player2N > 4 || player1N > 4) {
	    playGame = 0;
	}
	// how do I update the board state?
    } while (playGame == 1);
    // that's all folks
    return 0;
}
