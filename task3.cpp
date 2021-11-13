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
    //{w,h}
    int permission[2] = {MAX_MONITOR_W - 10, MAX_MONITOR_H - 10};
#define PER_H permission[1]
#define PER_W permission[0]
    int position[2] = {10, MAX_MONITOR_H - 10};
#define POS_W position[0]
#define POS_H position[1]
    bool setPosition(int &x,int &y){
        if (x <= MAX_MONITOR_W && x > 0){
            POS_W = x;
        }else return false;
        if (y <= MAX_MONITOR_H && y > 0){
            POS_H = y;
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
            PER_W = w;
            PER_H = h;
        }
    }
    void display(){
        int winH = PER_H;
        int winW = PER_W;
        for (int h = MAX_MONITOR_H; h >= 0; h--) {
            if (h <= POS_H)winH--;
            for (int w = 0; w <= MAX_MONITOR_W; w++) {
                if (w >= POS_W)winW--;
                if ((h <= POS_H && w >= POS_W) && (winW > 0 && winH > 0)){
                    std::cout << 1;
                }else std::cout << 0;
            }
            std::cout << std::endl;
        }
    }
};

int main(){
    Windows windows = Windows();
    windows.display();
    return 0;
}
