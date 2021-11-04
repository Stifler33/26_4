#include <iostream>
#include <ctime>
#include <iomanip>

class Track{
private:
    std::string track1Name = "Kino - zvezda po imeni solnce";
    std::time_t track1Date = 620390003;
    std::time_t track1Duration = 226;
    std::string track2Name = "AC/DC - Black and Black";
    std::time_t track2Date = 330777787;
    std::time_t track2Duration = 255;
    std::string track3Name = "SlipKnot - Before i forget";
    std::time_t track3Date = 1085482178;
    std::time_t track3Duration = 278;
};
int main() {
    std::time_t kino = 620390003;
    std::tm Kino = *std::localtime(&kino);
    std::cout << std::put_time(&Kino, "%Y.%m.%d");
    return 0;
}
