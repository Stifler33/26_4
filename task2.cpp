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
        if (call && !haveContact(name)){
            std::cout << "not contact\n";
            return "null";
        }
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
    void setNumber(){
        book.addNumber();
    }
    std::string reqNumber(){
        return book.getNumber();
    }
    void getListNumber(){
        book.coutList();
    }
    bool haveNumber(std::string &name){
        return book.haveContact(name);
    }
    void call(){
        std::string contact = book.getNumber(true);
        if (contact == "null"){
            return;
        }
        std::cout << "Call " << contact << std::endl;
    }
    void sms(){
        std::string name = book.getNumber(true);
        if (name == "null"){
            return;
        }
        std::string textSms;
        std::cout << "Enter to text\n";
        std::cin.ignore();
        std::getline(std::cin,textSms);
        std::cout << "sending a massage :\n";
        std::cout << "'" <<textSms << "'" <<std::endl;
        std::cout << "for contact :\n";
        std::cout << name << std::endl;
    }

};
int main(){
    Telephone telephone = Telephone();
    std::string action ;
    while (action != "exit"){
        std::cout << "Enter action\n";
        std::cin >> action;
        if (action == "add"){
            telephone.setNumber();
        }else if (action == "get"){
            std::cout << telephone.reqNumber() << std::endl;
        }else if (action == "list"){
            telephone.getListNumber();
        }else if (action == "call"){
            telephone.call();
        }else if (action == "sms"){
            telephone.sms();
        }
    }
    return 0;
}