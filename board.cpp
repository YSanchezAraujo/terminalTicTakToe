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

int main() {
    // spit out initial board to players
    init_board();
    return 0;
}
