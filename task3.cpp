#include <iostream>
class Monitor{
private:
    int h = 50;
    int w = 80;
public:
    int PermissionMonitor[2] = {w,h};
#define MAX_MONITOR_W monitor.PermissionMonitor[0]
#define MAX_MONITOR_H monitor.PermissionMonitor[1]
};

class Windows{
private:
    Monitor monitor = Monitor();
    //set default
    int permission[2] = {MAX_MONITOR_W - 20, MAX_MONITOR_H - 20};
#define WIN_PER_H permission[1]
#define WIN_PER_W permission[0]
    int position[2] = {10, MAX_MONITOR_H - 10};
#define WIN_POS_W position[0]
#define WIN_POS_H position[1]
    bool setPosition(int &x,int &y){
        if (x <= MAX_MONITOR_W && x >= 0){
            WIN_POS_W = x;
        }else return false;
        if (y <= MAX_MONITOR_H && y >= 0){
            WIN_POS_H = y;
        }else return false;
        return true;
    }
public:
    void move(){
        int x;
        int y;
        std::cout << "Enter new position x, y\n";
        std::cin >> x >> y;
        if (setPosition(x,y)){
            std::cout << "new position " << x << ", " << y << std::endl;
        }else std::cout << "Error coordinates\n";
    }
    void resize(){
        int h;
        int w;
        std::cout << "Enter new size w, h\n";
        std::cin >> w >> h;
        if (w > 0 && h > 0){
            WIN_PER_W = w;
            WIN_PER_H = h;
        }
    }
    void display(){
        int winH = WIN_PER_H;
        for (int h = MAX_MONITOR_H; h > 0; h--) {
            if (h <= WIN_POS_H && winH >= 0)winH--;
            for (int w = 0, winW = WIN_PER_W; w < MAX_MONITOR_W; w++) {
                if (w >= WIN_POS_W && winW >= 0)winW--;
                if ((h <= WIN_POS_H && w >= WIN_POS_W) && (winW >= 0 && winH >= 0)){
                    std::cout << 1;
                }else std::cout << 0;
            }
            std::cout << std::endl;
        }
    }
};

int main(){
    Windows windows = Windows();
    std::string action;
    while (action != "close"){
        std::cout << "Enter action\n";
        std::cin >> action;
        if (action == "move"){
            windows.move();
        }else if (action == "resize"){
            windows.resize();
        }else if (action == "display"){
            windows.display();
        }else if (action == "close"){
            std::cout << "Good by\n";
        }
    }
    return 0;
}
