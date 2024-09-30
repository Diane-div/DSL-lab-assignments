#include<iostream>
#include<string>
using namespace std;
//node
struct Node {
    string prn;
    string name;
    Node* next;
    Node(string prn, string name) : prn(prn), name(name), next(nullptr) {}
};
//pinnacle class
class PinnacleClub{
private:
    Node* head;
    Node* tail;
    Node* president;
    Node* secretary;
    int memberCount;

    void displayReverse(Node* node) {
        if(node == nullptr) return;
        displayReverse(node->next);
        cout<<node->prn<<"-"<<node->name<<endl;
    }

public:
    PinnacleClub() : head(nullptr), tail(nullptr), president(nullptr), secretary(nullptr), memberCount(0){}
    
    void addMember(const string& prn, const string& name){
        Node* newNode= new Node(prn,name);
        if(head==nullptr){
            head=tail=newNode;
        }
        else{
            tail->next=newNode;
            tail=newNode;
        }
        memberCount++;
    }

    void displayMembers()const{
        Node* current = head;
        while (current != nullptr) {
            cout<<current->prn<<"-"<<current->name<<endl;
            // cout<<&current<<endl;
            current=current->next;
        }
    }

    //get secretary
    void setPresident(const string& prn){
        Node*current=head;
        while(current!=nullptr){
            if(current->prn==prn){
                president=current;
                return;
            }
            current=current->next;
        }
        cout << "President with PRN " << prn << " not found." << endl;
    }

    //get secretary
    void setSecretary(const string& prn) {
        Node* current = head;
        while (current != nullptr) {
            if (current->prn == prn) {
                secretary = current;
                return;
            }
            current = current->next;
        }
        cout << "Secretary with PRN " << prn << " not found." << endl;
    }

    int getTotalMembers() const {
        return memberCount;
    }

};

int main() {
    
    PinnacleClub club1, club2;

    // Adding members to club1
    club1.addMember("PRN001", "Alice");
    club1.addMember("PRN002", "Bob");
    club1.addMember("PRN003", "Charlie");

    // Adding members to club2
    club2.addMember("PRN004", "David");
    club2.addMember("PRN005", "Eve");

    cout << "Club 1 Members:" << endl;
    club1.displayMembers();
    cout << "Club 2 Members:" << endl;
    club2.displayMembers();

    club1.setPresident("PRN001");
    club1.setSecretary("PRN003");

    cout << "President: " << (club1.president ? club1.president->name : "None") << endl;
    cout << "Secretary: " << (club1.secretary ? club1.secretary->name : "None") << endl;

    cout << "Total Members: " << club1.getTotalMembers() << endl;

}
