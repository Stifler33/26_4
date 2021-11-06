#include <iostream>
#include <vector>
#include <map>
class Book{
private:
    std::map<std::string, std::string> name_to_number;
    std::map<std::string, std::string> number_to_name;
#define BEGIN_NAME (name[0] >= 'a' && name[0] <= 'z') || (name[0] >= 'A' && name[0] <= 'Z')
#define BEGIN_NUMBER name[0] >= '0' && name[0] <= '9' || name[0] == '+'
public:
    void addNumber(){
        std::cout << "Enter name\n";
        std::string name;
        std::cin >> name;
        std::cout << "Enter number\n";
        std::string number;
        std::cin >> number;
        name_to_number[name] = number;
        number_to_name[number] = name;
    }
    std::string getNumber(){
        std::string name;
        std::cout << "Enter name\n";
        std::cin >> name;
        if (BEGIN_NAME){
            return name_to_number[name];
        }else if (BEGIN_NUMBER){
            return number_to_name[name];
        }else return "Error";
    }
    void coutList(){
        for (auto &i : name_to_number){
            std::cout << i.first << " ";
            std::cout << i.second << std::endl;
        }
    }
};
int main(){
    Book book = Book();
    std::string action ;
    while (action != "exit"){
        std::cout << "Enter action\n";
        std::cin >> action;
        if (action == "add"){
            book.addNumber();
        }else if (action == "get"){
            std::cout << book.getNumber() << std::endl;
        }else if (action == "list"){
            book.coutList();
        }
    }
    return 0;
}