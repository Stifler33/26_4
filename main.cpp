#include <iostream>
#include <ctime>
#include <iomanip>
#include <random>
class Track{
private:
    std::string track1Name = "Kino - zvezda po imeni solnce";
    std::time_t track1Date = 620390003;
    std::tm date1 = *std::localtime(&track1Date);
    std::time_t track1Duration = 226;
    std::tm duration1 = *std::localtime(&track1Duration);
    std::string track2Name = "AC/DC - Black and Black";
    std::time_t track2Date = 330777787;
    std::tm date2 = *std::localtime(&track2Date);
    std::time_t track2Duration = 255;
    std::tm duration2 = *std::localtime(&track2Duration);
    std::string track3Name = "SlipKnot - Before i forget";
    std::time_t track3Date = 1085482178;
    std::tm date3 = *std::localtime(&track3Date);
    std::time_t track3Duration = 278;
    std::tm duration3 = *std::localtime(&track3Duration);
public:
    void nameTrack(int number){
        switch(number){
            case 1:
                std::cout << track1Name << std::endl;
                break;
            case 2:
                std::cout << track2Name << std::endl;
                break;
            case 3:
                std::cout << track3Name << std::endl;
                break;
            default:
                break;
        }
    }
    void durationTrack(int number){
        switch(number){
            case 1:
                std::cout << std::put_time(std::localtime(&track1Duration), "%M:%S") << std::endl;
                break;
            case 2:
                std::cout << std::put_time(std::localtime(&track2Duration), "%M:%S") << std::endl;
                break;
            case 3:
                std::cout << std::put_time(std::localtime(&track3Duration), "%M:%S") << std::endl;
                break;
            default:
                break;
        }
    }
    void dateTrack(int number){
        switch(number){
            case 1:
                std::cout << std::put_time(std::localtime(&track1Date), "%Y.%m.%d") << std::endl;
                break;
            case 2:
                std::cout << std::put_time(std::localtime(&track2Date), "%Y.%m.%d") << std::endl;
                break;
            case 3:
                std::cout << std::put_time(std::localtime(&track3Date), "%Y.%m.%d") << std::endl;
                break;
            default:
                break;
        }
    }
};
class Walkman{
private:
    bool plays = false;
    bool pause = false;
    int number;
    Track *track = new Track();
    int randNum(int min = 1, int max = 3){
        double frac = 1.0 / (RAND_MAX + 1.0);
        int out = int(rand() * frac * (max - min + 1) + min);
        if (out == number){
            randNum();
        }else return out;
    }
public:
    void play(int numTrack = 0, bool trackNext = false){
        if (pause && !trackNext){
            std::cout << "Play track ";
            track->nameTrack(number);
            pause = false;
            return;
        }
        if (plays && !trackNext) return;
        if (!trackNext){
            std::cout << "Enter number track\n";
            std::cin >> number;
            plays = true;
        }else if (trackNext){
            number = numTrack;
        }
        std::cout << "Name track\n";
        track->nameTrack(number);
        std::cout << "Duration track\n";
        track->durationTrack(number);
        std::cout << "Track date of creation\n";
        track->dateTrack(number);
    }
    void pauseTrack(){
        std::cout << "Pause\n";
        pause = true;
    }
    void next(){
        srand(int(std::time(nullptr)));
        play(randNum(), true);
    }
    void stop(){
        if (plays){
            plays = false;
            pause = false;
            std::cout << "Stop\n";
        }
    }
    void exit(){
        plays = false;
        pause = false;
        std::cout << "goodbye\n";
        delete track;
    }
};
int main() {
    Walkman *walkman = new Walkman();
    std::string action;
    while (action != "exit"){
        std::cout << "Enter action\n";
        std::cin >> action;
        if (action == "play"){
            walkman->play();
        }else if (action == "pause"){
            walkman->pauseTrack();
        }else if (action == "next"){
            walkman->next();
        }else if (action == "stop"){
            walkman->stop();
        }else if (action == "exit"){
            walkman->exit();
        }
    }
    delete walkman;
    return 0;
}
