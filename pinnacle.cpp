//  The Department of computer engineeering has student's club named"Pinnacle Club'
// Students of second, third and final year can be granted membership on request
// similarly one may cancel membership
// first node for president and last node for secretary
// write a c++ program to maintain club member's information using singly linked list
// store student prn and name
// write functions to: add and delete members and president and secretary
// compute total no. of member in club
// display members
// display list in reverse order using recursion
// two linked list exist for two divisions, concatenate two lists

#include <iostream>
#include <string>
using namespace std;

// Node structure for singly linked list
struct Node {
    string prn;
    string name;
    Node* next;
    Node(string prn, string name) : prn(prn), name(name), next(nullptr) {}
};

// Class to manage the Pinnacle Club
class PinnacleClub {
private:
    Node* head;   // Head of the linked list
    Node* tail;   // Tail of the linked list
    Node* president; // President node
    Node* secretary; // Secretary node
    int memberCount; // Number of members

    // Helper function to display the list in reverse order using recursion
    void displayReverse(Node* node) {
        if (node == nullptr) return;
        displayReverse(node->next);
        cout << node->prn << " - " << node->name << endl;
    }

public:
    PinnacleClub() : head(nullptr), tail(nullptr), president(nullptr), secretary(nullptr), memberCount(0) {}

    // Add a new member to the list
    void addMember(const string& prn, const string& name) {
        Node* newNode = new Node(prn, name);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        memberCount++;
    }

    // Delete a member by PRN
    void deleteMember(const string& prn) {
        Node* current = head;
        Node* previous = nullptr;

        while (current != nullptr && current->prn != prn) {
            previous = current;
            current = current->next;
        }

        if (current == nullptr) return; // PRN not found

        if (previous == nullptr) {
            head = current->next;
        } else {
            previous->next = current->next;
        }

        if (current == tail) {
            tail = previous;
        }

        delete current;
        memberCount--;
    }

    // Set president
    void setPresident(const string& prn) {
        Node* current = head;
        while (current != nullptr) {
            if (current->prn == prn) {
                president = current;
                return;
            }
            current = current->next;
        }
        cout << "President with PRN " << prn << " not found." << endl;
    }

    // Set secretary
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

    // Compute the total number of members
    int getTotalMembers() const {
        return memberCount;
    }

    // Display all members
    void displayMembers() const {
        Node* current = head;
        while (current != nullptr) {
            cout << current->prn << " - " << current->name << endl;
            current = current->next;
        }
    }

    // Display list in reverse order
    void displayReverse() const {
        displayReverse(head);
    }

    // Concatenate two linked lists
    void concatenate(PinnacleClub& other) {
        if (head == nullptr) {
            head = other.head;
            tail = other.tail;
        } else if (other.head != nullptr) {
            tail->next = other.head;
            tail = other.tail;
        }

        memberCount += other.memberCount;
        other.head = other.tail = nullptr; // Clear the other list
        other.memberCount = 0;
    }

    ~PinnacleClub() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
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

    // Concatenating club2 into club1
    club1.concatenate(club2);

    cout << "After concatenation:" << endl;
    club1.displayMembers();

    // Setting president and secretary
    club1.setPresident("PRN001");
    club1.setSecretary("PRN003");

    // Displaying president and secretary
    cout << "President: " << (club1.president ? club1.president->name : "None") << endl;
    cout << "Secretary: " << (club1.secretary ? club1.secretary->name : "None") << endl;

    // Displaying members in reverse order
    cout << "Members in Reverse Order:" << endl;
    club1.displayReverse();

    // Deleting a member
    club1.deleteMember("PRN002");
    cout << "After deleting member with PRN002:" << endl;
    club1.displayMembers();

    // Display total number of members
    cout << "Total Members: " << club1.getTotalMembers() << endl;

    return 0;
}
