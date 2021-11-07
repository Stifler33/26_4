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
    bool haveContact(std::string name){
         if (BEGIN_NAME){
             return name_to_number.count(name);
         }else if (BEGIN_NUMBER){
             return number_to_name.count(name);
         }
    }
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
    std::string getNumber(bool call = false){
        std::string name;
        std::cout << "Enter name or fon number\n";
        std::cin >> name;
        /*
        if (!haveContact(name)){
            std::cerr << "not contact\n";
            return "error";
        }
         */
        std::string callNumber;
        if (BEGIN_NAME){
            if (call){
                callNumber = (name + " " + name_to_number[name]);
                return callNumber;
            }
            return name + " " + name_to_number[name];
        }else if (BEGIN_NUMBER){
            if (call){
                callNumber = (number_to_name[name] + " " + name);
                return callNumber;
            }
            return number_to_name[name] + " " +name;
        }else return "Error";
    }
    void coutList(){
        for (auto &i : name_to_number){
            std::cout << i.first << " ";
            std::cout << i.second << std::endl;
        }
    }

};
class Telephone{
private:
    Book book = Book();
public:
    void call(){
        std::string contact = book.getNumber(true);
        std::cout << "Call " << contact << std::endl;
    }
    void sms(){
        std::string name = book.getNumber(true);
        std::string textSms;
        std::cout << "Enter to text\n";
        std::cin >> textSms;
        std::cout << "sending a massage :\n";
        std::cout << "'" <<textSms << "'" <<std::endl;
        std::cout << "for contact :\n";
        std::cout << name << std::endl;
    }

};
int main(){
    Book book = Book();
    Telephone telephone = Telephone();
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
        }else if (action == "call"){
            telephone.call();
        }else if (action == "sms"){
            telephone.sms();
        }
    }
    return 0;
}